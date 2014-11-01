#include "CppUnitTest.h"

#include <Model/Rectangle.h>
#include <Model/Transformation.h>
#include <Model/Triangle.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry;

namespace UnitTests
{
	TEST_CLASS(TriangleTests)
	{
	public:

		TEST_METHOD(ShouldThrowWhenTriangleNullptr)
		{
			auto func = []
			{
				Transformation transform;
				Triangle* tr(nullptr);
				transform.visit(tr);
			};

			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(ShouldThrowWhenRectangleNullptr)
		{
			auto func = []
			{
				Transformation transform;
				Rectangle* rect(nullptr);
				transform.visit(rect);
			};

			Assert::ExpectException<std::runtime_error>(func);
		}
	};
}