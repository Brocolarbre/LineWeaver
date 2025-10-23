#include "LineWeaver/Easing/EaseOutElastic.hpp"

#include <numbers>

namespace lw
{
	float EaseOutElastic::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		float c4 = (2.0f * std::numbers::pi_v<float>) / 3;

		if (t == 0.0f || t == 1.0f)
			return t;
		else
			return std::pow(2.0f, -10.0f * t)* std::sin((t * 10.0f - 0.75f) * c4) + 1.0f;
	}
}
