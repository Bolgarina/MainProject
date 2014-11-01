#include "./OpenGLController.h"

#include <Model/Display.h>

#include <FreeGlew/glew.h>
#include <FreeGlut/glut.h>

#include <iostream>

namespace
{
	// http://stackoverflow.com/questions/3589422/using-opengl-glutdisplayfunc-within-class
	OpenGLController* g_controller; // g_ - global

    void displayCallback()
	{
		g_controller->display();
	}

	void reshapeCallback(int width, int height)
	{
		g_controller->reshape(width, height);
	}

	void mouseCallback(int button, int state, int x, int y)
	{
		g_controller->mouse(button, state, x, y);
	}

	void motionCallback(int x, int y)
	{
		g_controller->motion(x, y);
	}

	void keyboardCallback(unsigned char key, int x, int y)
	{
		g_controller->keyboard(key, x, y);
	}

	void keySpecialCallback(int key, int x, int y)
	{
		g_controller->keySpecial(key, x, y);
	}
}

OpenGLController::OpenGLController(ShapesReader::ShList *i_shapes) : shapes(i_shapes)
{
}

void OpenGLController::init(int &i_argc, char **i_argv)
{
	g_controller = this;

	glutInit(&i_argc, i_argv);
	
	GLsizei width, height;
	width = glutGet(GLUT_SCREEN_WIDTH);
	height = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize((width / 2) - 4, height / 2);
	glutInitWindowPosition(width / 4, height / 4);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("3D scene");

	glewInit();

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glutDisplayFunc(displayCallback);
	//glutIdleFunc(display);
	glutReshapeFunc(reshapeCallback);

	glutMouseFunc(mouseCallback);
	glutMotionFunc(motionCallback);
	glutKeyboardFunc(keyboardCallback);
	glutSpecialFunc(keySpecialCallback);

	glutMainLoop();
}

void OpenGLController::display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	Display display;
	for (auto it = shapes->begin(); it != shapes->end(); it++)
		(*it)->accept(&display);

	glutSwapBuffers();
}

void OpenGLController::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 12.0, 0.0, 12.0, -1.0, 1.0);
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

void OpenGLController::keySpecial(int key, int x, int y)
{
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