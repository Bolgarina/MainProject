#include "./Rectangle.h"
#include "./IVisitor.h"

namespace Geometry
{
	Rectangle::Rectangle() : color()
	{
		vertices.reserve(2);
		vertices.push_back(Point());
		vertices.push_back(Point(1.0f, 1.0f, 0.0f));
	}

	Rectangle::Rectangle(Point i_left_bottom_vertex, Point i_right_top_vertex, Color i_color) :
		color(i_color)
	{
		if ((i_left_bottom_vertex.x == i_right_top_vertex.x && i_left_bottom_vertex.y == i_right_top_vertex.y) || 
			(i_left_bottom_vertex.x == i_right_top_vertex.x && i_left_bottom_vertex.z == i_right_top_vertex.z) ||
			(i_left_bottom_vertex.y == i_right_top_vertex.y && i_left_bottom_vertex.z == i_right_top_vertex.z))
			throw std::logic_error("Degenerate rectangle (line/point).");

		vertices.reserve(2);
		vertices.push_back(i_left_bottom_vertex);
		vertices.push_back(i_right_top_vertex);
	}

	Rectangle::Rectangle(const Rectangle &i_rect) : color(i_rect.color)
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

	void Rectangle::accept(IVisitor *i_visitor)
	{
		if (!i_visitor)
			throw std::runtime_error("Exceptional case.");

		i_visitor->visit(this);
	}

	const Point& Rectangle::getLeftBottomVertex() const
	{
		return vertices[ELEFT_BOTTOM];
	}

	const Point& Rectangle::getRightTopVertex() const
	{
		return vertices[ERIGHT_TOP];
	}

	std::vector<Point> Rectangle::getVertices() const
	{
		Point right_top_vertex = getRightTopVertex();
		Point left_bottom_vertex = getLeftBottomVertex();
		Point right_bottom_vertex(right_top_vertex.x, left_bottom_vertex.y, right_top_vertex.z);
		Point left_top_vertex(left_bottom_vertex.x, right_top_vertex.y, left_bottom_vertex.z);

		std::vector<Point> verts;
		verts.push_back(left_bottom_vertex);
		verts.push_back(right_bottom_vertex);
		verts.push_back(left_top_vertex);
		verts.push_back(left_top_vertex);
		verts.push_back(right_bottom_vertex);
		verts.push_back(right_top_vertex);

		return verts;
	}

	const Point Rectangle::getCentroid() const
	{
		return Point((getLeftBottomVertex().x + getRightTopVertex().x) / 2.0f,
			(getLeftBottomVertex().y + getRightTopVertex().y) / 2.0f,
			(getLeftBottomVertex().z + getRightTopVertex().z) / 2.0f);
	}

	std::vector<float> Rectangle::getColor() const
	{
		std::vector<float> vColor;

		vColor.push_back(color.r);
		vColor.push_back(color.g);
		vColor.push_back(color.b);
		vColor.push_back(color.alpha);

		return vColor;
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