#include "CppUnitTest.h"

#include <Model/Point.h>
#include <Model/Triangle.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry;

namespace UnitTests
{
	TEST_CLASS(TriangleTests)
	{
	public:

		TEST_METHOD(ShouldBe_0_0_0__1_0_0__0_1_0_TriangleWhenDefaultCtor)
		{
			Triangle tr;

			Assert::IsTrue(tr.getVertices()[0] == Point(0.0f, 0.0f, 0.0f));
			Assert::IsTrue(tr.getVertices()[1] == Point(1.0f, 0.0f, 0.0f));
			Assert::IsTrue(tr.getVertices()[2] == Point(0.0f, 1.0f, 0.0f));
		}

		TEST_METHOD(ShouldSetTriangleVertices)
		{
			Point vertices[3] = { Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(7.0f, 8.0f, 9.0f) };
			Triangle tr(vertices[0], vertices[1], vertices[2]);

			Assert::IsTrue(tr.getVertices()[0] == vertices[0]);
			Assert::IsTrue(tr.getVertices()[1] == vertices[1]);
			Assert::IsTrue(tr.getVertices()[2] == vertices[2]);
		}

		TEST_METHOD(ShouldThrowWhen_EqualVertices)
		{
			auto func_v1v2equal = []()
			{
				Triangle(Point(1.0f, 2.0f, 3.0f), Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f));
			};

			auto func_v1v3equal = []()
			{
				Triangle(Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(1.0f, 2.0f, 3.0f));
			};

			auto func_v2v3equal = []()
			{
				Triangle(Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(4.0f, 5.0f, 6.0f));
			};

			Assert::ExpectException<std::logic_error>(func_v1v2equal);
			Assert::ExpectException<std::logic_error>(func_v1v3equal);
			Assert::ExpectException<std::logic_error>(func_v2v3equal);
		}

		TEST_METHOD(ShouldCopyTriangle)
		{
			Triangle tr1(Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(7.0f, 8.0f, 9.0f));
			Triangle tr2(tr1);

			Assert::IsTrue(tr1.getVertices()[0] == tr2.getVertices()[0]);
			Assert::IsTrue(tr1.getVertices()[1] == tr2.getVertices()[1]);
			Assert::IsTrue(tr1.getVertices()[2] == tr2.getVertices()[2]);
		}

		TEST_METHOD(ShouldBeName_triangle)
		{
			Assert::AreEqual(Triangle::name().c_str(), "triangle");
		}

		TEST_METHOD(ShouldReturn_1_2_3__4_5_6__7_8_9)
		{
			Point vertices[3] = { Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(7.0f, 8.0f, 9.0f) };
			Triangle tr(vertices[0], vertices[1], vertices[2]);

			Assert::IsTrue(tr.getVertices()[0] == vertices[0]);
			Assert::IsTrue(tr.getVertices()[1] == vertices[1]);
			Assert::IsTrue(tr.getVertices()[2] == vertices[2]);
		}

	};
}