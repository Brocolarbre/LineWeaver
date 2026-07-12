#pragma once

#include "LineWeaver/Export.hpp"

#include <algorithm>
#include <cmath>
#include <memory>

namespace lw
{
	class Easing
	{
	public:
		LINEWEAVER_EXPORT virtual ~Easing() = default;

		virtual std::unique_ptr<Easing> clone() const = 0;
		virtual float operator()(float t) const = 0;
	};

	template <typename Derived>
	class CloneableEasing : public Easing
	{
	public:
		std::unique_ptr<Easing> clone() const override;
	};

	template<typename Derived>
	inline std::unique_ptr<Easing> CloneableEasing<Derived>::clone() const
	{
		return std::make_unique<Derived>(static_cast<const Derived&>(*this));
	}
}