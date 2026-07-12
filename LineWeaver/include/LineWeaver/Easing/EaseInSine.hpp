#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInSine : public CloneableEasing<EaseInSine>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}