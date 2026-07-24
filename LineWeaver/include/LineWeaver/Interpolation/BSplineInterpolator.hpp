#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API BSplineInterpolator : public CloneableInterpolator<BSplineInterpolator>
	{
	private:
		std::unique_ptr<Interpolator> m_interpolator;
		unsigned int m_pointsPerSegment;
		unsigned int m_segmentStep;

	public:
		BSplineInterpolator(std::unique_ptr<Interpolator> interpolator);
		BSplineInterpolator(const BSplineInterpolator& bSplineInterpolator);

		Point operator()(const Curve& points, float u) const override;
	};
}