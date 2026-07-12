#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseSmootherstep : public CloneableEasing<EaseSmootherstep>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}