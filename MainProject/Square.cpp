#include "Square.h"

Square::Square() : origin(), side(0)
{
}

Square::Square(Point i_point, int i_side) : origin(i_point), side(i_side)
{
}

Square::~Square()
{
}