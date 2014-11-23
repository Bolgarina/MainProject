#include <Controller/ShapesReader.h>
#include <Controller/OpenGLController.h>
#include <Model/Model.h>
#include <View/View.h>

#include <memory>
#include <iostream>

int main(int argc, char **argv)
{
	ShapesReader reader("InputShapes.txt");
	
	if (!reader.read())
		return 1;

	Model model(reader.getShapes());
	View view;

	std::unique_ptr<IController> controller(new OpenGLController(model, view));
	if (!controller->init(argc, argv))
		return 1;

	return 0;
}