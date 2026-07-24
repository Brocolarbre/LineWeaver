#pragma once

#include "Easing.hpp"
#include "LineWeaver/Interpolation/Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API EaseCurve : public CloneableEasing<EaseCurve>
	{
	private:
		std::unique_ptr<Interpolator> m_interpolator;
		Curve m_points;

	public:
		EaseCurve(std::unique_ptr<Interpolator> interpolator, const Curve& points);
		EaseCurve(const EaseCurve& easeCurve);

		float operator()(float t) const override;
	};
}