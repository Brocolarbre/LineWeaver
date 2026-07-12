#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutQuintic : public CloneableEasing<EaseInOutQuintic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}