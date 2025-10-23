#include "LineWeaver/Easing/EaseInOutBounce.hpp"

namespace lw
{
	float EaseInOutBounce::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		float v = 0.0f;
		float t2 = t < 0.5f ? 1.0f - 2.0f * t : 2.0f * t - 1.0f;

		float n1 = 7.5625f;
		float d1 = 2.75f;

		if (t2 < 1.0f / d1)
			v = n1 * t2 * t2;
		else if (t2 < 2.0f / d1)
			v = n1 * (t2 -= 1.5f / d1) * t2 + 0.75f;
		else if (t2 < 2.5f / d1)
			v = n1 * (t2 -= 2.25f / d1) * t2 + 0.9375f;
		else
			v = n1 * (t2 -= 2.625f / d1) * t2 + 0.984375f;

		return t < 0.5f ? (1.0f - v) * 0.5f : (1.0f + v) * 0.5f;
	}
}
