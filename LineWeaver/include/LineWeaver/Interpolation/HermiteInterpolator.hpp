#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class HermiteInterpolator : public CloneableInterpolator<HermiteInterpolator>
	{
	public:
		LINEWEAVER_EXPORT HermiteInterpolator();

		LINEWEAVER_EXPORT Point operator()(const Curve& points, float t) const override;
	};
}