#include <iostream>
#include <string>
using namespace std;
// CONSTANTS AND CONST — PRACTICE WORKBOOK
//
// Instructions:
// 1. Attempt each task before checking the reference solution.
// 2. Explain why each value should or should not be constant.
// 3. Try changing a const variable and observe the compiler error.
// 4. Compile using C++17.

int main()
{
    // --------------------------------------------------------
    // Exercise 1: Declare Constants
    // --------------------------------------------------------
    // Task:
    // Declare constants for the maximum marks, days in a week,
    // and a character grade. Print all three.
    //
    // Reference solution:

    const int MAX_MARKS = 100;
    constexpr int DAYS_IN_WEEK = 7;
    const char GRADE = 'A';

    cout << "=== Exercise 1 ===\n";
    cout << "Maximum marks: " << MAX_MARKS << '\n';
    cout << "Days in a week: " << DAYS_IN_WEEK << '\n';
    cout << "Grade: " << GRADE << "\n\n";

    // --------------------------------------------------------
    // Exercise 2: Find the Error
    // --------------------------------------------------------
    // Task:
    // Explain why the following statement is invalid:
    //
    // const int age = 20;
    // age = 21;
    //
    // Reference answer:
    // A const-qualified object cannot be modified through its
    // const-qualified name after initialization.
    //
    // Correct approach when the value must change:

    int age = 20;
    age = 21;

    cout << "=== Exercise 2 ===\n";
    cout << "Updated age: " << age << "\n\n";

    // --------------------------------------------------------
    // Exercise 3: Circle Area
    // --------------------------------------------------------
    // Task:
    // Use a compile-time constant for PI and a variable for
    // the radius. Calculate the area.
    //
    // Reference solution:

    constexpr double PI = 3.141592653589793;
    double radius = 5.0;
    const double area = PI * radius * radius;

    cout << "=== Exercise 3 ===\n";
    cout << "Radius: " << radius << '\n';
    cout << "Area: " << area << "\n\n";

    // --------------------------------------------------------
    // Exercise 4: const vs constexpr
    // --------------------------------------------------------
    // Task:
    // Explain why the following is valid:
    //
    // int getValue() { return 10; }
    // const int a = getValue();
    //
    // But a constexpr variable cannot use an ordinary
    // non-constexpr function as its initializer.
    //
    // Reference solution:

    int runtimeValue = 10;
    const int readOnlyValue = runtimeValue;

    constexpr int compileTimeValue = 10;

    cout << "=== Exercise 4 ===\n";
    cout << "Const value: " << readOnlyValue << '\n';
    cout << "Constexpr value: "
         << compileTimeValue << "\n\n";

    // --------------------------------------------------------
    // Exercise 5: Const Reference
    // --------------------------------------------------------
    // Task:
    // Create an ordinary integer and a const reference to it.
    // Change the original integer and print through the
    // reference. Explain the result.
    //
    // Reference solution:

    int score = 70;
    const int &scoreReference = score;

    cout << "=== Exercise 5 ===\n";
    cout << "Before: " << scoreReference << '\n';

    score = 95;

    cout << "After: " << scoreReference << "\n\n";

    // --------------------------------------------------------
    // Exercise 6: Pointer Qualifications
    // --------------------------------------------------------
    // Task:
    // Identify which operations are valid:
    //
    // a. const int* ptr: redirect pointer? Modify data via ptr?
    // b. int* const ptr: redirect pointer? Modify data via ptr?
    //
    // Reference solution:

    int first = 10;
    int second = 20;

    const int *pointerToConst = &first;
    pointerToConst = &second; // Allowed.
    // *pointerToConst = 30;   // Not allowed.

    int *const constPointer = &first;
    *constPointer = 30; // Allowed.
    // constPointer = &second; // Not allowed.

    cout << "=== Exercise 6 ===\n";
    cout << "Pointer to const: " << *pointerToConst << '\n';
    cout << "Const pointer target: " << *constPointer
         << "\n\n";

    // --------------------------------------------------------
    // Exercise 7: Student Result Report
    // --------------------------------------------------------
    // Task:
    // Store a student's name and score. Define the passing
    // score as a constant. Calculate and display pass status.
    //
    // Reference solution:

    const string studentName = "Riya";
    double studentScore = 82.5;
    constexpr double PASSING_SCORE = 40.0;

    const bool passed = studentScore >= PASSING_SCORE;

    cout << "=== Exercise 7 ===\n";
    cout << "Student: " << studentName << '\n';
    cout << "Score: " << studentScore << '\n';
    cout << "Passing score: " << PASSING_SCORE << '\n';
    cout << "Passed: " << boolalpha << passed << '\n';

    return 0;
}
