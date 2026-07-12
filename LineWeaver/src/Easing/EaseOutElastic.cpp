#include "LineWeaver/Easing/EaseOutElastic.hpp"
#include "LineWeaver/Detail/Constants.hpp"

namespace lw
{
	float EaseOutElastic::operator()(float t) const
	{
		t = std::clamp(t, 0.0f, 1.0f);

		float c4 = (lw::math::two_pi) / 3.0f;

		if (t == 0.0f || t == 1.0f)
			return t;
		else
			return std::pow(2.0f, -10.0f * t) * std::sin((t * 10.0f - 0.75f) * c4) + 1.0f;
	}
}
