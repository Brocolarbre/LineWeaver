#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutBounce : public Easing
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}