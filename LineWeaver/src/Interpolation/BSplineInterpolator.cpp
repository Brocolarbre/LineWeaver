#include "LineWeaver/Interpolation/BSplineInterpolator.hpp"

namespace lw
{
	BSplineInterpolator::BSplineInterpolator(Interpolator* interpolator) :
		Interpolator(0, 0),
		m_interpolator(interpolator),
		m_degree(m_interpolator != nullptr ? m_interpolator->getDegree() : 0),
		m_segmentStep(m_interpolator != nullptr ? m_interpolator->getSegmentStep() : 0)
	{

	}

	Point BSplineInterpolator::operator()(const Curve& points, float u) const
	{
		if (m_interpolator == nullptr || points.size() < m_degree)
			return Point(0.0f);

		unsigned int maxBaseIndex = static_cast<unsigned int>(points.size() - m_degree);
		unsigned int curveCount = m_segmentStep == 0 ? 0 : maxBaseIndex / m_segmentStep + 1;
		u = glm::clamp(u, 0.0f, static_cast<float>(curveCount));

		if (curveCount == 0)
			return Point(0.0f);

		float k = 0.0f;
		float t = std::modf(u, &k);

		unsigned int curveIndex = static_cast<unsigned int>(k);
		if (curveIndex >= curveCount)
		{
			curveIndex = curveCount - 1;
			t = 1.0f;
		}

		unsigned int baseIndex = curveIndex * m_segmentStep;
		if (baseIndex > maxBaseIndex)
			baseIndex = maxBaseIndex;

		std::vector<Point> interpolatorPoints(m_degree);
		for (unsigned int i = 0; i < m_degree; ++i)
			interpolatorPoints[i] = points[static_cast<std::size_t>(baseIndex + i)];

		return (*m_interpolator)(interpolatorPoints, t);
	}
}