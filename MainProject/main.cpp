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
		exit(EXIT_FAILURE);

	Model model(reader.getShapes());
	View view;

	std::unique_ptr<IController> controller;
	try
	{
		controller.reset(new OpenGLController(&model, &view));
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Runtime error: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	controller->init(argc, argv);

	return 0;
}