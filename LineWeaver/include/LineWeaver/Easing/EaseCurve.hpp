#pragma once

#include "Easing.hpp"
#include "LineWeaver/Interpolation/Interpolator.hpp"

namespace lw
{
	class EaseCurve : public Easing
	{
	private:
		const Interpolator& m_interpolator;
		Curve m_points;

	public:
		LINEWEAVER_EXPORT EaseCurve(const Interpolator& interpolator, const Curve& points);

		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}