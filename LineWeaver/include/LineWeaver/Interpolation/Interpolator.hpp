#pragma once

#include "Point.hpp"

#include <memory>
#include <vector>

namespace lw
{
	using Curve = std::vector<Point>;

	class LINEWEAVER_API Interpolator
	{
	protected:
		unsigned int m_pointsPerSegment;
		unsigned int m_segmentStep;
		bool m_useBoundaryPoints;

	public:
		Interpolator(unsigned int pointsPerSegment, unsigned int segmentStep, bool useBoundaryPoints);
		virtual ~Interpolator() = default;

		unsigned int getPointsPerSegment() const;
		unsigned int getSegmentStep() const;
		bool useBoundaryPoints() const;

		virtual std::unique_ptr<Interpolator> clone() const = 0;
		virtual Point operator()(const Curve& points, float t) const = 0;
	};

	template <typename Derived>
	class CloneableInterpolator : public Interpolator
	{
	public:
		CloneableInterpolator(unsigned int pointsPerSegment, unsigned int segmentStep, bool useBoundaryPoints);

		std::unique_ptr<Interpolator> clone() const override;
	};

	template<typename Derived>
	inline CloneableInterpolator<Derived>::CloneableInterpolator(unsigned int pointsPerSegment, unsigned int segmentStep, bool useBoundaryPoints) :
		Interpolator(pointsPerSegment, segmentStep, useBoundaryPoints)
	{

	}

	template<typename Derived>
	inline std::unique_ptr<Interpolator> CloneableInterpolator<Derived>::clone() const
	{
		return std::make_unique<Derived>(static_cast<const Derived&>(*this));
	}
}