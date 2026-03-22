#pragma once

#include "LineWeaver/Export.hpp"

#include <algorithm>
#include <cmath>
#include <numbers>

namespace lw
{
	class Easing
	{
	public:
		LINEWEAVER_EXPORT virtual ~Easing() = default;

		virtual float operator()(float t) const = 0;
	};
}