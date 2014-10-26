#include "CppUnitTest.h"

#include <Model/Point.h>
#include <Model/Transformation.h>
#include <Model/Triangle.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TriangleTests)
	{
	public:

		TEST_METHOD(ShouldBe_0_0__1_0__0_1_TriangleWhenDefaultCtor)
		{
			Triangle tr;

			Assert::IsTrue(tr.getVertices()[0] == Point(0, 0));
			Assert::IsTrue(tr.getVertices()[1] == Point(1, 0));
			Assert::IsTrue(tr.getVertices()[2] == Point(0, 1));
		}

		TEST_METHOD(ShouldSetTriangleVertices)
		{
			Point vertices[3] = { Point(1, 2), Point(3, 4), Point(5, 6) };
			Triangle tr(vertices[0], vertices[1], vertices[2]);

			Assert::IsTrue(tr.getVertices()[0] == vertices[0]);
			Assert::IsTrue(tr.getVertices()[1] == vertices[1]);
			Assert::IsTrue(tr.getVertices()[2] == vertices[2]);
		}

		TEST_METHOD(ShouldThrowWhen_EqualVertices)
		{
			auto func_v1v2equal = []()
			{
				Triangle(Point(1, 2), Point(1, 2), Point(5, 6));
			};

			auto func_v1v3equal = []()
			{
				Triangle(Point(1, 2), Point(3, 4), Point(1, 2));
			};

			auto func_v2v3equal = []()
			{
				Triangle(Point(1, 2), Point(3, 4), Point(3, 4));
			};

			Assert::ExpectException<std::logic_error>(func_v1v2equal);
			Assert::ExpectException<std::logic_error>(func_v1v3equal);
			Assert::ExpectException<std::logic_error>(func_v2v3equal);
		}

		TEST_METHOD(ShouldCopyTriangle)
		{
			Triangle tr1(Point(1, 2), Point(3, 4), Point(5, 6));
			Triangle tr2(tr1);

			Assert::IsTrue(tr1.getVertices()[0] == tr2.getVertices()[0]);
			Assert::IsTrue(tr1.getVertices()[1] == tr2.getVertices()[1]);
			Assert::IsTrue(tr1.getVertices()[2] == tr2.getVertices()[2]);
		}

		TEST_METHOD(ShouldBeName_triangle)
		{
			Assert::AreEqual(Triangle::name().c_str(), "triangle");
		}

		TEST_METHOD(ShoulThrowWhenITransformationNullptr)
		{
			auto func = []
			{
				Triangle rect;
				Transformation* transform(nullptr);
				rect.accept(transform);
			};

			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(ShouldReturn_1_2__3_4__5_6)
		{
			Point vertices[3] = { Point(1, 2), Point(3, 4), Point(5, 6) };
			Triangle tr(vertices[0], vertices[1], vertices[2]);

			Assert::IsTrue(tr.getVertices()[0] == vertices[0]);
			Assert::IsTrue(tr.getVertices()[1] == vertices[1]);
			Assert::IsTrue(tr.getVertices()[2] == vertices[2]);
		}

	};
}