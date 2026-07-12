#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutBounce : public CloneableEasing<EaseOutBounce>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}