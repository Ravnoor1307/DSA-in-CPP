/*
Topic: OOP — Classes and Objects
File: 02_basics.cpp

Purpose:
Practice the basic mechanics of defining classes, creating objects,
controlling access to state, and writing member functions.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: SIMPLE CLASS ==========

class Student {
public:
    string name = "Unknown";
    int marks = 0;

    void display() const {
        cout << name << " -> " << marks << '\n';
    }
};

// ========== SECTION 2: PRIVATE STATE ==========

class Temperature {
private:
    double celsius = 0.0;

public:
    void setCelsius(double value) {
        // Absolute zero is approximately -273.15 C.
        if (value >= -273.15) {
            celsius = value;
        }
    }

    double getCelsius() const {
        return celsius;
    }

    double getFahrenheit() const {
        return celsius * 9.0 / 5.0 + 32.0;
    }
};

// ========== SECTION 3: OBJECT STATE CHANGES ==========

class Counter {
private:
    int value = 0;

public:
    void increment() {
        ++value;
    }

    void decrement() {
        --value;
    }

    void reset() {
        value = 0;
    }

    int getValue() const {
        return value;
    }
};

// ========== SECTION 4: THIS POINTER ==========

class Product {
private:
    string name = "Unknown";
    int price = 0;

public:
    void setName(string name) {
        this->name = name;
    }

    void setPrice(int price) {
        if (price >= 0) {
            this->price = price;
        }
    }

    void display() const {
        cout << name << ": " << price << '\n';
    }
};

// ========== SECTION 5: OBJECT AS ARGUMENT ==========

void printTemperature(const Temperature& temperature) {
    cout << temperature.getCelsius() << " C = "
         << temperature.getFahrenheit() << " F\n";
}

int main() {
    cout << "=== BASIC 1: STUDENT OBJECTS ===\n";

    Student a;
    Student b;

    a.name = "Aman";
    a.marks = 88;

    b.name = "Sara";
    b.marks = 94;

    a.display();
    b.display();

    cout << "\n=== BASIC 2: CONTROLLED STATE ===\n";

    Temperature temperature;

    temperature.setCelsius(25);
    printTemperature(temperature);

    // Invalid, so our setter leaves the existing state unchanged.
    temperature.setCelsius(-500);

    cout << "After invalid update: "
         << temperature.getCelsius() << " C\n";

    cout << "\n=== BASIC 3: COUNTER ===\n";

    Counter counter;

    counter.increment();
    counter.increment();
    counter.increment();
    counter.decrement();

    cout << "Counter = " << counter.getValue() << '\n';

    counter.reset();

    cout << "After reset = " << counter.getValue() << '\n';

    cout << "\n=== BASIC 4: this POINTER FOR NAME COLLISION ===\n";

    Product product;

    product.setName("Keyboard");
    product.setPrice(2500);
    product.display();

    cout << "\n=== BASIC 5: ARRAY OF OBJECTS ===\n";

    Student students[3];

    students[0].name = "Ali";
    students[0].marks = 70;

    students[1].name = "Neha";
    students[1].marks = 85;

    students[2].name = "John";
    students[2].marks = 90;

    int total = 0;

    for (int i = 0; i < 3; ++i) {
        students[i].display();
        total += students[i].marks;
    }

    cout << "Average = " << total / 3.0 << '\n';

    cout << "\nNext: 19_CONSTRUCTORS_DESTRUCTORS\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: STUDENT OBJECTS ===
Aman -> 88
Sara -> 94

=== BASIC 2: CONTROLLED STATE ===
25 C = 77 F
After invalid update: 25 C

=== BASIC 3: COUNTER ===
Counter = 2
After reset = 0

=== BASIC 4: this POINTER FOR NAME COLLISION ===
Keyboard: 2500

=== BASIC 5: ARRAY OF OBJECTS ===
Ali -> 70
Neha -> 85
John -> 90
Average = 81.6667

Next: 19_CONSTRUCTORS_DESTRUCTORS
*/
