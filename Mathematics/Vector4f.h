#pragma once

#include "./Matrix.h"

namespace Math
{
	class Vector4f
	{
	public:

		Vector4f();
		Vector4f(const float arg1, const float arg2, const float arg3, const float arg4);
		Vector4f(const Vector4f &rhs);
		~Vector4f();

		Vector4f& operator=(const Vector4f &rhs);

		Vector4f operator+(const Vector4f &rhs);
		Vector4f& operator+=(const Vector4f &rhs);
		Vector4f operator-(const Vector4f &rhs);
		Vector4f& operator-=(const Vector4f &rhs);

		// Vector/scalar operations
		Vector4f operator*(const float &rhs);
		Vector4f operator/(const float &rhs);

		// Bool operations
		const bool operator==(const Vector4f &rhs);

		void get(float o_values[SIZE]) const;
		const size_t& size() const;

		// Access the individual elements                                                                                                                                                                                               
		float& operator[](const size_t &index);
		const float& operator[](const size_t &index) const;

	private:
		float vect[SIZE];
	};
}