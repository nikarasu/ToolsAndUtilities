#include "pch.h"
#include "CppUnitTest.h"
#include "Vector2.h"
#include "assert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	namespace Vector2

	{
		TEST_CLASS(UnitTests)
		{
		public:

			TEST_METHOD(createDefaultVector2Int)
			{
				Math::Vector2<int> test;

				assert(test.x == 0 && test.y == 0);
			}

			TEST_METHOD(createVector2IntWithParameters)
			{
				Math::Vector2<int> test(10, 502);

				assert(test.x == 10 && test.y == 502);
			}

			TEST_METHOD(assignToVector2)
			{
				Math::Vector2<int> vec1;
				Math::Vector2<int> vec2(10, 11);

				assert(vec1.x == 0 && vec1.y == 0);

				vec1 = vec2;

				assert(vec1.x = 10 && vec1.y == 11);
			}

			TEST_METHOD()
		};
	}
}