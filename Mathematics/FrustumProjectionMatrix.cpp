#include "./FrustumProjectionMatrix.h"

namespace Math
{
	FrustumProjectionMatrix::FrustumProjectionMatrix(const float &i_left, const float &i_right,
		const float &i_bottom, const float &i_top,
		const float &i_near, const float &i_far) : BaseMatrix(4)
	{
		matrix[0][0] = 2.0f * i_near / (i_right - i_left);
		matrix[1][1] = 2.0f * i_near / (i_top - i_bottom);
		matrix[2][2] = -(i_far + i_near) / (i_far - i_near);
		matrix[2][3] = 2.0f * i_far * i_near / (i_far - i_near);
		matrix[3][2] = -1.0f;
		matrix[3][3] = 0.0f;
	}
}