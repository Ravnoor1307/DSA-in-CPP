#include <iostream>
using namespace std;
int main() {
    // 1. Declaring and initializing variables
    int studentAge{19};
    double studentMarks{88.5};
    char studentGrade{'A'};
    bool hasPassed{true};

    cout << "=== Student Information ===\n";
    cout << "Age: " << studentAge << '\n';
    cout << "Marks: " << studentMarks << '\n';
    cout << "Grade: " << studentGrade << '\n';
    cout << "Passed: " << std::boolalpha
              << hasPassed << '\n';

    // 2. Assigning a new value
    studentAge = 20;

    cout << "\n=== Updated Information ===\n";
    cout << "Updated age: " << studentAge << '\n';

    // 3. Using variables in calculations
    int firstNumber{10};
    int secondNumber{5};

    int sum{firstNumber + secondNumber};
    int difference{firstNumber - secondNumber};
    int product{firstNumber * secondNumber};
    int quotient{firstNumber / secondNumber};

    cout << "\n=== Arithmetic Operations ===\n";
    cout << "Sum: " << sum << '\n';
    cout << "Difference: " << difference << '\n';
    cout << "Product: " << product << '\n';
    cout << "Quotient: " << quotient << '\n';

    // 4. Updating a variable using its current value
    int score{0};

    score = score + 10;
    score = score + 5;

    cout << "\n=== Score Update ===\n";
    cout << "Final score: " << score << '\n';

    // 5. Integer division versus floating-point division
    int integerResult{7 / 2};
    double decimalResult{7.0 / 2.0};

    cout << "\n=== Division ===\n";
    cout << "Integer result: " << integerResult << '\n';
    cout << "Decimal result: " << decimalResult << '\n';

    return 0;
}
