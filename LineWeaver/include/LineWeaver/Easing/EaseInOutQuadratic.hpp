#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutQuadratic : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}