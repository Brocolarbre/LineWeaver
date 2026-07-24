#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInCircular : public CloneableEasing<EaseInCircular>
	{
	public:
		float operator()(float t) const override;
	};
}