#pragma once

#include "./DllApi.h"

#include <vector>

namespace Math
{
	class MATHEMATICS_API Vector4f
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
		Vector4f operator*(const Vector4f &rhs);
		Vector4f& operator*=(const Vector4f &rhs);

		// Vector/scalar operations
		Vector4f operator*(const float &rhs);
		Vector4f operator/(const float &rhs);

		const std::vector<float> &get() const;
		const size_t& size() const;

		// Access the individual elements                                                                                                                                                                                               
		float& operator[](const size_t &index);
		const float& operator[](const size_t &index) const;

	private:
#pragma warning (push)
#pragma warning(disable:4251)
		static const size_t VECTOR_SIZE = 4;
		std::vector<float> vect;
#pragma warning (pop)
	};
}