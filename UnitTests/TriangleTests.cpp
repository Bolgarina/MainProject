#include "CppUnitTest.h"

#include <Model/Point.h>
#include <Model/Triangle.h>
#include <Mathematics/Vector4f.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry;

namespace UnitTests
{
	TEST_CLASS(TriangleTests)
	{
	public:

		TEST_METHOD(ShouldBe_0_0_0__1_0_0__0_1_0_BlackTriangleWhenDefaultCtor)
		{
			Triangle tr;
			Math::Vector4f color = tr.getColor();

			Assert::IsTrue(tr.getVertices()[0] == Point(0.0f, 0.0f, 0.0f));
			Assert::IsTrue(tr.getVertices()[1] == Point(1.0f, 0.0f, 0.0f));
			Assert::IsTrue(tr.getVertices()[2] == Point(0.0f, 1.0f, 0.0f));
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == Color());
		}

		TEST_METHOD(ShouldSetBlackTriangleVertices)
		{
			Point vertices[3] = { Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(7.0f, 8.0f, 9.0f) };
			
			Triangle tr(vertices[0], vertices[1], vertices[2]);
			Math::Vector4f color = tr.getColor();

			Assert::IsTrue(tr.getVertices()[0] == vertices[0]);
			Assert::IsTrue(tr.getVertices()[1] == vertices[1]);
			Assert::IsTrue(tr.getVertices()[2] == vertices[2]);
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == Color());
		}

		TEST_METHOD(ShouldSetTriangleVerticesColor)
		{
			Point vertices[3] = { Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(7.0f, 8.0f, 9.0f) };
			Color cl(0.1f, 0.2f, 0.3f, 0.4f);

			Triangle tr(vertices[0], vertices[1], vertices[2], cl);
			Math::Vector4f color = tr.getColor();

			Assert::IsTrue(tr.getVertices()[0] == vertices[0]);
			Assert::IsTrue(tr.getVertices()[1] == vertices[1]);
			Assert::IsTrue(tr.getVertices()[2] == vertices[2]);
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == cl);
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

		TEST_METHOD(ShouldCopyBlackTriangle)
		{
			Triangle tr1(Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(7.0f, 8.0f, 9.0f));
			Triangle tr2(tr1);
			Math::Vector4f color = tr2.getColor();

			Assert::IsTrue(tr1.getVertices()[0] == tr2.getVertices()[0]);
			Assert::IsTrue(tr1.getVertices()[1] == tr2.getVertices()[1]);
			Assert::IsTrue(tr1.getVertices()[2] == tr2.getVertices()[2]);
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == Color());
		}

		TEST_METHOD(ShouldCopyTriangle)
		{
			Color cl(0.1f, 0.2f, 0.3f, 0.4f);
			Triangle tr1(Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(7.0f, 8.0f, 9.0f), cl);
			Triangle tr2(tr1);
			Math::Vector4f color = tr2.getColor();

			Assert::IsTrue(tr1.getVertices()[0] == tr2.getVertices()[0]);
			Assert::IsTrue(tr1.getVertices()[1] == tr2.getVertices()[1]);
			Assert::IsTrue(tr1.getVertices()[2] == tr2.getVertices()[2]);
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == cl);
		}

		TEST_METHOD(ShouldBeName_triangle)
		{
			Assert::AreEqual(Triangle::name().c_str(), "triangle");
		}

		TEST_METHOD(ShouldBe_1_2_3__4_5_6__7_8_9)
		{
			Point vertices[3] = { Point(1.0f, 2.0f, 3.0f), Point(4.0f, 5.0f, 6.0f), Point(7.0f, 8.0f, 9.0f) };
			Triangle tr;
			tr.setVertex(0, vertices[0]);
			tr.setVertex(1, vertices[1]);
			tr.setVertex(2, vertices[2]);

			Assert::IsTrue(tr.getVertices()[0] == vertices[0]);
			Assert::IsTrue(tr.getVertices()[1] == vertices[1]);
			Assert::IsTrue(tr.getVertices()[2] == vertices[2]);
		}

		TEST_METHOD(ShouldThrowWhen_WrongVertexIndex)
		{			
			auto func_greater_than_2 = []()
			{
				Triangle tr;
				tr.setVertex(3, Point());
			};

			auto func_less_than_0 = []()
			{
				Triangle tr;
				tr.setVertex(-1, Point());
			};

			Assert::ExpectException<std::invalid_argument>(func_greater_than_2);
			Assert::ExpectException<std::invalid_argument>(func_less_than_0);
		}

		TEST_METHOD(ShouldBeTriangleCentroid_0_0_0)
		{
			Triangle tr(Point(-1.0f, -1.0f, 1.0f), Point(1.0f, -1.0f, -1.0f), Point(0.0f, 2.0f, 0.0f));
			Point centr = tr.getCentroid();

			Assert::IsTrue(centr == Point());
		}

		TEST_METHOD(ShouldBeTriangleColor)
		{
			Color cl(1.0f, 2.0f, 3.0f, 4.0f);
			Triangle tr(Point(-1.0f, -1.0f, 1.0f), Point(1.0f, -1.0f, -1.0f), Point(0.0f, 2.0f, 0.0f), cl);

			Math::Vector4f color = tr.getColor();
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == cl);
		}

	};
}