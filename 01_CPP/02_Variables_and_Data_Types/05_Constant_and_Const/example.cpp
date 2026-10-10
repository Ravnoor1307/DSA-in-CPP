#include <iostream>
#include <string>
using namespace std;
int getRuntimeValue() {
    return 42;
}

void printName(const string& name) {
    cout << "Name: " << name << '\n';

    // name = "Changed"; // Compilation error:
    // cannot modify through a const reference.
}

int main() {
    // 1. Basic const variables
    const int MAX_ATTEMPTS = 3;
    const double PI = 3.141592653589793;
    const char GRADE = 'A';

    cout << "=== Basic Constants ===\n";
    cout << "Maximum attempts: " << MAX_ATTEMPTS << '\n';
    cout << "PI: " << PI << '\n';
    cout << "Grade: " << GRADE << "\n\n";

    // 2. Mutable variable vs const variable
    int score = 70;
    score = 95;

    const int passingScore = 40;

    cout << "=== Variables and Constants ===\n";
    cout << "Updated score: " << score << '\n';
    cout << "Passing score: " << passingScore << "\n\n";

    // 3. Compile-time constants
    constexpr int DAYS_IN_WEEK = 7;
    constexpr int HOURS_IN_DAY = 24;
    constexpr int HOURS_IN_WEEK = DAYS_IN_WEEK * HOURS_IN_DAY;

    cout << "=== constexpr ===\n";
    cout << "Days in a week: " << DAYS_IN_WEEK << '\n';
    cout << "Hours in a day: " << HOURS_IN_DAY << '\n';
    cout << "Hours in a week: " << HOURS_IN_WEEK << "\n\n";

    // 4. const initialized at runtime
    const int runtimeValue = getRuntimeValue();

    cout << "=== Runtime Initialization ===\n";
    cout << "Runtime value: " << runtimeValue << "\n\n";

    // 5. Constants in calculations
    constexpr double DISCOUNT_RATE = 0.10;
    double price = 500.0;

    const double discount = price * DISCOUNT_RATE;
    const double finalPrice = price - discount;

    cout << "=== Discount Calculation ===\n";
    cout << "Original price: " << price << '\n';
    cout << "Discount: " << discount << '\n';
    cout << "Final price: " << finalPrice << "\n\n";

    // 6. Const reference
    int originalScore = 80;
    const int& scoreView = originalScore;

    cout << "=== Const Reference ===\n";
    cout << "Score through reference: " << scoreView << '\n';

    originalScore = 90;
    cout << "After changing original: " << scoreView << "\n\n";

    // 7. Pointer to const data
    int firstValue = 10;
    int secondValue = 20;

    const int* pointerToConst = &firstValue;

    cout << "=== Pointer to Const Data ===\n";
    cout << "Value: " << *pointerToConst << '\n';

    pointerToConst = &secondValue; // Allowed: pointer can change.
    cout << "After redirecting: " << *pointerToConst << "\n\n";

    // 8. Const pointer
    int modifiableValue = 30;
    int* const constPointer = &modifiableValue;

    *constPointer = 35; // Allowed: pointed-to value can change.

    cout << "=== Const Pointer ===\n";
    cout << "Modified value: " << modifiableValue << "\n\n";

    // 9. Const pointer to const data
    int fixedTarget = 100;
    const int* const fixedPointer = &fixedTarget;

    cout << "=== Const Pointer to Const Data ===\n";
    cout << "Value: " << *fixedPointer << "\n\n";

    // 10. Const-reference function parameter
    const string studentName = "Alex";

    cout << "=== Const Reference in a Function ===\n";
    printName(studentName);

    return 0;
}
