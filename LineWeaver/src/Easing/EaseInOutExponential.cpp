#include "LineWeaver/Easing/EaseInOutExponential.hpp"

namespace lw
{
	float EaseInOutExponential::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		if (t == 0.0f || t == 1.0f)
			return t;
		else if (t < 0.5f)
			return std::pow(2.0f, 20.0f * t - 10.0f) * 0.5f;
		else
			return (2.0f - std::pow(2.0f, -20.0f * t + 10.0f)) * 0.5f;
	}
}
