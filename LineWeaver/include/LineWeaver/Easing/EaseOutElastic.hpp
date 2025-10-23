#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutElastic : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}