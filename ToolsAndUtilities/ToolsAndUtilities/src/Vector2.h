#pragma once

namespace Math
{
	template <typename T>
	class Vector2
	{
	public:

		//Default constructor
		Vector2<T>()
		{
			x = 0;
			y = 0;
		}

		//Constructor with parameters
		Vector2<T>(const T& aX, const T& aY)
		{
			x = aX;
			y = aY;
		}

		//Destructor
		~Vector2()
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
			return x * x + y * y;
		}

		//Return normalized vector
		//Remember: type int will give you a 0,0 vector
		//Remember: type float will cause rounding errors
		Vector2<T> GetNormal()
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

			T length = GetLength();
			x /= length;
			y /= length;
		}

		//Get dot product of vectors
		//Projects right hand vector onto this vector
		//If result = 0, then vectors are perpendicular
		//If result > 0, then vectors point in the same direction
		//If result < 0, then vectors point in the oppsite direction
		T GetDotProduct(const Vector2<T>& aRightHand)
		{
			return x * aRightHand.x + y * aRightHand.y;
		}

		Vector2<T>& operator=(const Vector2<T>& aVeaRightHand) = default;

		//Checks if current vector is inside an upper and lower corner of a frame/box
		//Here the vectors represent points
		template<class T>
		bool IsInside(const Vector2<T>& aVec1, const Vector2<T> aVec2)
		{
			bool xWithin0 = (x > aVec1.x && x < aVec2.x);
			bool xWithin1 = (x > aVec2.x && x < aVec1.x);
			bool xTrue = (xWithin0 || xWithin1);

			bool yWithin0 = (y > aVec1.y && y < aVec2.y);
			bool yWithin1 = (y > aVec2.y && y < aVec1.y);
			bool yTrue = (yWithin0 || yWithin1);

			return (xTrue && yTrue);
		}

		//TODO: Convert to Vector3
		//Vector3<T> ToVector3(T aZ);

		//TODO: Convert to Vector4
		//Vector4<T> ToVector4(T aZ, T aW);

		T x;
		T y;
	};

	//+ operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector2<T> operator+(const Vector2<T>& aLeftHand, const Vector2<T>& aRightHand)
	{
		return Vector2<T>(
			aRightHand.x + aLeftHand.x,
			aRightHand.y + aLeftHand.y
			);
	}

	//+= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator+=(Vector2<T>& aLeftHand, const Vector2<T>& aRightHand)
	{
		aLeftHand.x += aRightHand.x;
		aLeftHand.y += aRightHand.y;
	}

	//- operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector2<T> operator-(const Vector2<T>& aLeftHand, const Vector2<T>& aRightHand)
	{
		return Vector2<T>(
			aLeftHand.x - aRightHand.x,
			aLeftHand.y - aRightHand.y
			);
	}

	//-= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator-=(Vector2<T>& aLeftHand, const Vector2<T>& aRightHand)
	{
		aLeftHand.x -= aRightHand.x;
		aLeftHand.y -= aRightHand.y;
	}

	//* operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector2<T> operator*(const Vector2<T>& aLeftHand, const T& aRightHand)
	{
		return Vector2<T>(
			aLeftHand.x * aRightHand,
			aLeftHand.y * aRightHand
			);
	}

	//*= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator*=(Vector2<T>& aLeftHand, const T& aRightHand)
	{
		aLeftHand.x *= aRightHand;
		aLeftHand.y *= aRightHand;
	}

	// / operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector2<T> operator/(const Vector2<T>& aLeftHand, const T& aRightHand)
	{
		return Vector2<T>(
			aLeftHand.x / aRightHand,
			aLeftHand.y / aRightHand
			);
	}

	// /= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator/=(Vector2<T>& aLeftHand, const T& aRightHand)
	{
		aLeftHand.x /= aRightHand;
		aLeftHand.y /= aRightHand;
	}

	// == operator
	//Remember: left hand must be first parameter
	template<typename T>
	bool operator==(Vector2<T>& aLeftHand, Vector2<T>& aRightHand)
	{
		return 
			aLeftHand.x == aRightHand.x && 
			aLeftHand.y == aRightHand.y
			;
	}

	// != operator
//Remember: left hand must be first parameter
	template<typename T>
	bool operator!=(Vector2<T>& aLeftHand, Vector2<T>& aRightHand)
	{
		return 
			aLeftHand.x != aRightHand.x || 
			aLeftHand.y != aRightHand.y
			;
	}

	template<typename T>
	T GetDistance(const Vector2<T> aVec1, const Vector2<T> aVec2)
	{
		return (aVec2 - aVec1).GetLength();
	}
}