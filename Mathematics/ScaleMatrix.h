#pragma once

#include "./BaseMatrix.h"

// Scale Matrix
// http://unspecified.wordpress.com/2012/06/21/calculating-the-gluperspective-matrix-and-other-opengl-matrix-maths/
namespace Math
{
	class MATHEMATICS_API ScaleMatrix : public BaseMatrix
	{
	public:
		ScaleMatrix(const float &i_sx, const float &i_sy, const float &i_sz);
	};
}