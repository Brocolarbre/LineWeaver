#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutSine : public CloneableEasing<EaseOutSine>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}