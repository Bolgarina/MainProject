#include "./Rectangle.h"
#include "./IVisitor.h"

namespace Geometry
{
	Rectangle::Rectangle()
	{
		vertices.reserve(2);
		vertices.push_back(Point());
		vertices.push_back(Point(1.0f, 1.0f, 0.0f));
	}

	Rectangle::Rectangle(Point i_left_bottom_vertex, Point i_right_top_vertex)
	{
		//if (width == 0 || height == 0)
		//	throw std::logic_error("Width and height should be greater than 0.");
		vertices.reserve(2);
		vertices.push_back(i_left_bottom_vertex);
		vertices.push_back(i_right_top_vertex);
	}

	Rectangle::Rectangle(const Rectangle &i_rect)// : 
	{
		vertices.reserve(2);
		vertices.push_back(i_rect.getLeftBottomVertex());
		vertices.push_back(i_rect.getRightTopVertex());
	}

	Rectangle::~Rectangle()
	{
	}

	std::string Rectangle::name()
	{
		return "rectangle";
	}

	void Rectangle::accept(IVisitor *i_view)
	{
		if (!i_view)
			throw std::runtime_error("Exceptional case.");

		i_view->visit(this);
	}

	const Point &Rectangle::getLeftBottomVertex() const
	{
		return vertices[ELEFT_BOTTOM];
	}

	const Point &Rectangle::getRightTopVertex() const
	{
		return vertices[ERIGHT_TOP];
	}

	std::vector<Point> Rectangle::getVertices() const
	{
		Point right_top_vertex = getRightTopVertex();
		Point left_bottom_vertex = getLeftBottomVertex();
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

	const Point Rectangle::getCentroid() const
	{
		return Point((getLeftBottomVertex().x + getRightTopVertex().x) / 2.0f,
			(getLeftBottomVertex().y + getRightTopVertex().y) / 2.0f,
			(getLeftBottomVertex().z + getRightTopVertex().z) / 2.0f);
	}

	void Rectangle::setLeftBottomVertex(Point i_pt)
	{
		vertices[ELEFT_BOTTOM] = i_pt;
	}

	void Rectangle::setRightTopVertex(Point i_pt)
	{
		vertices[ERIGHT_TOP] = i_pt;
	}
}