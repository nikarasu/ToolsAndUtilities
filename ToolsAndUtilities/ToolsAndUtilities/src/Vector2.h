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
		~Vector2();

		T x;
		T y;
	};
}