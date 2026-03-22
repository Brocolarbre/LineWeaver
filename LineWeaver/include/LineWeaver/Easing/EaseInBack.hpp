#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInBack : public Easing
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}