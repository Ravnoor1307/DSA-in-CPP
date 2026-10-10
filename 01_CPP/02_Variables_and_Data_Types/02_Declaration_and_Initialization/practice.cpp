
#include <iostream>
#include <string>
using namespace std;
int main() {
    // =====================================================
    // EXERCISE 1: Declaration and assignment
    // =====================================================
    // TODO:
    // Declare an integer named number.
    // Assign it the value 100 before displaying it.

    int number{};
    number = 100;

    cout << "=== Exercise 1 ===\n";
    cout << "Number: " << number << '\n';


    // =====================================================
    // EXERCISE 2: Initialization forms
    // =====================================================
    // TODO:
    // Create three integer variables:
    // 1. Copy initialization with value 10.
    // 2. Direct initialization with value 20.
    // 3. Brace initialization with value 30.
    // Display all three values.

    int first = 10;
    int second(20);
    int third{30};

    cout << "\n=== Exercise 2 ===\n";
    cout << first << '\n';
    cout << second << '\n';
    cout << third << '\n';


    // =====================================================
    // EXERCISE 3: Value initialization
    // =====================================================
    // TODO:
    // Initialize an integer, a double, and a bool
    // using empty braces.
    // Display their values.

    int count{};
    double amount{};
    bool isComplete{};

    cout << "\n=== Exercise 3 ===\n";
    cout << "Count: " << count << '\n';
    cout << "Amount: " << amount << '\n';
    cout << std::boolalpha;
    cout << "Complete: " << isComplete << '\n';


    // =====================================================
    // EXERCISE 4: Assignment versus initialization
    // =====================================================
    // TODO:
    // Start a variable named marks at 60.
    // Assign it 75, then assign it 95.
    // Display the final value.
    // Explain why the later statements are assignments.

    int marks{60};

    marks = 75;
    marks = 95;

    cout << "\n=== Exercise 4 ===\n";
    cout << "Final marks: " << marks << '\n';


    // =====================================================
    // EXERCISE 5: Brace initialization
    // =====================================================
    // TODO:
    // Initialize an int named wholeNumber to 25.
    // Initialize a double named decimalNumber to 25.5.
    //
    // Experiment separately with:
    // int invalidNumber{25.5};
    //
    // The experimental line should fail to compile.
    // Do not uncomment it in this working file.

    int wholeNumber{25};
    double decimalNumber{25.5};

    cout << "\n=== Exercise 5 ===\n";
    cout << "Whole number: " << wholeNumber << '\n';
    cout << "Decimal number: " << decimalNumber << '\n';


    // =====================================================
    // EXERCISE 6: Constants
    // =====================================================
    // TODO:
    // Declare a const integer named daysInWeek.
    // Initialize it to 7 and display it.
    // Try changing its value in a separate experiment.
    // Explain the compiler error.

    const int daysInWeek{7};

    cout << "\n=== Exercise 6 ===\n";
    cout << "Days in a week: " << daysInWeek << '\n';


    // =====================================================
    // EXERCISE 7: String initialization
    // =====================================================
    // TODO:
    // Initialize a string named city with a city name.
    // Create an empty string using braces.
    // Display both strings and the empty string's length.

    string city{"Ludhiana"};
    string emptyString{};

    cout << "\n=== Exercise 7 ===\n";
    cout << "City: " << city << '\n';
    cout << "Empty string length: "
              << emptyString.size() << '\n';


    // =====================================================
    // CHALLENGE: Student result
    // =====================================================
    // TODO:
    // 1. Initialize three subject marks.
    // 2. Calculate their total.
    // 3. Calculate the average using floating-point division.
    // 4. Store the maximum possible marks in a const variable.
    // 5. Display the results.

    int mathematics{80};
    int science{90};
    int english{85};

    int totalMarks{mathematics + science + english};
    double averageMarks{totalMarks / 3.0};
    const int maximumMarks{300};

    cout << "\n=== Student Result ===\n";
    cout << "Total: " << totalMarks << '\n';
    cout << "Average: " << averageMarks << '\n';
    cout << "Maximum marks: " << maximumMarks << '\n';

    return 0;
}
