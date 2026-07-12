#include "LineWeaver/Easing/EaseInOutSine.hpp"
#include "LineWeaver/Detail/Constants.hpp"

namespace lw
{
	float EaseInOutSine::operator()(float t) const
	{
		t = std::clamp(t, 0.0f, 1.0f);

		return -(std::cos(lw::math::pi * t) - 1.0f) * 0.5f;
	}
}
