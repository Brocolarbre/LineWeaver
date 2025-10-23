#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseLinear : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}