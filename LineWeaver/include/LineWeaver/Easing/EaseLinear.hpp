#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseLinear : public CloneableEasing<EaseLinear>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}