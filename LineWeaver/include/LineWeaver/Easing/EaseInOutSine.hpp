#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutSine : public CloneableEasing<EaseInOutSine>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}