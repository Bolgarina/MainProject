#include "./Transformation.h"
#include "./Triangle.h"
#include "./Rectangle.h"

#include <iostream>

void Transformation::visit(Triangle* i_trianle)
{
	if (!i_trianle)
		throw std::runtime_error("Exceptional case.");

	std::cout << "*  " << std::endl << "* *" << std::endl << "*  *" << std::endl << "****" << std::endl << std::endl;
}

void Transformation::visit(Rectangle* i_rectangle)
{
	if (!i_rectangle)
		throw std::runtime_error("Exceptional case.");

	std::cout << "********" << std::endl << "*      *" << std::endl << "********" << std::endl << std::endl;
}