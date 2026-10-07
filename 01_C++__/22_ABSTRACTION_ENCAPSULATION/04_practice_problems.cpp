/*
Topic: Abstraction and Encapsulation
File: 04_practice_problems.cpp

Practice:
1. Bank account invariant
2. Valid percentage
3. Fixed-capacity queue abstraction
4. Door state machine
5. Payment abstraction

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <string>

using namespace std;

// ========== PROBLEM 1: BANK ACCOUNT ==========
//
// Requirements:
// - balance must never become negative
// - deposits must be positive
// - withdrawals must be positive and affordable

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

// ========== PROBLEM 2: PERCENTAGE ==========
//
// Invariant:
// 0 <= value <= 100

class Percentage {
private:
    int value = 0;

public:
    bool set(int newValue) {
        if (newValue < 0 || newValue > 100) {
            return false;
        }

        value = newValue;
        return true;
    }

    int get() const {
        return value;
    }

    bool passed() const {
        return value >= 40;
    }
};

// ========== PROBLEM 3: SMALL QUEUE ==========
//
// Hide all index-management details from callers.
//
// This simple implementation shifts elements after a pop.
// Therefore:
//
// push: O(1)
// pop:  O(n)
//
// A later queue lesson develops better implementations.

class SmallQueue {
private:
    static const int CAPACITY = 5;

    int values[CAPACITY] = {};
    int size = 0;

public:
    bool push(int value) {
        if (size == CAPACITY) {
            return false;
        }

        values[size] = value;
        ++size;
        return true;
    }

    bool pop() {
        if (size == 0) {
            return false;
        }

        for (int i = 1; i < size; ++i) {
            values[i - 1] = values[i];
        }

        --size;
        return true;
    }

    bool front(int& result) const {
        if (size == 0) {
            return false;
        }

        result = values[0];
        return true;
    }

    int count() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }
};

// ========== PROBLEM 4: DOOR STATE ==========
//
// Outside code cannot arbitrarily modify the state.
//
// Operations define legal transitions.

class Door {
private:
    bool open = false;
    bool locked = false;

public:
    bool openDoor() {
        if (locked || open) {
            return false;
        }

        open = true;
        return true;
    }

    bool closeDoor() {
        if (!open) {
            return false;
        }

        open = false;
        return true;
    }

    bool lock() {
        if (open || locked) {
            return false;
        }

        locked = true;
        return true;
    }

    bool unlock() {
        if (!locked) {
            return false;
        }

        locked = false;
        return true;
    }

    void display() const {
        cout << "Door: "
             << (open ? "open" : "closed")
             << ", "
             << (locked ? "locked" : "unlocked")
             << '\n';
    }
};

// ========== PROBLEM 5: PAYMENT ABSTRACTION ==========

class PaymentMethod {
public:
    virtual void pay(int amount) const = 0;
    virtual ~PaymentMethod() = default;
};

class Cash : public PaymentMethod {
public:
    void pay(int amount) const override {
        cout << "Cash payment of "
             << amount << '\n';
    }
};

class Card : public PaymentMethod {
public:
    void pay(int amount) const override {
        cout << "Card payment of "
             << amount << '\n';
    }
};

void checkout(
    const PaymentMethod& method,
    int amount
) {
    method.pay(amount);
}

int main() {
    cout << boolalpha;

    cout << "=== PROBLEM 1: BANK ACCOUNT ===\n";

    BankAccount account;

    cout << "Deposit 500: "
         << account.deposit(500) << '\n';

    cout << "Withdraw 200: "
         << account.withdraw(200) << '\n';

    cout << "Withdraw 500: "
         << account.withdraw(500) << '\n';

    cout << "Balance = "
         << account.getBalance() << '\n';

    cout << "\n=== PROBLEM 2: PERCENTAGE ===\n";

    Percentage percentage;

    cout << "Set 75: "
         << percentage.set(75) << '\n';

    cout << "Set 120: "
         << percentage.set(120) << '\n';

    cout << "Value = "
         << percentage.get() << '\n';

    cout << "Passed? "
         << percentage.passed() << '\n';

    cout << "\n=== PROBLEM 3: QUEUE ABSTRACTION ===\n";

    SmallQueue queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    int frontValue = 0;

    if (queue.front(frontValue)) {
        cout << "Front = "
             << frontValue << '\n';
    }

    queue.pop();

    if (queue.front(frontValue)) {
        cout << "After pop, front = "
             << frontValue << '\n';
    }

    cout << "Count = "
         << queue.count() << '\n';

    cout << "\n=== PROBLEM 4: DOOR STATE ===\n";

    Door door;

    door.display();

    cout << "Lock: "
         << door.lock() << '\n';

    cout << "Open while locked: "
         << door.openDoor() << '\n';

    cout << "Unlock: "
         << door.unlock() << '\n';

    cout << "Open: "
         << door.openDoor() << '\n';

    door.display();

    cout << "\n=== PROBLEM 5: PAYMENT ABSTRACTION ===\n";

    Cash cash;
    Card card;

    checkout(cash, 500);
    checkout(card, 750);

    cout << "\nNext: 23_STATIC_CONST_FRIEND\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: BANK ACCOUNT ===
Deposit 500: true
Withdraw 200: true
Withdraw 500: false
Balance = 300

=== PROBLEM 2: PERCENTAGE ===
Set 75: true
Set 120: false
Value = 75
Passed? true

=== PROBLEM 3: QUEUE ABSTRACTION ===
Front = 10
After pop, front = 20
Count = 2

=== PROBLEM 4: DOOR STATE ===
Door: closed, unlocked
Lock: true
Open while locked: false
Unlock: true
Open: true
Door: open, unlocked

=== PROBLEM 5: PAYMENT ABSTRACTION ===
Cash payment of 500
Card payment of 750

Next: 23_STATIC_CONST_FRIEND
*/
