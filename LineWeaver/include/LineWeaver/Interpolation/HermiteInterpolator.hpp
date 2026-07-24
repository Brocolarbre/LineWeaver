#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API HermiteInterpolator : public CloneableInterpolator<HermiteInterpolator>
	{
	public:
		HermiteInterpolator();

		Point operator()(const Curve& points, float t) const override;
	};
}