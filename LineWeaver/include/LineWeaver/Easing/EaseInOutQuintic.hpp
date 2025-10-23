#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutQuintic : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}