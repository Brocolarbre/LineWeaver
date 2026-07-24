#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseSmoothstep : public CloneableEasing<EaseSmoothstep>
	{
	public:
		float operator()(float t) const override;
	};
}