#include "CppUnitTest.h"

#include <Model/Point.h>
#include <Model/Color.h>
#include <Model/Rectangle.h>

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry;

namespace UnitTests
{
	TEST_CLASS(RectangleTests)
	{
	public:

		TEST_METHOD(ShouldBeIdentityBlackSquareWhenDefaultCtor)
		{
			Rectangle rect;
			std::vector<float> color = rect.getColor();

			Assert::IsTrue(rect.getLeftBottomVertex() == Point());
			Assert::IsTrue(rect.getRightTopVertex() == Point(1.0f, 1.0f, 0.0f));
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == Color());
		}

		TEST_METHOD(ShouldSetBlackRectangle2DiagElements)
		{
			Point pt_left_bottom(-5.0f, 7.0f, 10.0f);
			Point pt_right_top(13.0f, 22.0f, 16.0f);

			Rectangle rect(pt_left_bottom, pt_right_top);
			std::vector<float> color = rect.getColor();

			Assert::IsTrue(rect.getLeftBottomVertex() == pt_left_bottom);
			Assert::IsTrue(rect.getRightTopVertex() == pt_right_top);
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == Color());
		}

		TEST_METHOD(ShouldSetRectangle2DiagElementsColor)
		{
			Point pt_left_bottom(-5.0f, 7.0f, 10.0f);
			Point pt_right_top(13.0f, 22.0f, 16.0f);
			Color cl(0.1f, 0.2f, 0.3f, 0.4f);

			Rectangle rect(pt_left_bottom, pt_right_top, cl);
			std::vector<float> color = rect.getColor();

			Assert::IsTrue(rect.getLeftBottomVertex() == pt_left_bottom);
			Assert::IsTrue(rect.getRightTopVertex() == pt_right_top);
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == cl);
		}

		TEST_METHOD(ShouldThrowWhenDegenerateRectangle)
		{
			auto func_x_line = []()
			{
				Rectangle(Point(1.0f, 2.0f, 3.0f), Point(5.0f, 2.0f, 3.0f));
			};

			auto func_y_line = []()
			{
				Rectangle(Point(1.0f, 2.0f, 3.0f), Point(1.0f, 6.0f, 3.0f));
			};

			auto func_z_line = []()
			{
				Rectangle(Point(1.0f, 2.0f, 3.0f), Point(1.0f, 2.0f, 7.0f));
			};

			auto func_point = []()
			{
				Rectangle(Point(1.0f, 2.0f, 3.0f), Point(1.0f, 2.0f, 3.0f));
			};

			Assert::ExpectException<std::logic_error>(func_x_line);
			Assert::ExpectException<std::logic_error>(func_y_line);
			Assert::ExpectException<std::logic_error>(func_z_line);
			Assert::ExpectException<std::logic_error>(func_point);
		}

		TEST_METHOD(ShouldCopyBlackRectangle) // if the color is not set, it is black by default
		{
			Rectangle rect1(Point(-23.0f, 42.0f, 10.0f), Point(13.0f, 22.0f, 16.0f));
			Rectangle rect2(rect1);

			std::vector<float> color = rect2.getColor();

			Assert::IsTrue(rect2.getLeftBottomVertex() == rect1.getLeftBottomVertex());
			Assert::IsTrue(rect2.getRightTopVertex() == rect1.getRightTopVertex());
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == Color());
		}

		TEST_METHOD(ShouldCopyRectangle)
		{
			Color cl(1.0f, 2.0f, 3.0f, 4.0f);

			Rectangle rect1(Point(-23.0f, 42.0f, 10.0f), Point(13.0f, 22.0f, 16.0f), cl);
			Rectangle rect2(rect1);

			std::vector<float> color = rect2.getColor();

			Assert::IsTrue(rect2.getLeftBottomVertex() == rect1.getLeftBottomVertex());
			Assert::IsTrue(rect2.getRightTopVertex() == rect1.getRightTopVertex());
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == cl);
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
			Point pt_left_bottom(23.0f, 42.0f, 10.0f);
			Rectangle rect;
			rect.setLeftBottomVertex(pt_left_bottom);

			Assert::IsTrue(rect.getLeftBottomVertex() == pt_left_bottom);
		}

		TEST_METHOD(ShouldBeRightTopVertex_13_22_16)
		{
			Point pt_right_top(13.0f, 22.0f, 16.0f);
			Rectangle rect;
			rect.setRightTopVertex(pt_right_top);

			Assert::IsTrue(rect.getRightTopVertex() == pt_right_top);
		}

		TEST_METHOD(ShouldBeRectangleVertices)
		{
			Point left_bottom_vertex(-3.0f, -2.0f, -1.0f);
			Point left_top_vertex(left_bottom_vertex);   left_top_vertex.y *= (-1.0f);
			Point right_top_vertex(3.0f, 2.0f, 1.0f);
			Point right_bottom_vertex(right_top_vertex); right_bottom_vertex.y *= (-1.0f);
			Rectangle rect(left_bottom_vertex, right_top_vertex);
			std::vector<Point> vertices = rect.getVertices();

			for (auto it = vertices.begin(); it != vertices.end(); it++)
				Assert::IsTrue(*it == left_bottom_vertex || *it == left_top_vertex || *it == right_top_vertex || *it == right_bottom_vertex);
		}

		TEST_METHOD(ShouldBeRectangleCentroid_0_0_0)
		{
			Rectangle rect(Point(-3.0f, -2.0f, -1.0f), Point(3.0f, 2.0f, 1.0f));
			Point centr = rect.getCentroid();

			Assert::IsTrue(centr == Point());
		}

		TEST_METHOD(ShouldBeRectangleColor)
		{
			Color cl(1.0f, 2.0f, 3.0f, 4.0f);
			Rectangle rect(Point(-3.0f, -2.0f, -1.0f), Point(3.0f, 2.0f, 1.0f), cl);

			std::vector<float> color = rect.getColor();
			Assert::IsTrue(Color(color[0], color[1], color[2], color[3]) == cl);
		}

	};
}