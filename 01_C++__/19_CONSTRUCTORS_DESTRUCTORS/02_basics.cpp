/*
Topic: Constructors and Destructors
File: 02_basics.cpp

Purpose:
Practice constructors, initializer lists, overloading,
delegation, destructors, and basic lifetime rules.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: PARAMETERIZED CONSTRUCTOR ==========

class Student {
private:
    string name;
    int marks;

public:
    Student(const string& name, int marks)
        : name(name), marks(marks) {
    }

    void display() const {
        cout << name << " -> " << marks << '\n';
    }
};

// ========== SECTION 2: OVERLOADING ==========

class Account {
private:
    int balance;

public:
    Account()
        : balance(0) {
    }

    Account(int initialBalance)
        : balance(initialBalance >= 0 ? initialBalance : 0) {
    }

    int getBalance() const {
        return balance;
    }
};

// ========== SECTION 3: DELEGATION ==========

class Dimensions {
private:
    int width;
    int height;

public:
    Dimensions()
        : Dimensions(1, 1) {
    }

    Dimensions(int side)
        : Dimensions(side, side) {
    }

    Dimensions(int width, int height)
        : width(width >= 0 ? width : 0),
          height(height >= 0 ? height : 0) {
    }

    int area() const {
        return width * height;
    }
};

// ========== SECTION 4: DESTRUCTOR TRACE ==========

class ScopeDemo {
private:
    string label;

public:
    ScopeDemo(const string& label)
        : label(label) {
        cout << "Enter lifetime: " << label << '\n';
    }

    ~ScopeDemo() {
        cout << "End lifetime: " << label << '\n';
    }
};

int main() {
    cout << "=== BASIC 1: STUDENT ===\n";

    Student first("Asha", 91);
    Student second("Ravi", 84);

    first.display();
    second.display();

    cout << "\n=== BASIC 2: OVERLOADED CONSTRUCTORS ===\n";

    Account emptyAccount;
    Account fundedAccount(500);
    Account invalidAccount(-100);

    cout << "Empty = " << emptyAccount.getBalance() << '\n';
    cout << "Funded = " << fundedAccount.getBalance() << '\n';
    cout << "Invalid input fallback = "
         << invalidAccount.getBalance() << '\n';

    cout << "\n=== BASIC 3: DELEGATION ===\n";

    Dimensions a;
    Dimensions b(4);
    Dimensions c(3, 5);

    cout << "Areas = "
         << a.area() << ", "
         << b.area() << ", "
         << c.area() << '\n';

    cout << "\n=== BASIC 4: SCOPE-BASED DESTRUCTION ===\n";

    ScopeDemo outer("outer");

    {
        ScopeDemo inner("inner");
        cout << "Inside nested block\n";
    }

    cout << "Back in outer block\n";

    cout << "\nNext: 20_INHERITANCE\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: STUDENT ===
Asha -> 91
Ravi -> 84

=== BASIC 2: OVERLOADED CONSTRUCTORS ===
Empty = 0
Funded = 500
Invalid input fallback = 0

=== BASIC 3: DELEGATION ===
Areas = 1, 16, 15

=== BASIC 4: SCOPE-BASED DESTRUCTION ===
Enter lifetime: outer
Enter lifetime: inner
Inside nested block
End lifetime: inner
Back in outer block

Next: 20_INHERITANCE
End lifetime: outer
*/
