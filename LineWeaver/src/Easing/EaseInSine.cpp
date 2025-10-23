#include "LineWeaver/Easing/EaseInSine.hpp"

#include <numbers>

namespace lw
{
	float EaseInSine::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return 1.0f - std::cos((t * std::numbers::pi_v<float>) * 0.5f);
	}
}
