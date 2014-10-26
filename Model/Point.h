#pragma once

#include "./DllApi.h"

struct MODEL_API Point
{
	Point();
	Point(int i_x, int i_y);
	Point(const Point &i_point);
	~Point();

	bool operator==(const Point &pt) const;

	int x;
	int y;
};