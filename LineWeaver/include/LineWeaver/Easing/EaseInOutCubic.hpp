#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutCubic : public CloneableEasing<EaseInOutCubic>
	{
	public:
		float operator()(float t) const override;
	};
}