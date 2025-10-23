#include "LineWeaver/Interpolation/Interpolator.hpp"

namespace lw
{
	Interpolator::Interpolator(unsigned int degree) :
		m_degree(degree)
	{

	}

	unsigned int Interpolator::getDegree() const
	{
		return m_degree;
	}
}