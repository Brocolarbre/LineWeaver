#include "LineWeaver/Interpolation/HermiteInterpolator.hpp"

namespace lw
{
    HermiteInterpolator::HermiteInterpolator() :
        Interpolator(4, 0, false)
    {

    }

    Point HermiteInterpolator::operator()(const Curve& points, float t) const
	{
        if (points.size() < m_pointsPerSegment)
            return Point(0.0f);

        t = glm::clamp(t, 0.0f, 1.0f);

        Point t0 = points[1] - points[0];
        Point t1 = points[3] - points[2];

        float t2 = t * t;
        float t3 = t2 * t;

        float f1 = 2.0f * t3 - 3.0f * t2 + 1.0f;
        float f2 = t3 - 2.0f * t2 + t;
        float f3 = -2.0f * t3 + 3.0f * t2;
        float f4 = t3 - t2;

        return f1 * points[0] + f2 * t0 + f3 * points[3] + f4 * t1;
	}
}