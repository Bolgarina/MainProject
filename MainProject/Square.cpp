#include "Square.h"

Square::Square() : origin(), side(0)
{
}

Square::Square(Point i_point, int i_side) : origin(i_point), side(i_side)
{
}

Square::Square(const Square &i_square) : origin(i_square.origin), side(i_square.side)
{
}

Square::~Square()
{
}

std::istream &operator>>(std::istream &stream, Square &i_square)
{
	// don't forget to check the input
	stream >> i_square.origin.x >> i_square.origin.y >> i_square.side;
	return stream;
}

void Square::accept(Renderer *i_renderer)
{
	i_renderer->visit(this);
}