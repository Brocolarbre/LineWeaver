#pragma once

#include "Easing.hpp"

namespace lw
{
	class EaseInOutBack : public CloneableEasing<EaseInOutBack>
	{
	public:
		LINEWEAVER_EXPORT float operator()(float t) const override;
	};
}