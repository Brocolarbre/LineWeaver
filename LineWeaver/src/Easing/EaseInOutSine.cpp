#include "LineWeaver/Easing/EaseInOutSine.hpp"

namespace lw
{
	float EaseInOutSine::operator()(float t) const
	{
		t = std::clamp(t, 0.0f, 1.0f);

		return -(std::cos(std::numbers::pi_v<float> * t) - 1.0f) * 0.5f;
	}
}
