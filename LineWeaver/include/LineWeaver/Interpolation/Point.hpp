#pragma once

#include "LineWeaver/Export.hpp"

namespace lw
{
	struct LINEWEAVER_API Point
	{
		float x;
		float y;
		float z;

		Point();
		Point(float value);
		Point(float x, float y, float z);

		Point& operator=(const Point& point) = default;

		const float& operator[](size_t index) const;
		float& operator[](size_t index);

		Point operator+(const Point& point) const;
		Point operator-(const Point& point) const;
		Point operator*(float value) const;
	};

	LINEWEAVER_API Point operator*(float value, const Point& point);
}