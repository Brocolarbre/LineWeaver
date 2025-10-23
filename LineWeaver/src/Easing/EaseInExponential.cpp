#include "LineWeaver/Easing/EaseInExponential.hpp"

namespace lw
{
	float EaseInExponential::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t == 0.0f ? 0.0f : std::pow(2.0f, 10.0f * t - 10.0f);
	}
}
