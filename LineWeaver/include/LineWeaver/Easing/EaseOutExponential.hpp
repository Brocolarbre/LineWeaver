#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutExponential : public CloneableEasing<EaseOutExponential>
	{
	public:
		float operator()(float t) const override;
	};
}