#include "LineWeaver/Interpolation/Point.hpp"

namespace lw
{
	Point::Point() :
		x(0.0f),
		y(0.0f),
		z(0.0f)
	{

	}

	Point::Point(float value) :
		x(value),
		y(value),
		z(value)
	{

	}

	Point::Point(float x, float y, float z) :
		x(x),
		y(y),
		z(z)
	{

	}

	float& Point::operator[](size_t index)
	{
		switch (index)
		{
		case 0: return x;
		case 1: return y;
		default: return z;
		}
	}

	Point Point::operator+(const Point& point)
	{
		return Point(x + point.x, y + point.y, z + point.z);
	}

	 Point Point::operator-(const Point& point)
	 {
	 	 return Point(x - point.x, y - point.y, z - point.z);
	 }

	 Point Point::operator*(float value)
	 {
		 return Point(x * value, y * value, z * value);
	 }

	Point operator+(float value, const Point& point)
	{
		return Point(value + point.x, value + point.y, value + point.z);
	}

	Point operator*(float value, const Point& point)
	{
		return Point(value * point.x, value * point.y, value * point.z);
	}

	Point operator-(const Point& a, const Point& b)
	{
		return Point(a.x - b.x, a.y - b.y, a.z - b.z);
	}
}