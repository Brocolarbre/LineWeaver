#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutQuintic : public CloneableEasing<EaseInOutQuintic>
	{
	public:
		float operator()(float t) const override;
	};
}