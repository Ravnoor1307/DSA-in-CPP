/*
Topic: Polymorphism

Covers:
- compile-time and runtime polymorphism
- function overloading
- virtual functions
- overriding and override
- base references and pointers
- dynamic dispatch
- abstract classes
- pure virtual functions
- virtual destructors
- object slicing
- final
- virtual calls during construction/destruction

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: COMPILE-TIME POLYMORPHISM ==========

void display(int value) {
    cout << "Integer: " << value << '\n';
}

void display(double value) {
    cout << "Double: " << value << '\n';
}

void display(const string& value) {
    cout << "String: " << value << '\n';
}

// ========== SECTION 2: VIRTUAL FUNCTIONS ==========

class Animal {
public:
    virtual void speak() const {
        cout << "Animal sound\n";
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Meow\n";
    }
};

void makeSpeak(const Animal& animal) {
    animal.speak();
}

// ========== SECTION 3: PURE VIRTUAL FUNCTIONS ==========

class Shape {
public:
    virtual double area() const = 0;
    virtual const char* name() const = 0;

    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height)
        : width(width), height(height) {
    }

    double area() const override {
        return width * height;
    }

    const char* name() const override {
        return "Rectangle";
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double side)
        : side(side) {
    }

    double area() const override {
        return side * side;
    }

    const char* name() const override {
        return "Square";
    }
};

void printShape(const Shape& shape) {
    cout << shape.name()
         << " area = "
         << shape.area()
         << '\n';
}

// ========== SECTION 4: VIRTUAL DESTRUCTOR ==========

class ResourceBase {
public:
    ResourceBase() {
        cout << "ResourceBase constructed\n";
    }

    virtual ~ResourceBase() {
        cout << "ResourceBase destroyed\n";
    }
};

class ResourceDerived : public ResourceBase {
private:
    int* value;

public:
    ResourceDerived()
        : value(new int(42)) {
        cout << "ResourceDerived constructed\n";
    }

    ~ResourceDerived() override {
        cout << "ResourceDerived releasing "
             << *value << '\n';

        delete value;

        cout << "ResourceDerived destroyed\n";
    }
};

// ========== SECTION 5: OBJECT SLICING ==========

class BaseInfo {
public:
    virtual void identify() const {
        cout << "BaseInfo\n";
    }

    virtual ~BaseInfo() = default;
};

class DerivedInfo : public BaseInfo {
public:
    void identify() const override {
        cout << "DerivedInfo\n";
    }
};

void byValue(BaseInfo value) {
    value.identify();
}

void byReference(const BaseInfo& value) {
    value.identify();
}

// ========== SECTION 6: final ==========

class Parent {
public:
    virtual void run() const {
        cout << "Parent::run\n";
    }

    virtual ~Parent() = default;
};

class Child : public Parent {
public:
    void run() const final {
        cout << "Child::run\n";
    }
};

// ========== SECTION 7: CONSTRUCTOR VIRTUAL-CALL RULE ==========

class ConstructionBase {
public:
    ConstructionBase() {
        cout << "ConstructionBase constructor calls: ";
        show();
    }

    virtual void show() const {
        cout << "ConstructionBase::show\n";
    }

    virtual ~ConstructionBase() = default;
};

class ConstructionDerived : public ConstructionBase {
public:
    ConstructionDerived() {
        cout << "ConstructionDerived constructor\n";
    }

    void show() const override {
        cout << "ConstructionDerived::show\n";
    }
};

int main() {
    cout << "=== DEMO 1: COMPILE-TIME POLYMORPHISM ===\n";

    display(10);
    display(3.5);
    display(string("hello"));

    cout << "\n=== DEMO 2: RUNTIME POLYMORPHISM ===\n";

    Dog dog;
    Cat cat;

    makeSpeak(dog);
    makeSpeak(cat);

    cout << "\n=== DEMO 3: BASE POINTER ===\n";

    Animal* animal = &dog;

    animal->speak();

    animal = &cat;

    animal->speak();

    cout << "\n=== DEMO 4: ABSTRACT BASE CLASS ===\n";

    Rectangle rectangle(4, 5);
    Square square(6);

    printShape(rectangle);
    printShape(square);

    cout << "\n=== DEMO 5: VIRTUAL DESTRUCTOR ===\n";

    ResourceBase* resource = new ResourceDerived;

    cout << "Deleting through ResourceBase*\n";

    delete resource;
    resource = nullptr;

    cout << "\n=== DEMO 6: OBJECT SLICING ===\n";

    DerivedInfo derived;

    cout << "Pass by value: ";
    byValue(derived);

    cout << "Pass by reference: ";
    byReference(derived);

    cout << "\n=== DEMO 7: final OVERRIDE ===\n";

    Child child;
    Parent& parentView = child;

    parentView.run();

    cout << "\n=== DEMO 8: VIRTUAL CALL IN CONSTRUCTOR ===\n";

    ConstructionDerived constructionObject;

    cout << "After construction: ";
    constructionObject.show();

    cout << "\nNext: 22_ABSTRACTION_ENCAPSULATION\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: COMPILE-TIME POLYMORPHISM ===
Integer: 10
Double: 3.5
String: hello

=== DEMO 2: RUNTIME POLYMORPHISM ===
Woof
Meow

=== DEMO 3: BASE POINTER ===
Woof
Meow

=== DEMO 4: ABSTRACT BASE CLASS ===
Rectangle area = 20
Square area = 36

=== DEMO 5: VIRTUAL DESTRUCTOR ===
ResourceBase constructed
ResourceDerived constructed
Deleting through ResourceBase*
ResourceDerived releasing 42
ResourceDerived destroyed
ResourceBase destroyed

=== DEMO 6: OBJECT SLICING ===
Pass by value: BaseInfo
Pass by reference: DerivedInfo

=== DEMO 7: final OVERRIDE ===
Child::run

=== DEMO 8: VIRTUAL CALL IN CONSTRUCTOR ===
ConstructionBase constructor calls: ConstructionBase::show
ConstructionDerived constructor
After construction: ConstructionDerived::show

Next: 22_ABSTRACTION_ENCAPSULATION
*/
