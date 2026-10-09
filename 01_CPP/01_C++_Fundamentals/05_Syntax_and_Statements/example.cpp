#include <iostream>
#include <string>
using namespace std;
int main()
{
    // Variable declarations
    int age = 21;
    double height = 1.75;
    string name = "Alex";
    bool isStudent = true;

    // An arithmetic expression
    int firstNumber = 10;
    int secondNumber = 20;
    int sum = firstNumber + secondNumber;

    // Output statements
    cout << "=== C++ Syntax Demonstration ===\n";
    cout << "Name: " << name << '\n';
    cout << "Age: " << age << '\n';
    cout << "Height: " << height << " metres\n";
    cout << "Is a student: " << std::boolalpha
         << isStudent << '\n';

    cout << "\nArithmetic expression:\n";
    cout << firstNumber << " + " << secondNumber
         << " = " << sum << '\n';

    // A separate compound statement and local scope
    {
        int localNumber = 100;
        cout << "\nLocal number: " << localNumber << '\n';
    }

    // The localNumber variable is no longer accessible here.

    return 0;
}