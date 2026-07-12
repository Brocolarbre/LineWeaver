#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutExponential : public CloneableEasing<EaseOutExponential>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}