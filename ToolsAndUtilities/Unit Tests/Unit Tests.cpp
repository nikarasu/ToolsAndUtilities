#include "pch.h"
#include "CppUnitTest.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "assert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTests
{
	
	void LogMsg(int aInt)
	{
		std::stringstream strs;
		strs << aInt;
		std::string temp = strs.str();
		temp.append("\n");
		char* result = (char*)temp.c_str();

		Logger::WriteMessage(result);
	}

	namespace Vector2
	{
		TEST_CLASS(Vector2Tests)
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

			TEST_METHOD(CompareVector2WithVector2_1)
			{
				Math::Vector2<int> vec1(9, 20);
				Math::Vector2<int> vec2(9, 20);

				assert(vec1 == vec2);
			}

			TEST_METHOD(CompareVector2WithVector2_2)
			{
				Math::Vector2<int> vec1(9, 20);
				Math::Vector2<int> vec2(5, 60);

				assert(!(vec1 == vec2));
			}

			TEST_METHOD(CompareVector2WithVector2_3)
			{
				Math::Vector2<int> vec1(9, 20);
				Math::Vector2<int> vec2(5, 60);

				assert(vec1 != vec2);
			}

			TEST_METHOD(Vector2IntLength)
			{
				Math::Vector2<int> vec(3, 3);
				int res = (int)sqrt(18);

				assert(vec.GetLength() == res);
			}

			TEST_METHOD(Vector2IntLengthSquared)
			{
				Math::Vector2<int> vec(3, 3);
				int sqr = vec.GetSquareLength();
				int res = 18;

				assert(sqr == res);
			}

			TEST_METHOD(Vector2IntDotProduct)
			{
				Math::Vector2<int> vec1(9, 20);
				Math::Vector2<int> vec2(3, 5);
				

				assert(vec1.GetDotProduct(vec2) == 127);
			}

			TEST_METHOD(Vector2doubleNormal)
			{
				Math::Vector2<double> vec(9, 20);
				Math::Vector2<double> normal = vec.GetNormal();

				assert(normal.GetLength() == 1);
			}

			TEST_METHOD(GetLengthZeroVector)
			{
				Math::Vector2<int> vec;

				int length = vec.GetLength();
				assert(length == 0);
			}

			TEST_METHOD(GetDistanceVector2)
			{
				Math::Vector2<double> zeroVec;

				double a1 = 11;
				double b1 = 3;
				Math::Vector2<double> vec1(a1, b1);
				double zToOne = Math::GetDistance(zeroVec, vec1);
				double expectedResult1 = sqrt
				(
					a1 * a1 +
					b1 * b1
				);
				assert(zToOne == expectedResult1);

				double a2 = 3;
				double b2 = 8;
				Math::Vector2<double> vec2(a2, b2);
				double OneToTwo = Math::GetDistance(vec1, vec2);
				double expectedResult2 = sqrt
				(
					(a1 - a2) * (a1 - a2) +
					(b1 - b2) * (b1 - b2)
				);
				assert(OneToTwo == expectedResult2);

				double a3 = 13;
				double b3 = 17;
				Math::Vector2<double> vec3(13, 17);
				double TwoToThree = Math::GetDistance(vec2, vec3);
				double expectedResult3 = sqrt
				(
					(a2 - a3) * (a2 - a3) +
					(b2 - b3) * (b2 - b3)
				);
				assert(TwoToThree == expectedResult3);
			}
		};
	}

	namespace Vector3
	{
		TEST_CLASS(Vector3Tests)
		{
		public:
			TEST_METHOD(createDefaultVector3Int)
			{
				Math::Vector3<int> test;

				assert(test.x == 0 && test.y == 0 && test.z == 0);
			}

			TEST_METHOD(createVector3IntWithParameters)
			{
				Math::Vector3<int> test(10, 502, 777);

				assert(test.x == 10 && test.y == 502 && test.z == 777);
			}

			TEST_METHOD(assignToVector3)
			{
				Math::Vector3<int> vec1;
				Math::Vector3<int> vec2(10, 11, 12);

				assert(vec1.x == 0 && vec1.y == 0 && vec1.z == 0);

				vec1 = vec2;

				assert(vec1.x == 10 && vec1.y == 11 && vec1.z == 12);
			}

			TEST_METHOD(AddVectorIntToVectorInt)
			{
				Math::Vector3<int> vec1(7, 23, 46);
				Math::Vector3<int> vec2(10, 11, 66);
				Math::Vector3<int> vec3 = vec1 + vec2;

				assert(vec3.x == 17 && vec3.y == 34 && vec3.z == 112);
			}

			TEST_METHOD(PlusEqualVectorIntToVectorInt)
			{
				Math::Vector3<int> vec1(7, 23, 55);
				Math::Vector3<int> vec2(10, 11, 77);

				vec1 += vec2;

				assert(vec1.x == 17 && vec1.y == 34 && vec1.z == 132);
			}

			TEST_METHOD(SubtractVectorIntToVectorInt)
			{
				Math::Vector3<int> vec1(10, 11, 44);
				Math::Vector3<int> vec2(7, 23, 66);

				Math::Vector3<int> vec3 = vec1 - vec2;

				assert(vec3.x == 3 && vec3.y == -12 && vec3.z == -22);
			}

			TEST_METHOD(MinusEqualVectorIntToVectorInt)
			{
				Math::Vector3<int> vec1(10, 11, 77);
				Math::Vector3<int> vec2(7, 23, 77);

				vec1 -= vec2;

				assert(vec1.x == 3 && vec1.y == -12 && vec1.z == 0);
			}

			TEST_METHOD(MultiplyVector3IntWithScalar)
			{
				Math::Vector3<int> vec(7, 23, 88);

				vec = vec * 3;

				assert(vec.x == 21 && vec.y == 69 && vec.z == 264);
			}

			TEST_METHOD(MultiplyEqualVector3IntWithScalar)
			{
				Math::Vector3<int> vec(7, 23, 11);

				vec *= 3;


				assert(vec.x == 21 && vec.y == 69 && vec.z == 33);
			}

			TEST_METHOD(DivideVector3IntWholeNumbers)
			{
				Math::Vector3<int> vec(7, 21, 56);

				vec = vec / 7;

				assert(vec.x == 1 && vec.y == 3 && vec.z == 8);
			}

			TEST_METHOD(DivideEqualVector3IntWholeNumbers)
			{
				Math::Vector3<int> vec(7, 21, 63);

				vec /= 7;

				assert(vec.x == 1 && vec.y == 3 && vec.z == 9);
			}

			TEST_METHOD(DivideVector2IntOddNumbers)
			{
				Math::Vector3<int> vec(9, 20, 55);

				vec = vec / 7;

				assert(vec.x == 1 && vec.y == 2 && vec.z == 7);
			}

			TEST_METHOD(DivideEqualVector2IntOddNumbers)
			{
				Math::Vector3<int> vec(9, 20, 22);

				vec /= 7;

				assert(vec.x == 1 && vec.y == 2 && vec.z == 3);
			}

			TEST_METHOD(CompareVector3WithVector3_1)
			{
				Math::Vector3<int> vec1(9, 20, 34);
				Math::Vector3<int> vec2(9, 20, 34);

				assert(vec1 == vec2);
			}

			TEST_METHOD(CompareVector3WithVector3_2)
			{
				Math::Vector3<int> vec1(9, 20, 34);
				Math::Vector3<int> vec2(5, 60, 34);

				assert(!(vec1 == vec2));
			}

			TEST_METHOD(CompareVector3WithVector3_3)
			{
				Math::Vector3<int> vec1(9, 20, 47);
				Math::Vector3<int> vec2(5, 60, 47);

				assert(vec1 != vec2);
			}

			TEST_METHOD(Vector3IntLength)
			{
				int a = 3;
				int b = 3;
				int c = 3;

				Math::Vector3<int> vec(a, b, c);
				int res = (int)sqrt(a * a + b * b + c * c);

				assert(vec.GetLength() == res);
			}

			TEST_METHOD(Vector3IntLengthSquared)
			{
				int a = 3;
				int b = 3;
				int c = 3;

				Math::Vector3<int> vec(a, b, c);
				int sqr = vec.GetSquareLength();
				int res = 27;

				assert(sqr == res);
			}

			TEST_METHOD(Vector3IntDotProduct)
			{
				Math::Vector3<int> vec1(9, 20, 6);
				Math::Vector3<int> vec2(3, 5, 8);


				assert(vec1.GetDotProduct(vec2) == 175);
			}

			TEST_METHOD(Vector3doubleNormal)
			{
				Math::Vector3<double> vec(9, 20, 34);
				Math::Vector3<double> normal = vec.GetNormal();

				assert(normal.GetLength() == 1);
			}

			TEST_METHOD(GetLengthZeroVector)
			{
				Math::Vector3<int> vec;

				int length = vec.GetLength();
				assert(length == 0);
			}

			TEST_METHOD(GetDistanceVector3)
			{
				Math::Vector3<double> zeroVec;
				
				double a1 = 11;
				double b1 = 3;
				double c1 = 3;
				Math::Vector3<double> vec1(a1, b1, c1);
				double zToOne = Math::GetDistance(zeroVec, vec1);
				double expectedResult1 = sqrt
				(
					a1 * a1 + 
					b1 * b1 + 
					c1 * c1
				);
				assert(zToOne == expectedResult1);
				
				double a2 = 3;
				double b2 = 8;
				double c2 = 5;
				Math::Vector3<double> vec2(a2, b2, c2);
				double OneToTwo = Math::GetDistance(vec1, vec2);
				double expectedResult2 = sqrt
				(
					(a1 - a2) * (a1 - a2) +
					(b1 - b2) * (b1 - b2) +
					(c1 - c2) * (c1 - c2)
				);
				assert(OneToTwo == expectedResult2);

				double a3 = 13;
				double b3 = 17;
				double c3 = 8;
				Math::Vector3<double> vec3(13, 17, 8);
				double TwoToThree = Math::GetDistance(vec2, vec3);
				double expectedResult3 = sqrt
				(
					(a2 - a3) * (a2 - a3) +
					(b2 - b3) * (b2 - b3) +
					(c2 - c3) * (c2 - c3)
				);
				assert(TwoToThree == expectedResult3);
			}
		};
	}

	namespace Vector4
	{
			TEST_CLASS(Vector4Tests)
			{
			public:
				TEST_METHOD(createDefaultVector3Int)
				{
					Math::Vector4<int> test;

					assert(test.x == 0 && test.y == 0 && test.z == 0 && test.w == 0);
				}

				TEST_METHOD(createVector4IntWithParameters)
				{
					Math::Vector4<int> test(10, 502, 777, 666);

					assert(test.x == 10 && test.y == 502 && test.z == 777 && test.w == 666);
				}

				TEST_METHOD(assignToVector4)
				{
					Math::Vector4<int> vec1;
					Math::Vector4<int> vec2(10, 11, 12, 13);

					assert(vec1.x == 0 && vec1.y == 0 && vec1.z == 0 && vec1.w == 0);

					vec1 = vec2;

					assert(vec1.x == 10 && vec1.y == 11 && vec1.z == 12 && vec1.w == 13);
				}

				TEST_METHOD(AddVectorIntToVectorInt)
				{
					Math::Vector4<int> vec1(7, 23, 46, 11);
					Math::Vector4<int> vec2(10, 11, 66, 22);
					Math::Vector4<int> vec3 = vec1 + vec2;

					assert(vec3.x == 17 && vec3.y == 34 && vec3.z == 112 && vec3.w == 33);
				}

				TEST_METHOD(PlusEqualVectorIntToVectorInt)
				{
					Math::Vector4<int> vec1(7, 23, 55, 44);
					Math::Vector4<int> vec2(10, 11, 77, 55);

					vec1 += vec2;

					assert(vec1.x == 17 && vec1.y == 34 && vec1.z == 132 && vec1.w == 99);
				}

				TEST_METHOD(SubtractVectorIntToVectorInt)
				{
					Math::Vector4<int> vec1(10, 11, 44, 88);
					Math::Vector4<int> vec2(7, 23, 66, 87);

					Math::Vector4<int> vec3 = vec1 - vec2;

					assert(vec3.x == 3 && vec3.y == -12 && vec3.z == -22 && vec3.w == 1);
				}

				TEST_METHOD(MinusEqualVectorIntToVectorInt)
				{
					Math::Vector4<int> vec1(10, 11, 77, 45);
					Math::Vector4<int> vec2(7, 23, 77, 45);

					vec1 -= vec2;

					assert(vec1.x == 3 && vec1.y == -12 && vec1.z == 0 && vec1.w == 0);
				}

				TEST_METHOD(MultiplyVector4IntWithScalar)
				{
					Math::Vector4<int> vec(7, 23, 88, 22);

					vec = vec * 3;

					assert(vec.x == 21 && vec.y == 69 && vec.z == 264 && vec.w == 66);
				}

				TEST_METHOD(MultiplyEqualVector4IntWithScalar)
				{
					Math::Vector4<int> vec(7, 23, 11, 88);

					vec *= 3;


					assert(vec.x == 21 && vec.y == 69 && vec.z == 33 && vec.w == 264);
				}

				TEST_METHOD(DivideVector4IntWholeNumbers)
				{
					Math::Vector4<int> vec(7, 21, 56, 70);

					vec = vec / 7;

					assert(vec.x == 1 && vec.y == 3 && vec.z == 8 && vec.w == 10);
				}

				TEST_METHOD(DivideEqualVector4IntWholeNumbers)
				{
					Math::Vector4<int> vec(7, 21, 63, 70);

					vec /= 7;

					assert(vec.x == 1 && vec.y == 3 && vec.z == 9 && vec.w == 10);
				}

				TEST_METHOD(DivideVector2IntOddNumbers)
				{
					Math::Vector4<int> vec(9, 20, 55, 6);

					vec = vec / 7;

					assert(vec.x == 1 && vec.y == 2 && vec.z == 7 && vec.w == 0);
				}

				TEST_METHOD(DivideEqualVector2IntOddNumbers)
				{
					Math::Vector4<int> vec(9, 20, 22, 3);

					vec /= 7;

					assert(vec.x == 1 && vec.y == 2 && vec.z == 3 && vec.w == 0);
				}

				TEST_METHOD(CompareVector3WithVector3_1)
				{
					Math::Vector4<int> vec1(9, 20, 34, 55);
					Math::Vector4<int> vec2(9, 20, 34, 55);

					assert(vec1 == vec2);
				}

				TEST_METHOD(CompareVector4WithVector3_2)
				{
					Math::Vector4<int> vec1(9, 20, 34, 87);
					Math::Vector4<int> vec2(5, 60, 34, 87);

					assert(!(vec1 == vec2));
				}

				TEST_METHOD(CompareVector4WithVector4_3)
				{
					Math::Vector4<int> vec1(9, 20, 47, 52);
					Math::Vector4<int> vec2(5, 60, 47, 55);

					assert(vec1 != vec2);
				}

				TEST_METHOD(Vector4IntLength)
				{
					int a = 3;
					int b = 3;
					int c = 3;
					int d = 3;

					Math::Vector4<int> vec(a, b, c, d);
					int res = (int)sqrt(a * a + b * b + c * c + d * d);

					assert(vec.GetLength() == res);
				}

				TEST_METHOD(Vector4IntLengthSquared)
				{
					int a = 3;
					int b = 3;
					int c = 3;
					int d = 3;

					Math::Vector4<int> vec(a, b, c, d);
					int sqr = vec.GetSquareLength();
					int res = 36;

					assert(sqr == res);
				}

				TEST_METHOD(Vector4IntDotProduct)
				{
					Math::Vector4<int> vec1(9, 20, 6, 2);
					Math::Vector4<int> vec2(3, 5, 8, 11);


					assert(vec1.GetDotProduct(vec2) == 197);
				}

				TEST_METHOD(Vector4doubleNormal)
				{
					Math::Vector4<double> vec(9, 20, 34, 5);
					Math::Vector4<double> normal = vec.GetNormal();

					assert(normal.GetLength() == 1);
				}

				TEST_METHOD(GetLengthZeroVector)
				{
					Math::Vector4<int> vec;

					int length = vec.GetLength();
					assert(length == 0);
				}

				TEST_METHOD(GetDistanceVector3)
				{
					Math::Vector4<double> zeroVec;

					double a1 = 11;
					double b1 = 3;
					double c1 = 3;
					double d1 = 11;
					Math::Vector4<double> vec1(a1, b1, c1, d1);
					double zToOne = Math::GetDistance(zeroVec, vec1);
					double expectedResult1 = sqrt
					(
						a1 * a1 +
						b1 * b1 +
						c1 * c1 +
						d1 * d1
					);
					assert(zToOne == expectedResult1);

					double a2 = 3;
					double b2 = 8;
					double c2 = 5;
					double d2 = 4;
					Math::Vector4<double> vec2(a2, b2, c2, d2);
					double OneToTwo = Math::GetDistance(vec1, vec2);
					double expectedResult2 = sqrt
					(
						(a1 - a2) * (a1 - a2) +
						(b1 - b2) * (b1 - b2) +
						(c1 - c2) * (c1 - c2) + 
						(d1 - d2) * (d1 - d2)
					);
					assert(OneToTwo == expectedResult2);

					double a3 = 13;
					double b3 = 17;
					double c3 = 8;
					double d3 = 27;
					Math::Vector4<double> vec3(a3, b3, c3, d3);
					double TwoToThree = Math::GetDistance(vec2, vec3);
					double expectedResult3 = sqrt
					(
						(a2 - a3) * (a2 - a3) +
						(b2 - b3) * (b2 - b3) +
						(c2 - c3) * (c2 - c3) +
						(d2 - d3) * (d2 - d3)
					);
					assert(TwoToThree == expectedResult3);
				}
			};
	}
}