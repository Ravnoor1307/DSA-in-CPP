/*
Topic: OOP — Classes and Objects

Covers:
- classes and objects
- state and behavior
- data members and member functions
- public/private access
- class scope
- this pointer
- const member functions
- object independence
- passing objects
- arrays and pointers to objects
- basic object copying
- struct versus class

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: A SIMPLE CLASS ==========
//
// A class defines a user-defined type.
// Each object is an instance of that type.

class Player {
public:
    string name = "Unknown";
    int health = 100;

    void takeDamage(int damage) {
        if (damage > 0) {
            health -= damage;

            if (health < 0) {
                health = 0;
            }
        }
    }

    void show() const {
        cout << name << " has " << health << " health\n";
    }
};

// ========== SECTION 2: PRIVATE DATA ==========
//
// Class members are private by default.
// Public methods can provide controlled access.

class BankAccount {
private:
    double balance = 0.0;

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }

        balance -= amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

// ========== SECTION 3: THIS POINTER ==========
//
// Inside a non-static member function, "this" points to
// the object for which the function was called.

class Number {
private:
    int value = 0;

public:
    void setValue(int value) {
        // Parameter and member have the same name.
        this->value = value;
    }

    int getValue() const {
        return this->value;
    }

    const Number* addressFromInside() const {
        return this;
    }
};

// ========== SECTION 4: OUT-OF-CLASS METHOD DEFINITION ==========

class Rectangle {
private:
    int width = 0;
    int height = 0;

public:
    void setDimensions(int width, int height);
    int area() const;
};

void Rectangle::setDimensions(int width, int height) {
    if (width >= 0 && height >= 0) {
        this->width = width;
        this->height = height;
    }
}

int Rectangle::area() const {
    return width * height;
}

// ========== SECTION 5: OBJECTS AS FUNCTION ARGUMENTS ==========

class Score {
public:
    int value = 0;
};

// Pass by value: receives a copy.
void changeCopy(Score score) {
    score.value = 999;
}

// Pass by reference: can modify original.
void changeOriginal(Score& score) {
    score.value = 80;
}

// Const reference: avoids a copy and prevents modification here.
void printScore(const Score& score) {
    cout << "Read-only score = " << score.value << '\n';
}

// ========== SECTION 6: RETURNING AN OBJECT ==========

class Point {
public:
    int x = 0;
    int y = 0;

    void print() const {
        cout << '(' << x << ", " << y << ')';
    }
};

Point makePoint(int x, int y) {
    Point result;
    result.x = x;
    result.y = y;
    return result;
}

// ========== SECTION 7: STRUCT VS CLASS ==========

struct PublicByDefault {
    int value = 10;
};

class PrivateByDefault {
    int value = 20;

public:
    int getValue() const {
        return value;
    }
};

int main() {
    cout << "=== DEMO 1: CLASS AND OBJECT ===\n";

    Player first;
    first.name = "Asha";
    first.health = 100;

    first.show();
    first.takeDamage(30);
    first.show();

    cout << "\n=== DEMO 2: OBJECTS HAVE INDEPENDENT STATE ===\n";

    Player second;
    second.name = "Ravi";
    second.health = 70;

    first.takeDamage(20);

    first.show();
    second.show();

    cout << "\n=== DEMO 3: PRIVATE DATA AND CONTROLLED METHODS ===\n";

    BankAccount account;

    account.deposit(1000);
    cout << "After deposit: " << account.getBalance() << '\n';

    cout << "Withdraw 250: "
         << (account.withdraw(250) ? "success" : "failed") << '\n';

    cout << "Balance: " << account.getBalance() << '\n';

    cout << "Withdraw 1000: "
         << (account.withdraw(1000) ? "success" : "failed") << '\n';

    cout << "Balance: " << account.getBalance() << '\n';

    cout << "\n=== DEMO 4: THE this POINTER ===\n";

    Number number;
    number.setValue(42);

    cout << "Stored value = " << number.getValue() << '\n';
    cout << boolalpha;
    cout << "this points to the current object: "
         << (number.addressFromInside() == &number) << '\n';

    cout << "\n=== DEMO 5: METHOD DEFINED OUTSIDE CLASS ===\n";

    Rectangle rectangle;
    rectangle.setDimensions(6, 4);

    cout << "Rectangle area = " << rectangle.area() << '\n';

    cout << "\n=== DEMO 6: PASSING OBJECTS ===\n";

    Score score;
    score.value = 50;

    cout << "Before changeCopy: " << score.value << '\n';
    changeCopy(score);
    cout << "After changeCopy: " << score.value << '\n';

    changeOriginal(score);
    cout << "After changeOriginal: " << score.value << '\n';

    printScore(score);

    cout << "\n=== DEMO 7: RETURNING OBJECTS ===\n";

    Point point = makePoint(3, 7);

    cout << "Returned point = ";
    point.print();
    cout << '\n';

    cout << "\n=== DEMO 8: ARRAY OF OBJECTS ===\n";

    Point points[3];

    points[0].x = 1;
    points[0].y = 2;

    points[1].x = 3;
    points[1].y = 4;

    points[2].x = 5;
    points[2].y = 6;

    for (int i = 0; i < 3; ++i) {
        cout << "points[" << i << "] = ";
        points[i].print();
        cout << '\n';
    }

    cout << "\n=== DEMO 9: POINTER TO OBJECT ===\n";

    Player pointerDemo;
    pointerDemo.name = "Mina";

    Player* playerPtr = &pointerDemo;

    playerPtr->health = 88;
    playerPtr->show();

    cout << "\n=== DEMO 10: COPYING A SIMPLE OBJECT ===\n";

    Point original;
    original.x = 10;
    original.y = 20;

    Point copied = original;
    copied.x = 99;

    cout << "Original = ";
    original.print();

    cout << "\nCopy     = ";
    copied.print();

    cout << '\n';

    cout << "\n=== DEMO 11: CONST OBJECT ===\n";

    const Point fixedPoint = makePoint(8, 9);

    cout << "Const point = ";
    fixedPoint.print();
    cout << '\n';

    // fixedPoint.x = 100; // ERROR: fixedPoint is const.
    // fixedPoint.print() works because print() is const.

    cout << "\n=== DEMO 12: STRUCT VS CLASS DEFAULT ACCESS ===\n";

    PublicByDefault s;
    PrivateByDefault c;

    cout << "struct public member = " << s.value << '\n';
    cout << "class private member through getter = "
         << c.getValue() << '\n';

    cout << "\nNext: 19_CONSTRUCTORS_DESTRUCTORS\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: CLASS AND OBJECT ===
Asha has 100 health
Asha has 70 health

=== DEMO 2: OBJECTS HAVE INDEPENDENT STATE ===
Asha has 50 health
Ravi has 70 health

=== DEMO 3: PRIVATE DATA AND CONTROLLED METHODS ===
After deposit: 1000
Withdraw 250: success
Balance: 750
Withdraw 1000: failed
Balance: 750

=== DEMO 4: THE this POINTER ===
Stored value = 42
this points to the current object: true

=== DEMO 5: METHOD DEFINED OUTSIDE CLASS ===
Rectangle area = 24

=== DEMO 6: PASSING OBJECTS ===
Before changeCopy: 50
After changeCopy: 50
After changeOriginal: 80
Read-only score = 80

=== DEMO 7: RETURNING OBJECTS ===
Returned point = (3, 7)

=== DEMO 8: ARRAY OF OBJECTS ===
points[0] = (1, 2)
points[1] = (3, 4)
points[2] = (5, 6)

=== DEMO 9: POINTER TO OBJECT ===
Mina has 88 health

=== DEMO 10: COPYING A SIMPLE OBJECT ===
Original = (10, 20)
Copy     = (99, 20)

=== DEMO 11: CONST OBJECT ===
Const point = (8, 9)

=== DEMO 12: STRUCT VS CLASS DEFAULT ACCESS ===
struct public member = 10
class private member through getter = 20

Next: 19_CONSTRUCTORS_DESTRUCTORS
*/
