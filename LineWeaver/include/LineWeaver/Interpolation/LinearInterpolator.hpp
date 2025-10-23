#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API LinearInterpolator : public Interpolator
	{
	public:
		LinearInterpolator();

		Point operator()(const Curve& points, float t) const override;
	};
}