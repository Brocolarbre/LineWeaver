#include "LineWeaver/Easing/EaseLinear.hpp"

namespace lw
{
	float EaseLinear::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t;
	}
}
