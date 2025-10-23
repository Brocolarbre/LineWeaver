# LineWeaver

LineWeaver is a **C++ library** that provides a unifed way of **interpolating curves**.
You provide a **list of points** to an interpolator as well as a **value** you want to sample the curve at and the interpolator **interpolates** the curve at this value.
The library is able to use any interpolator with the B-Spline interpolator, thus allowing B-Splines with **any type** of curve.
The library works in **3D** and can be used in **2D** as well by just ignoring **z** values or setting them at zero.

## Usage

### Points and curves

The library uses **glm** for its data representation. This is the only external dependency.
Two types are defined : **Point** and **Curve**. In reality, these types are just aliases for glm types :
```c++
using Point = glm::vec3;
using Curve = std::vector<Point>;
```

### Curve interpolators

- Linear
- Bezier
- Hermite
- Catmull-Rom
- B-Spline

Each interpolator computes the interpolation of a curve, at a **t** value in a range of [**0**, **1**].
Note that the B-Spline interpolator is a bit different. Since it combines multiple curves, the sampling value is called **u** and has a range of [**0**, **n**], where **n** equals the number of concatenated curves forming the B-Spline.
The library takes care of clamping **t** and **u** values to the appropriate range in case the value is too high or too low.

While most of the interpolators have a fixed number of points per curve, this is not the case for Bezier curves. This is why the `BezierInterpolator` class takes an optional value in its constructor. You can specify the degree of the curve (how many points are part of the curve).

Below is a list of the degree values of the interpolators. You should make sure that each interpolator interpolates a curve where the number of points matches the degree of the interpolator. If there are not enough points, the interpolator returns a point with zero values. If there are too many points, the interpolator ignores the extra points.

- Linear - 2
- Bezier - n
- Hermite - 4
- Catmull-Rom - 4
- B-Spline - Uses the interpolator degree

If you have **7** points in a curve and are using Hermite or Catmull-Rom interpolators, you have a total of **2** concatenated curves in a B-Spline.
If you have **5** points in a curve and are using a Linear interpolator, you have a total of **4** concatenated curves in a B-Spline.

Here is an example of the Bezier interpolator :
```c++
#include <LineWeaver/Interpolation/BezierInterpolator.hpp>

lw::Curve curve { ... };
lw::BezierInterpolator bezierInterpolator(4); // optional degree, default is 3

float samplingValue = 0.5f;
lw::Point point = bezierInterpolator(curve, samplingValue);
```

Here is an example of the B-Spline interpolator (using Hermite curves) :
```c++
#include <LineWeaver/Interpolation/HermiteInterpolator.hpp>
#include <LineWeaver/Interpolation/BSplineInterpolator.hpp>

lw::Curve curve { ... };
lw::HermiteInterpolator hermiteInterpolator;
lw::BSplineInterpolator hermiteBSplineInterpolator(&hermiteInterpolator);

float samplingValue = 2.4f; // 2.4 assumes that there are at least 3 concatenated curves
lw::Point point = hermiteBSplineInterpolator(curve, samplingValue);
```

### Easing functions

The curves are typically interpolated by warying the *t* parameter from 0 to 1 (or more for BSplines).
This is a linear behavior that works fine but there are cases where it is useful to vary the parameter in a **non-linear** way.
This is why the library provides a set of **easing functions**.
Their usage consists of instantiating the appropriate class given the desired easing type, and calling the parenthesis operator overload with the *t* value as an argument.
Each ease function converts the linear argument and returns its corresponding non-linear value.
This can be used to sample a curve by putting an emphasis on the begining of the curve, or the end, or both.

Here is an example :
```c++
#include <LineWeaver/Easing/EaseInOutCubic.hpp>
#include <LineWeaver/Interpolation/CatmullRomInterpolator.hpp>

lw::Curve curve { ... };
lw::CatmullRomInterpolator catmullRomInterpolator;

lw::EaseInOutCubic easing;

float samplingValue = easing(0.35f); // The () operator converts the linear value to its corresponding cubic value
lw::Point point = bezierInterpolator(curve, samplingValue);
```

### Curve sampler

Each interpolator implements an **overload of the ()** operator. This makes the use more compact and avoids repetitions such as "interpolator.interpolate()".
What if you need to sample a curve a **certain amount of times**, with values each having an **even interval** ?
The **CurveSampler** is used for this exact reason. It contains two **static methods**.
One that can generate a **custom-sized** sequence of sampling values between in a  [**min**, **max**] interval given an easing function, and another that processes a curve by applying a interpolator to a curve with a sequence of sampling values.

Here is an example :
```c++
#include <LineWeaver/Easing/EaseInQuadratic.hpp>
#include <LineWeaver/BezierInterpolator.hpp>
#include <LineWeaver/Sampling/CurveSampler.hpp>

lw::Curve curve { ... };
lw::BezierInterpolator bezierInterpolator;

lw::EaseInQuadratic easing;
std::vector<float> samples = lw::CurveSampler::generateSampleValues(10, 0.0f, 1.0f, easing);

lw::Curve bezierCurve = lw::CurveSampler::sampleCurve(curve, bezierInterpolator, samples);
```

The above code generates a sequence of 10 sampling values that are evenly spaced between 0 and 1. To keep a linear sampling while generating sampling values, simply use the **EaseLinear** easing function.
It then samples the curve using the sampling values.
If you need more control over the easing function, the *EaseCurve* easing function is available. It takes an interpolator and a list of control points in its constructor.

Note that unlike the other easing functions, the *EaseCurve* function can be sampled at values exceeding 1.0, as long as the curve is using a B-Spline interpolator and there are enough concatenated curves on the B-Spline.
In practice, this means that the *max* parameter for the *CurveSampler::generateSampleValues* method should only exceed 1 if the easing function is *EaseCurve*.
Similarly, the *CurveSampler::sampleCurve* method sampling values should only exceed 1 if it is using a B-Spline interpolator.

The value returned by the *EaseCurve* function is the corresponding y value of the interpolated point of the curve.
This allows for a more intuitive way of defining the curve with a 2D graph : the x axis corresponds to the *t* parameter progression and the y axis corresponds to the function result. The z axis can be ignored.

## Test application

**LineWeaverTest** is a test application that you can use to try the library with ease. It implements a few **use cases** as well as utility functions to **read** and **write** **.csv** curves and **print** points and curves in the console.

## Setup

The project follows the [Nest](https://github.com/Brocolarbre/Nest/) structure.
To build the project :
- Open a terminal in the **root folder** of the project
- Run the following command :
  - Windows : `.\scripts\windows\set_workspace.bat`
  - Linux : `./scripts/linux/setup_workspace.sh`
- Open the project workspace
- Build the project

### Static and dynamic linkage

Any project that uses the the static version of the library shoud define the `LINEWEAVER_STATIC` macro.
To manually export the library as a shared library, the project should define the `LINEWEAVER_EXPORT` macro.
Using the library as a static library requires to link the external dependencies of the library (as only a dynamic library or an executable can store static dependencies).
The dependencies are listed below, the library is guaranteed to work with the specified library versions. Replacing a library with another version may or may not work.

### External dependencies

**LineWeaver** has the following external dependencies :
- glm (1.0.1)