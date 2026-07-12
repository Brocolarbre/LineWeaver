#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutCircular : public CloneableEasing<EaseInOutCircular>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}