#pragma once

#include "./DllApi.h"

#include <FreeGlew/glew.h>
#include <FreeGlut/glut.h>

#include <string>

class VIEW_API Shader
{
public:
	Shader();
	~Shader();

	void init(const GLenum &i_type, const std::string &i_fileName);
	const GLuint &id() const;
	void compile() const;
	bool validateShader() const;

private:
	GLuint shader_id;

	std::string loadFromFile(const std::string &i_fileName) const;
};