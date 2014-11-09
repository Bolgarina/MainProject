#include "CppUnitTest.h"

#include <Model/Point.h>
#include <Model/Rectangle.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry;

namespace UnitTests
{
	TEST_CLASS(RectangleTests)
	{
	public:

		TEST_METHOD(ShouldBeIdentitySquareWhenDefaultCtor)
		{
			Rectangle rect;

			Assert::IsTrue(rect.getLeftBottomVertex() == Point());
			Assert::IsTrue(rect.getRightTopVertex() == Point(1.0f, 1.0f, 0.0f));
		}

		TEST_METHOD(ShouldSetRectangle2DiagElements)
		{
			Point pt_left_bottom(-5, 7, 10);
			Point pt_right_top(13, 22, 16);

			Rectangle rect(pt_left_bottom, pt_right_top);

			Assert::IsTrue(rect.getLeftBottomVertex() == pt_left_bottom);
			Assert::IsTrue(rect.getRightTopVertex() == pt_right_top);
		}

		//TEST_METHOD(ShouldThrowWhen_0_Side)
		//{
		//	auto func_0_0 = []()
		//	{
		//		Rectangle(Point(1, 2), 0, 0);
		//	};

		//	auto func_0_1 = []()
		//	{
		//		Rectangle(Point(1, 2), 0, 1);
		//	};

		//	auto func_1_0 = []()
		//	{
		//		Rectangle(Point(1, 2), 1, 0);
		//	};

		//	Assert::ExpectException<std::logic_error>(func_0_0);
		//	Assert::ExpectException<std::logic_error>(func_0_1);
		//	Assert::ExpectException<std::logic_error>(func_1_0);
		//}

		TEST_METHOD(ShouldCopySquare)
		{
			Rectangle rect1(Point(-23, 42, 10), Point(13, 22, 16));
			Rectangle rect2(rect1);

			Assert::IsTrue(rect2.getLeftBottomVertex() == rect1.getLeftBottomVertex());
			Assert::IsTrue(rect2.getRightTopVertex() == rect1.getRightTopVertex());
		}

		TEST_METHOD(ShouldBeName_rectangle)
		{
			Assert::AreEqual(Rectangle::name().c_str(), "rectangle");
		}

		//TEST_METHOD(ShoulThrowWhenITransformationNullptr)
		//{
		//	auto func = []
		//	{
		//		Rectangle rect;
		//		Transformation* transform(nullptr);
		//		rect.accept(transform);
		//	};

		//	Assert::ExpectException<std::runtime_error>(func);
		//}

		TEST_METHOD(ShouldBeLeftBottomVertex_23_42_10)
		{
			Point pt_left_bottom(23, 42, 10);
			Rectangle rect(pt_left_bottom, Point(13, 22, 16));

			Assert::IsTrue(rect.getLeftBottomVertex() == pt_left_bottom);
		}

		TEST_METHOD(ShouldBeRightTopVertex_13_22_16)
		{
			Point pt_right_top(13, 22, 16);
			Rectangle rect(Point(23, 42, 10), pt_right_top);

			Assert::IsTrue(rect.getRightTopVertex() == pt_right_top);
		}

	};
}