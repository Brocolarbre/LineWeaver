#include "LineWeaver/Easing/EaseSmootherstep.hpp"

namespace lw
{
	float EaseSmootherstep::operator()(float t) const
	{
		t = glm::clamp(t, 0.0f, 1.0f);

		return t * t * t * (6.0f * t * t - 15.0f * t + 10.0f);
	}
}
