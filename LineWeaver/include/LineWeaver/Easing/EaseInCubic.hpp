#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInCubic : public CloneableEasing<EaseInCubic>
	{
	public:
		float operator()(float t) const override;
	};
}