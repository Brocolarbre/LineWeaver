#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutBounce : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}