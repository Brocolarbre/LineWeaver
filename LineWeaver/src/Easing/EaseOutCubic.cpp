#include "LineWeaver/Easing/EaseOutCubic.hpp"

namespace lw
{
	float EaseOutCubic::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return 1.0f - (1.0f - t) * (1.0f - t) * (1.0f - t);
	}
}
