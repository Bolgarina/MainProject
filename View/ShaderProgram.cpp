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

	// Verifying that shaders compiled successfully
	if (shader_vp.validateShader() && shader_fp.validateShader())
	{
		program_id = glCreateProgram(); // the returned value is zero if an error occured
		glAttachShader(program_id, shader_fp.id());
		glAttachShader(program_id, shader_vp.id());
		glLinkProgram(program_id);

		// If the shader link phase completed unsuccessfully...
		if (!validateProgram())
		{
			std::cerr << "The shader link phase completed unsuccessfully." << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}

void ShaderProgram::bind() const
{
	if (!program_id)
		std::cerr << "Program, which is passed to glUseProgram command, is zero. OpenGL's operation is undefined if no shader is bound." << std::endl;

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

bool ShaderProgram::validateProgram() const
{
	GLint isLinked = 0;
	glGetProgramiv(program_id, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program_id, maxLength, &maxLength, &infoLog[0]);

		// glDeleteProgram(program);
		return false;
	}
	
	// Shader link phase completed successfully
	return true;
}

GLint ShaderProgram::getAttributeLocation(const std::string &i_attribute) const
{
	GLint attribute_location = glGetAttribLocation(program_id, i_attribute.c_str());

	if (attribute_location == -1)
	{
		std::cerr << "Could not bind attribute " << i_attribute << std::endl;
		exit(EXIT_FAILURE);
	}

	return attribute_location;
}

GLint ShaderProgram::getUniformLocation(const std::string &i_uniform) const
{
	GLint uniform_location = glGetUniformLocation(program_id, i_uniform.c_str());

	if (uniform_location == -1)
	{
		std::cerr << "Could not bind uniform " << i_uniform << std::endl;
		exit(EXIT_FAILURE);
	}

	return uniform_location;
}

void ShaderProgram::setUniformVector(const GLint &i_location, const std::vector<float> &i_vector)
{
	glUniform4fv(i_location, 1, &i_vector[0]);
	// The first parameter is the location of the uniform variable (retrieved after shader compilation using glGetUniformLocation()).
	// The second parameter indicates the number of vectors we are updating.
}

void ShaderProgram::setUniformMatrix(const GLint &i_location, const Math::Matrix4f &i_transformationMatrix)
{
	glUniformMatrix4fv(i_location, 1, GL_TRUE, &i_transformationMatrix.get()[0]);
	// The first parameter is the location of the uniform variable (retrieved after shader compilation using glGetUniformLocation()).
	// The second parameter indicates the number of matrices we are updating.
	// The third parameter indicates whether the matrix is supplied in row-major or column-major order. 
	// Row-major (GL_TRUE) means the matrix is supplied row after row, starting from the top. Column-major is the same but in columns.
}