#include "LineWeaver/Easing/EaseCurve.hpp"

namespace lw
{
	EaseCurve::EaseCurve(const Interpolator& interpolator, const Curve& points) :
		m_interpolator(interpolator),
		m_points(points)
	{

	}

	float EaseCurve::operator()(float t) const
	{
		return m_interpolator(m_points, t).y;
	}
}
