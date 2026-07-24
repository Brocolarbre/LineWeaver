#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInElastic : public CloneableEasing<EaseInElastic>
	{
	public:
		float operator()(float t) const override;
	};
}