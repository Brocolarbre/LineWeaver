#pragma once

#include "Easing.hpp"
#include "LineWeaver/Interpolation/Interpolator.hpp"

namespace lw
{
	class EaseCurve : public CloneableEasing<EaseCurve>
	{
	private:
		std::unique_ptr<Interpolator> m_interpolator;
		Curve m_points;

	public:
		LINEWEAVER_EXPORT EaseCurve(std::unique_ptr<Interpolator> interpolator, const Curve& points);
		LINEWEAVER_EXPORT EaseCurve(const EaseCurve& easeCurve);

		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}