#pragma once

#include "Easing.hpp"

namespace lw
{
	class LINEWEAVER_API EaseInOutBack : public CloneableEasing<EaseInOutBack>
	{
	public:
		float operator()(float t) const override;
	};
}