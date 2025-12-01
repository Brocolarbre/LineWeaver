#include "LineWeaver/Interpolation/CatmullRomInterpolator.hpp"

namespace lw
{
    CatmullRomInterpolator::CatmullRomInterpolator() :
        Interpolator(4, 1, true)
    {

    }

    Point CatmullRomInterpolator::operator()(const Curve& points, float t) const
    {
        if (points.size() < m_pointsPerSegment)
            return Point(0.0f);

        t = glm::clamp(t, 0.0f, 1.0f);

        float t2 = t * t;
        float t3 = t2 * t;

        float f1 = -t3 + 2.0f * t2 - t;
        float f2 = 3.0f * t3 - 5.0f * t2 + 2.0f;
        float f3 = -3.0f * t3 + 4.0f * t2 + t;
        float f4 = t3 - t2;

        return (f1 * points[0] + f2 * points[1] + f3 * points[2] + f4 * points[3]) * 0.5f;
    }
}