#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class BSplineInterpolator : public CloneableInterpolator<BSplineInterpolator>
	{
	private:
		std::unique_ptr<Interpolator> m_interpolator;
		unsigned int m_pointsPerSegment;
		unsigned int m_segmentStep;

	public:
		LINEWEAVER_EXPORT BSplineInterpolator(std::unique_ptr<Interpolator> interpolator);
		LINEWEAVER_EXPORT BSplineInterpolator(const BSplineInterpolator& bSplineInterpolator);

		LINEWEAVER_EXPORT Point operator()(const Curve& points, float u) const override;
	};
}