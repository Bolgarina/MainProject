#pragma once

#include "./DllApi.h"

#include <FreeGlew/glew.h>
#include <FreeGlut/glut.h>

#include <string>

class CONTROLLER_API Shader
{
public:
	Shader();
	~Shader();

	void init(const GLenum &i_type, const std::string &i_fileName);
	const GLuint &id() const;
	void compile() const;

private:
	GLuint shader_id;

	std::string loadFromFile(const std::string &i_fileName) const;
};