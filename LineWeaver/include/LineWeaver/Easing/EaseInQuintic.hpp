#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInQuintic : public CloneableEasing<EaseInQuintic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}