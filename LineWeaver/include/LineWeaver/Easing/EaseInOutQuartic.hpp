#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutQuartic : public CloneableEasing<EaseInOutQuartic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}