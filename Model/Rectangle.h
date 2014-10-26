#pragma once

#include "./DllApi.h"

#include "./IShape.h"
#include "./Point.h"

#include <iostream>
#include <string>

class ITransformation;

class MODEL_API Rectangle : public IShape
{
public:
	Rectangle();
	Rectangle(Point i_point, int i_width, int i_height);
	explicit Rectangle(const Rectangle &i_rect);
	~Rectangle();

	static std::string name();
	/*friend std::istream &operator>>(std::istream &stream, Rectangle &i_rect);*/
	void accept(ITransformation* i_transform);

	// For tests
	const Point &getOrigin() const;
	const size_t &getWidth() const;
	const size_t &getHeight() const;

private:
	Point origin;
	size_t width;
	size_t height;
};