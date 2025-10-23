#include "LineWeaver/Easing/EaseInQuintic.hpp"

namespace lw
{
	float EaseInQuintic::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t * t * t * t * t;
	}
}
