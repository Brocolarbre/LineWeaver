#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutExponential : public CloneableEasing<EaseInOutExponential>
	{
	public:
		float operator()(float t) const override;
	};
}