#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class CatmullRomInterpolator : public Interpolator
	{
	public:
		LINEWEAVER_EXPORT CatmullRomInterpolator();

		LINEWEAVER_EXPORT Point operator()(const Curve& points, float t) const override;
	};
}