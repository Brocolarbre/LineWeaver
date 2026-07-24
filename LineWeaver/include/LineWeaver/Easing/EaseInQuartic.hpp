#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInQuartic : public CloneableEasing<EaseInQuartic>
	{
	public:
		float operator()(float t) const override;
	};
}