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
		unsigned int m_degree;
		unsigned int m_segmentStep;

	public:
		Interpolator(unsigned int degree, unsigned int segmentStep);

		unsigned int getDegree() const;
		unsigned int getSegmentStep() const;

		virtual Point operator()(const Curve& points, float t) const = 0;
	};
}