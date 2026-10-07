/*
Topic: Inheritance
File: 04_practice_problems.cpp

Practice implementations:
1. Person -> Student
2. Shape -> Rectangle
3. Vehicle hierarchy
4. Multilevel inheritance
5. Multiple inheritance

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <string>

using namespace std;

// ========== PROBLEM 1: PERSON -> STUDENT ==========
//
// Build a Student that inherits common identity information
// from Person.
//
// Complexity:
// construction: O(1) ignoring string allocation details
// display:      O(1) for fixed-size conceptual output

class Person {
private:
    string name;
    int age;

public:
    Person(const string& name, int age)
        : name(name),
          age(age >= 0 ? age : 0) {
    }

    const string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

class Student : public Person {
private:
    int marks;

public:
    Student(
        const string& name,
        int age,
        int marks
    )
        : Person(name, age),
          marks(
              marks >= 0 && marks <= 100
                  ? marks
                  : 0
          ) {
    }

    void display() const {
        cout << getName()
             << ", age=" << getAge()
             << ", marks=" << marks
             << '\n';
    }
};

// ========== PROBLEM 2: SHAPE -> RECTANGLE ==========

class Shape {
protected:
    string color;

public:
    Shape(const string& color)
        : color(color) {
    }

    void showColor() const {
        cout << "Color = " << color << '\n';
    }
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(
        const string& color,
        int width,
        int height
    )
        : Shape(color),
          width(width >= 0 ? width : 0),
          height(height >= 0 ? height : 0) {
    }

    int area() const {
        return width * height;
    }
};

// ========== PROBLEM 3: VEHICLE HIERARCHY ==========

class Vehicle {
private:
    int speed;

public:
    Vehicle(int speed)
        : speed(speed >= 0 ? speed : 0) {
    }

    int getSpeed() const {
        return speed;
    }
};

class Car : public Vehicle {
private:
    int doors;

public:
    Car(int speed, int doors)
        : Vehicle(speed),
          doors(doors >= 0 ? doors : 0) {
    }

    void display() const {
        cout << "Car: speed="
             << getSpeed()
             << ", doors="
             << doors
             << '\n';
    }
};

class Bike : public Vehicle {
public:
    Bike(int speed)
        : Vehicle(speed) {
    }

    void display() const {
        cout << "Bike: speed="
             << getSpeed()
             << '\n';
    }
};

// ========== PROBLEM 4: MULTILEVEL INHERITANCE ==========

class A {
public:
    int aValue() const {
        return 10;
    }
};

class B : public A {
public:
    int bValue() const {
        return 20;
    }
};

class C : public B {
public:
    int total() const {
        return aValue() + bValue() + 30;
    }
};

// ========== PROBLEM 5: MULTIPLE INHERITANCE ==========

class Academic {
protected:
    int academicScore;

public:
    Academic(int score)
        : academicScore(score) {
    }
};

class Sports {
protected:
    int sportsScore;

public:
    Sports(int score)
        : sportsScore(score) {
    }
};

class Result : public Academic, public Sports {
public:
    Result(int academic, int sports)
        : Academic(academic),
          Sports(sports) {
    }

    int total() const {
        return academicScore + sportsScore;
    }
};

int main() {
    cout << "=== PROBLEM 1: PERSON -> STUDENT ===\n";

    Student student("Asha", 20, 92);
    student.display();

    cout << "\n=== PROBLEM 2: SHAPE -> RECTANGLE ===\n";

    Rectangle rectangle("Blue", 5, 4);

    rectangle.showColor();

    cout << "Area = "
         << rectangle.area()
         << '\n';

    cout << "\n=== PROBLEM 3: VEHICLE HIERARCHY ===\n";

    Car car(120, 4);
    Bike bike(80);

    car.display();
    bike.display();

    cout << "\n=== PROBLEM 4: MULTILEVEL INHERITANCE ===\n";

    C object;

    cout << "Total = "
         << object.total()
         << '\n';

    cout << "\n=== PROBLEM 5: MULTIPLE INHERITANCE ===\n";

    Result result(85, 15);

    cout << "Combined score = "
         << result.total()
         << '\n';

    cout << "\nNext: 21_POLYMORPHISM\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: PERSON -> STUDENT ===
Asha, age=20, marks=92

=== PROBLEM 2: SHAPE -> RECTANGLE ===
Color = Blue
Area = 20

=== PROBLEM 3: VEHICLE HIERARCHY ===
Car: speed=120, doors=4
Bike: speed=80

=== PROBLEM 4: MULTILEVEL INHERITANCE ===
Total = 60

=== PROBLEM 5: MULTIPLE INHERITANCE ===
Combined score = 100

Next: 21_POLYMORPHISM
*/
