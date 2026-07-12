#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseOutQuadratic : public CloneableEasing<EaseOutQuadratic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}