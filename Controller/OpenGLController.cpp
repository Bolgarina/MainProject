#include <FreeGlew/glew.h>
#include <FreeGlut/glut.h>

#include "./OpenGLController.h"

#include <iostream>

OpenGLController::OpenGLController(ShapesReader::ShList *i_shapes) : shapes(i_shapes)
{
}

void OpenGLController::init(int &i_argc, char **i_argv) const
{
	glutInit(&i_argc, i_argv);
	
	GLsizei width, height;
	width = glutGet(GLUT_SCREEN_WIDTH);
	height = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize((width / 2) - 4, height / 2);
	glutInitWindowPosition(width / 4, height / 4);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("3D scene");

	glewInit();

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keySpecial);

	glutMainLoop();
}

void OpenGLController::mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			printLog("LEFT_BUTTON down");
		if (state == GLUT_UP)
			printLog("LEFT_BUTTON up");
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			printLog("RIGHT_BUTTON down");
		if (state == GLUT_UP)
			printLog("RIGHT_BUTTON up");
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
			printLog("MIDDLE_BUTTON down");
		if (state == GLUT_UP)
			printLog("MIDDLE_BUTTON up");
		break;
	}
}

void OpenGLController::motion(int x, int y)
{
	printLog("Mouse motion:  x = " + std::to_string(x) + ",   y = " + std::to_string(y));
}

void OpenGLController::keyboard(unsigned char key, int x, int y)
{
	std::string str;
	str += key;
	printLog("'" + str + "' has been pressed ( x = " + std::to_string(x) + ", y = " + std::to_string(y) + ")");
}

void OpenGLController::keySpecial(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_LEFT:
		printLog("Left arrow key has been pressed.");
		break;
	case GLUT_KEY_DOWN:
		printLog("Down arrow key has been pressed.");
		break;
	case GLUT_KEY_RIGHT:
		printLog("Right arrow key has been pressed.");
		break;
	case GLUT_KEY_UP:
		printLog("Up arrow key has been pressed.");
		break;
	default:
		printLog("Special key has been pressed.");
		break;
	}
}

void OpenGLController::printLog(const std::string &log)
{
	if (!log.empty())
		std::cout << log << std::endl;
}