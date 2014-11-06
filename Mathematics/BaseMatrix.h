#pragma once

#include "./DllApi.h"

#include <vector>

namespace Math
{
	class MATHEMATICS_API BaseMatrix
	{
	public:
		BaseMatrix(unsigned i_dimention);
		BaseMatrix(unsigned i_rows, unsigned i_cols, const float& i_initial);
		BaseMatrix(const BaseMatrix& rhs);
		/*virtual*/ ~BaseMatrix();

		// Operator overloading, for "standard" mathematical matrix operations                                                                                                                                                          
		BaseMatrix& operator=(const BaseMatrix& rhs);

		// Matrix hematical operations                                                                                                                                                                                               
		BaseMatrix operator+(const BaseMatrix& rhs);
		BaseMatrix& operator+=(const BaseMatrix& rhs);
		BaseMatrix operator-(const BaseMatrix& rhs);
		BaseMatrix& operator-=(const BaseMatrix& rhs);
		BaseMatrix operator*(const BaseMatrix& rhs);
		BaseMatrix& operator*=(const BaseMatrix& rhs);
		BaseMatrix transpose();

		// Matrix/scalar operations                                                                                                                                                                                                     
		BaseMatrix operator+(const float& rhs);
		BaseMatrix operator-(const float& rhs);
		BaseMatrix operator*(const float& rhs);
		BaseMatrix operator/(const float& rhs);

		// Matrix/vector operations                                                                                                                                                                                                     
		std::vector<float> operator*(const std::vector<float>& rhs);
		std::vector<float> diag_vec() const;
		std::vector<float> get_matrix() const;

		// Access the individual elements                                                                                                                                                                                               
		float& operator()(const unsigned& i_row, const unsigned& i_col);
		const float& operator()(const unsigned& i_row, const unsigned& i_col) const;

		// Access the row and column sizes                                                                                                                                                                                              
		unsigned get_rows() const;
		unsigned get_cols() const;

	protected:
#pragma warning (push)
#pragma warning(disable:4251)
		std::vector<std::vector<float>> matrix;
#pragma warning (pop)
		unsigned rows;
		unsigned cols;
	};
}