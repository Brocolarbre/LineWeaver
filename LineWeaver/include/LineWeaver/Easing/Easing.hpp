#pragma once

#include "LineWeaver/Export.hpp"

#include <glm/glm.hpp>

namespace lw
{
	class LINEWEAVER_API Easing
	{
	public:
		virtual ~Easing() = default;

		virtual float operator()(float t) const = 0;
	};
}