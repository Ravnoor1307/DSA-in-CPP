/*
Topic: Constructors and Destructors

Covers:
- default and parameterized constructors
- overloaded constructors
- member initializer lists
- initialization order
- in-class member initializers
- delegating constructors
- destructors
- scope and object lifetime
- reverse destruction order
- member-object lifetime
- copy constructor introduction
- dynamic object lifetime

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: DEFAULT CONSTRUCTOR ==========

class Counter {
private:
    int value;

public:
    Counter()
        : value(0) {
        cout << "Counter constructed\n";
    }

    int getValue() const {
        return value;
    }
};

// ========== SECTION 2: PARAMETERIZED CONSTRUCTOR ==========

class Point {
private:
    int x;
    int y;

public:
    Point(int xValue, int yValue)
        : x(xValue), y(yValue) {
    }

    void print() const {
        cout << '(' << x << ", " << y << ')';
    }
};

// ========== SECTION 3: CONSTRUCTOR OVERLOADING ==========

class Box {
private:
    int width;
    int height;

public:
    Box()
        : width(1), height(1) {
    }

    Box(int side)
        : width(side), height(side) {
    }

    Box(int width, int height)
        : width(width), height(height) {
    }

    void print() const {
        cout << width << " x " << height;
    }
};

// ========== SECTION 4: IN-CLASS INITIALIZERS ==========

class Player {
private:
    string name = "Unknown";
    int health = 100;

public:
    Player() = default;

    Player(const string& playerName, int startingHealth)
        : name(playerName), health(startingHealth) {
    }

    void show() const {
        cout << name << ": " << health << '\n';
    }
};

// ========== SECTION 5: CONST MEMBER INITIALIZATION ==========

class IdCard {
private:
    const int id;

public:
    IdCard(int value)
        : id(value) {
    }

    int getId() const {
        return id;
    }
};

// ========== SECTION 6: DELEGATING CONSTRUCTORS ==========

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

    Rectangle(int w, int h)
        : width(w), height(h) {
    }

    int area() const {
        return width * height;
    }
};

// ========== SECTION 7: DESTRUCTOR AND SCOPE ==========

class Trace {
private:
    string name;

public:
    Trace(const string& name)
        : name(name) {
        cout << "Construct " << name << '\n';
    }

    ~Trace() {
        cout << "Destroy " << name << '\n';
    }
};

// ========== SECTION 8: MEMBER OBJECT LIFETIME ==========

class Engine {
public:
    Engine() {
        cout << "Engine constructor\n";
    }

    ~Engine() {
        cout << "Engine destructor\n";
    }
};

class Car {
private:
    Engine engine;

public:
    Car() {
        cout << "Car constructor\n";
    }

    ~Car() {
        cout << "Car destructor\n";
    }
};

// ========== SECTION 9: COPY CONSTRUCTOR INTRODUCTION ==========

class Number {
private:
    int value;

public:
    Number(int value)
        : value(value) {
        cout << "Number constructed: " << value << '\n';
    }

    Number(const Number& other)
        : value(other.value) {
        cout << "Number copied: " << value << '\n';
    }

    int getValue() const {
        return value;
    }
};

// ========== SECTION 10: DYNAMIC OBJECT ==========

class DynamicTrace {
public:
    DynamicTrace() {
        cout << "DynamicTrace constructor\n";
    }

    ~DynamicTrace() {
        cout << "DynamicTrace destructor\n";
    }
};

int main() {
    cout << "=== DEMO 1: DEFAULT CONSTRUCTOR ===\n";

    Counter counter;
    cout << "Counter value = " << counter.getValue() << '\n';

    cout << "\n=== DEMO 2: PARAMETERIZED CONSTRUCTOR ===\n";

    Point point(3, 7);

    cout << "Point = ";
    point.print();
    cout << '\n';

    cout << "\n=== DEMO 3: OVERLOADED CONSTRUCTORS ===\n";

    Box a;
    Box b(5);
    Box c(4, 6);

    cout << "a = ";
    a.print();

    cout << "\nb = ";
    b.print();

    cout << "\nc = ";
    c.print();

    cout << '\n';

    cout << "\n=== DEMO 4: IN-CLASS INITIALIZERS ===\n";

    Player defaultPlayer;
    Player customPlayer("Mira", 80);

    defaultPlayer.show();
    customPlayer.show();

    cout << "\n=== DEMO 5: CONST MEMBER ===\n";

    IdCard card(101);
    cout << "ID = " << card.getId() << '\n';

    cout << "\n=== DEMO 6: DELEGATING CONSTRUCTORS ===\n";

    Rectangle r1;
    Rectangle r2(5);
    Rectangle r3(4, 7);

    cout << "Areas = "
         << r1.area() << ", "
         << r2.area() << ", "
         << r3.area() << '\n';

    cout << "\n=== DEMO 7: NESTED SCOPE ===\n";

    cout << "Before block\n";

    {
        Trace local("local");
        cout << "Inside block\n";
    }

    cout << "After block\n";

    cout << "\n=== DEMO 8: REVERSE DESTRUCTION ORDER ===\n";

    {
        Trace first("first");
        Trace second("second");
        Trace third("third");

        cout << "Objects are alive\n";
    }

    cout << "\n=== DEMO 9: MEMBER OBJECT LIFETIME ===\n";

    {
        Car car;
        cout << "Car is alive\n";
    }

    cout << "\n=== DEMO 10: COPY CONSTRUCTOR ===\n";

    Number original(42);
    Number copied = original;

    cout << "Copied value = " << copied.getValue() << '\n';

    cout << "\n=== DEMO 11: DYNAMIC OBJECT ===\n";

    DynamicTrace* ptr = new DynamicTrace;

    cout << "Object created with new\n";

    delete ptr;
    ptr = nullptr;

    cout << "Object deleted\n";

    cout << "\nNext: 20_INHERITANCE\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: DEFAULT CONSTRUCTOR ===
Counter constructed
Counter value = 0

=== DEMO 2: PARAMETERIZED CONSTRUCTOR ===
Point = (3, 7)

=== DEMO 3: OVERLOADED CONSTRUCTORS ===
a = 1 x 1
b = 5 x 5
c = 4 x 6

=== DEMO 4: IN-CLASS INITIALIZERS ===
Unknown: 100
Mira: 80

=== DEMO 5: CONST MEMBER ===
ID = 101

=== DEMO 6: DELEGATING CONSTRUCTORS ===
Areas = 1, 25, 28

=== DEMO 7: NESTED SCOPE ===
Before block
Construct local
Inside block
Destroy local
After block

=== DEMO 8: REVERSE DESTRUCTION ORDER ===
Construct first
Construct second
Construct third
Objects are alive
Destroy third
Destroy second
Destroy first

=== DEMO 9: MEMBER OBJECT LIFETIME ===
Engine constructor
Car constructor
Car is alive
Car destructor
Engine destructor

=== DEMO 10: COPY CONSTRUCTOR ===
Number constructed: 42
Number copied: 42
Copied value = 42

=== DEMO 11: DYNAMIC OBJECT ===
DynamicTrace constructor
Object created with new
DynamicTrace destructor
Object deleted

Next: 20_INHERITANCE
*/
