#include "LineWeaver/Sampling/CurveSampler.hpp"

namespace lw
{
	std::vector<float> CurveSampler::generateSampleValues(unsigned int count, float min, float max, const Easing& easing)
	{
		if (max < min || min < 0.0f || max < 0.0f)
			return {};

		std::vector<float> sampleValues(count);

		float step = (max - min) / static_cast<float>(count - 1);

		for (unsigned int i = 0; i < sampleValues.size(); ++i)
			sampleValues[i] = easing(min + i * step);

		return sampleValues;
	}

	Curve CurveSampler::sampleCurve(const Curve& curve, const Interpolator& generator, const std::vector<float>& t)
	{
		lw::Curve sampledCurve(t.size());

		for (unsigned int i = 0; i < t.size(); ++i)
			sampledCurve[i] = generator(curve, t[i]);

		return sampledCurve;
	}
}