#pragma once

#include "./BaseMatrix.h"

// Orthographic projection matrix
// http://unspecified.wordpress.com/2012/06/21/calculating-the-gluperspective-matrix-and-other-opengl-matrix-maths/
namespace Math
{
	class MATHEMATICS_API OrthoMatrix : public BaseMatrix
	{
	public:
		OrthoMatrix(const float &i_left, const float &i_right,
			const float &i_bottom, const float &i_top,
			const float &i_near, const float &i_far);
	};
}