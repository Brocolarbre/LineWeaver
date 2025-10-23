#include "LineWeaver/Easing/EaseInOutBack.hpp"

namespace lw
{
	float EaseInOutBack::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		float c1 = 1.70158f;
		float c2 = c1 * 1.525f;

		return t < 0.5f ? (std::pow(2.0f * t, 2.0f) * ((c2 + 1.0f) * 2.0f * t - c2)) * 0.5f : (std::pow(2.0f * t - 2.0f, 2.0f) * ((c2 + 1.0f) * (t * 2.0f - 2.0f) + c2) + 2.0f) * 0.5f;
	}
}
