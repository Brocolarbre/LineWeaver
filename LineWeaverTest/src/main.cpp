#include "CurveUtils.hpp"

#include <LineWeaver/Easing/EaseLinear.hpp>
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
	lw::Curve curve5 = CurveUtils::readCurveCsv("res/curves/curve_5.csv");

	// Easing

	lw::EaseLinear easing;

	// Sampling

	std::vector<float> curve1Samples = lw::CurveSampler::generateSampleValues(100, 0.0f, 1.0f, easing);
	std::vector<float> curve2Samples = lw::CurveSampler::generateSampleValues(100, 0.0f, 4.0f, easing);
	std::vector<float> curve3Samples = lw::CurveSampler::generateSampleValues(100, 0.0f, 7.0f, easing);
	std::vector<float> curve4Samples = lw::CurveSampler::generateSampleValues(100, 0.0f, 8.0f, easing);
	std::vector<float> curve5Samples = lw::CurveSampler::generateSampleValues(100, 0.0f, 11.0f, easing);

	// Interpolators

	lw::LinearInterpolator linearInterpolator;
	lw::BezierInterpolator bezierInterpolator(4);
	lw::HermiteInterpolator hermiteInterpolator;
	lw::CatmullRomInterpolator catmullRomInterpolator;
	lw::BSplineInterpolator linearBSplineInterpolator(&linearInterpolator);
	lw::BSplineInterpolator bezierBSplineInterpolator(&bezierInterpolator);
	lw::BSplineInterpolator hermiteBSplineInterpolator(&hermiteInterpolator);
	lw::BSplineInterpolator catmullRomBSplineInterpolator(&catmullRomInterpolator);

	// Curves

	lw::Curve linearCurve1 = lw::CurveSampler::sampleCurve(curve1, linearInterpolator, curve1Samples);
	lw::Curve linearCurve2 = lw::CurveSampler::sampleCurve(curve2, linearInterpolator, curve2Samples);
	lw::Curve linearCurve3 = lw::CurveSampler::sampleCurve(curve3, linearInterpolator, curve3Samples);
	lw::Curve linearCurve4 = lw::CurveSampler::sampleCurve(curve4, linearInterpolator, curve4Samples);
	lw::Curve linearCurve5 = lw::CurveSampler::sampleCurve(curve5, linearInterpolator, curve5Samples);
	lw::Curve bezierCurve1 = lw::CurveSampler::sampleCurve(curve1, bezierInterpolator, curve1Samples);
	lw::Curve bezierCurve2 = lw::CurveSampler::sampleCurve(curve2, bezierInterpolator, curve2Samples);
	lw::Curve bezierCurve3 = lw::CurveSampler::sampleCurve(curve3, bezierInterpolator, curve3Samples);
	lw::Curve bezierCurve4 = lw::CurveSampler::sampleCurve(curve4, bezierInterpolator, curve4Samples);
	lw::Curve bezierCurve5 = lw::CurveSampler::sampleCurve(curve5, bezierInterpolator, curve5Samples);
	lw::Curve hermiteCurve1 = lw::CurveSampler::sampleCurve(curve1, hermiteInterpolator, curve1Samples);
	lw::Curve hermiteCurve2 = lw::CurveSampler::sampleCurve(curve2, hermiteInterpolator, curve2Samples);
	lw::Curve hermiteCurve3 = lw::CurveSampler::sampleCurve(curve3, hermiteInterpolator, curve3Samples);
	lw::Curve hermiteCurve4 = lw::CurveSampler::sampleCurve(curve4, hermiteInterpolator, curve4Samples);
	lw::Curve hermiteCurve5 = lw::CurveSampler::sampleCurve(curve5, hermiteInterpolator, curve5Samples);
	lw::Curve catmullRomCurve1 = lw::CurveSampler::sampleCurve(curve1, catmullRomInterpolator, curve1Samples);
	lw::Curve catmullRomCurve2 = lw::CurveSampler::sampleCurve(curve2, catmullRomInterpolator, curve2Samples);
	lw::Curve catmullRomCurve3 = lw::CurveSampler::sampleCurve(curve3, catmullRomInterpolator, curve3Samples);
	lw::Curve catmullRomCurve4 = lw::CurveSampler::sampleCurve(curve4, catmullRomInterpolator, curve4Samples);
	lw::Curve catmullRomCurve5 = lw::CurveSampler::sampleCurve(curve5, catmullRomInterpolator, curve5Samples);
	lw::Curve linearBSplineCurve1 = lw::CurveSampler::sampleCurve(curve1, linearBSplineInterpolator, curve1Samples);
	lw::Curve linearBSplineCurve2 = lw::CurveSampler::sampleCurve(curve2, linearBSplineInterpolator, curve2Samples);
	lw::Curve linearBSplineCurve3 = lw::CurveSampler::sampleCurve(curve3, linearBSplineInterpolator, curve3Samples);
	lw::Curve linearBSplineCurve4 = lw::CurveSampler::sampleCurve(curve4, linearBSplineInterpolator, curve4Samples);
	lw::Curve linearBSplineCurve5 = lw::CurveSampler::sampleCurve(curve5, linearBSplineInterpolator, curve5Samples);
	lw::Curve bezierBSplineCurve1 = lw::CurveSampler::sampleCurve(curve1, bezierBSplineInterpolator, curve1Samples);
	lw::Curve bezierBSplineCurve2 = lw::CurveSampler::sampleCurve(curve2, bezierBSplineInterpolator, curve2Samples);
	lw::Curve bezierBSplineCurve3 = lw::CurveSampler::sampleCurve(curve3, bezierBSplineInterpolator, curve3Samples);
	lw::Curve bezierBSplineCurve4 = lw::CurveSampler::sampleCurve(curve4, bezierBSplineInterpolator, curve4Samples);
	lw::Curve bezierBSplineCurve5 = lw::CurveSampler::sampleCurve(curve5, bezierBSplineInterpolator, curve5Samples);
	lw::Curve hermiteBSplineCurve1 = lw::CurveSampler::sampleCurve(curve1, hermiteBSplineInterpolator, curve1Samples);
	lw::Curve hermiteBSplineCurve2 = lw::CurveSampler::sampleCurve(curve2, hermiteBSplineInterpolator, curve2Samples);
	lw::Curve hermiteBSplineCurve3 = lw::CurveSampler::sampleCurve(curve3, hermiteBSplineInterpolator, curve3Samples);
	lw::Curve hermiteBSplineCurve4 = lw::CurveSampler::sampleCurve(curve4, hermiteBSplineInterpolator, curve4Samples);
	lw::Curve hermiteBSplineCurve5 = lw::CurveSampler::sampleCurve(curve5, hermiteBSplineInterpolator, curve5Samples);
	lw::Curve catmullRomBSplineCurve1 = lw::CurveSampler::sampleCurve(curve1, catmullRomBSplineInterpolator, curve1Samples);
	lw::Curve catmullRomBSplineCurve2 = lw::CurveSampler::sampleCurve(curve2, catmullRomBSplineInterpolator, curve2Samples);
	lw::Curve catmullRomBSplineCurve3 = lw::CurveSampler::sampleCurve(curve3, catmullRomBSplineInterpolator, curve3Samples);
	lw::Curve catmullRomBSplineCurve4 = lw::CurveSampler::sampleCurve(curve4, catmullRomBSplineInterpolator, curve4Samples);
	lw::Curve catmullRomBSplineCurve5 = lw::CurveSampler::sampleCurve(curve5, catmullRomBSplineInterpolator, curve5Samples);

	std::cout << "Curve 1" << std::endl; CurveUtils::printCurve(curve1); std::cout << std::endl;
	std::cout << "Curve 2" << std::endl; CurveUtils::printCurve(curve2); std::cout << std::endl;
	std::cout << "Curve 3" << std::endl; CurveUtils::printCurve(curve3); std::cout << std::endl;
	std::cout << "Curve 4" << std::endl; CurveUtils::printCurve(curve4); std::cout << std::endl;
	std::cout << "Curve 5" << std::endl; CurveUtils::printCurve(curve5); std::cout << std::endl;
	std::cout << "Linear curve 1" << std::endl; CurveUtils::printCurve(linearCurve1); std::cout << std::endl;
	std::cout << "Linear curve 2" << std::endl; CurveUtils::printCurve(linearCurve2); std::cout << std::endl;
	std::cout << "Linear curve 3" << std::endl; CurveUtils::printCurve(linearCurve3); std::cout << std::endl;
	std::cout << "Linear curve 4" << std::endl; CurveUtils::printCurve(linearCurve4); std::cout << std::endl;
	std::cout << "Linear curve 5" << std::endl; CurveUtils::printCurve(linearCurve5); std::cout << std::endl;
	std::cout << "Bezier curve 1" << std::endl; CurveUtils::printCurve(bezierCurve1); std::cout << std::endl;
	std::cout << "Bezier curve 2" << std::endl; CurveUtils::printCurve(bezierCurve2); std::cout << std::endl;
	std::cout << "Bezier curve 3" << std::endl; CurveUtils::printCurve(bezierCurve3); std::cout << std::endl;
	std::cout << "Bezier curve 4" << std::endl; CurveUtils::printCurve(bezierCurve4); std::cout << std::endl;
	std::cout << "Bezier curve 5" << std::endl; CurveUtils::printCurve(bezierCurve5); std::cout << std::endl;
	std::cout << "Hermite curve 1" << std::endl; CurveUtils::printCurve(hermiteCurve1); std::cout << std::endl;
	std::cout << "Hermite curve 2" << std::endl; CurveUtils::printCurve(hermiteCurve2); std::cout << std::endl;
	std::cout << "Hermite curve 3" << std::endl; CurveUtils::printCurve(hermiteCurve3); std::cout << std::endl;
	std::cout << "Hermite curve 4" << std::endl; CurveUtils::printCurve(hermiteCurve4); std::cout << std::endl;
	std::cout << "Hermite curve 5" << std::endl; CurveUtils::printCurve(hermiteCurve5); std::cout << std::endl;
	std::cout << "CatmullRom curve 1" << std::endl; CurveUtils::printCurve(catmullRomCurve1); std::cout << std::endl;
	std::cout << "CatmullRom curve 2" << std::endl; CurveUtils::printCurve(catmullRomCurve2); std::cout << std::endl;
	std::cout << "CatmullRom curve 3" << std::endl; CurveUtils::printCurve(catmullRomCurve3); std::cout << std::endl;
	std::cout << "CatmullRom curve 4" << std::endl; CurveUtils::printCurve(catmullRomCurve4); std::cout << std::endl;
	std::cout << "CatmullRom curve 5" << std::endl; CurveUtils::printCurve(catmullRomCurve5); std::cout << std::endl;
	std::cout << "Linear B-Spline curve 1" << std::endl; CurveUtils::printCurve(linearBSplineCurve1); std::cout << std::endl;
	std::cout << "Linear B-Spline curve 2" << std::endl; CurveUtils::printCurve(linearBSplineCurve2); std::cout << std::endl;
	std::cout << "Linear B-Spline curve 3" << std::endl; CurveUtils::printCurve(linearBSplineCurve3); std::cout << std::endl;
	std::cout << "Linear B-Spline curve 4" << std::endl; CurveUtils::printCurve(linearBSplineCurve4); std::cout << std::endl;
	std::cout << "Linear B-Spline curve 5" << std::endl; CurveUtils::printCurve(linearBSplineCurve5); std::cout << std::endl;
	std::cout << "Bezier B-Spline curve 1" << std::endl; CurveUtils::printCurve(bezierBSplineCurve1); std::cout << std::endl;
	std::cout << "Bezier B-Spline curve 2" << std::endl; CurveUtils::printCurve(bezierBSplineCurve2); std::cout << std::endl;
	std::cout << "Bezier B-Spline curve 3" << std::endl; CurveUtils::printCurve(bezierBSplineCurve3); std::cout << std::endl;
	std::cout << "Bezier B-Spline curve 4" << std::endl; CurveUtils::printCurve(bezierBSplineCurve4); std::cout << std::endl;
	std::cout << "Bezier B-Spline curve 5" << std::endl; CurveUtils::printCurve(bezierBSplineCurve5); std::cout << std::endl;
	std::cout << "Hermite B-Spline curve 1" << std::endl; CurveUtils::printCurve(hermiteBSplineCurve1); std::cout << std::endl;
	std::cout << "Hermite B-Spline curve 2" << std::endl; CurveUtils::printCurve(hermiteBSplineCurve2); std::cout << std::endl;
	std::cout << "Hermite B-Spline curve 3" << std::endl; CurveUtils::printCurve(hermiteBSplineCurve3); std::cout << std::endl;
	std::cout << "Hermite B-Spline curve 4" << std::endl; CurveUtils::printCurve(hermiteBSplineCurve4); std::cout << std::endl;
	std::cout << "Hermite B-Spline curve 5" << std::endl; CurveUtils::printCurve(hermiteBSplineCurve5); std::cout << std::endl;
	std::cout << "CatmullRom B-Spline curve 1" << std::endl; CurveUtils::printCurve(catmullRomBSplineCurve1); std::cout << std::endl;
	std::cout << "CatmullRom B-Spline curve 2" << std::endl; CurveUtils::printCurve(catmullRomBSplineCurve2); std::cout << std::endl;
	std::cout << "CatmullRom B-Spline curve 3" << std::endl; CurveUtils::printCurve(catmullRomBSplineCurve3); std::cout << std::endl;
	std::cout << "CatmullRom B-Spline curve 4" << std::endl; CurveUtils::printCurve(catmullRomBSplineCurve4); std::cout << std::endl;
	std::cout << "CatmullRom B-Spline curve 5" << std::endl; CurveUtils::printCurve(catmullRomBSplineCurve5); std::cout << std::endl;

	// Saving sampled curves

	CurveUtils::writeCurveCsv("res/sampled_curves/linear_1.csv", linearCurve1);
	CurveUtils::writeCurveCsv("res/sampled_curves/linear_2.csv", linearCurve2);
	CurveUtils::writeCurveCsv("res/sampled_curves/linear_3.csv", linearCurve3);
	CurveUtils::writeCurveCsv("res/sampled_curves/linear_4.csv", linearCurve4);
	CurveUtils::writeCurveCsv("res/sampled_curves/linear_5.csv", linearCurve5);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_1.csv", bezierCurve1);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_2.csv", bezierCurve2);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_3.csv", bezierCurve3);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_4.csv", bezierCurve4);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_5.csv", bezierCurve5);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_1.csv", hermiteCurve1);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_2.csv", hermiteCurve2);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_3.csv", hermiteCurve3);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_4.csv", hermiteCurve4);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_5.csv", hermiteCurve5);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_1.csv", catmullRomCurve1);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_2.csv", catmullRomCurve2);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_3.csv", catmullRomCurve3);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_4.csv", catmullRomCurve4);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_5.csv", catmullRomCurve5);
	CurveUtils::writeCurveCsv("res/sampled_curves/linear_bspline_1.csv", linearBSplineCurve1);
	CurveUtils::writeCurveCsv("res/sampled_curves/linear_bspline_2.csv", linearBSplineCurve2);
	CurveUtils::writeCurveCsv("res/sampled_curves/linear_bspline_3.csv", linearBSplineCurve3);
	CurveUtils::writeCurveCsv("res/sampled_curves/linear_bspline_4.csv", linearBSplineCurve4);
	CurveUtils::writeCurveCsv("res/sampled_curves/linear_bspline_5.csv", linearBSplineCurve5);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_bspline_1.csv", bezierBSplineCurve1);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_bspline_2.csv", bezierBSplineCurve2);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_bspline_3.csv", bezierBSplineCurve3);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_bspline_4.csv", bezierBSplineCurve4);
	CurveUtils::writeCurveCsv("res/sampled_curves/bezier_bspline_5.csv", bezierBSplineCurve5);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_bspline_1.csv", hermiteBSplineCurve1);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_bspline_2.csv", hermiteBSplineCurve2);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_bspline_3.csv", hermiteBSplineCurve3);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_bspline_4.csv", hermiteBSplineCurve4);
	CurveUtils::writeCurveCsv("res/sampled_curves/hermite_bspline_5.csv", hermiteBSplineCurve5);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_bspline_1.csv", catmullRomBSplineCurve1);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_bspline_2.csv", catmullRomBSplineCurve2);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_bspline_3.csv", catmullRomBSplineCurve3);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_bspline_4.csv", catmullRomBSplineCurve4);
	CurveUtils::writeCurveCsv("res/sampled_curves/catmull_rom_bspline_5.csv", catmullRomBSplineCurve5);

	std::cout << "Press enter to exit..." << std::endl;
	std::cin.get();

	return 0;
}