#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutBounce : public CloneableEasing<EaseOutBounce>
	{
	public:
		float operator()(float t) const override;
	};
}