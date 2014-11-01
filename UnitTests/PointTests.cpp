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
			Assert::IsTrue(Point(23, 42) == Point(23, 42));
			Assert::IsFalse(Point(15, 42) == Point(-23, 5));
			Assert::IsFalse(Point(15, 42) == Point(15, 5));
			Assert::IsFalse(Point(15, 42) == Point(23, 42));
		}

		TEST_METHOD(ShouldBeZeroPointWhenDefaultCtor)
		{
			Point pt;

			Assert::AreEqual(pt.x, 0);
			Assert::AreEqual(pt.y, 0);
		}

		TEST_METHOD(ShouldSetPointXY)
		{
			int x = -23;
			int y = 42;
			Point pt(x, y);

			Assert::AreEqual(pt.x, x);
			Assert::AreEqual(pt.y, y);
		}

		TEST_METHOD(ShouldCopyPoint)
		{
			int x = -23;
			int y = 42;
			Point pt1(x, y);
			Point pt2(pt1);

			Assert::IsTrue(pt1 == pt2);
		}

	};
}