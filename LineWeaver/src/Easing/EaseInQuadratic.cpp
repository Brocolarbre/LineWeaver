#include "LineWeaver/Easing/EaseInQuadratic.hpp"

namespace lw
{
	float EaseInQuadratic::operator()(float t) const
	{
		t = std::clamp(t, 0.0f, 1.0f);

		return t * t;
	}
}
