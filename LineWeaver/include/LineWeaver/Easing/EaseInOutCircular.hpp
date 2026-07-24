#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutCircular : public CloneableEasing<EaseInOutCircular>
	{
	public:
		float operator()(float t) const override;
	};
}