#pragma once

#include "./DllApi.h"
#include "./ShaderProgram.h"

#include <list>
#include <memory>

namespace Math
{
	class Matrix4f;
}

namespace Geometry
{
	class IShape;
}

class VIEW_API View
{
public:
	View();
	~View();

	void postRedisplay();
	void reshape(int width, int height);
	void display(const Math::Matrix4f *const i_transformationMatrix, const std::list<std::shared_ptr<Geometry::IShape>>& i_list);
	void startInit(int &i_argc, char **i_argv);
	void finishInit();

	void setDisplayCallback(void(*callback)(void));
	void setReshapeCallback(void(*callback)(int, int));
	void setMouseCallback(void(*callback)(int, int, int, int));
	void setMouseWheelCallback(void(*callback)(int, int, int, int));
	void setMotionCallback(void(*callback)(int, int));
	void setKeyboardCallback(void(*callback)(unsigned char, int, int));
	void setKeySpecialCallback(void(*callback)(int, int, int));

private:
	void render(Geometry::IShape *i_shape, const Math::Matrix4f *const p_transformationMatrix);

	ShaderProgram sh_program;
	GLuint VBO;
	GLint a_coord, u_color, u_transformationMatrix; // attribute and uniforms' location
};
