#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutQuadratic : public CloneableEasing<EaseInOutQuadratic>
	{
	public:
		float operator()(float t) const override;
	};
}