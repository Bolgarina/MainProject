#include "CppUnitTest.h"

#include <Model/Point.h>
#include <Model/Rectangle.h>
#include <Model/Transformation.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(RectangleTests)
	{
	public:

		TEST_METHOD(ShouldBeIdentitySquareWhenDefaultCtor)
		{
			Rectangle rect;

			Assert::IsTrue(rect.getOrigin() == Point());
			Assert::AreEqual(rect.getHeight(), (size_t)1);
			Assert::AreEqual(rect.getWidth(), (size_t)1);
		}

		TEST_METHOD(ShouldSetRectangleOriginWidthHeight)
		{
			Point pt_origin(-23, 42);
			size_t width = 10;
			size_t height = 16;

			Rectangle rect(pt_origin, width, height);

			Assert::IsTrue(rect.getOrigin() == pt_origin);
			Assert::AreEqual(rect.getWidth(), width);
			Assert::AreEqual(rect.getHeight(), height);
		}

		TEST_METHOD(ShouldThrowWhen_0_Side)
		{
			auto func_0_0 = []()
			{
				Rectangle(Point(1, 2), 0, 0);
			};

			auto func_0_1 = []()
			{
				Rectangle(Point(1, 2), 0, 1);
			};

			auto func_1_0 = []()
			{
				Rectangle(Point(1, 2), 1, 0);
			};

			Assert::ExpectException<std::logic_error>(func_0_0);
			Assert::ExpectException<std::logic_error>(func_0_1);
			Assert::ExpectException<std::logic_error>(func_1_0);
		}

		TEST_METHOD(ShouldCopySquare)
		{
			Rectangle rect1(Point(-23, 42), 10, 16);
			Rectangle rect2(rect1);

			Assert::IsTrue(rect2.getOrigin() == rect1.getOrigin());
			Assert::AreEqual(rect2.getWidth(), rect1.getWidth());
			Assert::AreEqual(rect2.getHeight(), rect1.getHeight());
		}

		TEST_METHOD(ShouldBeName_square)
		{
			Assert::AreEqual(Rectangle::name().c_str(), "rectangle");
		}

		TEST_METHOD(ShoulThrowWhenITransformationNullptr)
		{
			auto func = []
			{
				Rectangle rect;
				Transformation* transform(nullptr);
				rect.accept(transform);
			};

			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(ShouldBeOrigin_23_42)
		{
			Point pt_origin(23, 42);
			Rectangle sq(pt_origin, 10, 16);

			Assert::IsTrue(sq.getOrigin() == pt_origin);
		}

		TEST_METHOD(ShouldBeWidth_10)
		{
			size_t width = 10;
			Rectangle rect(Point(23, 42), width, 16);

			Assert::AreEqual(rect.getWidth(), width);
		}

		TEST_METHOD(ShouldBeHeight_16)
		{
			size_t height = 16;
			Rectangle rect(Point(23, 42), 10, height);

			Assert::AreEqual(rect.getHeight(), height);
		}

	};
}