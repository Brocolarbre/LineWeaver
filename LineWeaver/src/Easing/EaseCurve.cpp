#include "LineWeaver/Easing/EaseCurve.hpp"

namespace lw
{
	EaseCurve::EaseCurve(std::unique_ptr<Interpolator> interpolator, const Curve& points) :
		m_interpolator(std::move(interpolator)),
		m_points(points)
	{

	}

	EaseCurve::EaseCurve(const EaseCurve& easeCurve) :
		m_interpolator(easeCurve.m_interpolator->clone()),
		m_points(easeCurve.m_points)
	{

	}

	float EaseCurve::operator()(float t) const
	{
		return (*m_interpolator)(m_points, t).y;
	}
}
