#pragma once

namespace Math
{
	template <typename T>
	class Vector3
	{
	public:
		//Default constructor
		Vector3<T>()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		//Constructor with parameters
		Vector3<T>(const T& aX, const T& aY, const T& aZ)
		{
			x = aX;
			y = aY;
			z = aZ;
		}

		//Destructor
		~Vector3()
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
				z * z
				;
		}

		//Return normalized vector
		//Remember: type int will give you a 0,0, 0 vector
		//Remember: type float will cause rounding errors
		Vector3<T> GetNormal()
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
		}

		//Get dot product of vectors
		//Projects right hand vector onto this vector
		//If result = 0, then vectors are perpendicular
		//If result > 0, then vectors point in the same direction
		//If result < 0, then vectors point in the oppsite direction
		T GetDotProduct(const Vector3<T>& aRightHand)
		{
			return 
				x * aRightHand.x + 
				y * aRightHand.y + 
				z * aRightHand.z
				;
		}

		Vector3<T>& operator=(const Vector3<T>& aVeaRightHand) = default;

		//Checks if current vector is inside an upper and lower corner of a frame/box
		//Here the vectors represent points
		template<class T>
		bool IsInside(const Vector3<T> & aVec1, const Vector3<T> aVec2)
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

			return (xTrue && yTrue && zTrue);
		}

		//TODO: Convert to Vector2
		//Vector2<T> ToVector2();

		//TODO: Convert to Vector4
		//Vector4<T> ToVector4(T aW);

		T x;
		T y;
		T z;
	};

	//+ operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector3<T> operator+(const Vector3<T>& aLeftHand, const Vector3<T>& aRightHand)
	{
		return Vector3<T>(
			aRightHand.x + aLeftHand.x,
			aRightHand.y + aLeftHand.y,
			aRightHand.z + aLeftHand.z
			);
	}

	//+= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator+=(Vector3<T>& aLeftHand, const Vector3<T>& aRightHand)
	{
		aLeftHand.x += aRightHand.x;
		aLeftHand.y += aRightHand.y;
		aLeftHand.z += aRightHand.z;
	}

	//- operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector3<T> operator-(const Vector3<T>& aLeftHand, const Vector3<T>& aRightHand)
	{
		return Vector3<T>(
			aLeftHand.x - aRightHand.x,
			aLeftHand.y - aRightHand.y,
			aLeftHand.z - aRightHand.z
			);
	}

	//-= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator-=(Vector3<T>& aLeftHand, const Vector3<T>& aRightHand)
	{
		aLeftHand.x -= aRightHand.x;
		aLeftHand.y -= aRightHand.y;
		aLeftHand.z -= aRightHand.z;
	}

	//* operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector3<T> operator*(const Vector3<T>& aLeftHand, const T& aRightHand)
	{
		return Vector3<T>(
			aLeftHand.x * aRightHand,
			aLeftHand.y * aRightHand,
			aLeftHand.z * aRightHand
			);
	}

	//*= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator*=(Vector3<T>& aLeftHand, const T& aRightHand)
	{
		aLeftHand.x *= aRightHand;
		aLeftHand.y *= aRightHand;
		aLeftHand.z *= aRightHand;
	}

	// / operator
	//Remember: left hand must be first parameter
	template<typename T>
	Vector3<T> operator/(const Vector3<T>& aLeftHand, const T& aRightHand)
	{
		return Vector3<T>(
			aLeftHand.x / aRightHand,
			aLeftHand.y / aRightHand,
			aLeftHand.z / aRightHand
			);
	}

	// /= operator
	//Remember: left hand must be first parameter
	template<typename T>
	void operator/=(Vector3<T>& aLeftHand, const T& aRightHand)
	{
		aLeftHand.x /= aRightHand;
		aLeftHand.y /= aRightHand;
		aLeftHand.z /= aRightHand;
	}

	// == operator asda sd
	//Remember: left hand must be first parameter
	template<typename T>
	bool operator==(Vector3<T>& aLeftHand, Vector3<T>& aRightHand)
	{
		return
			aLeftHand.x == aRightHand.x &&
			aLeftHand.y == aRightHand.y &&
			aLeftHand.z == aRightHand.z
			;
	}

	// != operator
//Remember: left hand must be first parameter
	template<typename T>
	bool operator!=(Vector3<T>& aLeftHand, Vector3<T>& aRightHand)
	{
		return
			aLeftHand.x != aRightHand.x ||
			aLeftHand.y != aRightHand.y ||
			aLeftHand.z != aRightHand.z
			;
	}

	template<typename T>
	T GetDistance(const Vector3<T> aVec1, const Vector3<T> aVec2)
	{
		return (aVec2 - aVec1).GetLength();
	}
}
