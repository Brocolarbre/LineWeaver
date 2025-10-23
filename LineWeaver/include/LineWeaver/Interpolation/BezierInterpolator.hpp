#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API BezierInterpolator: public Interpolator
	{
	public:
		BezierInterpolator(unsigned int degree = 3);

		Point operator()(const Curve& points, float t) const override;
	};
}