#pragma once

#include "LineWeaver/Export.hpp"

#include <glm/glm.hpp>
#include <vector>

namespace lw
{
	using Point = glm::vec3;
	using Curve = std::vector<Point>;

	class LINEWEAVER_API Interpolator
	{
	protected:
		unsigned int m_pointsPerSegment;
		unsigned int m_segmentStep;
		bool m_useBoundaryPoints;

	public:
		Interpolator(unsigned int pointsPerSegment, unsigned int segmentStep, bool useBoundaryPoints);

		unsigned int getPointsPerSegment() const;
		unsigned int getSegmentStep() const;
		bool useBoundaryPoints() const;

		virtual Point operator()(const Curve& points, float t) const = 0;
	};
}