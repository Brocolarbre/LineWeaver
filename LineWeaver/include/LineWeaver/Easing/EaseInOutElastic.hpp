#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutElastic : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}