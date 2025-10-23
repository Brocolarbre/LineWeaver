#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutCubic : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}