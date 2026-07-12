#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutQuadratic : public CloneableEasing<EaseInOutQuadratic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}