#pragma once

#include "./Vector4f.h"

#include <vector>

namespace Math
{
	class Matrix4f
	{
	public:
		Matrix4f();
		Matrix4f(const Vector4f vect1, const Vector4f vect2, const Vector4f vect3, const Vector4f vect4);
		Matrix4f(const Matrix4f &rhs);
		~Matrix4f();

		// Operator overloading, for "standard" mathematical matrix operations                                                                                                                                                          
		Matrix4f& operator=(const Matrix4f &rhs);

		// Matrix hematical operations                                                                                                                                                                                               
		Matrix4f operator+(const Matrix4f &rhs);
		Matrix4f& operator+=(const Matrix4f &rhs);
		Matrix4f operator-(const Matrix4f &rhs);
		Matrix4f& operator-=(const Matrix4f &rhs);
		Matrix4f operator*(const Matrix4f &rhs);
		Matrix4f& operator*=(const Matrix4f &rhs);
		Matrix4f transpose();

		// Matrix/scalar operations
		Matrix4f operator*(const float &rhs);
		Matrix4f operator/(const float &rhs);

		// Matrix/vector operations                                                                                                                                                                                                     
		Vector4f operator*(const Vector4f &rhs);

		// Bool operations
		const bool operator==(const Matrix4f &rhs);

		std::vector<float> get() const;

		// Access the individual elements                                                                                                                                                                                               
		Vector4f& operator[](const size_t &index);
		const Vector4f& operator[](const size_t &index) const;

		// Identity matrix
		static Matrix4f createIdentity();

		// Transformation matrices
		static Matrix4f createTranslation(const float &dx, const float &dy, const float &dz);
		static Matrix4f createScale(const float &sx, const float &sy, const float &sz);
		static Matrix4f createRotation(const float &angle, const float &x, const float &y, const float &z);

		// Projection matrices
		static Matrix4f createOrtho(const float &left, const float &right, const float &bottom, const float &top, const float &near, const float &far);
		static Matrix4f createPerspective(const float &left, const float &right, const float &bottom, const float &top, const float &near, const float &far);

	protected:
		static const size_t MATRIX_SIZE = 4; // = Vector4f::VECTOR_SIZE
		std::vector<Vector4f> matrix;
	};
}