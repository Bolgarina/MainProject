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

	bool Point::operator==(const Point &i_point) const
	{
		return (this->x == i_point.x) && (this->y == i_point.y) && (this->z == i_point.z);
	}
}