#include "LineWeaver/Easing/EaseOutCircular.hpp"

namespace lw
{
	float EaseOutCircular::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return std::sqrt(1.0f - (t - 1.0f) * (t - 1.0f));
	}
}
