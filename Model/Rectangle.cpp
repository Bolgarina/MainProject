#include "./Rectangle.h"
#include "./IView.h"

namespace Geometry
{
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

	void Rectangle::accept(IView *i_view)
	{
		if (!i_view)
			throw std::runtime_error("Exceptional case.");

		i_view->visit(this);
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
}