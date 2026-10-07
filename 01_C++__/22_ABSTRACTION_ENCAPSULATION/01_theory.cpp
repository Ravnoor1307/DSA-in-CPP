/*
Topic: Abstraction and Encapsulation

Covers:
- encapsulation
- data hiding
- controlled interfaces
- invariants
- abstraction
- interface vs implementation
- abstract interfaces
- composition
- const-correct queries
- DSA-style abstraction

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: ENCAPSULATION ==========

class BankAccount {
private:
    int balance;

public:
    explicit BankAccount(int initialBalance)
        : balance(initialBalance >= 0 ? initialBalance : 0) {
    }

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

// ========== SECTION 2: PRESERVING AN INVARIANT ==========
//
// Invariant:
// 0 <= percentage <= 100

class Percentage {
private:
    int value;

public:
    explicit Percentage(int value)
        : value(0) {
        set(value);
    }

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
};

// ========== SECTION 3: ABSTRACTION WITHOUT INHERITANCE ==========

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

// ========== SECTION 4: COMPOSITION HIDES DETAILS ==========

class Engine {
public:
    void ignite() const {
        cout << "Engine ignited\n";
    }
};

class Car {
private:
    Engine engine;

public:
    void start() const {
        engine.ignite();
        cout << "Car started\n";
    }
};

// ========== SECTION 5: ABSTRACT INTERFACE ==========

class Notification {
public:
    virtual void send() const = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
public:
    void send() const override {
        cout << "Email sent\n";
    }
};

class SMSNotification : public Notification {
public:
    void send() const override {
        cout << "SMS sent\n";
    }
};

void deliver(const Notification& notification) {
    notification.send();
}

// ========== SECTION 6: SIMPLE STACK ABSTRACTION ==========
//
// This intentionally uses a fixed C-style array because STL gets
// dedicated lessons later.

class SmallStack {
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

        --size;
        return true;
    }

    bool empty() const {
        return size == 0;
    }

    int count() const {
        return size;
    }

    bool peek(int& result) const {
        if (empty()) {
            return false;
        }

        result = values[size - 1];
        return true;
    }
};

int main() {
    cout << boolalpha;

    cout << "=== DEMO 1: ENCAPSULATED BANK ACCOUNT ===\n";

    BankAccount account(500);

    cout << "Initial balance = "
         << account.getBalance() << '\n';

    cout << "Withdraw 200: "
         << account.withdraw(200) << '\n';

    cout << "Balance = "
         << account.getBalance() << '\n';

    cout << "Withdraw 700: "
         << account.withdraw(700) << '\n';

    cout << "Balance remains = "
         << account.getBalance() << '\n';

    cout << "\n=== DEMO 2: INVARIANT ===\n";

    Percentage percentage(80);

    cout << "Initial percentage = "
         << percentage.get() << '\n';

    cout << "Set 95: "
         << percentage.set(95) << '\n';

    cout << "Set 150: "
         << percentage.set(150) << '\n';

    cout << "Final percentage = "
         << percentage.get() << '\n';

    cout << "\n=== DEMO 3: SIMPLE ABSTRACTION ===\n";

    Light light;

    light.turnOn();

    cout << "Light on? "
         << light.isOn() << '\n';

    light.turnOff();

    cout << "Light on? "
         << light.isOn() << '\n';

    cout << "\n=== DEMO 4: COMPOSITION ===\n";

    Car car;
    car.start();

    cout << "\n=== DEMO 5: ABSTRACT INTERFACE ===\n";

    EmailNotification email;
    SMSNotification sms;

    deliver(email);
    deliver(sms);

    cout << "\n=== DEMO 6: STACK ABSTRACTION ===\n";

    SmallStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    int topValue = 0;

    if (stack.peek(topValue)) {
        cout << "Top = " << topValue << '\n';
    }

    cout << "Count = " << stack.count() << '\n';

    stack.pop();

    if (stack.peek(topValue)) {
        cout << "After pop, top = "
             << topValue << '\n';
    }

    cout << "\nNext: 23_STATIC_CONST_FRIEND\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: ENCAPSULATED BANK ACCOUNT ===
Initial balance = 500
Withdraw 200: true
Balance = 300
Withdraw 700: false
Balance remains = 300

=== DEMO 2: INVARIANT ===
Initial percentage = 80
Set 95: true
Set 150: false
Final percentage = 95

=== DEMO 3: SIMPLE ABSTRACTION ===
Light on? true
Light on? false

=== DEMO 4: COMPOSITION ===
Engine ignited
Car started

=== DEMO 5: ABSTRACT INTERFACE ===
Email sent
SMS sent

=== DEMO 6: STACK ABSTRACTION ===
Top = 30
Count = 3
After pop, top = 20

Next: 23_STATIC_CONST_FRIEND
*/
