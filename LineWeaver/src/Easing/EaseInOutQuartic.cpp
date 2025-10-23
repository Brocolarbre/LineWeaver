#include "LineWeaver/Easing/EaseInOutQuartic.hpp"

namespace lw
{
	float EaseInOutQuartic::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t < 0.5f ? 8.0f * t * t * t * t : 1.0f - std::pow(-2.0f * t + 2.0f, 4.0f) * 0.5f;
	}
}
