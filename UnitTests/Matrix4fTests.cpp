#define _USE_MATH_DEFINES // For using M_PI const
#include <cmath>

#include "CppUnitTest.h"

#include <Mathematics/Matrix4f.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Math;

namespace UnitTests
{

	TEST_CLASS(Matrix4fTests)
	{
	public:

		TEST_METHOD(ShouldBe0MatrixWhenDefaultCtor)
		{
			Matrix4f matrix;

			Assert::IsTrue(matrix[0] == Vector4f());
			Assert::IsTrue(matrix[1] == Vector4f());
			Assert::IsTrue(matrix[2] == Vector4f());
			Assert::IsTrue(matrix[3] == Vector4f());
		}

		TEST_METHOD(ShouldSetMatrix4Vects)
		{
			Vector4f vects[4] = { Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f) };
			Matrix4f matrix(vects[0], vects[1], vects[2], vects[3]);

			Assert::IsTrue(matrix[0] == vects[0]);
			Assert::IsTrue(matrix[1] == vects[1]);
			Assert::IsTrue(matrix[2] == vects[2]);
			Assert::IsTrue(matrix[3] == vects[3]);
		}

		TEST_METHOD(ShouldCopyMatrix)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Matrix4f matrix2(matrix1);

			Assert::IsTrue(matrix2[0] == matrix1[0]);
			Assert::IsTrue(matrix2[1] == matrix1[1]);
			Assert::IsTrue(matrix2[2] == matrix1[2]);
			Assert::IsTrue(matrix2[3] == matrix1[3]);
		}

		TEST_METHOD(ShouldAssignMatrix)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Matrix4f matrix2;
			matrix2 = matrix1;

			Assert::IsTrue(matrix2[0] == matrix1[0]);
			Assert::IsTrue(matrix2[1] == matrix1[1]);
			Assert::IsTrue(matrix2[2] == matrix1[2]);
			Assert::IsTrue(matrix2[3] == matrix1[3]);
		}

		TEST_METHOD(ShouldAddMatrices)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Matrix4f matrix2(Vector4f(1.3f, 1.4f, 1.5f, 1.6f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.1f, 0.2f, 0.3f, 0.4f));
			Matrix4f matrix3 = matrix1 + matrix2;

			Assert::IsTrue(matrix3[0] == matrix1[0] + matrix2[0]);
			Assert::IsTrue(matrix3[1] == matrix1[1] + matrix2[1]);
			Assert::IsTrue(matrix3[2] == matrix1[2] + matrix2[2]);
			Assert::IsTrue(matrix3[3] == matrix1[3] + matrix2[3]);
		}

		TEST_METHOD(ShouldAddMatrixToThis)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Matrix4f matrix2(Vector4f(1.3f, 1.4f, 1.5f, 1.6f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.1f, 0.2f, 0.3f, 0.4f));
			Matrix4f matrix3(matrix1); // store this matrix in matrix3
			matrix1 += matrix2;

			Assert::IsTrue(matrix1[0] == matrix3[0] + matrix2[0]);
			Assert::IsTrue(matrix1[1] == matrix3[1] + matrix2[1]);
			Assert::IsTrue(matrix1[2] == matrix3[2] + matrix2[2]);
			Assert::IsTrue(matrix1[3] == matrix3[3] + matrix2[3]);
		}

		TEST_METHOD(ShouldSubMatrices)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Matrix4f matrix2(Vector4f(1.3f, 1.4f, 1.5f, 1.6f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.1f, 0.2f, 0.3f, 0.4f));
			Matrix4f matrix3 = matrix1 - matrix2;

			Assert::IsTrue(matrix3[0] == matrix1[0] - matrix2[0]);
			Assert::IsTrue(matrix3[1] == matrix1[1] - matrix2[1]);
			Assert::IsTrue(matrix3[2] == matrix1[2] - matrix2[2]);
			Assert::IsTrue(matrix3[3] == matrix1[3] - matrix2[3]);
		}

		TEST_METHOD(ShouldSubMatrixFromThis)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Matrix4f matrix2(Vector4f(1.3f, 1.4f, 1.5f, 1.6f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.1f, 0.2f, 0.3f, 0.4f));
			Matrix4f matrix3(matrix1); // store this matrix in matrix3
			matrix1 -= matrix2;

			Assert::IsTrue(matrix1[0] == matrix3[0] - matrix2[0]);
			Assert::IsTrue(matrix1[1] == matrix3[1] - matrix2[1]);
			Assert::IsTrue(matrix1[2] == matrix3[2] - matrix2[2]);
			Assert::IsTrue(matrix1[3] == matrix3[3] - matrix2[3]);
		}

		TEST_METHOD(ShouldMultMatrices)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Matrix4f matrix2(Vector4f(1.3f, 1.4f, 1.5f, 1.6f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.1f, 0.2f, 0.3f, 0.4f));
			Matrix4f matrix3 = matrix1 * matrix2;

			Assert::AreEqual(matrix3[0][0], matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0] + matrix1[0][2] * matrix2[2][0] + matrix1[0][3] * matrix2[3][0]);
			Assert::AreEqual(matrix3[0][1], matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1] + matrix1[0][2] * matrix2[2][1] + matrix1[0][3] * matrix2[3][1]);
			Assert::AreEqual(matrix3[0][2], matrix1[0][0] * matrix2[0][2] + matrix1[0][1] * matrix2[1][2] + matrix1[0][2] * matrix2[2][2] + matrix1[0][3] * matrix2[3][2]);
			Assert::AreEqual(matrix3[0][3], matrix1[0][0] * matrix2[0][3] + matrix1[0][1] * matrix2[1][3] + matrix1[0][2] * matrix2[2][3] + matrix1[0][3] * matrix2[3][3]);

			Assert::AreEqual(matrix3[1][0], matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0] + matrix1[1][2] * matrix2[2][0] + matrix1[1][3] * matrix2[3][0]);
			Assert::AreEqual(matrix3[1][1], matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1] + matrix1[1][2] * matrix2[2][1] + matrix1[1][3] * matrix2[3][1]);
			Assert::AreEqual(matrix3[1][2], matrix1[1][0] * matrix2[0][2] + matrix1[1][1] * matrix2[1][2] + matrix1[1][2] * matrix2[2][2] + matrix1[1][3] * matrix2[3][2]);
			Assert::AreEqual(matrix3[1][3], matrix1[1][0] * matrix2[0][3] + matrix1[1][1] * matrix2[1][3] + matrix1[1][2] * matrix2[2][3] + matrix1[1][3] * matrix2[3][3]);

			Assert::AreEqual(matrix3[2][0], matrix1[2][0] * matrix2[0][0] + matrix1[2][1] * matrix2[1][0] + matrix1[2][2] * matrix2[2][0] + matrix1[2][3] * matrix2[3][0]);
			Assert::AreEqual(matrix3[2][1], matrix1[2][0] * matrix2[0][1] + matrix1[2][1] * matrix2[1][1] + matrix1[2][2] * matrix2[2][1] + matrix1[2][3] * matrix2[3][1]);
			Assert::AreEqual(matrix3[2][2], matrix1[2][0] * matrix2[0][2] + matrix1[2][1] * matrix2[1][2] + matrix1[2][2] * matrix2[2][2] + matrix1[2][3] * matrix2[3][2]);
			Assert::AreEqual(matrix3[2][3], matrix1[2][0] * matrix2[0][3] + matrix1[2][1] * matrix2[1][3] + matrix1[2][2] * matrix2[2][3] + matrix1[2][3] * matrix2[3][3]);

			Assert::AreEqual(matrix3[3][0], matrix1[3][0] * matrix2[0][0] + matrix1[3][1] * matrix2[1][0] + matrix1[3][2] * matrix2[2][0] + matrix1[3][3] * matrix2[3][0]);
			Assert::AreEqual(matrix3[3][1], matrix1[3][0] * matrix2[0][1] + matrix1[3][1] * matrix2[1][1] + matrix1[3][2] * matrix2[2][1] + matrix1[3][3] * matrix2[3][1]);
			Assert::AreEqual(matrix3[3][2], matrix1[3][0] * matrix2[0][2] + matrix1[3][1] * matrix2[1][2] + matrix1[3][2] * matrix2[2][2] + matrix1[3][3] * matrix2[3][2]);
			Assert::AreEqual(matrix3[3][3], matrix1[3][0] * matrix2[0][3] + matrix1[3][1] * matrix2[1][3] + matrix1[3][2] * matrix2[2][3] + matrix1[3][3] * matrix2[3][3]);
		}

		TEST_METHOD(ShouldMultMatrixWithThis)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Matrix4f matrix2(Vector4f(1.3f, 1.4f, 1.5f, 1.6f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.1f, 0.2f, 0.3f, 0.4f));
			Matrix4f matrix3(matrix1); // store this matrix in matrix3
			matrix1 *= matrix2;

			Assert::IsTrue(matrix1 == matrix3 * matrix2);
		}

		TEST_METHOD(ShouldTranspose)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Matrix4f matrix2(matrix1.transpose());

			Assert::IsTrue(matrix2[0] == Vector4f(matrix1[0][0], matrix1[1][0], matrix1[2][0], matrix1[3][0]));
			Assert::IsTrue(matrix2[1] == Vector4f(matrix1[0][1], matrix1[1][1], matrix1[2][1], matrix1[3][1]));
			Assert::IsTrue(matrix2[2] == Vector4f(matrix1[0][2], matrix1[1][2], matrix1[2][2], matrix1[3][2]));
			Assert::IsTrue(matrix2[3] == Vector4f(matrix1[0][3], matrix1[1][3], matrix1[2][3], matrix1[3][3]));
		}

		TEST_METHOD(ShouldMultMatrixWithScalar)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			float k = 2.0f;
			Matrix4f matrix2(matrix1 * k);

			Assert::IsTrue(matrix2[0] == matrix1[0] * k);
			Assert::IsTrue(matrix2[1] == matrix1[1] * k);
			Assert::IsTrue(matrix2[2] == matrix1[2] * k);
			Assert::IsTrue(matrix2[3] == matrix1[3] * k);
		}

		TEST_METHOD(ShouldDivVectorByScalar)
		{
			Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			float k = 2.0f;
			Matrix4f matrix2(matrix1 / k);

			Assert::IsTrue(matrix2[0] == matrix1[0] / k);
			Assert::IsTrue(matrix2[1] == matrix1[1] / k);
			Assert::IsTrue(matrix2[2] == matrix1[2] / k);
			Assert::IsTrue(matrix2[3] == matrix1[3] / k);
		}

		TEST_METHOD(ShouldThrowWhen_DivMatrixBy0)
		{
			auto func_div_by_0 = []()
			{
				Matrix4f matrix1(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
				Matrix4f matrix2(matrix1 / 0.0f);
			};

			Assert::ExpectException<std::invalid_argument>(func_div_by_0);
		}

		TEST_METHOD(ShouldMultMatrixWithVector)
		{
			Matrix4f matrix(Vector4f(0.1f, 0.2f, 0.3f, 0.4f), Vector4f(0.5f, 0.6f, 0.7f, 0.8f), Vector4f(0.9f, 1.0f, 1.1f, 1.2f), Vector4f(1.3f, 1.4f, 1.5f, 1.6f));
			Vector4f vect(1.0f, 2.0f, 3.0f, 4.0f);
			Vector4f result = matrix * vect;

			Assert::IsTrue(result[0] == matrix[0][0] * vect[0] + matrix[0][1] * vect[1] + matrix[0][2] * vect[2] + matrix[0][3] * vect[3]);
			Assert::IsTrue(result[1] == matrix[1][0] * vect[0] + matrix[1][1] * vect[1] + matrix[1][2] * vect[2] + matrix[1][3] * vect[3]);
			Assert::IsTrue(result[2] == matrix[2][0] * vect[0] + matrix[2][1] * vect[1] + matrix[2][2] * vect[2] + matrix[2][3] * vect[3]);
			Assert::IsTrue(result[3] == matrix[3][0] * vect[0] + matrix[3][1] * vect[1] + matrix[3][2] * vect[2] + matrix[3][3] * vect[3]);
		}

		//TEST_METHOD(ShouldBeEqualMatrices)
		//{
		//}

		//TEST_METHOD(ShouldConvertMatrixToVector)
		//{
		//}

		TEST_METHOD(ShouldCreateIdentityMatrix)
		{
			Matrix4f matrix1 = Matrix4f::createIdentity();
			Matrix4f matrix2(Vector4f(1.0f, 0.0f, 0.0f, 0.0f), 
							 Vector4f(0.0f, 1.0f, 0.0f, 0.0f), 
							 Vector4f(0.0f, 0.0f, 1.0f, 0.0f), 
							 Vector4f(0.0f, 0.0f, 0.0f, 1.0f));

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(ShouldCreateTranslationMatrix)
		{
			float dx = 3.0f, dy = 4.0f, dz = 5.0f;
			Matrix4f matrix1 = Matrix4f::createTranslation(dx, dy, dz);
			Matrix4f matrix2(Vector4f(1.0f, 0.0f, 0.0f,  dx ), 
							 Vector4f(0.0f, 1.0f, 0.0f,  dy ), 
							 Vector4f(0.0f, 0.0f, 1.0f,  dz ), 
							 Vector4f(0.0f, 0.0f, 0.0f, 1.0f));

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(ShouldCreateScaleMatrix)
		{
			float sx = 3.0f, sy = 4.0f, sz = 5.0f;
			Matrix4f matrix1 = Matrix4f::createScale(sx, sy, sz);
			Matrix4f matrix2(Vector4f( sx,  0.0f, 0.0f, 0.0f), 
							 Vector4f(0.0f,  sy,  0.0f, 0.0f), 
							 Vector4f(0.0f, 0.0f,  sz,  0.0f), 
							 Vector4f(0.0f, 0.0f, 0.0f, 1.0f));

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(ShouldCreateXRotationMatrix)
		{
			float angle = (float)(7.0f * M_PI / 180.f);
			float s = sinf(angle);
			float c = cosf(angle);

			Matrix4f matrix1 = Matrix4f::createRotation(angle, 1.0f, 0.0f, 0.0f);
			Matrix4f matrix2(Vector4f(1.0f, 0.0f, 0.0f, 0.0f), 
							 Vector4f(0.0f,  c,   -s,   0.0f), 
							 Vector4f(0.0f,  s,    c,   0.0f), 
							 Vector4f(0.0f, 0.0f, 0.0f, 1.0f));

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(ShouldCreateYRotationMatrix)
		{
			float angle = (float)(7.0f * M_PI / 180.f);
			float s = sinf(angle);
			float c = cosf(angle);

			Matrix4f matrix1 = Matrix4f::createRotation(angle, 0.0f, 1.0f, 0.0f);
			Matrix4f matrix2(Vector4f(  c,  0.0f,  s,   0.0f), 
							 Vector4f(0.0f, 1.0f, 0.0f, 0.0f), 
							 Vector4f( -s,  0.0f,  c,   0.0f), 
							 Vector4f(0.0f, 0.0f, 0.0f, 1.0f));

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(ShouldCreateZRotationMatrix)
		{
			float angle = (float)(7.0f * M_PI / 180.f);
			float s = sinf(angle);
			float c = cosf(angle);

			Matrix4f matrix1 = Matrix4f::createRotation(angle, 0.0f, 0.0f, 1.0f);
			Matrix4f matrix2(Vector4f( c,    -s,  0.0f, 0.0f), 
							 Vector4f( s,     c,  0.0f, 0.0f), 
							 Vector4f(0.0f, 0.0f, 1.0f, 0.0f), 
							 Vector4f(0.0f, 0.0f, 0.0f, 1.0f));

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(ShouldCreateOrthoMatrix)
		{
			float left = -3.0f, right = 5.0f, bottom = -2.0f, top = 7.0f, near = 1.0f, far = 8.0f;
			Matrix4f matrix1 = Matrix4f::createOrtho(left, right, bottom, top, near, far);
			Matrix4f matrix2(Vector4f(2.0f / (right - left),         0.0f,                   0.0f,        -(right + left) / (right - left)),
							 Vector4f(        0.0f,          2.0f / (top - bottom),          0.0f,        -(top + bottom) / (top - bottom)),
							 Vector4f(        0.0f,                  0.0f,          -2.0f / (far - near),   -(far + near) / (far - near)  ),
							 Vector4f(        0.0f,                  0.0f,                   0.0f,                      1.0f              ));

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(ShouldThrowWhen_CreateOrthoMatrixWithWrongArg)
		{
			auto func_LR_equal = []() // left and right are equal
			{
				Matrix4f matrix1 = Matrix4f::createOrtho(1.0f, 1.0f, -0.5f, 0.5f, 0.5f, 1.5f);
			};

			auto func_BT_equal = []() // bottom and top are equal
			{
				Matrix4f matrix1 = Matrix4f::createOrtho(-0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 1.5f);
			};

			auto func_NF_equal = []() // near and far are equal
			{
				Matrix4f matrix1 = Matrix4f::createOrtho(-0.5f, 0.5f, -0.5f, 0.5f, 1.0f, 1.0f);
			};

			Assert::ExpectException<std::invalid_argument>(func_LR_equal);
			Assert::ExpectException<std::invalid_argument>(func_BT_equal);
			Assert::ExpectException<std::invalid_argument>(func_NF_equal);
		}

		TEST_METHOD(ShouldThrowWhen_CreateOrthoMatrixWithFarLessThanNear)
		{
			auto func_F_less_N = []() // far is less than near
			{
				Matrix4f matrix1 = Matrix4f::createOrtho(-0.5f, 0.5f, -0.5f, 0.5f, 1.5f, 0.5f);
			};

			Assert::ExpectException<std::logic_error>(func_F_less_N);
		}

		TEST_METHOD(ShouldThrowWhen_CreateOrthoMatrixWithFarNearLessThan0)
		{
			auto func_FN_less_0 = []() // far and near is less than 0
			{
				Matrix4f matrix1 = Matrix4f::createOrtho(-0.5f, 0.5f, -0.5f, 0.5f, -1.5f, -0.5f);
			};

			auto func_N_less_0 = []() // near is less than 0
			{
				Matrix4f matrix1 = Matrix4f::createOrtho(-0.5f, 0.5f, -0.5f, 0.5f, -1.5f, 0.5f);
			};

			Assert::ExpectException<std::logic_error>(func_FN_less_0);
			Assert::ExpectException<std::logic_error>(func_N_less_0);
		}

		TEST_METHOD(ShouldCreatePerspectiveMatrix)
		{
			float left = -3.0f, right = 5.0f, bottom = -2.0f, top = 7.0f, near = 1.0f, far = 8.0f;
			Matrix4f matrix1 = Matrix4f::createPerspective(left, right, bottom, top, near, far);
			Matrix4f matrix2(Vector4f(2.0f * near / (right - left),            0.0f,                           0.0f,                          0.0f              ),
							 Vector4f(          0.0f,               2.0f * near / (top - bottom),              0.0f,                          0.0f              ),
							 Vector4f(          0.0f,                          0.0f,              -(far + near) / (far - near), 2.0f * far * near / (far - near)),
							 Vector4f(          0.0f,                          0.0f,                          -1.0f,                          0.0f              ));

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(ShouldThrowWhen_CreatePerspectiveMatrixWithWrongArg)
		{
			auto func_LR_equal = []() // left and right are equal
			{
				Matrix4f matrix1 = Matrix4f::createPerspective(1.0f, 1.0f, -0.5f, 0.5f, 0.5f, 1.5f);
			};

			auto func_BT_equal = []() // bottom and top are equal
			{
				Matrix4f matrix1 = Matrix4f::createPerspective(-0.5f, 0.5f, 1.0f, 1.0f, 0.5f, 1.5f);
			};

			auto func_NF_equal = []() // near and far are equal
			{
				Matrix4f matrix1 = Matrix4f::createPerspective(-0.5f, 0.5f, -0.5f, 0.5f, 1.0f, 1.0f);
			};

			Assert::ExpectException<std::invalid_argument>(func_LR_equal);
			Assert::ExpectException<std::invalid_argument>(func_BT_equal);
			Assert::ExpectException<std::invalid_argument>(func_NF_equal);
		}

		TEST_METHOD(ShouldThrowWhen_CreatePerspectiveMatrixWithFarLessThanNear)
		{
			auto func_F_less_N = []() // far is less than near
			{
				Matrix4f matrix1 = Matrix4f::createPerspective(-0.5f, 0.5f, -0.5f, 0.5f, 1.5f, 0.5f);
			};

			Assert::ExpectException<std::logic_error>(func_F_less_N);
		}

		TEST_METHOD(ShouldThrowWhen_CreatePerspectiveMatrixWithFarNearLessThan0)
		{
			auto func_FN_less_0 = []() // far and near is less than 0
			{
				Matrix4f matrix1 = Matrix4f::createPerspective(-0.5f, 0.5f, -0.5f, 0.5f, -1.5f, -0.5f);
			};

			auto func_N_less_0 = []() // near is less than 0
			{
				Matrix4f matrix1 = Matrix4f::createPerspective(-0.5f, 0.5f, -0.5f, 0.5f, -1.5f, 0.5f);
			};

			Assert::ExpectException<std::logic_error>(func_FN_less_0);
			Assert::ExpectException<std::logic_error>(func_N_less_0);
		}

	};
}