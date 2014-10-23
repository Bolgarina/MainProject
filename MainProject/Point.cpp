#include "Point.h"

Point::Point() : x(0), y(0)
{
}

Point::Point(int i_x, int i_y) : x(i_x), y(i_y)
{
}

Point::Point(const Point &i_point) : x(i_point.x), y(i_point.y)
{
}

Point::~Point()
{
}