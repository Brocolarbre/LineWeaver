#include "LineWeaver/Easing/EaseInOutCircular.hpp"

namespace lw
{
	float EaseInOutCircular::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t < 0.5f ? (1.0f - std::sqrt(1.0f - std::pow(2.0f * t, 2.0f))) * 0.5f : (std::sqrt(1.0f - std::pow(-2.0f * t + 2.0f, 2.0f)) + 1.0f) * 0.5f;
	}
}
