#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInSine : public CloneableEasing<EaseInSine>
	{
	public:
		float operator()(float t) const override;
	};
}