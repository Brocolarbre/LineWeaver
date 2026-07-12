#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutQuintic : public CloneableEasing<EaseOutQuintic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}