#pragma once

#include "./BaseMatrix.h"

// Asymmetric Frustum Projection Matrix
namespace Math
{
	class MATHEMATICS_API AsymFrustumProjectionMatrix : public BaseMatrix
	{
	public:
		AsymFrustumProjectionMatrix(const float &i_left, const float &i_right,
			const float &i_bottom, const float &i_top,
			const float &i_near, const float &i_far);
	};
}