#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutBounce : public CloneableEasing<EaseInOutBounce>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}