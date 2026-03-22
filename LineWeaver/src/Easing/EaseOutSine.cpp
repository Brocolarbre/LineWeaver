#include "LineWeaver/Easing/EaseOutSine.hpp"

namespace lw
{
	float EaseOutSine::operator()(float t) const
	{
		t = std::clamp(t, 0.0f, 1.0f);

		return std::sin((t * std::numbers::pi_v<float>) * 0.5f);
	}
}
