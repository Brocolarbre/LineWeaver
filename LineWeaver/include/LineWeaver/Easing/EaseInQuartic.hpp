#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInQuartic : public CloneableEasing<EaseInQuartic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}