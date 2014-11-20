#define _USE_MATH_DEFINES // For using M_PI const
#include <cmath>

#include "./OpenGLController.h"

#include <Mathematics/Matrix4f.h>

#include <Model/Model.h>
#include <View/View.h>

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

OpenGLController::OpenGLController(Model *i_model, View* i_view) : 
	model(i_model), view(i_view), LEFT_BUTTON_down(false), RIGHT_BUTTON_down(false),
	dx(0.0f), dy(0.0f), dz(0.0f), sx(1.0f), sy(1.0f), sz(1.0f), angleX(0.0f), angleY(0.0f), angleZ(0.0f),
	STEP(0.1f), FACTOR(2.0f), ANGLE((float)(5.0f * M_PI / 180.f))
{
	if (!i_view || !i_model)
		throw std::runtime_error("Empty view/model");
}

void OpenGLController::init(int &i_argc, char **i_argv)
{
	g_controller = this;

	view->startInit(i_argc, i_argv);

	view->setDisplayCallback(displayCallback);
	view->setReshapeCallback(reshapeCallback);
	view->setMouseCallback(mouseCallback);
	view->setMouseWheelCallback(mouseWheelCallback);
	view->setMotionCallback(motionCallback);
	view->setKeyboardCallback(keyboardCallback);
	view->setKeySpecialCallback(keySpecialCallback);

	view->finishInit();
}

void OpenGLController::display()
{
	view->display(&model->getModelMatrix(), model->getData());
}

void OpenGLController::reshape(int width, int height)
{
	view->reshape(width, height);
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
		else if (state == GLUT_UP)
		{
			printLog("RIGHT_BUTTON up");
			RIGHT_BUTTON_down = false;
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
			printLog("MIDDLE_BUTTON down");
		else if (state == GLUT_UP)
			printLog("MIDDLE_BUTTON up");
		break;
	}
}

void OpenGLController::mouseWheel(int wheel, int direction, int x, int y)
{
	switch (direction)
	{
	case 1:
		sx = sy = sz *= FACTOR;
		model->updateScale(sx, sy, sz);
		view->postRedisplay();
		break;

	case -1:
		sx = sy = sz /= FACTOR;
		model->updateScale(sx, sy, sz);
		view->postRedisplay();
		break;

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
			angleY += ANGLE;
		else if (LEFT_BUTTON_down) // counterclockwise
			angleY -= ANGLE;
		
		model->updateRotation(angleX, angleY, angleZ);
		view->postRedisplay();
		break;

	case 'x':
	case 'X':
		if (RIGHT_BUTTON_down) // clockwise
			angleX += ANGLE;
		else if (LEFT_BUTTON_down) // counterclockwise
			angleX -= ANGLE;
		
		model->updateRotation(angleX, angleY, angleZ);
		view->postRedisplay();
		break;

	case 'z':
	case 'Z':
		if (RIGHT_BUTTON_down) // clockwise
			angleZ += ANGLE;
		else if (LEFT_BUTTON_down) // counterclockwise
			angleZ -= ANGLE;
		
		model->updateRotation(angleX, angleY, angleZ);
		view->postRedisplay();
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
		dx -= STEP;
		model->updateTranslation(dx, dy, dz);
		view->postRedisplay();
		break;

	case GLUT_KEY_DOWN:
		dy -= STEP;
		model->updateTranslation(dx, dy, dz);
		view->postRedisplay();
		break;

	case GLUT_KEY_RIGHT:
		dx += STEP;
		model->updateTranslation(dx, dy, dz);
		view->postRedisplay();
		break;

	case GLUT_KEY_UP:
		dy += STEP;
		model->updateTranslation(dx, dy, dz);
		view->postRedisplay();
		break;

	default:
		break;
	}
}

void OpenGLController::printLog(const std::string &log)
{
	if (!log.empty())
		std::cout << log << std::endl;
}