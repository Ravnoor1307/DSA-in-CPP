/*
Topic: Constructors and Destructors
File: 04_practice_problems.cpp

Practice implementations:
1. Rectangle constructor overloading
2. Bank account initialization
3. Immutable ID with const member
4. Constructor delegation
5. Resource-owner lifetime demonstration

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <string>

using namespace std;

// ========== PROBLEM 1: RECTANGLE ==========
//
// Requirements:
// - default rectangle should be 1 x 1
// - one argument creates a square
// - two arguments create a rectangle
//
// Complexity: O(1) per operation.

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle()
        : Rectangle(1, 1) {
    }

    Rectangle(int side)
        : Rectangle(side, side) {
    }

    Rectangle(int width, int height)
        : width(width >= 0 ? width : 0),
          height(height >= 0 ? height : 0) {
    }

    int area() const {
        return width * height;
    }
};

// ========== PROBLEM 2: BANK ACCOUNT ==========
//
// Require the owner's name when constructing the account.
// Initial balance must not be negative.

class BankAccount {
private:
    string owner;
    int balance;

public:
    BankAccount(const string& owner, int initialBalance)
        : owner(owner),
          balance(initialBalance >= 0 ? initialBalance : 0) {
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void display() const {
        cout << owner << ": " << balance << '\n';
    }
};

// ========== PROBLEM 3: IMMUTABLE ID ==========
//
// The ID should be established during construction and
// should not later be changed.
//
// A const member must be initialized with an initializer list.

class Employee {
private:
    const int id;
    string name;

public:
    Employee(int id, const string& name)
        : id(id), name(name) {
    }

    int getId() const {
        return id;
    }

    const string& getName() const {
        return name;
    }
};

// ========== PROBLEM 4: TIMER ==========
//
// Use constructor delegation to avoid duplicating initialization.

class Timer {
private:
    int minutes;
    int seconds;

public:
    Timer()
        : Timer(0, 0) {
    }

    Timer(int totalSeconds)
        : Timer(totalSeconds / 60, totalSeconds % 60) {
    }

    Timer(int minutes, int seconds)
        : minutes(minutes >= 0 ? minutes : 0),
          seconds(seconds >= 0 && seconds < 60 ? seconds : 0) {
    }

    void display() const {
        cout << minutes << "m " << seconds << "s\n";
    }
};

// ========== PROBLEM 5: SIMPLE RESOURCE OWNER ==========
//
// This exercise demonstrates acquisition and release.
//
// IMPORTANT:
// This class deliberately disables copying because a shallow
// pointer copy would make two owners delete the same memory.
//
// "= delete" tells the compiler that these operations are forbidden.
// Full copy/move design and RAII are covered later.

class IntOwner {
private:
    int* data;

public:
    IntOwner(int value)
        : data(new int(value)) {
        cout << "Allocated value " << *data << '\n';
    }

    IntOwner(const IntOwner&) = delete;
    IntOwner& operator=(const IntOwner&) = delete;

    int get() const {
        return *data;
    }

    ~IntOwner() {
        cout << "Releasing value " << *data << '\n';
        delete data;
    }
};

int main() {
    cout << "=== PROBLEM 1: RECTANGLE ===\n";

    Rectangle a;
    Rectangle b(5);
    Rectangle c(4, 6);

    cout << "Areas = "
         << a.area() << ", "
         << b.area() << ", "
         << c.area() << '\n';

    cout << "\n=== PROBLEM 2: BANK ACCOUNT ===\n";

    BankAccount account("Asha", 500);

    account.deposit(250);
    account.display();

    cout << "\n=== PROBLEM 3: IMMUTABLE ID ===\n";

    Employee employee(101, "Ravi");

    cout << employee.getName()
         << " has ID "
         << employee.getId() << '\n';

    cout << "\n=== PROBLEM 4: DELEGATING TIMER ===\n";

    Timer first;
    Timer second(125);
    Timer third(3, 45);

    first.display();
    second.display();
    third.display();

    cout << "\n=== PROBLEM 5: RESOURCE LIFETIME ===\n";

    {
        IntOwner owner(42);

        cout << "Owned value = "
             << owner.get() << '\n';

        // IntOwner copy = owner;
        // The line above intentionally does not compile because
        // copying was disabled to prevent double deletion.
    }

    cout << "Resource-owning object left its scope\n";

    cout << "\nNext: 20_INHERITANCE\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: RECTANGLE ===
Areas = 1, 25, 24

=== PROBLEM 2: BANK ACCOUNT ===
Asha: 750

=== PROBLEM 3: IMMUTABLE ID ===
Ravi has ID 101

=== PROBLEM 4: DELEGATING TIMER ===
0m 0s
2m 5s
3m 45s

=== PROBLEM 5: RESOURCE LIFETIME ===
Allocated value 42
Owned value = 42
Releasing value 42
Resource-owning object left its scope

Next: 20_INHERITANCE
*/
