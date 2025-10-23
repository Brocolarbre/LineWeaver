#include "LineWeaver/Easing/EaseInCircular.hpp"

namespace lw
{
	float EaseInCircular::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return 1.0f - std::sqrt(1.0f - t * t);
	}
}
