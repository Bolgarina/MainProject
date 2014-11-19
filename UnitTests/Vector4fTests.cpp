#include "CppUnitTest.h"

#include <Mathematics/Vector4f.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Math;

namespace UnitTests
{

	TEST_CLASS(Vector4fTests)
	{
	public:

		TEST_METHOD(ShouldBe0VectorWhenDefaultCtor)
		{
			Vector4f vect;

			Assert::AreEqual(vect[0], 0.0f);
			Assert::AreEqual(vect[1], 0.0f);
			Assert::AreEqual(vect[2], 0.0f);
			Assert::AreEqual(vect[3], 0.0f);
		}

		TEST_METHOD(ShouldSetVector4Args)
		{
			float arg[4] = { 1.0f, 2.0f, 3.0f, 4.0f };
			Vector4f vect(arg[0], arg[1], arg[2], arg[3]);

			Assert::AreEqual(vect[0], arg[0]);
			Assert::AreEqual(vect[1], arg[1]);
			Assert::AreEqual(vect[2], arg[2]);
			Assert::AreEqual(vect[3], arg[3]);
		}

		TEST_METHOD(ShouldCopyVector)
		{
			Vector4f vect1(1.0f, 2.0f, 3.0f, 4.0f);
			Vector4f vect2(vect1);

			Assert::IsTrue(vect2 == vect1);
		}

		TEST_METHOD(ShouldAssignVector)
		{
			Vector4f vect1(1.0f, 2.0f, 3.0f, 4.0f);
			Vector4f vect2;
			vect2 = vect1;

			Assert::IsTrue(vect2 == vect1);
		}

		TEST_METHOD(ShouldAddVectors)
		{
			Vector4f vect1(1.0f, 2.0f, 3.0f, 4.0f);
			Vector4f vect2(5.0f, 6.0f, 7.0f, 8.0f);
			Vector4f vect3 = vect1 + vect2;

			Assert::AreEqual(vect3[0], vect1[0] + vect2[0]);
			Assert::AreEqual(vect3[1], vect1[1] + vect2[1]);
			Assert::AreEqual(vect3[2], vect1[2] + vect2[2]);
			Assert::AreEqual(vect3[3], vect1[3] + vect2[3]);
		}

		TEST_METHOD(ShouldAddVectorToThis)
		{
			Vector4f vect1(1.0f, 2.0f, 3.0f, 4.0f);
			Vector4f vect2(5.0f, 6.0f, 7.0f, 8.0f);
			Vector4f vect3(vect1); // store this vector in vect3
			vect1 += vect2;

			Assert::AreEqual(vect1[0], vect3[0] + vect2[0]);
			Assert::AreEqual(vect1[1], vect3[1] + vect2[1]);
			Assert::AreEqual(vect1[2], vect3[2] + vect2[2]);
			Assert::AreEqual(vect1[3], vect3[3] + vect2[3]);
		}

		TEST_METHOD(ShouldSubVectors)
		{
			Vector4f vect1(1.0f, 2.0f, 3.0f, 4.0f);
			Vector4f vect2(5.0f, 6.0f, 7.0f, 8.0f);
			Vector4f vect3 = vect1 - vect2;

			Assert::AreEqual(vect3[0], vect1[0] - vect2[0]);
			Assert::AreEqual(vect3[1], vect1[1] - vect2[1]);
			Assert::AreEqual(vect3[2], vect1[2] - vect2[2]);
			Assert::AreEqual(vect3[3], vect1[3] - vect2[3]);
		}

		TEST_METHOD(ShouldSubVectorFromThis)
		{
			Vector4f vect1(1.0f, 2.0f, 3.0f, 4.0f);
			Vector4f vect2(5.0f, 6.0f, 7.0f, 8.0f);
			Vector4f vect3(vect1); // store this vector in vect3
			vect1 -= vect2;

			Assert::AreEqual(vect1[0], vect3[0] - vect2[0]);
			Assert::AreEqual(vect1[1], vect3[1] - vect2[1]);
			Assert::AreEqual(vect1[2], vect3[2] - vect2[2]);
			Assert::AreEqual(vect1[3], vect3[3] - vect2[3]);
		}

		TEST_METHOD(ShouldMultVectorWithScalar)
		{
			Vector4f vect1(1.0f, 2.0f, 3.0f, 4.0f);
			float k = 2.0f;
			Vector4f vect2(vect1 * k);

			Assert::AreEqual(vect2[0], vect1[0] * k);
			Assert::AreEqual(vect2[1], vect1[1] * k);
			Assert::AreEqual(vect2[2], vect1[2] * k);
			Assert::AreEqual(vect2[3], vect1[3] * k);
		}

		TEST_METHOD(ShouldDivVectorByScalar)
		{
			Vector4f vect1(1.0f, 2.0f, 3.0f, 4.0f);
			float k = 2.0f;
			Vector4f vect2(vect1 / k);

			Assert::AreEqual(vect2[0], vect1[0] / k);
			Assert::AreEqual(vect2[1], vect1[1] / k);
			Assert::AreEqual(vect2[2], vect1[2] / k);
			Assert::AreEqual(vect2[3], vect1[3] / k);
		}

		TEST_METHOD(ShouldThrowWhen_DivVectorBy0)
		{
			auto func_div_by_0 = []()
			{
				Vector4f vect1(1.0f, 2.0f, 3.0f, 4.0f);
				Vector4f vect2(vect1 / 0.0f);
			};

			Assert::ExpectException<std::invalid_argument>(func_div_by_0);
		}

		TEST_METHOD(ShouldBeSize4)
		{
			Vector4f vect;

			Assert::AreEqual(vect.size(), (size_t)4);
		}

		TEST_METHOD(ShouldThrowWhen_WrongIndexRequested)
		{
			auto func_greater_than_3 = []()
			{
				Vector4f vect;
				float el = vect[4];
			};

			auto func_less_than_0 = []()
			{
				Vector4f vect;
				float el = vect[-1];
			};

			Assert::ExpectException<std::invalid_argument>(func_greater_than_3);
			Assert::ExpectException<std::invalid_argument>(func_less_than_0);
		}
	};
}