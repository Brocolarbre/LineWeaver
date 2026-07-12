#include "LineWeaver/Interpolation/LinearInterpolator.hpp"

#include <algorithm>

namespace lw
{
	LinearInterpolator::LinearInterpolator() :
		CloneableInterpolator(2, 1, false)
	{

	}

	Point LinearInterpolator::operator()(const Curve& points, float t) const
	{
		if (points.size() < m_pointsPerSegment)
			return Point(0.0f);

		t = std::clamp(t, 0.0f, 1.0f);

		return points[0] + (points[1] - points[0]) * t;
	}
}