#include "./OrthoMatrix.h"

namespace Math
{
	OrthoMatrix::OrthoMatrix(const float &i_left, const float &i_right,
		const float &i_bottom, const float &i_top,
		const float &i_nearVal, const float &i_farVal) : BaseMatrix(4)
	{
		matrix[0][0] = 2 / (i_right - i_left);
		matrix[1][1] = 2 / (i_top - i_bottom);
		matrix[2][2] = -2 / (i_farVal - i_nearVal);

		matrix[0][3] = -(i_right + i_left) / (i_right - i_left);
		matrix[1][3] = -(i_top + i_bottom) / (i_top - i_bottom);
		matrix[2][3] = -(i_farVal + i_nearVal) / (i_farVal - i_nearVal);
	}
}