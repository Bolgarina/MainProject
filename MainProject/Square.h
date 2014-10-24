#pragma once

#include "IShape.h"
#include "Point.h"
#include "Renderer.h"

#include <iostream>
#include <string>

class Square : public IShape
{
public:
	Square();
	Square(Point i_point, int i_side);
	explicit Square(const Square &i_square);
	~Square();

	static std::string name();
	/*friend std::istream &operator>>(std::istream &stream, Square &i_square);*/
	void accept(Renderer *i_renderer);

private:
	Point origin;
	int side;
};