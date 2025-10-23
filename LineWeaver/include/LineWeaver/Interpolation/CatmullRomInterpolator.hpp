#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API CatmullRomInterpolator : public Interpolator
	{
	public:
		CatmullRomInterpolator();

		Point operator()(const Curve& points, float t) const override;
	};
}