/*
Topic: static, const, and friend
File: 02_basics.cpp

Purpose:
Practice:
- shared static state
- static utility functions
- const-correct accessors
- mutable bookkeeping
- friend functions

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: STATIC ID GENERATOR ==========

class User {
private:
    inline static int nextId = 1;

    int id;
    string name;

public:
    explicit User(const string& name)
        : id(nextId++),
          name(name) {
    }

    int getId() const {
        return id;
    }

    const string& getName() const {
        return name;
    }

    static int peekNextId() {
        return nextId;
    }
};

// ========== SECTION 2: CLASS CONSTANT ==========

class Game {
public:
    inline static constexpr int MAX_PLAYERS = 4;
};

// ========== SECTION 3: CONST-CORRECT CLASS ==========

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle(int width, int height)
        : width(width >= 0 ? width : 0),
          height(height >= 0 ? height : 0) {
    }

    int widthValue() const {
        return width;
    }

    int heightValue() const {
        return height;
    }

    int area() const {
        return width * height;
    }
};

// ========== SECTION 4: mutable BOOKKEEPING ==========

class Calculator {
private:
    mutable int calculations = 0;

public:
    int square(int value) const {
        ++calculations;
        return value * value;
    }

    int calculationCount() const {
        return calculations;
    }
};

// ========== SECTION 5: FRIEND HELPER ==========

class Distance {
private:
    int meters;

public:
    explicit Distance(int meters)
        : meters(meters >= 0 ? meters : 0) {
    }

    friend int difference(
        const Distance& a,
        const Distance& b
    );
};

int difference(
    const Distance& a,
    const Distance& b
) {
    int result = a.meters - b.meters;

    return result >= 0 ? result : -result;
}

int main() {
    cout << "=== BASIC 1: STATIC ID ===\n";

    User first("Asha");
    User second("Ravi");
    User third("Mina");

    cout << first.getName()
         << " -> "
         << first.getId() << '\n';

    cout << second.getName()
         << " -> "
         << second.getId() << '\n';

    cout << third.getName()
         << " -> "
         << third.getId() << '\n';

    cout << "Next ID = "
         << User::peekNextId() << '\n';

    cout << "\n=== BASIC 2: CLASS CONSTANT ===\n";

    cout << "Maximum players = "
         << Game::MAX_PLAYERS << '\n';

    cout << "\n=== BASIC 3: CONST CORRECTNESS ===\n";

    const Rectangle rectangle(5, 4);

    cout << "Width = "
         << rectangle.widthValue() << '\n';

    cout << "Height = "
         << rectangle.heightValue() << '\n';

    cout << "Area = "
         << rectangle.area() << '\n';

    cout << "\n=== BASIC 4: mutable BOOKKEEPING ===\n";

    const Calculator calculator;

    cout << "square(4) = "
         << calculator.square(4) << '\n';

    cout << "square(5) = "
         << calculator.square(5) << '\n';

    cout << "Calculations = "
         << calculator.calculationCount() << '\n';

    cout << "\n=== BASIC 5: FRIEND FUNCTION ===\n";

    Distance a(100);
    Distance b(65);

    cout << "Difference = "
         << difference(a, b)
         << " meters\n";

    cout << "\nNext: 24_OPERATOR_OVERLOADING\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: STATIC ID ===
Asha -> 1
Ravi -> 2
Mina -> 3
Next ID = 4

=== BASIC 2: CLASS CONSTANT ===
Maximum players = 4

=== BASIC 3: CONST CORRECTNESS ===
Width = 5
Height = 4
Area = 20

=== BASIC 4: mutable BOOKKEEPING ===
square(4) = 16
square(5) = 25
Calculations = 2

=== BASIC 5: FRIEND FUNCTION ===
Difference = 35 meters

Next: 24_OPERATOR_OVERLOADING
*/
