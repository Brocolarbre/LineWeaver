#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class BSplineInterpolator : public Interpolator
	{
	private:
		Interpolator* m_interpolator;
		unsigned int m_pointsPerSegment;
		unsigned int m_segmentStep;

	public:
		LINEWEAVER_EXPORT BSplineInterpolator(Interpolator* interpolator);

		LINEWEAVER_EXPORT Point operator()(const Curve& points, float u) const override;
	};
}