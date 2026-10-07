/*
Topic: Polymorphism
File: 04_practice_problems.cpp

Practice:
1. Animal sounds
2. Shape area interface
3. Payment methods
4. Employee work behavior
5. Virtual destructor and resource cleanup

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <string>

using namespace std;

// ========== PROBLEM 1: ANIMAL SOUNDS ==========
//
// Create one common interface for multiple animal sounds.
//
// Complexity:
// Each sound() implementation here performs O(1) work.

class Animal {
public:
    virtual void sound() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() const override {
        cout << "Dog: Woof\n";
    }
};

class Cat : public Animal {
public:
    void sound() const override {
        cout << "Cat: Meow\n";
    }
};

void playSound(const Animal& animal) {
    animal.sound();
}

// ========== PROBLEM 2: SHAPE AREA ==========

class Shape {
public:
    virtual int area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int width, int height)
        : width(width), height(height) {
    }

    int area() const override {
        return width * height;
    }
};

class Square : public Shape {
private:
    int side;

public:
    Square(int side)
        : side(side) {
    }

    int area() const override {
        return side * side;
    }
};

void showArea(const Shape& shape) {
    cout << "Area = " << shape.area() << '\n';
}

// ========== PROBLEM 3: PAYMENT METHODS ==========

class Payment {
public:
    virtual void process(int amount) const = 0;
    virtual ~Payment() = default;
};

class Card : public Payment {
public:
    void process(int amount) const override {
        cout << "Card payment: "
             << amount << '\n';
    }
};

class UPI : public Payment {
public:
    void process(int amount) const override {
        cout << "UPI payment: "
             << amount << '\n';
    }
};

void pay(const Payment& method, int amount) {
    method.process(amount);
}

// ========== PROBLEM 4: EMPLOYEE BEHAVIOR ==========

class Employee {
protected:
    string name;

public:
    Employee(const string& name)
        : name(name) {
    }

    virtual void work() const = 0;

    virtual ~Employee() = default;
};

class Programmer : public Employee {
public:
    Programmer(const string& name)
        : Employee(name) {
    }

    void work() const override {
        cout << name << " writes software\n";
    }
};

class Designer : public Employee {
public:
    Designer(const string& name)
        : Employee(name) {
    }

    void work() const override {
        cout << name << " designs interfaces\n";
    }
};

void startWork(const Employee& employee) {
    employee.work();
}

// ========== PROBLEM 5: SAFE POLYMORPHIC DESTRUCTION ==========
//
// The derived class owns dynamic memory solely to demonstrate why
// complete destruction matters.
//
// Manual ownership is educational here. Later RAII/smart-pointer
// lessons show safer production designs.

class Resource {
public:
    virtual void show() const = 0;

    virtual ~Resource() {
        cout << "Resource base destroyed\n";
    }
};

class IntegerResource : public Resource {
private:
    int* value;

public:
    IntegerResource(int value)
        : value(new int(value)) {
        cout << "Allocated " << *this->value << '\n';
    }

    void show() const override {
        cout << "Stored value = "
             << *value << '\n';
    }

    ~IntegerResource() override {
        cout << "Releasing "
             << *value << '\n';

        delete value;
    }
};

int main() {
    cout << "=== PROBLEM 1: ANIMAL SOUNDS ===\n";

    Dog dog;
    Cat cat;

    playSound(dog);
    playSound(cat);

    cout << "\n=== PROBLEM 2: SHAPE AREA ===\n";

    Rectangle rectangle(4, 6);
    Square square(5);

    showArea(rectangle);
    showArea(square);

    cout << "\n=== PROBLEM 3: PAYMENTS ===\n";

    Card card;
    UPI upi;

    pay(card, 1000);
    pay(upi, 750);

    cout << "\n=== PROBLEM 4: EMPLOYEES ===\n";

    Programmer programmer("Asha");
    Designer designer("Ravi");

    startWork(programmer);
    startWork(designer);

    cout << "\n=== PROBLEM 5: VIRTUAL DESTRUCTOR ===\n";

    Resource* resource = new IntegerResource(42);

    resource->show();

    cout << "Deleting through Resource*\n";

    delete resource;
    resource = nullptr;

    cout << "\nNext: 22_ABSTRACTION_ENCAPSULATION\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: ANIMAL SOUNDS ===
Dog: Woof
Cat: Meow

=== PROBLEM 2: SHAPE AREA ===
Area = 24
Area = 25

=== PROBLEM 3: PAYMENTS ===
Card payment: 1000
UPI payment: 750

=== PROBLEM 4: EMPLOYEES ===
Asha writes software
Ravi designs interfaces

=== PROBLEM 5: VIRTUAL DESTRUCTOR ===
Allocated 42
Stored value = 42
Deleting through Resource*
Releasing 42
Resource base destroyed

Next: 22_ABSTRACTION_ENCAPSULATION
*/
