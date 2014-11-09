#pragma once

#include "./DllApi.h"

#include "./IView.h"
#include "./ShaderProgram.h"

#include <Mathematics/BaseMatrix.h>

#include <string>

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class MODEL_API Display : public IView
{
public:
	Display(const Math::BaseMatrix *const i_transformationMatrix);
	void visit(Geometry::Triangle *i_triangle);
	void visit(Geometry::Rectangle *i_rectangle);

private:
	ShaderProgram sh_program;
	GLuint VBO;
	GLint a_coord, u_color, u_transformationMatrix; // atrribute and uniforms' location
	const Math::BaseMatrix *const p_transformationMatrix;
};
