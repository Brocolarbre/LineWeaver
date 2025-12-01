#include "LineWeaver/Sampling/CurveSampler.hpp"

namespace lw
{
	namespace
	{
		float mapRange(float value, float fromMin, float fromMax, float toMin, float toMax)
		{
			return (((value - fromMin) * (toMax - toMin)) / (fromMax - fromMin)) + toMin;
		}
	}

	std::vector<float> CurveSampler::generateSampleValues(unsigned int count, float min, float max, const Easing& easing)
	{
		if (max < min || min < 0.0f || max < 0.0f)
			return {};

		std::vector<float> sampleValues(count);

		float step = (max - min) / static_cast<float>(count - 1);

		for (unsigned int i = 0; i < sampleValues.size(); ++i)
			sampleValues[i] = mapRange(easing(mapRange(min + i * step, min, max, 0.0f, 1.0f)), 0.0f, 1.0f, min, max);

		return sampleValues;
	}

	Curve CurveSampler::sampleCurve(const Curve& curve, const Interpolator& interpolator, const std::vector<float>& t)
	{
		lw::Curve sampledCurve(t.size());

		for (unsigned int i = 0; i < t.size(); ++i)
			sampledCurve[i] = interpolator(curve, t[i]);

		return sampledCurve;
	}
}