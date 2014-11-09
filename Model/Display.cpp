#include "./Display.h"
#include "./Triangle.h"
#include "./Rectangle.h"

#include <FreeGlut/glut.h>
#include <Mathematics/BaseMatrix.h>

#include <iostream>

Display::Display(const Math::BaseMatrix *const i_transformationMatrix) : p_transformationMatrix(i_transformationMatrix)
{
	sh_program.init("shader.vert", "shader.frag");

	a_coord = sh_program.getAttributeLocation("coord");
	u_color = sh_program.getUniformLocation("color");
	u_transformationMatrix = sh_program.getUniformLocation("transformationMatrix");
}

void Display::visit(Geometry::Triangle *i_triangle)
{
	if (!i_triangle)
		throw std::runtime_error("Exceptional case.");

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// add check of null (i_triangle->getVertices())
	glBufferData(GL_ARRAY_BUFFER, sizeof(*i_triangle->getVertices()) * 3, i_triangle->getVertices(), GL_STATIC_DRAW);
	
	sh_program.bind();
		sh_program.setUniformMatrix(u_transformationMatrix, *p_transformationMatrix);

		std::vector<float> red(4, 1.0f); red[1] = red[2] = 0.0f;
		sh_program.setUniformVector(u_color, red);

		glEnableVertexAttribArray(a_coord); // lets to use a_coord
		glVertexAttribPointer(a_coord, 3, GL_FLOAT, GL_FALSE, 0, 0); // set access parameters of a_coord to VBO
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(a_coord);
	sh_program.unbind();

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBO);
}

void Display::visit(Geometry::Rectangle *i_rectangle)
{
	if (!i_rectangle)
		throw std::runtime_error("Exceptional case.");

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	const std::vector<Geometry::Point> rectangle = i_rectangle->getVertices();

	if (rectangle.size() == 6)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle[0]) * rectangle.size(), &rectangle.front(), GL_STATIC_DRAW);

		sh_program.bind();
			sh_program.setUniformMatrix(u_transformationMatrix, *p_transformationMatrix);

			std::vector<float> white(4, 1.0f);
			sh_program.setUniformVector(u_color, white);

			glEnableVertexAttribArray(a_coord); // lets to use a_coord
			glVertexAttribPointer(a_coord, 3, GL_FLOAT, GL_FALSE, 0, 0); // set access parameters of a_coord to VBO
			glDrawArrays(GL_TRIANGLES, 0, 6);

			glDisableVertexAttribArray(a_coord);
		sh_program.unbind();
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBO);
}
