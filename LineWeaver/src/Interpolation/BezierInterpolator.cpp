#include "LineWeaver/Interpolation/BezierInterpolator.hpp"

namespace lw
{
	BezierInterpolator::BezierInterpolator(unsigned int degree) :
		Interpolator(degree, degree > 0 ? degree - 1 : 0)
	{

	}

	Point BezierInterpolator::operator()(const Curve& points, float t) const
	{
		if (points.size() < m_degree)
			return Point(0.0f);

		std::vector<Point> currentPoints = points;

		while (currentPoints.size() != 1)
		{
			std::vector<Point> nextPoints;

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