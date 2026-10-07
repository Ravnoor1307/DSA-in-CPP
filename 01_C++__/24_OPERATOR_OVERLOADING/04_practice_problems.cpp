/*
Topic: Operator Overloading
File: 04_practice_problems.cpp

Practice:
1. 2D vector arithmetic
2. Fraction equality
3. Counter prefix/postfix increment
4. Fixed-size array subscript
5. Callable range checker

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>

using namespace std;

// ========== PROBLEM 1: 2D VECTOR ==========
//
// Implement:
// +
// +=
// ==
// <<
//
// Complexity: O(1)

class Vector2D {
private:
    int x;
    int y;

public:
    Vector2D(int x = 0, int y = 0)
        : x(x), y(y) {
    }

    Vector2D& operator+=(const Vector2D& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    friend Vector2D operator+(
        Vector2D lhs,
        const Vector2D& rhs
    ) {
        lhs += rhs;
        return lhs;
    }

    bool operator==(const Vector2D& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    friend ostream& operator<<(
        ostream& out,
        const Vector2D& vector
    ) {
        out << '<'
            << vector.x
            << ", "
            << vector.y
            << '>';

        return out;
    }
};

// ========== PROBLEM 2: FRACTION EQUALITY ==========
//
// Compare fractions using cross multiplication.
//
// Example:
// 1/2 == 2/4
//
// We use long long during multiplication to reduce the chance of
// overflow compared with int multiplication.

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
        : numerator(numerator),
          denominator(denominator == 0 ? 1 : denominator) {
    }

    bool operator==(const Fraction& rhs) const {
        return static_cast<long long>(numerator)
                   * rhs.denominator
            == static_cast<long long>(rhs.numerator)
                   * denominator;
    }

    bool operator!=(const Fraction& rhs) const {
        return !(*this == rhs);
    }
};

// ========== PROBLEM 3: COUNTER ==========

class Counter {
private:
    int value;

public:
    explicit Counter(int value = 0)
        : value(value) {
    }

    Counter& operator++() {
        ++value;
        return *this;
    }

    Counter operator++(int) {
        Counter old = *this;
        ++(*this);
        return old;
    }

    int get() const {
        return value;
    }
};

// ========== PROBLEM 4: FIXED ARRAY ==========
//
// operator[] is O(1).
//
// This learning version assumes valid indices 0..2.
// A production abstraction should clearly document or enforce its
// bounds policy.

class ThreeValues {
private:
    int values[3] = {0, 0, 0};

public:
    int& operator[](int index) {
        return values[index];
    }

    const int& operator[](int index) const {
        return values[index];
    }
};

// ========== PROBLEM 5: CALLABLE RANGE CHECKER ==========
//
// Build an object such that:
//
// InRange checker(10, 20);
// checker(15) -> true
// checker(30) -> false

class InRange {
private:
    int low;
    int high;

public:
    InRange(int first, int second)
        : low(first <= second ? first : second),
          high(first <= second ? second : first) {
    }

    bool operator()(int value) const {
        return value >= low && value <= high;
    }
};

int main() {
    cout << boolalpha;

    cout << "=== PROBLEM 1: VECTOR2D ===\n";

    Vector2D a(2, 3);
    Vector2D b(4, 5);

    Vector2D c = a + b;

    cout << a
         << " + "
         << b
         << " = "
         << c
         << '\n';

    a += b;

    cout << "a after += : "
         << a << '\n';

    cout << "a == c: "
         << (a == c) << '\n';

    cout << "\n=== PROBLEM 2: FRACTION ===\n";

    Fraction half(1, 2);
    Fraction twoFourths(2, 4);
    Fraction third(1, 3);

    cout << "1/2 == 2/4: "
         << (half == twoFourths)
         << '\n';

    cout << "1/2 != 1/3: "
         << (half != third)
         << '\n';

    cout << "\n=== PROBLEM 3: COUNTER ===\n";

    Counter counter(5);

    Counter old = counter++;

    cout << "Postfix returned = "
         << old.get() << '\n';

    cout << "Current = "
         << counter.get() << '\n';

    Counter& current = ++counter;

    cout << "Prefix returned = "
         << current.get() << '\n';

    cout << "\n=== PROBLEM 4: SUBSCRIPT ===\n";

    ThreeValues values;

    values[0] = 10;
    values[1] = 20;
    values[2] = 30;

    cout << values[0] << ' '
         << values[1] << ' '
         << values[2] << '\n';

    const ThreeValues& readOnly = values;

    cout << "Const read = "
         << readOnly[2] << '\n';

    cout << "\n=== PROBLEM 5: CALLABLE OBJECT ===\n";

    InRange checker(10, 20);

    cout << "15 in range? "
         << checker(15) << '\n';

    cout << "30 in range? "
         << checker(30) << '\n';

    cout << "\nNext: 25_TEMPLATES\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: VECTOR2D ===
<2, 3> + <4, 5> = <6, 8>
a after += : <6, 8>
a == c: true

=== PROBLEM 2: FRACTION ===
1/2 == 2/4: true
1/2 != 1/3: true

=== PROBLEM 3: COUNTER ===
Postfix returned = 5
Current = 6
Prefix returned = 7

=== PROBLEM 4: SUBSCRIPT ===
10 20 30
Const read = 30

=== PROBLEM 5: CALLABLE OBJECT ===
15 in range? true
30 in range? false

Next: 25_TEMPLATES
*/
