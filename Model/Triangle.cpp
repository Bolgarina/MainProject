#include "./Triangle.h"
#include "./ITransformation.h"

Triangle::Triangle()
{
	vertices[0] = Point(0, 0);
	vertices[1] = Point(1, 0);
	vertices[2] = Point(0, 1);
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

void Triangle::accept(ITransformation *i_transform)
{
	if (!i_transform)
		throw std::runtime_error("Exceptional case.");

	i_transform->visit(this);
}

const Point *const Triangle::getVertices() const
{
	return vertices;
}