#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutBack : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}