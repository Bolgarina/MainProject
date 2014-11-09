#define _USE_MATH_DEFINES // For using M_PI const
#include <cmath>

#include "./OpenGLController.h"

#include <Model/Display.h>

#include <FreeGlew/glew.h>
#include <FreeGlut/glut.h>
#include <FreeGlut/freeglut_ext.h>
#include <Mathematics/ScaleMatrix.h>
#include <Mathematics/RotationMatrix.h>
#include <Mathematics/TranslationMatrix.h>

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

	void mouseWheelCallback(int wheel, int direction, int x, int y)
	{
		g_controller->mouseWheel(wheel, direction, x, y);
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

OpenGLController::OpenGLController(ShapesReader::ShList *i_shapes) : shapes(i_shapes), transformationMatrix(4), LEFT_BUTTON_down(false), RIGHT_BUTTON_down(false)
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
	glutReshapeFunc(reshapeCallback);

	glutMouseFunc(mouseCallback);
	glutMouseWheelFunc(mouseWheelCallback);
	glutMotionFunc(motionCallback);
	glutKeyboardFunc(keyboardCallback);
	glutSpecialFunc(keySpecialCallback);

	glutMainLoop();
}

void OpenGLController::display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	Display display(&transformationMatrix);
	for (auto it = shapes->begin(); it != shapes->end(); it++)
		(*it)->accept(&display);

	glutSwapBuffers();
}

void OpenGLController::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(0.0, 12.0, 0.0, 12.0, -1.0, 1.0);
}

void OpenGLController::mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			printLog("LEFT_BUTTON down");
			LEFT_BUTTON_down = true;
		}
		else if (state == GLUT_UP)
		{
			printLog("LEFT_BUTTON up");
			LEFT_BUTTON_down = false;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{
			printLog("RIGHT_BUTTON down");
			RIGHT_BUTTON_down = true;
		}
		if (state == GLUT_UP)
		{
			printLog("RIGHT_BUTTON up");
			RIGHT_BUTTON_down = false;
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
			printLog("MIDDLE_BUTTON down");
		if (state == GLUT_UP)
			printLog("MIDDLE_BUTTON up");
		break;
	}
}

void OpenGLController::mouseWheel(int wheel, int direction, int x, int y)
{
	switch (direction)
	{
	case 1:
	{
		Math::ScaleMatrix scaleMatrix(2.0f, 2.0f, 2.0f);
		transformationMatrix *= scaleMatrix;
		glutPostRedisplay();
		break;
	}
	case -1:
	{
		Math::ScaleMatrix scaleMatrix(0.5f, 0.5f, 0.5f);
		transformationMatrix *= scaleMatrix;
		glutPostRedisplay();
		break;
	}
	default:
		break;
	}
}

void OpenGLController::motion(int x, int y)
{
	printLog("Mouse motion:  x = " + std::to_string(x) + ",   y = " + std::to_string(y));
}

void OpenGLController::keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'y':
	case 'Y':
		if (RIGHT_BUTTON_down) // clockwise
		{
			Math::RotationMatrix rotateMatrix((float)(5.0f * M_PI / 180.f), 0.0f, 1.0f, 0.0f);
			transformationMatrix *= rotateMatrix;
			glutPostRedisplay();
		}
		else if (LEFT_BUTTON_down) // counterclockwise
		{
			Math::RotationMatrix rotateMatrix((float)(-5.0f * M_PI / 180.f), 0.0f, 1.0f, 0.0f);
			transformationMatrix *= rotateMatrix;
			glutPostRedisplay();
		}
		break;
	case 'x':
	case 'X':
		if (RIGHT_BUTTON_down) // clockwise
		{
			Math::RotationMatrix rotateMatrix((float)(5.0f * M_PI / 180.f), 1.0f, 0.0f, 0.0f);
			transformationMatrix *= rotateMatrix;
			glutPostRedisplay();
		}
		else if (LEFT_BUTTON_down) // counterclockwise
		{
			Math::RotationMatrix rotateMatrix((float)(-5.0f * M_PI / 180.f), 1.0f, 0.0f, 0.0f);
			transformationMatrix *= rotateMatrix;
			glutPostRedisplay();
		}
		break;
	case 'z':
	case 'Z':
		if (RIGHT_BUTTON_down) // clockwise
		{
			Math::RotationMatrix rotateMatrix((float)(5.0f * M_PI / 180.f), 0.0f, 0.0f, 1.0f);
			transformationMatrix *= rotateMatrix;
			glutPostRedisplay();
		}
		else if (LEFT_BUTTON_down) // counterclockwise
		{
			Math::RotationMatrix rotateMatrix((float)(-5.0f * M_PI / 180.f), 0.0f, 0.0f, 1.0f);
			transformationMatrix *= rotateMatrix;
			glutPostRedisplay();
		}
		break;
	default:
		std::cout << (int)key << std::endl;
	}
}

void OpenGLController::keySpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		Math::TranslationMatrix translateMatrix(-0.1f, 0.0f, 0.0f);
		transformationMatrix *= translateMatrix;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_DOWN:
	{
		Math::TranslationMatrix translateMatrix(0.0f, -0.1f, 0.0f);
		transformationMatrix *= translateMatrix;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		Math::TranslationMatrix translateMatrix(0.1f, 0.0f, 0.0f);
		transformationMatrix *= translateMatrix;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_UP:
	{
		Math::TranslationMatrix translateMatrix(0.0f, 0.1f, 0.0f);
		transformationMatrix *= translateMatrix;
		glutPostRedisplay();
		break;
	}
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