#pragma once

#include "Point.hpp"

#include <memory>
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
		LINEWEAVER_EXPORT virtual ~Interpolator() = default;

		LINEWEAVER_EXPORT unsigned int getPointsPerSegment() const;
		LINEWEAVER_EXPORT unsigned int getSegmentStep() const;
		LINEWEAVER_EXPORT bool useBoundaryPoints() const;

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