#include "./ShaderProgram.h"

#include <iostream>

ShaderProgram::ShaderProgram() : program_id(0)
{
}

ShaderProgram::ShaderProgram(const std::string &vsFile, const std::string &fsFile)
{
	init(vsFile, fsFile);
}

ShaderProgram::~ShaderProgram()
{
	glDetachShader(program_id, shader_fp.id());
	glDetachShader(program_id, shader_vp.id());

	glDeleteProgram(program_id);
}

void ShaderProgram::init(const std::string &i_vsFile, const std::string &i_fsFile)
{
	shader_vp.init(GL_VERTEX_SHADER, i_vsFile);
	shader_fp.init(GL_FRAGMENT_SHADER, i_fsFile);

	shader_vp.compile();
	shader_fp.compile();

	program_id = glCreateProgram();
	glAttachShader(program_id, shader_fp.id());
	glAttachShader(program_id, shader_vp.id());
	glLinkProgram(program_id);

	//validateProgram(program_id);
}

void ShaderProgram::bind() const
{
	glUseProgram(program_id);
}

void ShaderProgram::unbind() const
{
	glUseProgram(0);
}

const GLuint &ShaderProgram::id() const
{
	return program_id;
}

GLint ShaderProgram::getAttributeLocation(const std::string &i_attribute) const
{
	GLint attribute_location = glGetAttribLocation(program_id, i_attribute.c_str());

	if (attribute_location == -1)
	{
		std::cout << "Could not bind attrib " << i_attribute << std::endl;
		exit(-1);
	}

	return attribute_location;
}

GLint ShaderProgram::getUniformLocation(const std::string &i_uniform) const
{
	GLint uniform_location = glGetUniformLocation(program_id, i_uniform.c_str());

	if (uniform_location == -1)
	{
		std::cout << "Could not bind attrib " << i_uniform << std::endl;
		exit(-1);
	}

	return uniform_location;
}

void ShaderProgram::setUniformVector(const GLint &i_location, const std::vector<float> &i_vector)
{
	glUniform4fv(i_location, 1, &i_vector[0]);
	// The first parameter is the location of the uniform variable (retrieved after shader compilation using glGetUniformLocation()).
	// The second parameter indicates the number of vectors we are updating.
}

void ShaderProgram::setUniformMatrix(const GLint &i_location, const Math::BaseMatrix &i_transformationMatrix)
{
	glUniformMatrix4fv(i_location, 1, GL_TRUE, &i_transformationMatrix.get_matrix()[0]);
	// The first parameter is the location of the uniform variable (retrieved after shader compilation using glGetUniformLocation()).
	// The second parameter indicates the number of matrices we are updating.
	// The third parameter indicates whether the matrix is supplied in row-major or column-major order. 
	// Row-major (GL_TRUE) means the matrix is supplied row after row, starting from the top. Column-major is the same but in columns.
}