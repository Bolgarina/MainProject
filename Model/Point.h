#pragma once

#include "./DllApi.h"

namespace Geometry
{
	struct MODEL_API Point
	{
		Point();
		Point(float i_x, float i_y, float i_z);
		Point(const Point &i_point);
		~Point();

		bool operator==(const Point &pt) const;

		float x;
		float y;
		float z;
	};
}