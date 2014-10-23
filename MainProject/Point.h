#pragma once

struct Point
{
	Point();
	Point(int i_x, int i_y);
	explicit Point(const Point &i_point);

	~Point();

	int x;
	int y;
};