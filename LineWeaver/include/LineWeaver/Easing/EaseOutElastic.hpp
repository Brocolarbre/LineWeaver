#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutElastic : public CloneableEasing<EaseOutElastic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}