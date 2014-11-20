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

	std::unique_ptr<IController> controller;
	try
	{
		controller.reset(new OpenGLController(&model, &view));
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Runtime error: " << e.what() << std::endl;
		return 1;
	}

	controller->init(argc, argv);

	return 0;
}