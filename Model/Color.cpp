#include "./Color.h"

namespace Geometry
{
	Color::Color() : r(1.0f), g(1.0f), b(1.0f), alpha(1.0f)
	{
	}

	Color::Color(const float i_r, const float i_g, const float i_b, const float i_alpha) :
		r(i_r), g(i_g), b(i_b), alpha(i_alpha)
	{
	}

	Color::Color(const Color &i_color) :
		r(i_color.r), g(i_color.g), b(i_color.b), alpha(i_color.alpha)
	{
	}

	Color::~Color()
	{
	}

	bool Color::operator==(const Color &i_color) const
	{
		return (this->r == i_color.r) && (this->g == i_color.g) && (this->b == i_color.b) && (this->alpha == i_color.alpha);
	}
}