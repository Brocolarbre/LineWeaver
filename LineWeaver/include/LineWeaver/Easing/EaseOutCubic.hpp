#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutCubic : public CloneableEasing<EaseOutCubic>
	{
	public:
		float operator()(float t) const override;
	};
}