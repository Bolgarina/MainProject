#include "./Display.h"
#include "./Triangle.h"
#include "./Rectangle.h"

#include <FreeGlut/glut.h>

#include <iostream>

void Display::visit(Geometry::Triangle *i_triangle)
{
	if (!i_triangle)
		throw std::runtime_error("Exceptional case.");

	glColor3f(0.0, 1.0, 0.0); // Green
	glBegin(GL_TRIANGLES);
		glVertex2i(i_triangle->getVertices()[0].x, i_triangle->getVertices()[0].y);
		glVertex2i(i_triangle->getVertices()[1].x, i_triangle->getVertices()[1].y);
		glVertex2i(i_triangle->getVertices()[2].x, i_triangle->getVertices()[2].y);
	glEnd();
}

void Display::visit(Geometry::Rectangle *i_rectangle)
{
	if (!i_rectangle)
		throw std::runtime_error("Exceptional case.");

	glColor3f(0.0, 0.0, 1.0); // Blue
	glRecti(i_rectangle->getOrigin().x, i_rectangle->getOrigin().y,
		i_rectangle->getOrigin().x + i_rectangle->getWidth(), i_rectangle->getOrigin().y + i_rectangle->getHeight());
}
