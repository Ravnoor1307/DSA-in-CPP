/*
Topic: Inheritance

Covers:
- base and derived classes
- public/protected/private members
- public inheritance
- constructor/destructor order
- base-constructor initialization
- function hiding
- multilevel and hierarchical inheritance
- multiple inheritance
- virtual inheritance
- upcasting and object slicing
- virtual-destructor preview

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: BASIC PUBLIC INHERITANCE ==========

class Animal {
public:
    void eat() const {
        cout << "Animal is eating\n";
    }
};

class Dog : public Animal {
public:
    void bark() const {
        cout << "Dog says woof\n";
    }
};

// ========== SECTION 2: ACCESS CONTROL ==========

class Person {
private:
    int id;

protected:
    string name;

public:
    Person(int id, const string& name)
        : id(id), name(name) {
    }

    int getId() const {
        return id;
    }

    const string& getName() const {
        return name;
    }
};

class Student : public Person {
private:
    int rollNumber;

public:
    Student(int id, const string& name, int rollNumber)
        : Person(id, name),
          rollNumber(rollNumber) {
    }

    void introduce() const {
        // name is protected, so Student can access it directly.
        //
        // id is private in Person, so Student must use getId().
        cout << name
             << ", id=" << getId()
             << ", roll=" << rollNumber
             << '\n';
    }
};

// ========== SECTION 3: CONSTRUCTION / DESTRUCTION ORDER ==========

class BaseTrace {
public:
    BaseTrace() {
        cout << "Base constructor\n";
    }

    ~BaseTrace() {
        cout << "Base destructor\n";
    }
};

class DerivedTrace : public BaseTrace {
public:
    DerivedTrace() {
        cout << "Derived constructor\n";
    }

    ~DerivedTrace() {
        cout << "Derived destructor\n";
    }
};

// ========== SECTION 4: FUNCTION HIDING ==========

class BasePrinter {
public:
    void print(int value) const {
        cout << "Base int: " << value << '\n';
    }
};

class DerivedPrinter : public BasePrinter {
public:
    // Bring BasePrinter overloads into this scope.
    using BasePrinter::print;

    void print() const {
        cout << "Derived no-argument print\n";
    }
};

// ========== SECTION 5: MULTILEVEL INHERITANCE ==========

class LivingThing {
public:
    void live() const {
        cout << "LivingThing::live\n";
    }
};

class Mammal : public LivingThing {
public:
    void breathe() const {
        cout << "Mammal::breathe\n";
    }
};

class Cat : public Mammal {
public:
    void meow() const {
        cout << "Cat::meow\n";
    }
};

// ========== SECTION 6: MULTIPLE INHERITANCE ==========

class Scanner {
public:
    void scan() const {
        cout << "Scanning\n";
    }
};

class Printer {
public:
    void printDocument() const {
        cout << "Printing\n";
    }
};

class AllInOne : public Scanner, public Printer {
};

// ========== SECTION 7: AMBIGUITY ==========

class Left {
public:
    void identify() const {
        cout << "Left\n";
    }
};

class Right {
public:
    void identify() const {
        cout << "Right\n";
    }
};

class Combined : public Left, public Right {
};

// ========== SECTION 8: VIRTUAL INHERITANCE ==========

class Human {
public:
    int age = 20;
};

class Learner : virtual public Human {
};

class Worker : virtual public Human {
};

class WorkingStudent : public Learner, public Worker {
};

// ========== SECTION 9: OBJECT SLICING ==========

class BaseValue {
public:
    int base = 10;
};

class DerivedValue : public BaseValue {
public:
    int derived = 20;
};

// ========== SECTION 10: VIRTUAL DESTRUCTOR PREVIEW ==========

class SafeBase {
public:
    SafeBase() {
        cout << "SafeBase constructor\n";
    }

    virtual ~SafeBase() {
        cout << "SafeBase destructor\n";
    }
};

class SafeDerived : public SafeBase {
public:
    SafeDerived() {
        cout << "SafeDerived constructor\n";
    }

    ~SafeDerived() override {
        cout << "SafeDerived destructor\n";
    }
};

int main() {
    cout << "=== DEMO 1: BASIC INHERITANCE ===\n";

    Dog dog;
    dog.eat();
    dog.bark();

    cout << "\n=== DEMO 2: ACCESS AND BASE CONSTRUCTOR ===\n";

    Student student(101, "Asha", 42);
    student.introduce();

    cout << "\n=== DEMO 3: CONSTRUCTION AND DESTRUCTION ===\n";

    {
        DerivedTrace object;
        cout << "Derived object is alive\n";
    }

    cout << "\n=== DEMO 4: FUNCTION HIDING AND using ===\n";

    DerivedPrinter printer;

    printer.print();
    printer.print(50);

    cout << "\n=== DEMO 5: MULTILEVEL INHERITANCE ===\n";

    Cat cat;

    cat.live();
    cat.breathe();
    cat.meow();

    cout << "\n=== DEMO 6: MULTIPLE INHERITANCE ===\n";

    AllInOne machine;

    machine.scan();
    machine.printDocument();

    cout << "\n=== DEMO 7: RESOLVING AMBIGUITY ===\n";

    Combined combined;

    combined.Left::identify();
    combined.Right::identify();

    cout << "\n=== DEMO 8: VIRTUAL INHERITANCE ===\n";

    WorkingStudent person;

    // There is one shared Human virtual base.
    person.age = 25;

    cout << "Shared Human age = " << person.age << '\n';

    cout << "\n=== DEMO 9: UPCASTING ===\n";

    DerivedValue derivedObject;
    BaseValue* basePtr = &derivedObject;
    BaseValue& baseRef = derivedObject;

    cout << "Through base pointer = "
         << basePtr->base << '\n';

    cout << "Through base reference = "
         << baseRef.base << '\n';

    cout << "\n=== DEMO 10: OBJECT SLICING ===\n";

    BaseValue sliced = derivedObject;

    cout << "Sliced base value = "
         << sliced.base << '\n';

    // sliced.derived does not exist because sliced is a BaseValue.

    cout << "\n=== DEMO 11: VIRTUAL DESTRUCTOR PREVIEW ===\n";

    SafeBase* ptr = new SafeDerived;

    cout << "Deleting through base pointer\n";
    delete ptr;

    cout << "\nNext: 21_POLYMORPHISM\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: BASIC INHERITANCE ===
Animal is eating
Dog says woof

=== DEMO 2: ACCESS AND BASE CONSTRUCTOR ===
Asha, id=101, roll=42

=== DEMO 3: CONSTRUCTION AND DESTRUCTION ===
Base constructor
Derived constructor
Derived object is alive
Derived destructor
Base destructor

=== DEMO 4: FUNCTION HIDING AND using ===
Derived no-argument print
Base int: 50

=== DEMO 5: MULTILEVEL INHERITANCE ===
LivingThing::live
Mammal::breathe
Cat::meow

=== DEMO 6: MULTIPLE INHERITANCE ===
Scanning
Printing

=== DEMO 7: RESOLVING AMBIGUITY ===
Left
Right

=== DEMO 8: VIRTUAL INHERITANCE ===
Shared Human age = 25

=== DEMO 9: UPCASTING ===
Through base pointer = 10
Through base reference = 10

=== DEMO 10: OBJECT SLICING ===
Sliced base value = 10

=== DEMO 11: VIRTUAL DESTRUCTOR PREVIEW ===
SafeBase constructor
SafeDerived constructor
Deleting through base pointer
SafeDerived destructor
SafeBase destructor

Next: 21_POLYMORPHISM
*/
