#include <iostream>
using namespace std;
int main()
{

    // Implicit TypeConversion
    int a = 34;
    int sum = a + 45.45753;

    cout << sum << endl;

    // Explicite TypeConversion
    float b = 45.25455;
    int prod = a * (int)b;
    cout << prod << endl;

    // Taking Input

    int age;
    cout << "Enter your age : ";
    cin >> age;

    cout << "Your age is : " << age << endl;
    
    return 0;
}