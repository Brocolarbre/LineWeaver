#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInCircular : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}