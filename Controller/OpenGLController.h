#pragma once

#include "./IController.h"

#include <string>

class Model;
class View;

class OpenGLController: public IController
{
public:
	OpenGLController(Model &i_model, View &i_view);

	bool init(int &i_argc, char **i_argv);

	void display();
	void reshape(int width, int height);

	// Interaction
	void mouse(int button, int state, int x, int y);
	void mouseWheel(int wheel, int direction, int x, int y);
	void motion(int x, int y) const;
	void keyboard(unsigned char key, int x, int y);
	void keySpecial(int key, int x, int y);

private:
	void printLog(const std::string &log) const;

private:
	Model &model;
	View &view;

	bool LEFT_BUTTON_down, RIGHT_BUTTON_down;

	float dx, dy, dz;
	float sx, sy, sz;
	float angleX, angleY, angleZ;
	const float STEP, FACTOR, ANGLE;
};