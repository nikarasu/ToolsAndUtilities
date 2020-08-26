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

				assert(vec1.x == 10 && vec1.y == 11);
			}


			TEST_METHOD(AddVectorIntToVectorInt)
			{
				Math::Vector2<int> vec1(7, 23);
				Math::Vector2<int> vec2(10, 11);

				Math::Vector2<int> vec3 = vec1 + vec2;

				assert(vec3.x == 17 && vec3.y == 34);
			}

			TEST_METHOD(PlusEqualVectorIntToVectorInt)
			{
				Math::Vector2<int> vec1(7, 23);
				Math::Vector2<int> vec2(10, 11);

				vec1 += vec2;

				assert(vec1.x == 17 && vec1.y == 34);
			}

			TEST_METHOD(SubtractVectorIntToVectorInt)
			{
				Math::Vector2<int> vec1(10, 11);
				Math::Vector2<int> vec2(7, 23);

				Math::Vector2<int> vec3 = vec1 - vec2;

				assert(vec3.x == 3 && vec3.y == -12);
			}

			TEST_METHOD(MinusEqualVectorIntToVectorInt)
			{
				Math::Vector2<int> vec1(10, 11);
				Math::Vector2<int> vec2(7, 23);

				vec1 -= vec2;

				assert(vec1.x == 3 && vec1.y == -12);
			}

			/*
			TEST_METHOD(MultiplyVector2IntWithScalar)
			{
				Math::Vector2<int> vec(7, 23);

				vec = vec * 3;

				assert(vec.x == 21 && vec.y == 69);
			}

			TEST_METHOD(MultiplyEqualVector2IntWithScalar)
			{
				Math::Vector2<int> vec(7, 23);

				vec *= 3;

				assert(vec.x == 21 && vec.y == 69);
			}

			TEST_METHOD(DivideVector2IntWholeNumbers)
			{
				Math::Vector2<int> vec(7, 21);

				vec = vec / 7;

				assert(vec.x == 1 && vec.y == 3);
			}

			TEST_METHOD(DivideEqualVector2IntWholeNumbers)
			{
				Math::Vector2<int> vec(7, 21);

				vec /= 7;

				assert(vec.x == 1 && vec.y == 3);
			}

			TEST_METHOD(DivideVector2IntOddNumbers)
			{
				Math::Vector2<int> vec(9, 20);

				vec = vec / 7;

				assert(vec.x == 1 && vec.y == 2);
			}

			TEST_METHOD(DivideEqualVector2IntOddNumbers)
			{
				Math::Vector2<int> vec(9, 20);

				vec /= 7;

				assert(vec.x == 1 && vec.y == 2);
			}

			*/
		};
	}
}