#include <iostream>
#include <string>
using namespace std;
// Exercise 1:
// Rewrite the following code using consistent indentation,
// spaces around operators, and blank lines where appropriate.
//
// int main(){int a=10;int b=20;int sum=a+b;std::cout<<sum<<'\n';return 0;}
int main_1()
{
    int a = 10;
    int b = 20;
    int sum = a + b;
    cout << sum << '\n';
    return 0;
}

// Exercise 2:
// Add a useful comment explaining why the calculation is needed.
int calculateRectangleArea(int length, int width)
{
    // TODO: area_of_rectangle = length * breadth .
    return length * width;
}

// Exercise 3:
// Rename these variables to communicate their meaning.
void printPurchase()
{
    double a = 25.50;
    int b = 4;
    double c = a * b;

    cout << "Total: " << c << '\n';
}

// Exercise 4:
// Improve the formatting of this function.
void printStudentInformation()
{
    int age = 20;
    string name = "Alex";
    double score = 92.5;
    cout << "Name: " << name << '\n';
    cout << "Age: " << age << '\n';
    cout << "Score: " << score << '\n';
}

// Exercise 5:
// Write a short comment above main() describing the program.
int main()
{
    // TODO: Add a descriptive comment above main().

    cout << "Formatting practice\n";

    // Call the functions you have improved.
    cout << "Rectangle area: "
         << calculateRectangleArea(5, 3) << '\n';

    printPurchase();
    printStudentInformation();

    return 0;
}