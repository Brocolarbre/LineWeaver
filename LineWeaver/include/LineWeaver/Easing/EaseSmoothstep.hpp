#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseSmoothstep : public CloneableEasing<EaseSmoothstep>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}