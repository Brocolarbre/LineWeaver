#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseSmootherstep : public CloneableEasing<EaseSmootherstep>
	{
	public:
		float operator()(float t) const override;
	};
}