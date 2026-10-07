/*
Topic: OOP — Classes and Objects
File: 03_variation.cpp

Purpose:
Explore useful variations:
- methods defined outside a class
- const correctness
- pass by value vs reference
- returning objects
- object pointers
- dynamic objects
- simple object copying

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>

using namespace std;

// ========== SECTION 1: OUT-OF-CLASS DEFINITIONS ==========

class Wallet {
private:
    int money = 0;

public:
    void add(int amount);
    bool spend(int amount);
    int getMoney() const;
};

void Wallet::add(int amount) {
    if (amount > 0) {
        money += amount;
    }
}

bool Wallet::spend(int amount) {
    if (amount <= 0 || amount > money) {
        return false;
    }

    money -= amount;
    return true;
}

int Wallet::getMoney() const {
    return money;
}

// ========== SECTION 2: PASSING OBJECTS ==========

void modifyCopy(Wallet wallet) {
    wallet.add(1000);

    cout << "Inside modifyCopy = "
         << wallet.getMoney() << '\n';
}

void modifyOriginal(Wallet& wallet) {
    wallet.add(50);
}

// ========== SECTION 3: RETURNING OBJECTS ==========

class Coordinate {
public:
    int x = 0;
    int y = 0;

    void print() const {
        cout << '(' << x << ", " << y << ')';
    }
};

Coordinate shifted(Coordinate point, int dx, int dy) {
    // point is a copy.
    point.x += dx;
    point.y += dy;

    return point;
}

// ========== SECTION 4: OBJECT POINTERS ==========

class Light {
private:
    bool on = false;

public:
    void turnOn() {
        on = true;
    }

    void turnOff() {
        on = false;
    }

    bool isOn() const {
        return on;
    }
};

// ========== SECTION 5: COPY INDEPENDENCE FOR VALUE MEMBERS ==========

class Pair {
public:
    int first = 0;
    int second = 0;
};

int main() {
    cout << "=== VARIATION 1: OUT-OF-CLASS METHODS ===\n";

    Wallet wallet;
    wallet.add(200);
    wallet.spend(40);

    cout << "Wallet = " << wallet.getMoney() << '\n';

    cout << "\n=== VARIATION 2: VALUE VS REFERENCE ===\n";

    cout << "Before copy call = " << wallet.getMoney() << '\n';

    modifyCopy(wallet);

    cout << "After copy call = " << wallet.getMoney() << '\n';

    modifyOriginal(wallet);

    cout << "After reference call = "
         << wallet.getMoney() << '\n';

    cout << "\n=== VARIATION 3: RETURNING AN OBJECT ===\n";

    Coordinate original;
    original.x = 2;
    original.y = 3;

    Coordinate moved = shifted(original, 10, -1);

    cout << "Original: ";
    original.print();

    cout << "\nShifted: ";
    moved.print();

    cout << '\n';

    cout << "\n=== VARIATION 4: POINTER TO STACK OBJECT ===\n";

    Light lamp;
    Light* ptr = &lamp;

    ptr->turnOn();

    cout << "Lamp on? "
         << boolalpha << ptr->isOn() << '\n';

    ptr->turnOff();

    cout << "Lamp on after turnOff? "
         << ptr->isOn() << '\n';

    cout << "\n=== VARIATION 5: DYNAMIC OBJECT ===\n";

    Light* dynamicLight = new Light;

    dynamicLight->turnOn();

    cout << "Dynamic light on? "
         << dynamicLight->isOn() << '\n';

    delete dynamicLight;
    dynamicLight = nullptr;

    cout << "Dynamic pointer reset? "
         << (dynamicLight == nullptr) << '\n';

    cout << "\n=== VARIATION 6: SIMPLE OBJECT COPY ===\n";

    Pair a;
    a.first = 10;
    a.second = 20;

    Pair b = a;

    b.first = 99;

    cout << "a = " << a.first << ", " << a.second << '\n';
    cout << "b = " << b.first << ", " << b.second << '\n';

    cout << "\n=== VARIATION 7: CONST READING ===\n";

    const Coordinate fixed = shifted(original, 1, 1);

    fixed.print();
    cout << '\n';

    // fixed.x = 100;
    // The line above would fail because fixed is const.

    cout << "\nNext: 19_CONSTRUCTORS_DESTRUCTORS\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: OUT-OF-CLASS METHODS ===
Wallet = 160

=== VARIATION 2: VALUE VS REFERENCE ===
Before copy call = 160
Inside modifyCopy = 1160
After copy call = 160
After reference call = 210

=== VARIATION 3: RETURNING AN OBJECT ===
Original: (2, 3)
Shifted: (12, 2)

=== VARIATION 4: POINTER TO STACK OBJECT ===
Lamp on? true
Lamp on after turnOff? false

=== VARIATION 5: DYNAMIC OBJECT ===
Dynamic light on? true
Dynamic pointer reset? true

=== VARIATION 6: SIMPLE OBJECT COPY ===
a = 10, 20
b = 99, 20

=== VARIATION 7: CONST READING ===
(3, 4)

Next: 19_CONSTRUCTORS_DESTRUCTORS
*/
