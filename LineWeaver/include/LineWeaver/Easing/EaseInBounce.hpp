#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInBounce : public CloneableEasing<EaseInBounce>
	{
	public:
		float operator()(float t) const override;
	};
}