#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInBounce : public CloneableEasing<EaseInBounce>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}