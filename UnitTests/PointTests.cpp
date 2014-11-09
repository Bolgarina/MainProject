#include "CppUnitTest.h"

#include <Model/Point.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry;

namespace UnitTests
{

	TEST_CLASS(PointTests)
	{
	public:

		TEST_METHOD(ShouldBeEqual)
		{
			Assert::IsTrue(Point(23.0f, 42.0f, 10.0f) == Point(23.0f, 42.0f, 10.0f));
			Assert::IsFalse(Point(15.0f, 42.0f, 10.0f) == Point(-23.0f, 5.0f, 8.0f)); // all are different
			Assert::IsFalse(Point(15.0f, 42.0f, 10.0f) == Point(-23.0f, 5.0f, 10.0f)); // x and y are different
			Assert::IsFalse(Point(15.0f, 42.0f, 10.0f) == Point(-23.0f, 5.0f, 8.0f)); // x and z are different
			Assert::IsFalse(Point(15.0f, 42.0f, 10.0f) == Point(15.0f, 5.0f, 8.0f)); // y and z are different
			Assert::IsFalse(Point(15.0f, 42.0f, 10.0f) == Point(23.0f, 42.0f, 10.0f)); // x is different
			Assert::IsFalse(Point(15.0f, 42.0f, 10.0f) == Point(15.0f, 5.0f, 10.0f)); // y is different
			Assert::IsFalse(Point(15.0f, 42.0f, 10.0f) == Point(15.0f, 42.0f, 8.0f)); // z is different
		}

		TEST_METHOD(ShouldBeZeroPointWhenDefaultCtor)
		{
			Point pt;

			Assert::AreEqual(pt.x, 0.0f);
			Assert::AreEqual(pt.y, 0.0f);
			Assert::AreEqual(pt.z, 0.0f);
		}

		TEST_METHOD(ShouldSetPointXYZ)
		{
			float x = -23.0f;
			float y = 42.0f;
			float z = 10.0f;
			Point pt(x, y, z);

			Assert::AreEqual(pt.x, x);
			Assert::AreEqual(pt.y, y);
			Assert::AreEqual(pt.z, z);
		}

		TEST_METHOD(ShouldCopyPoint)
		{
			float x = -23.0f;
			float y = 42.0f;
			float z = 10.0f;
			Point pt1(x, y, z);
			Point pt2(pt1);

			Assert::IsTrue(pt1 == pt2);
		}

	};
}