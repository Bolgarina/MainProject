#pragma once

#include "IShape.h"
#include "Point.h"

#include <iostream>

class Square : public IShape
{
public:
	Square();
	Square(Point i_point, int i_side);
	explicit Square(const Square &i_square);
	~Square();

	friend std::istream &operator>>(std::istream &stream, Square &i_square);

private:
	Point origin;
	int side;
};