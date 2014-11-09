#include "./Triangle.h"
#include "./IView.h"

namespace Geometry
{
	Triangle::Triangle()
	{
		vertices[0] = Point(0.0f, 0.0f, 0.0f);
		vertices[1] = Point(1.0f, 0.0f, 0.0f);
		vertices[2] = Point(0.0f, 1.0f, 0.0f);
	}

	Triangle::Triangle(Point i_vertex1, Point i_vertex2, Point i_vertex3)
	{
		if (i_vertex1 == i_vertex2 || i_vertex1 == i_vertex3 || i_vertex2 == i_vertex3)
			throw std::logic_error("Vertices should be different.");

		vertices[0] = i_vertex1;
		vertices[1] = i_vertex2;
		vertices[2] = i_vertex3;
	}

	Triangle::Triangle(const Triangle &i_triangle)
	{
		vertices[0] = i_triangle.getVertices()[0];
		vertices[1] = i_triangle.getVertices()[1];
		vertices[2] = i_triangle.getVertices()[2];
	}

	Triangle::~Triangle()
	{
	}

	std::string Triangle::name()
	{
		return "triangle";
	}

	void Triangle::accept(IView *i_view)
	{
		if (!i_view)
			throw std::runtime_error("Exceptional case.");

		i_view->visit(this);
	}

	const Point *const Triangle::getVertices() const
	{
		return vertices;
	}
}