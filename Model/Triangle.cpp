#include "./Triangle.h"
#include "./IVisitor.h"

namespace Geometry
{
	Triangle::Triangle()
	{
		vertices.reserve(3);

		vertices.push_back(Point(0.0f, 0.0f, 0.0f));
		vertices.push_back(Point(1.0f, 0.0f, 0.0f));
		vertices.push_back(Point(0.0f, 1.0f, 0.0f));
	}

	Triangle::Triangle(Point i_vertex1, Point i_vertex2, Point i_vertex3)
	{
		if (i_vertex1 == i_vertex2 || i_vertex1 == i_vertex3 || i_vertex2 == i_vertex3)
			throw std::logic_error("Vertices should be different.");

		vertices.reserve(3);

		vertices.push_back(i_vertex1);
		vertices.push_back(i_vertex2);
		vertices.push_back(i_vertex3);
	}

	Triangle::Triangle(const Triangle &i_triangle)
	{
		vertices.push_back(i_triangle.getVertices()[0]);
		vertices.push_back(i_triangle.getVertices()[1]);
		vertices.push_back(i_triangle.getVertices()[2]);
	}

	Triangle::~Triangle()
	{
	}

	std::string Triangle::name()
	{
		return "triangle";
	}

	void Triangle::accept(IVisitor *i_view)
	{
		if (!i_view)
			throw std::runtime_error("Exceptional case.");

		i_view->visit(this);
	}

	std::vector<Point> Triangle::getVertices() const
	{
		return vertices;
	}

	const Point Triangle::getCentroid() const
	{
		return Point((vertices[0].x + vertices[1].x + vertices[2].x) / 3.0f,
			(vertices[0].y + vertices[1].y + vertices[2].y) / 3.0f,
			(vertices[0].z + vertices[1].z + vertices[2].z) / 3.0f);
	}

	void Triangle::setVertex(size_t i_index, Point i_pt)
	{
		if ((i_index > 2) || (i_index < 0))
			throw std::logic_error("Invalid argument (out of range).");

		vertices[i_index] = i_pt;
	}
}