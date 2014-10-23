#include "Rectangle.h"

Rectangle::Rectangle() : origin(), width(0), height(0)
{
}

Rectangle::Rectangle(Point i_point, int i_width, int i_height) : origin(i_point), width(i_width), height(i_height)
{
}

Rectangle::~Rectangle()
{
}