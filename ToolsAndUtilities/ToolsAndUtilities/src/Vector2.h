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

		//Return length of vector
		//T Length();

		//Return squared length of vector
		//T SqrLength();

		//Return normalized vector
		//Vector2<T> GetNormal();

		//Normalize this vector
		//void Normalize();

		//Get dot product of vector
		//T GetDotProduct(Vector2<T> aVec);

		//Convert to Vector3
		//Vector3<T> ToVector3(T aZ);

		//Convert to Vector4
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

}