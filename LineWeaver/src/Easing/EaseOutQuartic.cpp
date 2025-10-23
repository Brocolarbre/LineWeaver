#include "LineWeaver/Easing/EaseOutQuartic.hpp"

namespace lw
{
	float EaseOutQuartic::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return 1.0f - (1.0f - t) * (1.0f - t) * (1.0f - t) * (1.0f - t);
	}
}
