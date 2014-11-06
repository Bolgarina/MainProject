#include "./RotationMatrix.h"
#include <cmath>

namespace Math
{
	RotationMatrix::RotationMatrix(const float &i_angle, const float &i_x, const float &i_y, const float &i_z) : BaseMatrix(4)
	{
		if (i_x)
		{
			matrix[1][1] = matrix[2][2] = cos(i_angle);
			matrix[1][2] = -sin(i_angle);
			matrix[2][1] = sin(i_angle);
		}
		else if (i_y)
		{
			matrix[0][0] = matrix[2][2] = cos(i_angle);
			matrix[2][0] = -sin(i_angle);
			matrix[0][2] = sin(i_angle);
		}
		else if (i_z)
		{
			matrix[0][0] = matrix[1][1] = cos(i_angle);
			matrix[0][1] = -sin(i_angle);
			matrix[1][0] = sin(i_angle);
		}
	}
}