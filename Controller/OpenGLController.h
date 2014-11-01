#pragma once

#include "./DllApi.h"

#include "./IController.h"
#include "./ShapesReader.h"

#include <string>

class CONTROLLER_API OpenGLController: public IController
{
public:
	OpenGLController(ShapesReader::ShList *i_shapes);

	void init(int &i_argc, char **i_argv);

	void display();
	void reshape(int width, int height);

	// Interaction
	void mouse(int button, int state, int x, int y);
	void mouseWheel(int wheel, int direction, int x, int y);
	void motion(int x, int y);
	void keyboard(unsigned char key, int x, int y);
	void keySpecial(int key, int x, int y);

	void printLog(const std::string &log);

private:
	ShapesReader::ShList *shapes;
};