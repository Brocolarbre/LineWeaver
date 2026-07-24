#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutQuartic : public CloneableEasing<EaseInOutQuartic>
	{
	public:
		float operator()(float t) const override;
	};
}