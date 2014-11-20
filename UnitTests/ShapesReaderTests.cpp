#include "CppUnitTest.h"

#include <Controller/ShapesReader.h>
#include <Model/Point.h>
#include <Model/Triangle.h>
#include <Model/Rectangle.h>

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <typeinfo>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry;

namespace UnitTests
{
	TEST_CLASS(ShapesReaderTests)
	{
	public:

		TEST_METHOD(ShouldFalseWhenNotIsOpen)
		{
			ShapesReader reader("");
			Assert::IsFalse(reader.read());
		}

		TEST_METHOD(ShouldFalseWhenEmptyFile)
		{
			ShapesReader reader("..\\UnitTests\\EmptyFile.txt");
			Assert::IsFalse(reader.read());
		}

		TEST_METHOD(ShouldFalseWhenIncompleteTriangle)
		{
			ShapesReader reader("..\\UnitTests\\IncompleteTriangle.txt");
			Assert::IsFalse(reader.read());
		}

		TEST_METHOD(ShouldFalseWhenIncompleteRectangle)
		{
			ShapesReader reader("..\\UnitTests\\IncompleteRectangle.txt");
			Assert::IsFalse(reader.read());
		}

		TEST_METHOD(ShouldFalseWhenUnknownShape)
		{
			ShapesReader reader("..\\UnitTests\\UnknownShape.txt");
			Assert::IsFalse(reader.read());
		}

		TEST_METHOD(ShouldFalseWhenInvalidVertices)
		{
			ShapesReader reader("..\\UnitTests\\WrongTriangleVertices.txt");
			Assert::IsFalse(reader.read());
		}

		TEST_METHOD(ShouldTrueWhenGoodShapes)
		{
			ShapesReader reader("..\\UnitTests\\GoodShapes.txt");
			Assert::IsTrue(reader.read());
		}

		TEST_METHOD(ShouldReturnAllShapes)
		{
			ShapesReader reader("..\\UnitTests\\GoodShapes.txt");
			reader.read();

			auto &shapes = reader.getShapes();
			Assert::AreEqual(shapes.size(), (size_t)2);

			Geometry::IShape *tr = shapes.front().get();
			auto vertices_tr = tr->getVertices();
			Assert::IsTrue(vertices_tr[0] == Point(0.3f, 0.1f, 0.02f));
			Assert::IsTrue(vertices_tr[1] == Point(0.2f, 0.3f, 0.5f));
			Assert::IsTrue(vertices_tr[2] == Point(0.4f, 0.1f, 0.7f));
			
			auto color_tr = tr->getColor();
			Assert::IsTrue(color_tr == Math::Vector4f(0.1f, 0.4f, 0.5f, 1.0f));


			Geometry::IShape *rc = shapes.back().get();
			auto vertices_rc = rc->getVertices();
			Assert::IsTrue(vertices_rc[0] == Point(0.2f, 0.3f, 0.5f));
			Assert::IsTrue(vertices_rc[5] == Point(0.4f, 0.1f, 0.7f));

			auto color_rc = rc->getColor();
			Assert::IsTrue(color_rc == Math::Vector4f(0.1f, 0.2f, 0.3f, 1.0f));
		}

	};
}