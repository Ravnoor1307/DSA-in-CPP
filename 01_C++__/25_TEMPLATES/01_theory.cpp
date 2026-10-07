/*
Topic: Templates

Covers:
- function templates
- template deduction
- explicit template arguments
- multiple template parameters
- class templates
- non-type template parameters
- template member functions
- overloads and specialization
- generic programming

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: FUNCTION TEMPLATE ==========

template <typename T>
T maximum(const T& a, const T& b) {
    return a < b ? b : a;
}

// ========== SECTION 2: GENERIC SWAP ==========

template <typename T>
void swapValues(T& a, T& b) {
    T temporary = a;
    a = b;
    b = temporary;
}

// ========== SECTION 3: MULTIPLE TEMPLATE PARAMETERS ==========

template <typename First, typename Second>
void showPair(const First& first, const Second& second) {
    cout << first << " | " << second << '\n';
}

// ========== SECTION 4: DEDUCED RETURN TYPE ==========

template <typename T, typename U>
auto add(T a, U b) {
    return a + b;
}

// ========== SECTION 5: CLASS TEMPLATE ==========

template <typename T>
class Box {
private:
    T value;

public:
    explicit Box(const T& value)
        : value(value) {
    }

    void set(const T& newValue) {
        value = newValue;
    }

    const T& get() const {
        return value;
    }
};

// ========== SECTION 6: NON-TYPE TEMPLATE PARAMETER ==========

template <typename T, int Size>
class FixedArray {
private:
    T values[Size] = {};

public:
    int size() const {
        return Size;
    }

    T& operator[](int index) {
        return values[index];
    }

    const T& operator[](int index) const {
        return values[index];
    }
};

// ========== SECTION 7: FUNCTION TEMPLATE OVERLOAD ==========

template <typename T>
void describe(const T& value) {
    cout << "Generic value: "
         << value << '\n';
}

void describe(int value) {
    cout << "Integer overload: "
         << value << '\n';
}

// ========== SECTION 8: FULL SPECIALIZATION ==========

template <typename T>
class TypePrinter {
public:
    void print(const T& value) const {
        cout << "Generic printer: "
             << value << '\n';
    }
};

template <>
class TypePrinter<bool> {
public:
    void print(bool value) const {
        cout << "Boolean printer: "
             << (value ? "true" : "false")
             << '\n';
    }
};

// ========== SECTION 9: CUSTOM TYPE WITH TEMPLATE ==========

class Score {
private:
    int value;

public:
    explicit Score(int value)
        : value(value) {
    }

    bool operator<(const Score& other) const {
        return value < other.value;
    }

    friend ostream& operator<<(
        ostream& out,
        const Score& score
    ) {
        out << score.value;
        return out;
    }
};

int main() {
    cout << "=== DEMO 1: FUNCTION TEMPLATE ===\n";

    cout << "maximum(10, 20) = "
         << maximum(10, 20) << '\n';

    cout << "maximum(3.5, 2.1) = "
         << maximum(3.5, 2.1) << '\n';

    cout << "\n=== DEMO 2: EXPLICIT TEMPLATE ARGUMENT ===\n";

    cout << "maximum<int>(7, 4) = "
         << maximum<int>(7, 4) << '\n';

    cout << "\n=== DEMO 3: GENERIC SWAP ===\n";

    int a = 10;
    int b = 20;

    swapValues(a, b);

    cout << "Integers: "
         << a << ", " << b << '\n';

    string first = "left";
    string second = "right";

    swapValues(first, second);

    cout << "Strings: "
         << first << ", " << second << '\n';

    cout << "\n=== DEMO 4: MULTIPLE TEMPLATE PARAMETERS ===\n";

    showPair("age", 20);
    showPair(10, 3.14);

    cout << "\n=== DEMO 5: DEDUCED RETURN TYPE ===\n";

    cout << "add(10, 2.5) = "
         << add(10, 2.5) << '\n';

    cout << "\n=== DEMO 6: CLASS TEMPLATE ===\n";

    Box<int> number(42);
    Box<string> word("DSA");

    cout << "number = "
         << number.get() << '\n';

    cout << "word = "
         << word.get() << '\n';

    word.set("Algorithms");

    cout << "updated word = "
         << word.get() << '\n';

    cout << "\n=== DEMO 7: NON-TYPE PARAMETER ===\n";

    FixedArray<int, 3> values;

    values[0] = 10;
    values[1] = 20;
    values[2] = 30;

    cout << "Size = "
         << values.size() << '\n';

    cout << "Values = "
         << values[0] << ' '
         << values[1] << ' '
         << values[2] << '\n';

    cout << "\n=== DEMO 8: TEMPLATE + OVERLOAD ===\n";

    describe(100);
    describe(2.5);

    cout << "\n=== DEMO 9: CLASS SPECIALIZATION ===\n";

    TypePrinter<int> intPrinter;
    TypePrinter<bool> boolPrinter;

    intPrinter.print(25);
    boolPrinter.print(true);

    cout << "\n=== DEMO 10: CUSTOM TYPE ===\n";

    Score low(70);
    Score high(95);

    Score best = maximum(low, high);

    cout << "Maximum score = "
         << best << '\n';

    cout << "\nNext: 26_EXCEPTION_HANDLING\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: FUNCTION TEMPLATE ===
maximum(10, 20) = 20
maximum(3.5, 2.1) = 3.5

=== DEMO 2: EXPLICIT TEMPLATE ARGUMENT ===
maximum<int>(7, 4) = 7

=== DEMO 3: GENERIC SWAP ===
Integers: 20, 10
Strings: right, left

=== DEMO 4: MULTIPLE TEMPLATE PARAMETERS ===
age | 20
10 | 3.14

=== DEMO 5: DEDUCED RETURN TYPE ===
add(10, 2.5) = 12.5

=== DEMO 6: CLASS TEMPLATE ===
number = 42
word = DSA
updated word = Algorithms

=== DEMO 7: NON-TYPE PARAMETER ===
Size = 3
Values = 10 20 30

=== DEMO 8: TEMPLATE + OVERLOAD ===
Integer overload: 100
Generic value: 2.5

=== DEMO 9: CLASS SPECIALIZATION ===
Generic printer: 25
Boolean printer: true

=== DEMO 10: CUSTOM TYPE ===
Maximum score = 95

Next: 26_EXCEPTION_HANDLING
*/
