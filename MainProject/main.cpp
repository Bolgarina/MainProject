#include "ShapesReader.h"

int main()
{
	ShapesReader reader("InputShapes.txt");
	const bool flag = reader.read();

	return 0;
}