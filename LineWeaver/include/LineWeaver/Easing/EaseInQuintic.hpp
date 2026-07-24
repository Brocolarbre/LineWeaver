#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInQuintic : public CloneableEasing<EaseInQuintic>
	{
	public:
		float operator()(float t) const override;
	};
}