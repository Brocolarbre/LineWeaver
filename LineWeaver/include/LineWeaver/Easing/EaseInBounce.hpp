#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInBounce : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}