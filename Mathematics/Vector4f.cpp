#include "./Vector4f.h"

namespace Math
{
	Vector4f::Vector4f() : vect(VECTOR_SIZE, 0.0f)
	{
	}

	Vector4f::Vector4f(const float arg1, const float arg2, const float arg3, const float arg4)
	{
		vect.reserve(VECTOR_SIZE);
		vect.push_back(arg1);
		vect.push_back(arg2);
		vect.push_back(arg3);
		vect.push_back(arg4);
	}

	Vector4f::Vector4f(const Vector4f &rhs)
	{
		vect = rhs.vect;
	}

	Vector4f::~Vector4f()
	{
	}

	Vector4f& Vector4f::operator=(const Vector4f &rhs)
	{
		if (&rhs == this)
			return *this;

		vect.resize(VECTOR_SIZE);
		for (size_t i = 0; i < vect.size(); i++)
			vect[i] = rhs[i];

		return *this;
	}

	Vector4f Vector4f::operator+(const Vector4f &rhs)
	{
		Vector4f result;
		for (size_t i = 0; i < VECTOR_SIZE; i++)
			result[i] = this->vect[i] + rhs[i];

		return result;
	}

	Vector4f& Vector4f::operator+=(const Vector4f &rhs)
	{
		for (size_t i = 0; i < VECTOR_SIZE; i++)
			this->vect[i] += rhs[i];

		return *this;
	}

	Vector4f Vector4f::operator-(const Vector4f &rhs)
	{
		Vector4f result;
		for (size_t i = 0; i < VECTOR_SIZE; i++)
			result[i] = this->vect[i] - rhs[i];

		return result;
	}

	Vector4f& Vector4f::operator-=(const Vector4f &rhs)
	{
		for (size_t i = 0; i < VECTOR_SIZE; i++)
			this->vect[i] -= rhs[i];

		return *this;
	}

	// Vector/scalar operations
	Vector4f Vector4f::operator*(const float &rhs)
	{
		Vector4f result;
		for (size_t i = 0; i < VECTOR_SIZE; i++)
			result[i] = this->vect[i] * rhs;

		return result;
	}

	Vector4f Vector4f::operator/(const float &rhs)
	{
		if (!rhs)
			throw std::invalid_argument("Invalid argument (division by 0).");

		Vector4f result;
		for (size_t i = 0; i < VECTOR_SIZE; i++)
			result[i] = this->vect[i] / rhs;

		return result;
	}

	const bool Vector4f::operator==(const Vector4f &rhs)
	{
		return this->vect[0] == rhs[0] && this->vect[1] == rhs[1] && this->vect[2] == rhs[2] && this->vect[3] == rhs[3];
	}

	const std::vector<float> &Vector4f::get() const
	{
		return vect;
	}

	const size_t& Vector4f::size() const
	{
		return VECTOR_SIZE;
	}

	// Access to element                                                                                                                                                                                             
	float& Vector4f::operator[](const size_t &index)
	{
		if ((index < 0) || (index >= VECTOR_SIZE))
			throw std::invalid_argument("Invalid argument (out of range).");

		return this->vect[index];
	}

	const float& Vector4f::operator[](const size_t &index) const
	{
		if ((index < 0) || (index >= VECTOR_SIZE))
			throw std::invalid_argument("Invalid argument (out of range).");

		return this->vect[index];
	}
}