#include "./TranslationMatrix.h"

namespace Math
{
	TranslationMatrix::TranslationMatrix(const float &i_dx, const float &i_dy, const float &i_dz) : BaseMatrix(4)
	{
		matrix[0][3] = i_dx;
		matrix[1][3] = i_dy;
		matrix[2][3] = i_dz;
	}
}