#include "LineWeaver/Easing/EaseInBack.hpp"

namespace lw
{
	float EaseInBack::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		float c1 = 1.70158f;
		float c3 = c1 + 1.0f;

		return c3 * t * t * t - c1 * t * t;
	}
}
