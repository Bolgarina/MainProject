#include "Rectangle.h"

Rectangle::Rectangle() : origin(), width(0), height(0)
{
}

Rectangle::Rectangle(Point i_point, int i_width, int i_height) : origin(i_point), width(i_width), height(i_height)
{
}

Rectangle::Rectangle(const Rectangle &i_rect) : origin(i_rect.origin), width(i_rect.width), height(i_rect.height)
{
}

Rectangle::~Rectangle()
{
}

std::string Rectangle::name()
{
	return "rectangle";
}

//std::istream &operator>>(std::istream &stream, Rectangle &i_rect)
//{
//	// don't forget to check the input
//	stream >> i_rect.origin.x >> i_rect.origin.y >> i_rect.width >> i_rect.height;
//	return stream;
//}

void Rectangle::accept(Renderer *i_renderer)
{
	i_renderer->visit(this);
}