#include <Controller/ShapesReader.h>
#include <Model/Transformation.h>

int main()
{
	ShapesReader reader("InputShapes.txt");
	
	ShapesReader::ShList shapes;
	if (reader.read())
		shapes = reader.getShapes();

	Transformation transf;
	for (auto it = shapes.begin(); it != shapes.end(); it++)
		(*it)->accept(&transf);

	return 0;
}