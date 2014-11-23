#include "./Matrix4f.h"

#include <cmath>

namespace Math
{
	Matrix4f::Matrix4f() : matrix(SIZE, Vector4f())
	{
	}

	Matrix4f::Matrix4f(const Vector4f &vect1, const Vector4f &vect2, const Vector4f &vect3, const Vector4f &vect4)
	{
		matrix.reserve(SIZE);
		matrix.push_back(vect1);
		matrix.push_back(vect2);
		matrix.push_back(vect3);
		matrix.push_back(vect4);
	}

	// Copy Constructor                                                                                                                                                           
	Matrix4f::Matrix4f(const Matrix4f& rhs)
	{
		matrix = rhs.matrix;
	}
                                                                                                                                                       
	Matrix4f::~Matrix4f()
	{
	}

	// Assignment Operator                                                                                                                                                        
	Matrix4f& Matrix4f::operator=(const Matrix4f &rhs)
	{
		if (&rhs == this)
			return *this;

		matrix.resize(SIZE);
		for (size_t i = 0; i < SIZE; i++)
			matrix[i] = rhs[i];

		return *this;
	}

	// Addition of two matrices                                                                                                                                                   
	Matrix4f Matrix4f::operator+(const Matrix4f &rhs)
	{
		Matrix4f result;
		for (size_t i = 0; i < SIZE; i++)
			result[i] = this->matrix[i] + rhs[i];

		return result;
	}

	// Cumulative addition of this matrix and another                                                                                                                             
	Matrix4f& Matrix4f::operator+=(const Matrix4f &rhs)
	{
		for (size_t i = 0; i < SIZE; i++)
			this->matrix[i] += rhs[i];

		return *this;
	}

	// Subtraction of this matrix and another                                                                                                                                     
	Matrix4f Matrix4f::operator-(const Matrix4f &rhs)
	{
		Matrix4f result;
		for (size_t i = 0; i < SIZE; i++)
			result[i] = this->matrix[i] - rhs[i];

		return result;
	}

	// Cumulative subtraction of this matrix and another                                                                                                                          
	Matrix4f& Matrix4f::operator-=(const Matrix4f &rhs)
	{
		for (size_t i = 0; i < SIZE; i++)
			this->matrix[i] -= rhs[i];

		return *this;
	}

	// Left multiplication of this matrix and another                                                                                                                              
	Matrix4f Matrix4f::operator*(const Matrix4f &rhs)
	{
		Matrix4f result;
		for (size_t i = 0; i < SIZE; i++)
			for (size_t j = 0; j < SIZE; j++)
				for (size_t k = 0; k < SIZE; k++)
					result[i][j] += this->matrix[i][k] * rhs[k][j];

		return result;
	}

	// Cumulative left multiplication of this matrix and another                                                                                                                  
	Matrix4f& Matrix4f::operator*=(const Matrix4f &rhs)
	{
		Matrix4f result = (*this) * rhs;
		(*this) = result;
		return *this;
	}

	// Calculate a transpose of this matrix                                                                                                                                       
	Matrix4f Matrix4f::transpose()
	{
		Matrix4f result;
		for (size_t i = 0; i < SIZE; i++)
			for (size_t j = 0; j < SIZE; j++)
				result[i][j] = this->matrix[j][i];

		return result;
	}

	// Matrix/scalar multiplication                                                                                                                                               
	Matrix4f Matrix4f::operator*(const float &rhs)
	{
		Matrix4f result;
		for (size_t i = 0; i < SIZE; i++)
			result[i] = this->matrix[i] * rhs;

		return result;
	}

	// Matrix/scalar division                                                                                                                                                     
	Matrix4f Matrix4f::operator/(const float &rhs)
	{
		if (std::abs(rhs) < FLT_EPSILON)
			throw std::invalid_argument("Invalid argument (division by 0).");

		Matrix4f result;
		for (size_t i = 0; i < SIZE; i++)
			result[i] = this->matrix[i] / rhs;

		return result;
	}

	// Multiply a matrix with a vector                                                                                                                                            
	Vector4f Matrix4f::operator*(const Vector4f &rhs)
	{
		Vector4f result;
		for (size_t i = 0; i < SIZE; i++)
			for (size_t j = 0; j < SIZE; j++)
				result[i] += this->matrix[i][j] * rhs[j];

		return result;
	}

	const bool Matrix4f::operator==(const Matrix4f &rhs)
	{
		return this->matrix[0] == rhs[0] && this->matrix[1] == rhs[1] && this->matrix[2] == rhs[2] && this->matrix[3] == rhs[3];
	}

	std::vector<float> Matrix4f::get() const
	{
		std::vector<float> vec;
		vec.reserve(SIZE * SIZE);
		for (size_t i = 0; i < SIZE; i++)
		{
			std::vector<float> row = matrix[i].get();
			vec.insert(vec.end(), row.begin(), row.end());
		}

		return vec;
	}

	// Access the individual elements                                                                                                                                             
	Vector4f& Matrix4f::operator[](const size_t &index)
	{
		return this->matrix[index];
	}

	// Access the individual elements (const)                                                                                                                                     
	const Vector4f& Matrix4f::operator[](const size_t &index) const
	{
		return this->matrix[index];
	}

	// Identity matrix (static)
	Matrix4f Matrix4f::createIdentity()
	{
		Matrix4f matrix;
		for (size_t i = 0; i < SIZE; i++)
			matrix[i][i] = 1.0f;

		return matrix;
	}

	// Transformation matrices (static)
	Matrix4f Matrix4f::createTranslation(const float dx, const float dy, const float dz)
	{
		Matrix4f matrix = createIdentity();
		matrix[0][3] = dx;
		matrix[1][3] = dy;
		matrix[2][3] = dz;

		return matrix;
	}

	Matrix4f Matrix4f::createScale(const float sx, const float sy, const float sz)
	{
		Matrix4f matrix = createIdentity();
		matrix[0][0] = sx;
		matrix[1][1] = sy;
		matrix[2][2] = sz;

		return matrix;
	}

	Matrix4f Matrix4f::createRotation(const float angle, const float x, const float y, const float z)
	{
		float s = sinf(angle);
		float c = cosf(angle);

		Matrix4f matrix = createIdentity();
		if (x)
		{
			matrix[1][1] = matrix[2][2] = c;
			matrix[1][2] = -s;
			matrix[2][1] = s;
		}
		else if (y)
		{
			matrix[0][0] = matrix[2][2] = c;
			matrix[2][0] = -s;
			matrix[0][2] = s;
		}
		else if (z)
		{
			matrix[0][0] = matrix[1][1] = c;
			matrix[0][1] = -s;
			matrix[1][0] = s;
		}

		return matrix;
	}

	// Projection matrices (static)
	Matrix4f Matrix4f::createOrtho(const float left, const float right, const float bottom, const float top, const float near, const float far)
	{
		if (right == left || top == bottom || far == near)
			throw std::invalid_argument("Invalid arguments (left/bottom/near should not be equal to right/top/far respectively).");

		if (far < 0 || near < 0 || far < near)
			throw std::logic_error("Far and near values must be positive, far value should be greater than near value.");

		Matrix4f matrix;
		matrix[0][0] = 2.0f / (right - left);
		matrix[1][1] = 2.0f / (top - bottom);
		matrix[2][2] = -2.0f / (far - near);

		matrix[0][3] = -(right + left) / (right - left);
		matrix[1][3] = -(top + bottom) / (top - bottom);
		matrix[2][3] = -(far + near) / (far - near);
		matrix[3][3] = 1.0f;

		return matrix;
	}

	Matrix4f Matrix4f::createPerspective(const float left, const float right, const float bottom, const float top, const float near, const float far)
	{
		if (right == left || top == bottom || far == near)
			throw std::invalid_argument("Invalid arguments (left/bottom/near should not be equal to right/top/far respectively).");

		if (far < 0 || near < 0 || far < near)
			throw std::logic_error("Far and near values must be positive, far value should be greater than near value.");

		Matrix4f matrix;
		matrix[0][0] = 2.0f * near / (right - left);
		matrix[1][1] = 2.0f * near / (top - bottom);
		matrix[2][2] = -(far + near) / (far - near);

		matrix[2][3] = 2.0f * far * near / (far - near);
		matrix[3][2] = -1.0f;

		return matrix;
	}
}