#pragma once

#include "IShape.h"
#include "Point.h"

class Square : public IShape
{
public:
	Square();
	Square(Point i_point, int i_side);
	~Square();

private:
	Point origin;
	int side;
};