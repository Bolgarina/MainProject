#pragma once

namespace Geometry
{
	struct Color
	{
		Color();
		Color(const float i_r, const float i_g, const float i_b, const float i_alpha = 1.0f);
		Color(const Color &i_color);
		~Color();

		bool operator==(const Color &i_color) const;

		float r;
		float g;
		float b;
		float alpha;
	};
}