#include <Controller/ShapesReader.h>
#include <Controller/IController.h>
#include <Controller/OpenGLController.h>
#include <Model/Transformation.h>

int main(int argc, char **argv)
{
	ShapesReader reader("InputShapes.txt");
	ShapesReader::ShList shapes;
	
	if (reader.read())
		shapes = reader.getShapes();

	IController *controller = new OpenGLController(&shapes);
	controller->init(argc, argv);

	//Transformation transf;
	//for (auto it = shapes.begin(); it != shapes.end(); it++)
	//	(*it)->accept(&transf);

	return 0;
}