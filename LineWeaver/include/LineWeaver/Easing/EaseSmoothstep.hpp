#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseSmoothstep : public Easing
	{
	public:
		float operator()(float t) const override;
	};
}