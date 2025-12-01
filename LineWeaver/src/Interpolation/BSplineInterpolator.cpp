#include "LineWeaver/Interpolation/BSplineInterpolator.hpp"

#include <iostream>

namespace lw
{
	BSplineInterpolator::BSplineInterpolator(Interpolator* interpolator) :
		Interpolator(0, 0, false),
		m_interpolator(interpolator),
		m_pointsPerSegment(m_interpolator != nullptr ? m_interpolator->getPointsPerSegment() : 0),
		m_segmentStep(m_interpolator != nullptr ? m_interpolator->getSegmentStep() : 0)
	{

	}

	Point BSplineInterpolator::operator()(const Curve& points, float u) const
	{
		if (m_interpolator == nullptr || points.size() < m_pointsPerSegment)
			return Point(0.0f);

		bool useBoundaryPoints = m_interpolator->useBoundaryPoints();
		unsigned int curveSize = points.size();

		if (useBoundaryPoints)
			curveSize += 2;

		Curve curvePoints;
		curvePoints.reserve(curveSize);

		if (useBoundaryPoints)
			curvePoints.push_back(points.front());
		curvePoints.insert(curvePoints.end(), points.begin(), points.end());
		if (useBoundaryPoints)
			curvePoints.push_back(points.back());

		unsigned int maxBaseIndex = static_cast<unsigned int>(curvePoints.size() - m_pointsPerSegment);
		unsigned int curveCount = m_segmentStep == 0 ? 0 : maxBaseIndex / m_segmentStep + 1;

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

		std::vector<Point> interpolatorPoints(m_pointsPerSegment);
		for (unsigned int i = 0; i < m_pointsPerSegment; ++i)
			interpolatorPoints[i] = curvePoints[static_cast<std::size_t>(baseIndex + i)];

		return (*m_interpolator)(interpolatorPoints, t);
	}
}