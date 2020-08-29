#pragma once

namespace Math
{
	template <typename T>
	class Vector4
	{
	public:
		//Default constructor
		Vector4<T>()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		//Constructor with parameters
		Vector4<T>(const T& aX, const T& aY, const T& aZ, const T& aW)
		{
			x = aX;
			y = aY;
			z = aZ;
			w = aW;
		}

		//Destructor
		~Vector4()
		{

		}

		//Return length/magnitude of vector
		T GetLength()
		{
			return sqrt(GetSquareLength());
		}

		//Return squared length/magnitude of vector
		T GetSquareLength()
		{
			return
				x * x +
				y * y +
				z * z +
				w * w
				;
		}

		//Return normalized vector
		//Remember: type int will give you a 0,0, 0 vector
		//Remember: type float will cause rounding errors
		Vector4<T> GetNormal()
		{
			//This seems unnecessary
			//TODO: Test if results change if using old algorithm

			//T squareLength = GetSquareLength();
			T length = GetLength();
			if (length == 0)
			{
				return *this;
			}

			return *this / length;
		}

		//Normalize this vector
		//Remember: type int will give you a 0,0 vector
		//Remember: type float will cause rounding errors
		void Normalize()
		{
			//This seems unnecessary
			//TODO: Test if results change if using old algorithm
			//T squareLength = GetSquareLength();
			//x /= sqrt(squareLength);
			//y /= sqrt(squareLength);
			//z /= sqrt(squareLength);

			T length = GetLength();
			x /= length;
			y /= length;
			z /= length;
			w /= length;
		}

		//Get dot product of vectors
		//Projects right hand vector onto this vector
		//If result = 0, then vectors are perpendicular
		//If result > 0, then vectors point in the same direction
		//If result < 0, then vectors point in the oppsite direction
		T GetDotProduct(const Vector4<T>& aRightHand)
		{
			return
				x * aRightHand.x +
				y * aRightHand.y +
				z * aRightHand.z + 
				w * aRightHand.w
				;
		}

		Vector4<T>& operator=(const Vector4<T>& aVeaRightHand) = default;

		//Checks if current vector is inside an upper and lower corner of a frame/box
		//Here the vectors represent points
		template<class T>
		bool IsInside(const Vector4<T>& aVec1, const Vector4<T> aVec2)
		{
			bool xWithin0 = (x > aVec1.x && x < aVec2.x);
			bool xWithin1 = (x > aVec2.x && x < aVec1.x);
			bool xTrue = (xWithin0 || xWithin1);

			bool yWithin0 = (y > aVec1.y && y < aVec2.y);
			bool yWithin1 = (y > aVec2.y && y < aVec1.y);
			bool yTrue = (yWithin0 || yWithin1);

			bool zWithin0 = (z > aVec1.z && z < aVec2.z);
			bool zWithin1 = (z > aVec2.z && z < aVec1.z);
			bool zTrue = (zWithin0 || zWithin1);

			bool wWithin0 = (w > aVec1.w && w < aVec2.w);
			bool wWithin1 = (w > aVec2.w && w < aVec1.w);
			bool wTrue = (wWithin0 || wWithin1);

			return (xTrue && yTrue && zTrue && wTrue);
		}

		//TODO: Convert to Vector2
		//Vector2<T> ToVector2();

		//TODO: Convert to Vector4
		//Vector4<T> ToVector4(T aW);

		T x;
		T y;
		T z;
		T w;
	};

	//+ operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector4<T> operator+(const Vector4<T>& aLeftHand, const Vector4<T>& aRightHand)
	{
		return Vector4<T>(
			aRightHand.x + aLeftHand.x,
			aRightHand.y + aLeftHand.y,
			aRightHand.z + aLeftHand.z,
			aRightHand.w + aLeftHand.w
			);
	}

	//+= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator+=(Vector4<T>& aLeftHand, const Vector4<T>& aRightHand)
	{
		aLeftHand.x += aRightHand.x;
		aLeftHand.y += aRightHand.y;
		aLeftHand.z += aRightHand.z;
		aLeftHand.w += aRightHand.w;
	}

	//- operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector4<T> operator-(const Vector4<T>& aLeftHand, const Vector4<T>& aRightHand)
	{
		return Vector4<T>(
			aLeftHand.x - aRightHand.x,
			aLeftHand.y - aRightHand.y,
			aLeftHand.z - aRightHand.z,
			aLeftHand.w - aRightHand.w
			);
	}

	//-= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator-=(Vector4<T>& aLeftHand, const Vector4<T>& aRightHand)
	{
		aLeftHand.x -= aRightHand.x;
		aLeftHand.y -= aRightHand.y;
		aLeftHand.z -= aRightHand.z;
		aLeftHand.w -= aRightHand.w;
	}

	//* operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector4<T> operator*(const Vector4<T>& aLeftHand, const T& aRightHand)
	{
		return Vector4<T>(
			aLeftHand.x * aRightHand,
			aLeftHand.y * aRightHand,
			aLeftHand.z * aRightHand,
			aLeftHand.w * aRightHand
			);
	}

	//*= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator*=(Vector4<T>& aLeftHand, const T& aRightHand)
	{
		aLeftHand.x *= aRightHand;
		aLeftHand.y *= aRightHand;
		aLeftHand.z *= aRightHand;
		aLeftHand.w *= aRightHand;
	}

	// / operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector4<T> operator/(const Vector4<T>& aLeftHand, const T& aRightHand)
	{
		return Vector4<T>(
			aLeftHand.x / aRightHand,
			aLeftHand.y / aRightHand,
			aLeftHand.z / aRightHand,
			aLeftHand.w / aRightHand
			);
	}

	// /= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator/=(Vector4<T>& aLeftHand, const T& aRightHand)
	{
		aLeftHand.x /= aRightHand;
		aLeftHand.y /= aRightHand;
		aLeftHand.z /= aRightHand;
		aLeftHand.w /= aRightHand;
	}

	// == operator
	//Remember: left hand must be first parameter
	template<typename T>
	bool operator==(Vector4<T>& aLeftHand, Vector4<T>& aRightHand)
	{
		return
			aLeftHand.x == aRightHand.x &&
			aLeftHand.y == aRightHand.y &&
			aLeftHand.z == aRightHand.z &&
			aLeftHand.w == aRightHand.w
			;
	}

	// != operator
//Remember: left hand must be first parameter
	template<typename T>
	bool operator!=(Vector4<T>& aLeftHand, Vector4<T>& aRightHand)
	{
		return
			aLeftHand.x != aRightHand.x ||
			aLeftHand.y != aRightHand.y ||
			aLeftHand.z != aRightHand.z ||
			aLeftHand.w != aRightHand.w
			;
	}

	template<typename T>
	T GetDistance(const Vector4<T> aVec1, const Vector4<T> aVec2)
	{
		return (aVec2 - aVec1).GetLength();
	}
}
