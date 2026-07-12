#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutExponential : public CloneableEasing<EaseInOutExponential>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}