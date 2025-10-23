#include "LineWeaver/Interpolation/LinearInterpolator.hpp"

namespace lw
{
	LinearInterpolator::LinearInterpolator() :
		Interpolator(2)
	{

	}

	Point LinearInterpolator::operator()(const Curve& points, float t) const
	{
		if (points.size() < m_degree)
			return Point(0.0f);

		return (1.0f - t) * points[0] + t * points[1];
	}
}