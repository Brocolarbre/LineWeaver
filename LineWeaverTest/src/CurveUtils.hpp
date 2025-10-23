#pragma once

#include <LineWeaver/Interpolation/Interpolator.hpp>
#include <string>

class CurveUtils
{
public:
	static void printPoint(const lw::Point& point);
	static void printCurve(const lw::Curve& curve);

	static lw::Curve readCurveCsv(const std::string& path);
	static void writeCurveCsv(const std::string& path, const lw::Curve& curve);
};