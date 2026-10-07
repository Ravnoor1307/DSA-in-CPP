/*
Topic: OOP — Classes and Objects
File: 04_practice_problems.cpp

Beginner-friendly class exercises with working solutions.

Problems:
1. Rectangle
2. Bank Account
3. Student
4. Parking System
5. Simple Inventory Item

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
// Create a class that stores width and height.
// Prevent negative dimensions.
// Provide area and perimeter operations.
//
// Complexity:
// setDimensions: O(1)
// area:          O(1)
// perimeter:     O(1)

class Rectangle {
private:
    int width = 0;
    int height = 0;

public:
    bool setDimensions(int newWidth, int newHeight) {
        if (newWidth < 0 || newHeight < 0) {
            return false;
        }

        width = newWidth;
        height = newHeight;
        return true;
    }

    int area() const {
        return width * height;
    }

    int perimeter() const {
        return 2 * (width + height);
    }
};

// ========== PROBLEM 2: BANK ACCOUNT ==========
//
// Maintain a non-negative balance.
// Deposit only positive amounts.
// Withdraw only an amount available in the account.
//
// Complexity of each operation: O(1)

class BankAccount {
private:
    int balance = 0;

public:
    bool deposit(int amount) {
        if (amount <= 0) {
            return false;
        }

        balance += amount;
        return true;
    }

    bool withdraw(int amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }

        balance -= amount;
        return true;
    }

    int getBalance() const {
        return balance;
    }
};

// ========== PROBLEM 3: STUDENT ==========
//
// Store marks in three subjects.
// Compute total and average.
//
// We deliberately use three simple int members because vectors
// have not yet received their dedicated STL lesson.

class Student {
private:
    string name = "Unknown";
    int mark1 = 0;
    int mark2 = 0;
    int mark3 = 0;

    bool validMark(int mark) const {
        return mark >= 0 && mark <= 100;
    }

public:
    void setName(const string& newName) {
        name = newName;
    }

    bool setMarks(int a, int b, int c) {
        if (!validMark(a) || !validMark(b) || !validMark(c)) {
            return false;
        }

        mark1 = a;
        mark2 = b;
        mark3 = c;
        return true;
    }

    int total() const {
        return mark1 + mark2 + mark3;
    }

    double average() const {
        return total() / 3.0;
    }

    void display() const {
        cout << name
             << ": total=" << total()
             << ", average=" << average()
             << '\n';
    }
};

// ========== PROBLEM 4: PARKING SYSTEM ==========
//
// Inspired by LeetCode 1603:
// https://leetcode.com/problems/design-parking-system/
//
// Type:
// 1 = big
// 2 = medium
// 3 = small
//
// Since constructors are the NEXT lesson, capacities are configured
// with a normal setup method here.

class ParkingSystem {
private:
    int big = 0;
    int medium = 0;
    int small = 0;

public:
    void setup(int bigSpaces, int mediumSpaces, int smallSpaces) {
        if (bigSpaces >= 0 && mediumSpaces >= 0 && smallSpaces >= 0) {
            big = bigSpaces;
            medium = mediumSpaces;
            small = smallSpaces;
        }
    }

    bool addCar(int carType) {
        if (carType == 1 && big > 0) {
            --big;
            return true;
        }

        if (carType == 2 && medium > 0) {
            --medium;
            return true;
        }

        if (carType == 3 && small > 0) {
            --small;
            return true;
        }

        return false;
    }
};

// ========== PROBLEM 5: INVENTORY ITEM ==========
//
// An item has a price and quantity.
// Both must remain non-negative.
// inventoryValue() computes price * quantity.

class InventoryItem {
private:
    int price = 0;
    int quantity = 0;

public:
    bool setPrice(int newPrice) {
        if (newPrice < 0) {
            return false;
        }

        price = newPrice;
        return true;
    }

    bool addStock(int amount) {
        if (amount <= 0) {
            return false;
        }

        quantity += amount;
        return true;
    }

    bool sell(int amount) {
        if (amount <= 0 || amount > quantity) {
            return false;
        }

        quantity -= amount;
        return true;
    }

    int getQuantity() const {
        return quantity;
    }

    long long inventoryValue() const {
        // Cast before multiplication so the multiplication itself
        // takes place using long long.
        return static_cast<long long>(price) * quantity;
    }
};

int main() {
    cout << boolalpha;

    cout << "=== PROBLEM 1: RECTANGLE ===\n";

    Rectangle rectangle;

    cout << "Valid dimensions? "
         << rectangle.setDimensions(5, 3) << '\n';

    cout << "Area = " << rectangle.area() << '\n';
    cout << "Perimeter = " << rectangle.perimeter() << '\n';

    cout << "\n=== PROBLEM 2: BANK ACCOUNT ===\n";

    BankAccount account;

    account.deposit(500);

    cout << "Withdraw 120? "
         << account.withdraw(120) << '\n';

    cout << "Withdraw 500? "
         << account.withdraw(500) << '\n';

    cout << "Balance = "
         << account.getBalance() << '\n';

    cout << "\n=== PROBLEM 3: STUDENT ===\n";

    Student student;

    student.setName("Maya");

    cout << "Valid marks? "
         << student.setMarks(90, 80, 85) << '\n';

    student.display();

    cout << "\n=== PROBLEM 4: PARKING SYSTEM ===\n";

    ParkingSystem parking;
    parking.setup(1, 1, 0);

    cout << "Add big car: "
         << parking.addCar(1) << '\n';

    cout << "Add big car again: "
         << parking.addCar(1) << '\n';

    cout << "Add medium car: "
         << parking.addCar(2) << '\n';

    cout << "Add small car: "
         << parking.addCar(3) << '\n';

    cout << "\n=== PROBLEM 5: INVENTORY ===\n";

    InventoryItem item;

    item.setPrice(250);
    item.addStock(10);
    item.sell(3);

    cout << "Quantity = "
         << item.getQuantity() << '\n';

    cout << "Inventory value = "
         << item.inventoryValue() << '\n';

    cout << "\nNext: 19_CONSTRUCTORS_DESTRUCTORS\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: RECTANGLE ===
Valid dimensions? true
Area = 15
Perimeter = 16

=== PROBLEM 2: BANK ACCOUNT ===
Withdraw 120? true
Withdraw 500? false
Balance = 380

=== PROBLEM 3: STUDENT ===
Valid marks? true
Maya: total=255, average=85

=== PROBLEM 4: PARKING SYSTEM ===
Add big car: true
Add big car again: false
Add medium car: true
Add small car: false

=== PROBLEM 5: INVENTORY ===
Quantity = 7
Inventory value = 1750

Next: 19_CONSTRUCTORS_DESTRUCTORS
*/
