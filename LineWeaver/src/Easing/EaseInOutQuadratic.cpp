#include "LineWeaver/Easing/EaseInOutQuadratic.hpp"

namespace lw
{
	float EaseInOutQuadratic::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t < 0.5f ? 2.0f * t * t : 1.0f - std::pow(-2.0f * t + 2.0f, 2.0f) * 0.5f;
	}
}
