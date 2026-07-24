#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutQuartic : public CloneableEasing<EaseOutQuartic>
	{
	public:
		float operator()(float t) const override;
	};
}