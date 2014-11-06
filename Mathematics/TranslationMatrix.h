#pragma once

#include "./BaseMatrix.h"

// Translation (Move) Matrix
// http://unspecified.wordpress.com/2012/06/21/calculating-the-gluperspective-matrix-and-other-opengl-matrix-maths/
namespace Math
{
	class MATHEMATICS_API TranslationMatrix : public BaseMatrix
	{
	public:
		TranslationMatrix(const float &i_dx, const float &i_dy, const float &i_dz);
	};
}