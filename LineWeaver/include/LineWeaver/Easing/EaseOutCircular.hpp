#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutCircular : public CloneableEasing<EaseOutCircular>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}