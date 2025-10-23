#include "LineWeaver/Easing/EaseInQuartic.hpp"

namespace lw
{
	float EaseInQuartic::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t * t * t * t;
	}
}
