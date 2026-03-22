#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class BezierInterpolator: public Interpolator
	{
	public:
		LINEWEAVER_EXPORT BezierInterpolator(unsigned int pointsPerSegment = 3);

		LINEWEAVER_EXPORT Point operator()(const Curve& points, float t) const override;
	};
}