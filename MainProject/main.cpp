#include <Controller/ShapesReader.h>
#include <Controller/OpenGLController.h>

int main(int argc, char **argv)
{
	ShapesReader reader("InputShapes.txt");
	ShapesReader::ShList shapes;
	
	if (reader.read())
		shapes = reader.getShapes();

	IController *controller = new OpenGLController(&shapes);
	controller->init(argc, argv);

	return 0;
}