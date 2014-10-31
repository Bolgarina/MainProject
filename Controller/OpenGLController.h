#pragma once

#include "./DllApi.h"

#include "./IController.h"
#include "./ShapesReader.h"

#include <string>

class CONTROLLER_API OpenGLController: public IController
{
public:
	OpenGLController(ShapesReader::ShList *i_shapes);

	void init(int &i_argc, char **i_argv) const;

private:
	ShapesReader::ShList *shapes;

	static void printLog(const std::string &log);
	static void mouse(int button, int state, int x, int y);
	static void motion(int x, int y);
	static void keyboard(unsigned char key, int x, int y);
	static void keySpecial(int key, int x, int y);
};