#include "./Rectangle.h"
#include "./IView.h"

namespace Geometry
{
	Rectangle::Rectangle() : left_bottom_vertex(), right_top_vertex(1.0f, 1.0f, 0.0f)
	{
	}

	Rectangle::Rectangle(Point i_left_bottom_vertex, Point i_right_top_vertex) : 
		left_bottom_vertex(i_left_bottom_vertex), right_top_vertex(i_right_top_vertex)
	{
		//if (width == 0 || height == 0)
		//	throw std::logic_error("Width and height should be greater than 0.");
	}

	Rectangle::Rectangle(const Rectangle &i_rect) : 
		left_bottom_vertex(i_rect.left_bottom_vertex), right_top_vertex(i_rect.right_top_vertex)
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

	const Point &Rectangle::getLeftBottomVertex() const
	{
		return left_bottom_vertex;
	}

	const Point &Rectangle::getRightTopVertex() const
	{
		return right_top_vertex;
	}

	const std::vector<Point> Rectangle::getVertices() const
	{
		Point right_bottom_vertex(right_top_vertex.x, left_bottom_vertex.y, right_top_vertex.z);
		Point left_top_vertex(left_bottom_vertex.x, right_top_vertex.y, left_bottom_vertex.z);

		std::vector<Point> vertices;
		vertices.push_back(left_bottom_vertex);
		vertices.push_back(right_bottom_vertex);
		vertices.push_back(left_top_vertex);
		vertices.push_back(left_top_vertex);
		vertices.push_back(right_bottom_vertex);
		vertices.push_back(right_top_vertex);

		return vertices;
	}
}