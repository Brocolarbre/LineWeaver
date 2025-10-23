#include "CurveUtils.hpp"

#include <LineWeaver/Easing/EaseInOutCubic.hpp>
#include <LineWeaver/Interpolation/BezierInterpolator.hpp>
#include <LineWeaver/Interpolation/BSplineInterpolator.hpp>
#include <LineWeaver/Interpolation/CatmullRomInterpolator.hpp>
#include <LineWeaver/Interpolation/HermiteInterpolator.hpp>
#include <LineWeaver/Interpolation/LinearInterpolator.hpp>
#include <LineWeaver/Sampling/CurveSampler.hpp>

#include <iostream>

int main()
{
	std::cout << "LineWeaverTest" << std::endl << std::endl;

	// Loading curves

	lw::Curve curve1 = CurveUtils::readCurveCsv("res/curves/curve_1.csv");
	lw::Curve curve2 = CurveUtils::readCurveCsv("res/curves/curve_2.csv");
	lw::Curve curve3 = CurveUtils::readCurveCsv("res/curves/curve_3.csv");
	lw::Curve curve4 = CurveUtils::readCurveCsv("res/curves/curve_4.csv");

	std::cout << "Curve 1" << std::endl;
	CurveUtils::printCurve(curve1); std::cout << std::endl;

	std::cout << "Curve 2" << std::endl;
	CurveUtils::printCurve(curve2); std::cout << std::endl;

	std::cout << "Curve 3" << std::endl;
	CurveUtils::printCurve(curve3); std::cout << std::endl;

	std::cout << "Curve 4" << std::endl;
	CurveUtils::printCurve(curve4); std::cout << std::endl;

	// Interpolators

	lw::LinearInterpolator linearInterpolator;
	lw::BezierInterpolator bezierInterpolator(4);
	lw::HermiteInterpolator hermiteInterpolator;
	lw::CatmullRomInterpolator catmullRomInterpolator;

	// Easing

	lw::EaseInOutCubic easing;

	// Sampling

	std::vector<float> samplesZeroToOne = lw::CurveSampler::generateSampleValues(100, 0.0f, 1.0f, easing);

	lw::Curve linearCurve = lw::CurveSampler::sampleCurve(curve1, linearInterpolator, samplesZeroToOne);
	lw::Curve bezierCurve = lw::CurveSampler::sampleCurve(curve2, bezierInterpolator, samplesZeroToOne);
	lw::Curve hermiteCurve = lw::CurveSampler::sampleCurve(curve2, hermiteInterpolator, samplesZeroToOne);
	lw::Curve catmullRomCurve = lw::CurveSampler::sampleCurve(curve2, catmullRomInterpolator, samplesZeroToOne);

	std::cout << "Linear curve" << std::endl;
	CurveUtils::printCurve(linearCurve); std::cout << std::endl;

	std::cout << "Bezier curve" << std::endl;
	CurveUtils::printCurve(bezierCurve); std::cout << std::endl;

	std::cout << "Hermite curve" << std::endl;
	CurveUtils::printCurve(hermiteCurve); std::cout << std::endl;

	std::cout << "CatmullRom curve" << std::endl;
	CurveUtils::printCurve(catmullRomCurve); std::cout << std::endl;
	
	// BSpline interpolator

	lw::BSplineInterpolator linearBSplineGenerator(&linearInterpolator);
	lw::BSplineInterpolator bezierBSplineGenerator(&bezierInterpolator);
	lw::BSplineInterpolator hermiteBSplineGenerator(&hermiteInterpolator);
	lw::BSplineInterpolator catmullRomBSplineGenerator(&hermiteInterpolator);

	std::vector<float> samplesZeroToTwo = lw::CurveSampler::generateSampleValues(100, 0.0f, 2.0f, easing);

	lw::Curve linearBSplineCurve = lw::CurveSampler::sampleCurve(curve2, linearBSplineGenerator, samplesZeroToTwo);
	lw::Curve bezierBSplineCurve = lw::CurveSampler::sampleCurve(curve3, bezierBSplineGenerator, samplesZeroToTwo);
	lw::Curve hermiteBSplineCurve = lw::CurveSampler::sampleCurve(curve3, hermiteBSplineGenerator, samplesZeroToTwo);
	lw::Curve catmullRomBSplineCurve = lw::CurveSampler::sampleCurve(curve4, catmullRomBSplineGenerator, samplesZeroToTwo);

	std::cout << "Linear B-Spline curve" << std::endl;
	CurveUtils::printCurve(linearBSplineCurve); std::cout << std::endl;

	std::cout << "Bezier B-Spline curve" << std::endl;
	CurveUtils::printCurve(bezierBSplineCurve); std::cout << std::endl;

	std::cout << "Hermite B-Spline curve" << std::endl;
	CurveUtils::printCurve(hermiteBSplineCurve); std::cout << std::endl;

	std::cout << "CatmullRom B-Spline curve" << std::endl;
	CurveUtils::printCurve(catmullRomBSplineCurve); std::cout << std::endl;

	// Saving sampled curves

	CurveUtils::writeCurveCsv("res/sampled_curves/linear.csv", linearCurve);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier.csv", bezierCurve);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite.csv", hermiteCurve);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom.csv", catmullRomCurve);

	CurveUtils::writeCurveCsv("res/sampled_curves/linear_bspline.csv", linearBSplineCurve);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_bspline.csv", bezierBSplineCurve);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_bspline.csv", hermiteBSplineCurve);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_bspline.csv", catmullRomBSplineCurve);

	std::cout << "Press enter to exit..." << std::endl;
	std::cin.get();

	return 0;
}