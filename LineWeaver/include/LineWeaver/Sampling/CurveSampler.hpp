#pragma once

#include "LineWeaver/Easing/Easing.hpp"
#include "LineWeaver/Interpolation/Interpolator.hpp"

namespace lw
{
	class CurveSampler
	{
	public:
		LINEWEAVER_EXPORT static std::vector<float> generateSampleValues(unsigned int count, float min, float max, const Easing& easing);
		LINEWEAVER_EXPORT static Curve sampleCurve(const Curve& curve, const Interpolator& interpolator, const std::vector<float>& t);
	};
}