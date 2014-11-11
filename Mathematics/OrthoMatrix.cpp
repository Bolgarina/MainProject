#include "./OrthoMatrix.h"

namespace Math
{
	OrthoMatrix::OrthoMatrix(const float &i_left, const float &i_right,
		const float &i_bottom, const float &i_top,
		const float &i_near, const float &i_far) : BaseMatrix(4)
	{
		matrix[0][0] = 2.0f / (i_right - i_left);
		matrix[1][1] = 2.0f / (i_top - i_bottom);
		matrix[2][2] = -2.0f / (i_far - i_near);

		matrix[0][3] = -(i_right + i_left) / (i_right - i_left);
		matrix[1][3] = -(i_top + i_bottom) / (i_top - i_bottom);
		matrix[2][3] = -(i_far + i_near) / (i_far - i_near);
	}
}