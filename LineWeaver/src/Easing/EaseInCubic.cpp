#include "LineWeaver/Easing/EaseInCubic.hpp"

namespace lw
{
	float EaseInCubic::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t * t * t;
	}
}
