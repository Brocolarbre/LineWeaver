#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutSine : public CloneableEasing<EaseOutSine>
	{
	public:
		float operator()(float t) const override;
	};
}