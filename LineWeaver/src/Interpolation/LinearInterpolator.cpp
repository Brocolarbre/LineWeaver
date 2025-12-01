#include "LineWeaver/Interpolation/LinearInterpolator.hpp"

namespace lw
{
	LinearInterpolator::LinearInterpolator() :
		Interpolator(2, 1, false)
	{

	}

	Point LinearInterpolator::operator()(const Curve& points, float t) const
	{
		if (points.size() < m_pointsPerSegment)
			return Point(0.0f);

		t = glm::clamp(t, 0.0f, 1.0f);

		return (1.0f - t) * points[0] + t * points[1];
	}
}