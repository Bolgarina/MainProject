#include "./ScaleMatrix.h"

namespace Math
{
	ScaleMatrix::ScaleMatrix(const float &i_sx, const float &i_sy, const float &i_sz) : BaseMatrix(4)
	{
		matrix[0][0] = i_sx;
		matrix[1][1] = i_sy;
		matrix[2][2] = i_sz;
	}
}