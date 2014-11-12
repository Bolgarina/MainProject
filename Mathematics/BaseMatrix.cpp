#include "./BaseMatrix.h"

namespace Math
{
	// Identity matrix
	BaseMatrix::BaseMatrix(unsigned i_dimention)
	{
		matrix.resize(i_dimention);
		for (unsigned i = 0; i < matrix.size(); i++)
		{
			matrix[i].resize(i_dimention, 0.0);
			matrix[i][i] = 1.0;
		}

		rows = cols = i_dimention;
	}

	// Parameter Constructor                                                                                                                                                      
	BaseMatrix::BaseMatrix(unsigned i_rows, unsigned i_cols, const float& i_initial)
	{
		matrix.resize(i_rows);
		for (unsigned i = 0; i < matrix.size(); i++)
			matrix[i].resize(i_cols, i_initial);

		rows = i_rows;
		cols = i_cols;
	}

	// Copy Constructor                                                                                                                                                           
	BaseMatrix::BaseMatrix(const BaseMatrix& rhs)
	{
		matrix = rhs.matrix;
		rows = rhs.get_rows();
		cols = rhs.get_cols();
	}

	// (Virtual) Destructor                                                                                                                                                       
	BaseMatrix::~BaseMatrix()
	{
	}

	// Assignment Operator                                                                                                                                                        
	BaseMatrix& BaseMatrix::operator=(const BaseMatrix& rhs)
	{
		if (&rhs == this)
			return *this;

		unsigned new_rows = rhs.get_rows();
		unsigned new_cols = rhs.get_cols();

		matrix.resize(new_rows);
		for (unsigned i = 0; i < matrix.size(); i++)
			matrix[i].resize(new_cols);

		for (unsigned i = 0; i < new_rows; i++)
			for (unsigned j = 0; j < new_cols; j++)
				matrix[i][j] = rhs(i, j);

		rows = new_rows;
		cols = new_cols;

		return *this;
	}

	// Addition of two matrices                                                                                                                                                   
	BaseMatrix BaseMatrix::operator+(const BaseMatrix& rhs)
	{
		BaseMatrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				result(i, j) = this->matrix[i][j] + rhs(i, j);

		return result;
	}

	// Cumulative addition of this matrix and another                                                                                                                             
	BaseMatrix& BaseMatrix::operator+=(const BaseMatrix& rhs)
	{
		unsigned rows = rhs.get_rows();
		unsigned cols = rhs.get_cols();

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				this->matrix[i][j] += rhs(i, j);

		return *this;
	}

	// Subtraction of this matrix and another                                                                                                                                     
	BaseMatrix BaseMatrix::operator-(const BaseMatrix& rhs)
	{
		unsigned rows = rhs.get_rows();
		unsigned cols = rhs.get_cols();
		BaseMatrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				result(i, j) = this->matrix[i][j] - rhs(i, j);

		return result;
	}

	// Cumulative subtraction of this matrix and another                                                                                                                          
	BaseMatrix& BaseMatrix::operator-=(const BaseMatrix& rhs)
	{
		unsigned rows = rhs.get_rows();
		unsigned cols = rhs.get_cols();

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				this->matrix[i][j] -= rhs(i, j);

		return *this;
	}

	// Left multiplication of this matrix and another                                                                                                                              
	BaseMatrix BaseMatrix::operator*(const BaseMatrix& rhs)
	{
		unsigned rows = rhs.get_rows();
		unsigned cols = rhs.get_cols();
		BaseMatrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				for (unsigned k = 0; k < rows; k++)
					result(i, j) += this->matrix[i][k] * rhs(k, j);

		return result;
	}

	// Cumulative left multiplication of this matrix and another                                                                                                                  
	BaseMatrix& BaseMatrix::operator*=(const BaseMatrix& rhs)
	{
		BaseMatrix result = (*this) * rhs;
		(*this) = result;
		return *this;
	}

	// Calculate a transpose of this matrix                                                                                                                                       
	BaseMatrix BaseMatrix::transpose()
	{
		BaseMatrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				result(i, j) = this->matrix[j][i];

		return result;
	}

	// Matrix/scalar multiplication                                                                                                                                               
	BaseMatrix BaseMatrix::operator*(const float& rhs)
	{
		BaseMatrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				result(i, j) = this->matrix[i][j] * rhs;

		return result;
	}

	// Matrix/scalar division                                                                                                                                                     
	BaseMatrix BaseMatrix::operator/(const float& rhs)
	{
		BaseMatrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				result(i, j) = this->matrix[i][j] / rhs;

		return result;
	}

	// Multiply a matrix with a vector                                                                                                                                            
	std::vector<float> BaseMatrix::operator*(const std::vector<float>& rhs)
	{
		std::vector<float> result(rhs.size(), 0.0);

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				result[i] = this->matrix[i][j] * rhs[j];

		return result;
	}

	std::vector<float> BaseMatrix::get_matrix() const
	{
		std::vector<float> vec;
		vec.reserve(rows * cols);

		for (unsigned i = 0; i < rows; i++)
			vec.insert(vec.end(), this->matrix[i].begin(), this->matrix[i].end());

		return vec;
	}

	// Access the individual elements                                                                                                                                             
	float& BaseMatrix::operator()(const unsigned& i_row, const unsigned& i_col)
	{
		return this->matrix[i_row][i_col];
	}

	// Access the individual elements (const)                                                                                                                                     
	const float& BaseMatrix::operator()(const unsigned& i_row, const unsigned& i_col) const
	{
		return this->matrix[i_row][i_col];
	}

	// Get the number of rows of the matrix                                                                                                                                       
	unsigned BaseMatrix::get_rows() const
	{
		return this->rows;
	}

	// Get the number of columns of the matrix                                                                                                                                    
	unsigned BaseMatrix::get_cols() const
	{
		return this->cols;
	}
}