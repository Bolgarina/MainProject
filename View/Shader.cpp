#include "./Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Shader::Shader() : shader_id(0)
{
}

Shader::~Shader()
{
	if (shader_id != 0)
		glDeleteShader(shader_id);
	// shader is tagged for deletion and deleted if it is no longer being used by any shader program
}

bool Shader::init(const GLenum &i_type, const std::string &i_fileName)
{
	shader_id = glCreateShader(i_type); // This function returns 0 if an error occurs creating the shader object
										// GL_INVALID_ENUM is generated if shaderType is not an accepted value.

	unsigned int glErr = glGetError();
	if (glErr == GL_INVALID_ENUM)
	{
		std::cout << "Shader type is incorrect." << std::endl;
		return false;
	}
	else
	{
		std::string shader_content;
		if (!loadFromFile(i_fileName, shader_content))
			return false;

		const char* shader_source = shader_content.c_str();

		glShaderSource(shader_id, 1, &shader_source, 0);

		// GL_INVALID_VALUE is generated if shader_id is not a value generated by OpenGL.
		// GL_INVALID_OPERATION is generated if shader_id is not a shader object.
		unsigned int glErr = glGetError();
		if ((glErr == GL_INVALID_VALUE) || (glErr == GL_INVALID_OPERATION))
		{
			std::cout << "Error occurred when OpenGL was copying the shader source code (glShaderSource)" << std::endl;
			return false;
		}
	}

	return true;
}

const GLuint &Shader::id() const
{
	return shader_id;
}

void Shader::compile() const
{
	glCompileShader(shader_id);
}

bool Shader::validateShader() const
{
	GLint isCompiled = 0;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(shader_id, maxLength, &maxLength, &errorLog[0]);

		return false;
	}

	// Shader compilation is successful
	return true; 
}

bool Shader::loadFromFile(const std::string &i_fileName, std::string &o_content) const
{
	std::ifstream file(i_fileName.c_str());

	if (!file.is_open())
	{
		std::cerr << "Failed to open file: " << i_fileName << std::endl;
		return false;
	}

	std::stringstream stream;
	stream << file.rdbuf();

	file.close();

	o_content = stream.str();
	return true;
}