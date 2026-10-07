/*
Topic: Exception Handling
File: 02_basics.cpp

Purpose:
Practice:
- validation through exceptions
- standard exception types
- multiple handlers
- exception propagation
- const-reference catches

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// ========== SECTION 1: SAFE DIVISION ==========

double divide(double a, double b) {
    if (b == 0.0) {
        throw invalid_argument(
            "cannot divide by zero"
        );
    }

    return a / b;
}

// ========== SECTION 2: VALID AGE ==========

class Person {
private:
    string name;
    int age;

public:
    Person(const string& name, int age)
        : name(name), age(age) {
        if (age < 0 || age > 150) {
            throw invalid_argument(
                "age outside accepted range"
            );
        }
    }

    void display() const {
        cout << name
             << " is "
             << age
             << " years old\n";
    }
};

// ========== SECTION 3: CHECKED ARRAY ACCESS ==========

int checkedGet(
    const int values[],
    int size,
    int index
) {
    if (index < 0 || index >= size) {
        throw out_of_range(
            "invalid array index"
        );
    }

    return values[index];
}

// ========== SECTION 4: PROPAGATION ==========

int parsePositive(int value) {
    if (value <= 0) {
        throw invalid_argument(
            "value must be positive"
        );
    }

    return value;
}

int doublePositive(int value) {
    // We deliberately do not catch here.
    // Any exception propagates to the caller.
    return parsePositive(value) * 2;
}

int main() {
    cout << "=== BASIC 1: DIVISION ===\n";

    try {
        cout << "20 / 4 = "
             << divide(20, 4) << '\n';

        cout << "20 / 0 = "
             << divide(20, 0) << '\n';
    }
    catch (const invalid_argument& error) {
        cout << "Division error: "
             << error.what() << '\n';
    }

    cout << "\n=== BASIC 2: CONSTRUCTOR VALIDATION ===\n";

    try {
        Person valid("Asha", 20);
        valid.display();

        Person invalid("Example", -5);
        invalid.display();
    }
    catch (const invalid_argument& error) {
        cout << "Person error: "
             << error.what() << '\n';
    }

    cout << "\n=== BASIC 3: CHECKED INDEX ===\n";

    int values[] = {10, 20, 30};

    try {
        cout << "values[1] = "
             << checkedGet(values, 3, 1)
             << '\n';

        cout << checkedGet(values, 3, 5)
             << '\n';
    }
    catch (const out_of_range& error) {
        cout << "Index error: "
             << error.what() << '\n';
    }

    cout << "\n=== BASIC 4: PROPAGATION ===\n";

    try {
        cout << "doublePositive(6) = "
             << doublePositive(6)
             << '\n';

        cout << doublePositive(-2)
             << '\n';
    }
    catch (const exception& error) {
        cout << "Caught in main: "
             << error.what() << '\n';
    }

    cout << "\nNext: 27_NAMESPACES_AND_HEADER_FILES\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: DIVISION ===
20 / 4 = 5
20 / 0 = Division error: cannot divide by zero

=== BASIC 2: CONSTRUCTOR VALIDATION ===
Asha is 20 years old
Person error: age outside accepted range

=== BASIC 3: CHECKED INDEX ===
values[1] = 20
Index error: invalid array index

=== BASIC 4: PROPAGATION ===
doublePositive(6) = 12
Caught in main: value must be positive

Next: 27_NAMESPACES_AND_HEADER_FILES
*/
