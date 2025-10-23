#pragma once

#include "LineWeaver/Easing/Easing.hpp"
#include "LineWeaver/Interpolation/Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API CurveSampler
	{
	public:
		static std::vector<float> generateSampleValues(unsigned int count, float min, float max, const Easing& easing);
		static Curve sampleCurve(const Curve& curve, const Interpolator& generator, const std::vector<float>& t);
	};
}