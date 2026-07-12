#include "LineWeaver/Easing/EaseInSine.hpp"
#include "LineWeaver/Detail/Constants.hpp"

namespace lw
{
	float EaseInSine::operator()(float t) const
	{
		t = std::clamp(t, 0.0f, 1.0f);

		return 1.0f - std::cos((t * lw::math::pi) * 0.5f);
	}
}
