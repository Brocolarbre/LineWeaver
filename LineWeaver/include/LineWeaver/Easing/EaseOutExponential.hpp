#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutExponential : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}