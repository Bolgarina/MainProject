#pragma once

#include "IShape.h"
#include "Point.h"

class Rectangle : public IShape
{
public:
	Rectangle();
	Rectangle(Point i_point, int i_width, int i_height);
	~Rectangle();

private:
	Point origin;
	int width;
	int height;
};