#include <iostream>
#include "Vector2.h"

using namespace std;

int main()
{

    Math::Vector2<int> testClass;
    cout << testClass.x << "\n";
    cout << testClass.y << "\n";

    Math::Vector2<int> testClass2(2,3);
    cout << testClass2.x << "\n";
    cout << testClass2.y << "\n";
    cout << "Hello World!\n";
}
