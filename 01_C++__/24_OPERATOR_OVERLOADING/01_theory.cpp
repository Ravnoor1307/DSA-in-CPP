/*
Topic: Operator Overloading

Covers:
- arithmetic operators
- compound assignment
- comparison
- prefix/postfix increment
- stream insertion/extraction
- subscript operator
- function-call operator
- member vs friend operators
- assignment basics

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: + AND += ==========

class Point {
private:
    int x;
    int y;

public:
    Point(int x = 0, int y = 0)
        : x(x), y(y) {
    }

    Point& operator+=(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    friend Point operator+(
        Point lhs,
        const Point& rhs
    ) {
        lhs += rhs;
        return lhs;
    }

    // ========== SECTION 2: COMPARISON ==========

    bool operator==(const Point& other) const {
        return x == other.x
            && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    // ========== SECTION 3: STREAM OPERATORS ==========

    friend ostream& operator<<(
        ostream& out,
        const Point& point
    ) {
        out << '('
            << point.x
            << ", "
            << point.y
            << ')';

        return out;
    }

    friend istream& operator>>(
        istream& in,
        Point& point
    ) {
        in >> point.x >> point.y;
        return in;
    }
};

// ========== SECTION 4: PREFIX AND POSTFIX ++ ==========

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

// ========== SECTION 5: SUBSCRIPT OPERATOR ==========

class Triple {
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

// ========== SECTION 6: FUNCTION-CALL OPERATOR ==========

class Multiplier {
private:
    int factor;

public:
    explicit Multiplier(int factor)
        : factor(factor) {
    }

    int operator()(int value) const {
        return factor * value;
    }
};

// ========== SECTION 7: ORDERING ==========
//
// We explicitly define lexicographical ordering:
// first compare x, then y.

class Coordinate {
private:
    int x;
    int y;

public:
    Coordinate(int x, int y)
        : x(x), y(y) {
    }

    bool operator<(const Coordinate& other) const {
        if (x != other.x) {
            return x < other.x;
        }

        return y < other.y;
    }
};

// ========== SECTION 8: ASSIGNMENT BASICS ==========

class Number {
private:
    int value;

public:
    explicit Number(int value = 0)
        : value(value) {
    }

    Number& operator=(const Number& other) {
        if (this != &other) {
            value = other.value;
        }

        return *this;
    }

    int get() const {
        return value;
    }
};

int main() {
    cout << boolalpha;

    cout << "=== DEMO 1: OPERATOR + ===\n";

    Point a(2, 3);
    Point b(5, 4);

    Point c = a + b;

    cout << a << " + "
         << b << " = "
         << c << '\n';

    cout << "\n=== DEMO 2: OPERATOR += ===\n";

    a += b;

    cout << "a after += b: "
         << a << '\n';

    cout << "\n=== DEMO 3: COMPARISON ===\n";

    Point first(1, 2);
    Point second(1, 2);
    Point third(9, 9);

    cout << "first == second: "
         << (first == second) << '\n';

    cout << "first != third: "
         << (first != third) << '\n';

    cout << "\n=== DEMO 4: PREFIX AND POSTFIX ===\n";

    Counter counter(5);

    Counter prefixResult = ++counter;

    cout << "After prefix: counter="
         << counter.get()
         << ", result="
         << prefixResult.get()
         << '\n';

    Counter postfixResult = counter++;

    cout << "After postfix: counter="
         << counter.get()
         << ", result="
         << postfixResult.get()
         << '\n';

    cout << "\n=== DEMO 5: SUBSCRIPT ===\n";

    Triple values;

    values[0] = 10;
    values[1] = 20;
    values[2] = 30;

    cout << values[0] << ' '
         << values[1] << ' '
         << values[2] << '\n';

    const Triple& readOnlyValues = values;

    cout << "Const access: "
         << readOnlyValues[1] << '\n';

    cout << "\n=== DEMO 6: FUNCTION-CALL OPERATOR ===\n";

    Multiplier triple(3);

    cout << "triple(7) = "
         << triple(7) << '\n';

    cout << "\n=== DEMO 7: ORDERING ===\n";

    Coordinate left(1, 5);
    Coordinate right(2, 0);

    cout << "(1,5) < (2,0): "
         << (left < right) << '\n';

    cout << "\n=== DEMO 8: COPY ASSIGNMENT ===\n";

    Number source(42);
    Number destination(10);

    destination = source;

    cout << "destination = "
         << destination.get() << '\n';

    destination = destination;

    cout << "after self-assignment = "
         << destination.get() << '\n';

    cout << "\n=== DEMO 9: STREAM EXTRACTION ===\n";

    // Interactive input would use:
    //
    // Point input;
    // cin >> input;
    //
    // The operator expects two integers.
    // We avoid requiring input in this runnable lecture.

    cout << "Point input syntax: cin >> point\n";

    cout << "\nNext: 25_TEMPLATES\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: OPERATOR + ===
(2, 3) + (5, 4) = (7, 7)

=== DEMO 2: OPERATOR += ===
a after += b: (7, 7)

=== DEMO 3: COMPARISON ===
first == second: true
first != third: true

=== DEMO 4: PREFIX AND POSTFIX ===
After prefix: counter=6, result=6
After postfix: counter=7, result=6

=== DEMO 5: SUBSCRIPT ===
10 20 30
Const access: 20

=== DEMO 6: FUNCTION-CALL OPERATOR ===
triple(7) = 21

=== DEMO 7: ORDERING ===
(1,5) < (2,0): true

=== DEMO 8: COPY ASSIGNMENT ===
destination = 42
after self-assignment = 42

=== DEMO 9: STREAM EXTRACTION ===
Point input syntax: cin >> point

Next: 25_TEMPLATES
*/
