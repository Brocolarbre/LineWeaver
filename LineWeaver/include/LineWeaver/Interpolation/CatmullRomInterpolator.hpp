#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API CatmullRomInterpolator : public CloneableInterpolator<CatmullRomInterpolator>
	{
	public:
		CatmullRomInterpolator();

		Point operator()(const Curve& points, float t) const override;
	};
}