#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInExponential : public CloneableEasing<EaseInExponential>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}