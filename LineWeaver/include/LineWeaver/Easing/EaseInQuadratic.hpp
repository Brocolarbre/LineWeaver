#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInQuadratic : public CloneableEasing<EaseInQuadratic>
	{
	public:
		float operator()(float t) const override;
	};
}