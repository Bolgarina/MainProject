#include "./Rectangle.h"
#include "./ITransformation.h"

Rectangle::Rectangle() : origin(), width(1), height(1)
{
}

Rectangle::Rectangle(Point i_point, int i_width, int i_height) : origin(i_point), width(i_width), height(i_height)
{
	if (width == 0 || height == 0)
		throw std::logic_error("Width and height should be greater than 0.");
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

void Rectangle::accept(ITransformation *i_transform)
{
	if (!i_transform)
		throw std::runtime_error("Exceptional case.");

	i_transform->visit(this);
}

const Point &Rectangle::getOrigin() const
{
	return origin;
}

const size_t &Rectangle::getWidth() const
{
	return width;
}

const size_t &Rectangle::getHeight() const
{
	return height;
}