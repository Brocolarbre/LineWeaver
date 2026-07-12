#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInCubic : public CloneableEasing<EaseInCubic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}