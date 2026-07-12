#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutCubic : public CloneableEasing<EaseOutCubic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}