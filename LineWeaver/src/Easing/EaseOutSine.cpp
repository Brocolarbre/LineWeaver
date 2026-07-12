#include "LineWeaver/Easing/EaseOutSine.hpp"
#include "LineWeaver/Detail/Constants.hpp"

namespace lw
{
	float EaseOutSine::operator()(float t) const
	{
		t = std::clamp(t, 0.0f, 1.0f);

		return std::sin((t * lw::math::pi) * 0.5f);
	}
}
