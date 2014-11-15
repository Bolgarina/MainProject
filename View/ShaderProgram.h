#pragma once

#include "./DllApi.h"

#include "./Shader.h"

#include <string>
#include <vector>
#include <Mathematics/BaseMatrix.h>

class VIEW_API ShaderProgram
{
public:
	ShaderProgram();
	ShaderProgram(const std::string &i_vsFile, const std::string &i_fsFile);
	~ShaderProgram();

	void init(const std::string &i_vsFile, const std::string &i_fsFile);
	void bind() const;         // to enable the shader program
	void unbind() const;       // to disable the shader program
	const GLuint &id() const;  // to get the number associated with the shader program, so that variable can be passed through to the shader program
	bool validateProgram() const;

	GLint getAttributeLocation(const std::string &i_attribute) const; // Returns the bound location of a named attribute
	GLint getUniformLocation(const std::string &i_uniform) const;     // Method to returns the bound location of a named uniform

	// Load data into uniform shader variables
	void setUniformVector(const GLint &i_location, const std::vector<float> &i_vector);
	void setUniformMatrix(const GLint &i_location, const Math::BaseMatrix &i_transformationMatrix);

private:
	GLuint program_id;
	Shader shader_vp;
	Shader shader_fp;
};