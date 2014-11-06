#pragma once

#include "./BaseMatrix.h"

// Translation (Move) Matrix
// http://unspecified.wordpress.com/2012/06/21/calculating-the-gluperspective-matrix-and-other-opengl-matrix-maths/
namespace Math
{
	class MATHEMATICS_API RotationMatrix : public BaseMatrix
	{
	public:
		RotationMatrix(const float &i_angle,
			const float &i_x, const float &i_y, const float &i_z);
	};
}