#pragma once

#include "IShape.h"
#include "Point.h"
#include "Renderer.h"

#include <iostream>
#include <string>

class Rectangle : public IShape
{
public:
	Rectangle();
	Rectangle(Point i_point, int i_width, int i_height);
	explicit Rectangle(const Rectangle &i_rect);
	~Rectangle();

	static std::string name();
	/*friend std::istream &operator>>(std::istream &stream, Rectangle &i_rect);*/
	void accept(Renderer* i_renderer);

private:
	Point origin;
	int width;
	int height;
};