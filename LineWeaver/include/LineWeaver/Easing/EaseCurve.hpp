#pragma once

#include "Easing.hpp"
#include "LineWeaver/Interpolation/Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API EaseCurve : public Easing
	{
	private:
		const Interpolator& m_interpolator;
		Curve m_points;

	public:
		EaseCurve(const Interpolator& interpolator, const Curve& points);

		float operator()(float t) const override;
	};
}