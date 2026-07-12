#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutQuartic : public CloneableEasing<EaseOutQuartic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}