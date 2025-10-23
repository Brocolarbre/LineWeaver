#include "LineWeaver/Easing/EaseSmoothstep.hpp"

namespace lw
{
	float EaseSmoothstep::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t * t * (3.0f - 2.0f * t);
	}
}
