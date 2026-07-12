#include "LineWeaver/Easing/EaseInOutElastic.hpp"
#include "LineWeaver/Detail/Constants.hpp"

namespace lw
{
	float EaseInOutElastic::operator()(float t) const
	{
		t = std::clamp(t, 0.0f, 1.0f);

		float c5 = (lw::math::two_pi) / 4.5f;

		if (t == 0.0f || t == 1.0f)
			return t;
		else if (t < 0.5f)
			return -(std::pow(2.0f, 20.0f * t - 10.0f) * std::sin((20.0f * t - 11.125f) * c5)) * 0.5f;
		else
			return (std::pow(2.0f, -20.0f * t + 10.0f) * std::sin((20.0f * t - 11.125f) * c5)) * 0.5f + 1.0f;
	}
}
