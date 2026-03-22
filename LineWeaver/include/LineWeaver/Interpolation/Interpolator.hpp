#pragma once

#include "Point.hpp"

#include <vector>

namespace lw
{
	using Curve = std::vector<Point>;

	class Interpolator
	{
	protected:
		unsigned int m_pointsPerSegment;
		unsigned int m_segmentStep;
		bool m_useBoundaryPoints;

	public:
		LINEWEAVER_EXPORT Interpolator(unsigned int pointsPerSegment, unsigned int segmentStep, bool useBoundaryPoints);

		LINEWEAVER_EXPORT unsigned int getPointsPerSegment() const;
		LINEWEAVER_EXPORT unsigned int getSegmentStep() const;
		LINEWEAVER_EXPORT bool useBoundaryPoints() const;

		virtual Point operator()(const Curve& points, float t) const = 0;
	};
}