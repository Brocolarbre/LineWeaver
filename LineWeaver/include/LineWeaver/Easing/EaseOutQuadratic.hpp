#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseOutQuadratic : public CloneableEasing<EaseOutQuadratic>
	{
	public:
		float operator()(float t) const override;
	};
}