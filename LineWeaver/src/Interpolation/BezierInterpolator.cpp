#include "LineWeaver/Interpolation/BezierInterpolator.hpp"

namespace lw
{
	BezierInterpolator::BezierInterpolator(unsigned int pointsPerSegment) :
		Interpolator(pointsPerSegment, pointsPerSegment > 0 ? pointsPerSegment - 1 : 0, false)
	{

	}

	Point BezierInterpolator::operator()(const Curve& points, float t) const
	{
		if (points.size() < m_pointsPerSegment)
			return Point(0.0f);

		t = glm::clamp(t, 0.0f, 1.0f);

		std::vector<Point> currentPoints(points.begin(), points.begin() + m_pointsPerSegment);

		while (currentPoints.size() != 1)
		{
			std::vector<Point> nextPoints;
			nextPoints.reserve(currentPoints.size());

			for (size_t i = 0; i < currentPoints.size() - 1; ++i)
			{
				Point a = currentPoints[i];
				Point b = currentPoints[i + 1];

				nextPoints.push_back((1.0f - t) * a + t * b);
			}

			currentPoints = nextPoints;
		}

		return currentPoints.front();
	}
}