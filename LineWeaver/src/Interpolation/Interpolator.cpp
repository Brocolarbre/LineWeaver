#include "LineWeaver/Interpolation/Interpolator.hpp"

namespace lw
{
	Interpolator::Interpolator(unsigned int degree, unsigned int segmentStep) :
		m_degree(degree),
		m_segmentStep(segmentStep)
	{

	}

	unsigned int Interpolator::getDegree() const
	{
		return m_degree;
	}

	unsigned int Interpolator::getSegmentStep() const
	{
		return m_segmentStep;
	}
}