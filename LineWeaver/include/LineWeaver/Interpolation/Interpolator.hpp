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

	public:
		Interpolator(unsigned int degree);

		unsigned int getDegree() const;

		virtual Point operator()(const Curve& points, float t) const = 0;
	};
}