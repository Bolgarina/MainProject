#include "ShapesReader.h"
#include "Drawer.h"

int main()
{
	ShapesReader reader("InputShapes.txt");
	
	ShapesReader::ShList shapes;
	if (reader.read())
		shapes = reader.getShapes();

	Drawer drawer;
	for (auto it = shapes.begin(); it != shapes.end(); it++)
		(*it)->accept(&drawer);

	return 0;
}