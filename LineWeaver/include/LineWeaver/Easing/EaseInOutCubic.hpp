#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutCubic : public CloneableEasing<EaseInOutCubic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}