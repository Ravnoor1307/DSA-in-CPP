/*
Topic: Polymorphism
File: 02_basics.cpp

Purpose:
Practice virtual functions, base references, abstract classes,
override, and virtual destructors.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: BASIC VIRTUAL FUNCTION ==========

class Notification {
public:
    virtual void send() const {
        cout << "Generic notification\n";
    }

    virtual ~Notification() = default;
};

class Email : public Notification {
public:
    void send() const override {
        cout << "Email sent\n";
    }
};

class SMS : public Notification {
public:
    void send() const override {
        cout << "SMS sent\n";
    }
};

void notify(const Notification& notification) {
    notification.send();
}

// ========== SECTION 2: ABSTRACT CLASS ==========

class PaymentMethod {
public:
    virtual void pay(int amount) const = 0;
    virtual ~PaymentMethod() = default;
};

class CardPayment : public PaymentMethod {
public:
    void pay(int amount) const override {
        cout << "Paid " << amount
             << " using card\n";
    }
};

class CashPayment : public PaymentMethod {
public:
    void pay(int amount) const override {
        cout << "Paid " << amount
             << " using cash\n";
    }
};

void checkout(
    const PaymentMethod& payment,
    int amount
) {
    payment.pay(amount);
}

// ========== SECTION 3: SHARED BASE IMPLEMENTATION ==========

class Employee {
protected:
    string name;

public:
    Employee(const string& name)
        : name(name) {
    }

    virtual void work() const {
        cout << name << " performs general work\n";
    }

    virtual ~Employee() = default;
};

class Developer : public Employee {
public:
    Developer(const string& name)
        : Employee(name) {
    }

    void work() const override {
        cout << name << " writes code\n";
    }
};

class Manager : public Employee {
public:
    Manager(const string& name)
        : Employee(name) {
    }

    void work() const override {
        cout << name << " manages a team\n";
    }
};

void performWork(const Employee& employee) {
    employee.work();
}

int main() {
    cout << "=== BASIC 1: NOTIFICATIONS ===\n";

    Notification generic;
    Email email;
    SMS sms;

    notify(generic);
    notify(email);
    notify(sms);

    cout << "\n=== BASIC 2: ABSTRACT PAYMENT INTERFACE ===\n";

    CardPayment card;
    CashPayment cash;

    checkout(card, 500);
    checkout(cash, 250);

    cout << "\n=== BASIC 3: EMPLOYEE POLYMORPHISM ===\n";

    Developer developer("Asha");
    Manager manager("Ravi");

    performWork(developer);
    performWork(manager);

    cout << "\n=== BASIC 4: BASE POINTER ===\n";

    Employee* employee = &developer;
    employee->work();

    employee = &manager;
    employee->work();

    cout << "\nNext: 22_ABSTRACTION_ENCAPSULATION\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: NOTIFICATIONS ===
Generic notification
Email sent
SMS sent

=== BASIC 2: ABSTRACT PAYMENT INTERFACE ===
Paid 500 using card
Paid 250 using cash

=== BASIC 3: EMPLOYEE POLYMORPHISM ===
Asha writes code
Ravi manages a team

=== BASIC 4: BASE POINTER ===
Asha writes code
Ravi manages a team

Next: 22_ABSTRACTION_ENCAPSULATION
*/
