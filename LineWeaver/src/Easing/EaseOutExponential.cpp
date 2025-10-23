#include "LineWeaver/Easing/EaseOutExponential.hpp"

namespace lw
{
	float EaseOutExponential::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t == 1.0f ? 1.0f : 1.0f - std::pow(2.0f, -10.0f * t);
	}
}
