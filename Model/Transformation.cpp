#include "./Transformation.h"
#include "./Triangle.h"
#include "./Rectangle.h"

#include <iostream>

void Transformation::visit(Geometry::Triangle* i_triangle)
{
	if (!i_triangle)
		throw std::runtime_error("Exceptional case.");

	std::cout << "*  " << std::endl << "* *" << std::endl << "*  *" << std::endl << "****" << std::endl << std::endl;
}

void Transformation::visit(Geometry::Rectangle* i_rectangle)
{
	if (!i_rectangle)
		throw std::runtime_error("Exceptional case.");

	std::cout << "********" << std::endl << "*      *" << std::endl << "********" << std::endl << std::endl;
}