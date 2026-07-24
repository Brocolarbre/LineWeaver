#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutCircular : public CloneableEasing<EaseOutCircular>
	{
	public:
		float operator()(float t) const override;
	};
}