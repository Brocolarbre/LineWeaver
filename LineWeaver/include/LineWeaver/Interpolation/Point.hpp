#pragma once

#include "LineWeaver/Export.hpp"

namespace lw
{
	struct Point
	{
		float x;
		float y;
		float z;

		LINEWEAVER_EXPORT Point();
		LINEWEAVER_EXPORT Point(float value);
		LINEWEAVER_EXPORT Point(float x, float y, float z);

		LINEWEAVER_EXPORT Point& operator=(const Point& point) = default;

		LINEWEAVER_EXPORT float& operator[](size_t index);

		LINEWEAVER_EXPORT Point operator+(const Point& point);
		LINEWEAVER_EXPORT Point operator-(const Point& point);
		LINEWEAVER_EXPORT Point operator*(float value);
	};

	Point operator*(float value, const Point& point);
	Point operator-(const Point& a, const Point& b);
}