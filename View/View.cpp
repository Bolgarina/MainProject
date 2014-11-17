#include "./View.h"

#include <FreeGlew/glew.h>
#include <FreeGlut/glut.h>
#include <FreeGlut/freeglut_ext.h>
#include <Model/IShape.h>

#include <iostream>

View::View()
{

}

View::~View()
{

}

void View::postRedisplay()
{
	glutPostRedisplay();
}

void View::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void View::display(const Math::Matrix4f *const i_transformationMatrix, const std::list<std::shared_ptr<Geometry::IShape>>& i_list)
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto it = i_list.begin(); it != i_list.end(); it++)
		render(it->get(), i_transformationMatrix);

	glutSwapBuffers();
}

void View::startInit(int &i_argc, char **i_argv)
{
	// Window configuration
	glutInit(&i_argc, i_argv);

	GLsizei width, height;
	width = glutGet(GLUT_SCREEN_WIDTH);
	height = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize((width / 2) - 4, height / 2);
	glutInitWindowPosition(width / 4, height / 4);
	// Type of the window
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("3D scene");

	if (glewInit())
	{
		std::cerr << "Unable to initialize GLEW ...exiting" << std::endl;
		exit(EXIT_FAILURE);
	};

	sh_program.init("shader.vert", "shader.frag");

	a_coord = sh_program.getAttributeLocation("coord");
	u_color = sh_program.getUniformLocation("color");
	u_transformationMatrix = sh_program.getUniformLocation("transformationMatrix");

	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void View::finishInit()
{
	glutMainLoop();
}

void View::setDisplayCallback(void(*callback)(void))
{
	glutDisplayFunc(callback);
}

void View::setReshapeCallback(void(*callback)(int, int))
{
	glutReshapeFunc(callback);
}

void View::setMouseCallback(void(*callback)(int, int, int, int))
{
	glutMouseFunc(callback);
}

void View::setMouseWheelCallback(void(*callback)(int, int, int, int))
{
	glutMouseWheelFunc(callback);
}

void View::setMotionCallback(void(*callback)(int, int))
{
	glutMotionFunc(callback);
}

void View::setKeyboardCallback(void(*callback)(unsigned char, int, int))
{
	glutKeyboardFunc(callback);
}

void View::setKeySpecialCallback(void(*callback)(int, int, int))
{
	glutSpecialFunc(callback);
}

void View::render(Geometry::IShape *i_shape, const Math::Matrix4f *const p_transformationMatrix)
{
	if (!i_shape)
		throw std::runtime_error("Exceptional case.");

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	const std::vector<Geometry::Point> rectangle = i_shape->getVertices();

	size_t size = rectangle.size();
	if (size == 6 || size == 3)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle[0]) * rectangle.size(), &rectangle.front(), GL_STATIC_DRAW);

		sh_program.bind();
		sh_program.setUniformMatrix(u_transformationMatrix, *p_transformationMatrix);

		std::vector<float> color = i_shape->getColor();
		sh_program.setUniformVector(u_color, color);

		glEnableVertexAttribArray(a_coord); // lets to use a_coord
		glVertexAttribPointer(a_coord, 3, GL_FLOAT, GL_FALSE, 0, 0); // set access parameters of a_coord to VBO
		glDrawArrays(GL_TRIANGLES, 0, size);

		glDisableVertexAttribArray(a_coord);
		sh_program.unbind();
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBO);
}