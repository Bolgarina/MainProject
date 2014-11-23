#pragma once

#include <FreeGlew/glew.h>
#include <FreeGlut/glut.h>

#include <string>

class Shader
{
public:
	Shader();
	~Shader();

	bool init(const GLenum &i_type, const std::string &i_fileName);
	const GLuint &id() const;
	void compile() const;
	bool validateShader() const;

private:
	GLuint shader_id;

	bool loadFromFile(const std::string &i_fileName, std::string &o_content) const;
};