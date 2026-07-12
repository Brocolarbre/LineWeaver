#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutElastic : public CloneableEasing<EaseInOutElastic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}