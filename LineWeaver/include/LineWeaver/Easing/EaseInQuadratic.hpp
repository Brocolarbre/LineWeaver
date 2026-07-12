#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInQuadratic : public CloneableEasing<EaseInQuadratic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}