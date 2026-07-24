#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutElastic : public CloneableEasing<EaseOutElastic>
	{
	public:
		float operator()(float t) const override;
	};
}