#include "LineWeaver/Interpolation/Interpolator.hpp"

namespace lw
{
	Interpolator::Interpolator(unsigned int pointsPerSegment, unsigned int segmentStep, bool useBoundaryPoints) :
		m_pointsPerSegment(pointsPerSegment),
		m_segmentStep(segmentStep),
		m_useBoundaryPoints(useBoundaryPoints)
	{

	}

	unsigned int Interpolator::getPointsPerSegment() const
	{
		return m_pointsPerSegment;
	}

	unsigned int Interpolator::getSegmentStep() const
	{
		return m_segmentStep;
	}
	bool Interpolator::useBoundaryPoints() const
	{
		return m_useBoundaryPoints;
	}
}