#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutSine : public CloneableEasing<EaseInOutSine>
	{
	public:
		float operator()(float t) const override;
	};
}