#include <cmath>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
// BASIC DATA TYPES — PRACTICE WORKBOOK
//
// Instructions:
// 1. Read each exercise.
// 2. Try writing your own solution first.
// 3. Uncomment or adapt the reference solution when ready.
// 4. Compile with C++17 and investigate any warnings.

int main() {
    cout << boolalpha;

    // --------------------------------------------------------
    // Exercise 1: Store Basic Information
    // --------------------------------------------------------
    // Task:
    // Create variables for your age, height, grade, and
    // whether you are a student. Print all four values.
    //
    // Reference solution:

    int age = 20;
    double height = 1.75;
    char grade = 'A';
    bool isStudent = true;

    cout << "=== Exercise 1 ===\n";
    cout << "Age: " << age << '\n';
    cout << "Height: " << height << '\n';
    cout << "Grade: " << grade << '\n';
    cout << "Student: " << isStudent << "\n\n";

    // --------------------------------------------------------
    // Exercise 2: Integer vs Floating-Point Division
    // --------------------------------------------------------
    // Task:
    // Divide 7 by 2 using integers, then using double.
    // Explain why the results differ.
    //
    // Reference solution:

    int numerator = 7;
    int denominator = 2;

    int integerResult = numerator / denominator;
    double decimalResult =
        static_cast<double>(numerator) / denominator;

    cout << "=== Exercise 2 ===\n";
    cout << "Integer division: " << integerResult << '\n';
    cout << "Floating-point division: "
              << decimalResult << "\n\n";

    // --------------------------------------------------------
    // Exercise 3: Student Report
    // --------------------------------------------------------
    // Task:
    // Store a student's name, score, grade, and pass status.
    // Print a simple report.
    //
    // Reference solution:

    string studentName = "Alex";
    double score = 87.5;
    char studentGrade = 'A';
    bool passed = score >= 40.0;

    cout << "=== Exercise 3 ===\n";
    cout << "Name: " << studentName << '\n';
    cout << "Score: " << score << '\n';
    cout << "Grade: " << studentGrade << '\n';
    cout << "Passed: " << passed << "\n\n";

    // --------------------------------------------------------
    // Exercise 4: Inspect Numeric Limits
    // --------------------------------------------------------
    // Task:
    // Print the maximum values of int, long long, and double.
    //
    // Reference solution:

    cout << "=== Exercise 4 ===\n";
    cout << "Maximum int: "
              << numeric_limits<int>::max() << '\n';
    cout << "Maximum long long: "
              << numeric_limits<long long>::max() << '\n';
    cout << "Maximum finite double: "
              << numeric_limits<double>::max()
              << "\n\n";

    // --------------------------------------------------------
    // Exercise 5: Choose Appropriate Types
    // --------------------------------------------------------
    // Task:
    // Declare suitable variables for:
    // a. Number of books
    // b. Average temperature
    // c. Whether an account is active
    // d. A person's first initial
    // e. A person's full name
    //
    // Reference solution:

    int numberOfBooks = 12;
    double averageTemperature = 24.75;
    bool accountActive = true;
    char firstInitial = 'R';
    string fullName = "Riya Sharma";

    cout << "=== Exercise 5 ===\n";
    cout << "Books: " << numberOfBooks << '\n';
    cout << "Average temperature: "
              << averageTemperature << '\n';
    cout << "Account active: " << accountActive << '\n';
    cout << "Initial: " << firstInitial << '\n';
    cout << "Full name: " << fullName << "\n\n";

    // --------------------------------------------------------
    // Exercise 6: Compare Floating-Point Values
    // --------------------------------------------------------
    // Task:
    // Calculate 0.1 + 0.2 and compare it with 0.3.
    // Then use a tolerance-based comparison.
    //
    // Reference solution:

    double calculated = 0.1 + 0.2;
    double expected = 0.3;
    double tolerance = 1e-9;

    bool exactMatch = calculated == expected;
    bool approximateMatch =
        abs(calculated - expected) < tolerance;

    cout << "=== Exercise 6 ===\n";
    cout << "Calculated: " << calculated << '\n';
    cout << "Exact match: " << exactMatch << '\n';
    cout << "Approximate match: "
              << approximateMatch << "\n\n";

    // --------------------------------------------------------
    // Exercise 7: Identify the Type
    // --------------------------------------------------------
    // For each variable below, identify its type and explain
    // why that type is appropriate.

    int numberOfAttempts = 3;
    double averageMarks = 82.25;
    char section = 'B';
    bool examCompleted = false;
    string subject = "Mathematics";

    cout << "=== Exercise 7 ===\n";
    cout << "Attempts: " << numberOfAttempts << '\n';
    cout << "Average marks: " << averageMarks << '\n';
    cout << "Section: " << section << '\n';
    cout << "Exam completed: " << examCompleted << '\n';
    cout << "Subject: " << subject << '\n';

    return 0;
}
