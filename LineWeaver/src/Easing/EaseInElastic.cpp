#include "LineWeaver/Easing/EaseInElastic.hpp"

#include <numbers>

namespace lw
{
	float EaseInElastic::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		float c4 = (2.0f * std::numbers::pi_v<float>) / 3.0f;

		if (t == 0.0f || t == 1.0f)
			return t;
		else
			return -std::pow(2.0f, 10.0f * t - 10.0f) * std::sin((t * 10.0f - 10.75f) * c4);
	}
}
