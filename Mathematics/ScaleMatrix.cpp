#include "./ScaleMatrix.h"

namespace Math
{
	ScaleMatrix::ScaleMatrix(const float &i_dx, const float &i_dy, const float &i_dz) : BaseMatrix(4)
	{
		matrix[0][0] = i_dx;
		matrix[1][1] = i_dy;
		matrix[2][2] = i_dz;
	}
}