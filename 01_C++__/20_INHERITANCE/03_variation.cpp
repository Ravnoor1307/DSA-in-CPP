/*
Topic: Inheritance
File: 03_variation.cpp

Purpose:
Explore:
- public/private inheritance accessibility
- function hiding
- multiple inheritance
- diamond inheritance
- virtual inheritance
- object slicing
- composition versus inheritance

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: PUBLIC VS PRIVATE INHERITANCE ==========

class Device {
public:
    void powerOn() const {
        cout << "Device powered on\n";
    }

protected:
    void runDiagnostics() const {
        cout << "Diagnostics complete\n";
    }
};

class Phone : public Device {
public:
    void test() const {
        // Protected members are accessible inside derived code.
        runDiagnostics();
    }
};

class InternalDevice : private Device {
public:
    void start() const {
        // Device::powerOn became private from the perspective
        // of users of InternalDevice, but this member can use it.
        powerOn();
    }
};

// ========== SECTION 2: FUNCTION HIDING ==========

class Base {
public:
    void show() const {
        cout << "Base::show()\n";
    }

    void show(int value) const {
        cout << "Base::show(int): "
             << value << '\n';
    }
};

class Derived : public Base {
public:
    using Base::show;

    void show(const string& text) const {
        cout << "Derived::show(string): "
             << text << '\n';
    }
};

// ========== SECTION 3: MULTIPLE INHERITANCE ==========

class Camera {
public:
    void use() const {
        cout << "Using camera\n";
    }
};

class GPS {
public:
    void use() const {
        cout << "Using GPS\n";
    }
};

class SmartDevice : public Camera, public GPS {
public:
    void demonstrate() const {
        Camera::use();
        GPS::use();
    }
};

// ========== SECTION 4: DIAMOND WITH VIRTUAL INHERITANCE ==========

class Person {
public:
    string name = "Unknown";
};

class Student : virtual public Person {
};

class Worker : virtual public Person {
};

class Assistant : public Student, public Worker {
public:
    void show() const {
        cout << "Assistant name = "
             << name << '\n';
    }
};

// ========== SECTION 5: OBJECT SLICING ==========

class Shape {
public:
    string category = "Shape";
};

class Circle : public Shape {
public:
    int radius = 5;
};

void inspectByValue(Shape shape) {
    cout << "By value: "
         << shape.category << '\n';
}

void inspectByReference(const Shape& shape) {
    cout << "By reference: "
         << shape.category << '\n';
}

// ========== SECTION 6: COMPOSITION ==========

class Engine {
public:
    void start() const {
        cout << "Engine started\n";
    }
};

class Car {
private:
    Engine engine;

public:
    void start() const {
        // Car HAS an Engine rather than IS an Engine.
        engine.start();
        cout << "Car ready\n";
    }
};

int main() {
    cout << "=== VARIATION 1: INHERITANCE ACCESS ===\n";

    Phone phone;

    phone.powerOn();
    phone.test();

    InternalDevice internal;
    internal.start();

    // internal.powerOn();
    // ERROR: Device was inherited privately.

    cout << "\n=== VARIATION 2: FUNCTION HIDING ===\n";

    Derived derived;

    derived.show();
    derived.show(42);
    derived.show("hello");

    cout << "\n=== VARIATION 3: MULTIPLE INHERITANCE ===\n";

    SmartDevice smart;
    smart.demonstrate();

    // smart.use();
    // ERROR: ambiguous without qualification.

    cout << "\n=== VARIATION 4: VIRTUAL DIAMOND ===\n";

    Assistant assistant;

    assistant.name = "Asha";
    assistant.show();

    cout << "\n=== VARIATION 5: OBJECT SLICING ===\n";

    Circle circle;
    circle.category = "Circle";

    inspectByValue(circle);
    inspectByReference(circle);

    Shape sliced = circle;

    cout << "Sliced category = "
         << sliced.category << '\n';

    cout << "Original circle radius = "
         << circle.radius << '\n';

    // sliced.radius does not exist.

    cout << "\n=== VARIATION 6: COMPOSITION ===\n";

    Car car;
    car.start();

    cout << "\nNext: 21_POLYMORPHISM\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: INHERITANCE ACCESS ===
Device powered on
Diagnostics complete
Device powered on

=== VARIATION 2: FUNCTION HIDING ===
Base::show()
Base::show(int): 42
Derived::show(string): hello

=== VARIATION 3: MULTIPLE INHERITANCE ===
Using camera
Using GPS

=== VARIATION 4: VIRTUAL DIAMOND ===
Assistant name = Asha

=== VARIATION 5: OBJECT SLICING ===
By value: Circle
By reference: Circle
Sliced category = Circle
Original circle radius = 5

=== VARIATION 6: COMPOSITION ===
Engine started
Car ready

Next: 21_POLYMORPHISM
*/
