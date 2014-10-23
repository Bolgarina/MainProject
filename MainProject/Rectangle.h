#pragma once

#include "IShape.h"
#include "Point.h"

#include <iostream>

class Rectangle : public IShape
{
public:
	Rectangle();
	Rectangle(Point i_point, int i_width, int i_height);
	explicit Rectangle(const Rectangle &i_rect);
	~Rectangle();

	friend std::istream &operator>>(std::istream &stream, Rectangle &i_rect);

private:
	Point origin;
	int width;
	int height;
};