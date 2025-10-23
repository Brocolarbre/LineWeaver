#include "LineWeaver/Interpolation/BSplineInterpolator.hpp"

namespace lw
{
	BSplineInterpolator::BSplineInterpolator(Interpolator* interpolator) :
		Interpolator(0),
		m_interpolator(interpolator)
	{

	}

	Point BSplineInterpolator::operator()(const Curve& points, float u) const
	{
		unsigned int degree = m_interpolator->getDegree();

		if (points.size() < degree)
			return Point(0.0f);

		unsigned int nbCurves = static_cast<unsigned int>(std::ceilf((points.size() - degree + 1) / static_cast<float>(degree - 1)));
		u = glm::clamp(u, 0.0f, static_cast<float>(nbCurves));

		float k = 0.0f;
		float t = std::modf(u, &k);

		std::vector<Point> interpolatorPoints(degree);
		for (unsigned int i = 0; i < degree; ++i)
		{
			if (u == nbCurves)
				interpolatorPoints[i] = points[static_cast<size_t>((degree - 1) * (k - 1) + i)];
			else
				interpolatorPoints[i] = points[static_cast<size_t>((degree - 1) * k + i)];
		}

		return (*m_interpolator)(interpolatorPoints, t);
	}
}