#include "CppUnitTest.h"

#include <Model/Color.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry;

namespace UnitTests
{

	TEST_CLASS(ColorTests)
	{
	public:

		TEST_METHOD(ShouldBeEqualColors)
		{
			Assert::IsTrue(Color(0.5f, 0.6f, 0.7f, 0.8f) == Color(0.5f, 0.6f, 0.7f, 0.8f));

			Assert::IsFalse(Color(0.1f, 0.2f, 0.3f, 0.4f) == Color(0.5f, 0.6f, 0.7f, 0.8f)); // r, g, b, alpha are different

			Assert::IsFalse(Color(0.1f, 0.2f, 0.3f, 1.0f) == Color(0.5f, 0.6f, 0.7f, 1.0f)); // r, g, b are different
			Assert::IsFalse(Color(0.1f, 0.2f, 1.0f, 0.4f) == Color(0.5f, 0.6f, 1.0f, 0.8f)); // r, g, alpha are different
			Assert::IsFalse(Color(0.1f, 1.0f, 0.3f, 0.4f) == Color(0.5f, 1.0f, 0.7f, 0.8f)); // r, b, alpha are different
			Assert::IsFalse(Color(1.0f, 0.2f, 0.3f, 0.4f) == Color(1.0f, 0.6f, 0.7f, 0.8f)); // g, b, alpha are different

			Assert::IsFalse(Color(0.1f, 0.2f, 0.9f, 1.0f) == Color(0.5f, 0.6f, 0.9f, 1.0f)); // r, g are different
			Assert::IsFalse(Color(0.1f, 0.9f, 0.3f, 1.0f) == Color(0.5f, 0.9f, 0.7f, 1.0f)); // r, b are different
			Assert::IsFalse(Color(0.1f, 0.9f, 1.0f, 0.4f) == Color(0.5f, 0.9f, 1.0f, 0.8f)); // r, alpha are different
			Assert::IsFalse(Color(0.9f, 0.2f, 0.3f, 1.0f) == Color(0.9f, 0.6f, 0.7f, 1.0f)); // g, b are different
			Assert::IsFalse(Color(0.9f, 0.2f, 1.0f, 0.4f) == Color(0.9f, 0.6f, 1.0f, 0.8f)); // g, alpha are different
			Assert::IsFalse(Color(0.9f, 1.0f, 0.3f, 0.4f) == Color(0.9f, 1.0f, 0.7f, 0.8f)); // b, alpha are different

			Assert::IsFalse(Color(1.0f, 0.6f, 0.7f, 0.8f) == Color(0.5f, 0.6f, 0.7f, 0.8f)); // r is different
			Assert::IsFalse(Color(0.5f, 1.0f, 0.7f, 0.8f) == Color(0.5f, 0.6f, 0.7f, 0.8f)); // g is different
			Assert::IsFalse(Color(0.5f, 0.6f, 1.0f, 0.8f) == Color(0.5f, 0.6f, 0.7f, 0.8f)); // b is different
			Assert::IsFalse(Color(0.5f, 0.6f, 0.7f, 1.0f) == Color(0.5f, 0.6f, 0.7f, 0.8f)); // alpha is different
		}

		TEST_METHOD(ShouldBeBlackColorWhenDefaultCtor)
		{
			Color color;

			Assert::AreEqual(color.r, 1.0f);
			Assert::AreEqual(color.g, 1.0f);
			Assert::AreEqual(color.b, 1.0f);
			Assert::AreEqual(color.alpha, 1.0f);
		}

		TEST_METHOD(ShouldSetColorRGB1)
		{
			float r = 0.0f;
			float g = 0.1f;
			float b = 0.2f;
			Color color(r, g, b);

			Assert::AreEqual(color.r, r);
			Assert::AreEqual(color.g, g);
			Assert::AreEqual(color.b, b);
			Assert::AreEqual(color.alpha, 1.0f);
		}

		TEST_METHOD(ShouldSetColorRGBA)
		{
			float r = 0.0f;
			float g = 0.1f;
			float b = 0.2f;
			float alpha = 0.3f;
			Color color(r, g, b, alpha);

			Assert::AreEqual(color.r, r);
			Assert::AreEqual(color.g, g);
			Assert::AreEqual(color.b, b);
			Assert::AreEqual(color.alpha, alpha);
		}

		TEST_METHOD(ShouldCopyColor)
		{
			float r = 0.0f;
			float g = 0.1f;
			float b = 0.2f;
			float alpha = 0.3f;
			Color color1(r, g, b, alpha);
			Color color2(color1);

			Assert::IsTrue(color1 == color2);
		}

	};
}