#pragma once

#include "Interpolator.hpp"

namespace lw
{
	class LINEWEAVER_API BSplineInterpolator : public Interpolator
	{
	private:
		Interpolator* m_interpolator;
		unsigned int m_degree;
		unsigned int m_segmentStep;

	public:
		BSplineInterpolator(Interpolator* interpolator);

		Point operator()(const Curve& points, float u) const override;
	};
}