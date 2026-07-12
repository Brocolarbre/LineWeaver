#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInElastic : public CloneableEasing<EaseInElastic>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}