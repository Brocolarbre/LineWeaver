#include "LineWeaver/Easing/EaseOutBack.hpp"

namespace lw
{
	float EaseOutBack::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		float c1 = 1.70158f;
		float c3 = c1 + 1.0f;

		return 1.0f + c3 * std::pow(t - 1.0f, 3.0f) + c1 * std::pow(t - 1.0f, 2.0f);
	}
}
