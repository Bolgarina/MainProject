#include "./Point.h"

namespace Geometry
{
	Point::Point() : x(0.0f), y(0.0f), z(0.0f)
	{
	}

	Point::Point(float i_x, float i_y, float i_z) : x(i_x), y(i_y), z(i_z)
	{
	}

	Point::Point(const Point &i_point) : x(i_point.x), y(i_point.y), z(i_point.z)
	{
	}

	Point::~Point()
	{
	}

	bool Point::operator==(const Point &pt) const
	{
		return this->x == pt.x && this->y == pt.y && this->z == pt.z;
	}
}