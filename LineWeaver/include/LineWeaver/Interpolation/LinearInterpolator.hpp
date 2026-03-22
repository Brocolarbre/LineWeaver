#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class LinearInterpolator : public Interpolator
	{
	public:
		LINEWEAVER_EXPORT LinearInterpolator();

		LINEWEAVER_EXPORT Point operator()(const Curve& points, float t) const override;
	};
}