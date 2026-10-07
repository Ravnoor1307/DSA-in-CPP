/*
Topic: Operator Overloading
File: 03_variation.cpp

Purpose:
Explore:
- non-member arithmetic
- const/non-const []
- function objects
- ordering
- stream chaining
- prefix/postfix differences

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>

using namespace std;

// ========== SECTION 1: NON-MEMBER ARITHMETIC ==========

class Money {
private:
    int amount;

public:
    explicit Money(int amount = 0)
        : amount(amount) {
    }

    Money& operator+=(const Money& other) {
        amount += other.amount;
        return *this;
    }

    int get() const {
        return amount;
    }
};

Money operator+(Money lhs, const Money& rhs) {
    lhs += rhs;
    return lhs;
}

// ========== SECTION 2: ARRAY-LIKE [] ==========

class FixedArray {
private:
    int values[3] = {0, 0, 0};

public:
    int& operator[](int index) {
        cout << "mutable []\n";
        return values[index];
    }

    const int& operator[](int index) const {
        cout << "const []\n";
        return values[index];
    }
};

// ========== SECTION 3: FUNCTION OBJECT ==========

class Add {
private:
    int amount;

public:
    explicit Add(int amount)
        : amount(amount) {
    }

    int operator()(int value) const {
        return value + amount;
    }
};

// ========== SECTION 4: ORDERING ==========

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
};

// ========== SECTION 5: STREAM CHAINING ==========

class Coordinate {
private:
    int x;
    int y;

public:
    Coordinate(int x, int y)
        : x(x), y(y) {
    }

    friend ostream& operator<<(
        ostream& out,
        const Coordinate& point
    ) {
        out << '('
            << point.x
            << ','
            << point.y
            << ')';

        return out;
    }
};

int main() {
    cout << boolalpha;

    cout << "=== VARIATION 1: NON-MEMBER + ===\n";

    Money a(100);
    Money b(50);

    Money c = a + b;

    cout << "Result = "
         << c.get() << '\n';

    cout << "\n=== VARIATION 2: [] CONST OVERLOAD ===\n";

    FixedArray array;

    array[0] = 10;
    array[1] = 20;

    const FixedArray& readOnly = array;

    cout << "Reading index 1:\n";
    cout << readOnly[1] << '\n';

    cout << "\n=== VARIATION 3: FUNCTION OBJECT ===\n";

    Add addFive(5);

    cout << "addFive(10) = "
         << addFive(10) << '\n';

    cout << "addFive(20) = "
         << addFive(20) << '\n';

    cout << "\n=== VARIATION 4: ORDERING ===\n";

    Score low(50);
    Score high(90);

    cout << "low < high: "
         << (low < high) << '\n';

    cout << "\n=== VARIATION 5: STREAM CHAINING ===\n";

    Coordinate first(1, 2);
    Coordinate second(3, 4);

    cout << first
         << " -> "
         << second
         << '\n';

    cout << "\nNext: 25_TEMPLATES\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: NON-MEMBER + ===
Result = 150

=== VARIATION 2: [] CONST OVERLOAD ===
mutable []
mutable []
Reading index 1:
const []
20

=== VARIATION 3: FUNCTION OBJECT ===
addFive(10) = 15
addFive(20) = 25

=== VARIATION 4: ORDERING ===
low < high: true

=== VARIATION 5: STREAM CHAINING ===
(1,2) -> (3,4)

Next: 25_TEMPLATES
*/
