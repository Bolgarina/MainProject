#include "Drawer.h"

#include <iostream>

void Drawer::visit(Square*)
{
	std::cout << "****" << std::endl << "*  *" << std::endl << "****" << std::endl << std::endl;
}

void Drawer::visit(Rectangle*)
{
	std::cout << "********" << std::endl << "*      *" << std::endl << "********" << std::endl << std::endl;
}