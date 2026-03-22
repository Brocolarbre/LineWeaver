#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInBounce : public Easing
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}