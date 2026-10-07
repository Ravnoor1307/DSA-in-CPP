/*
Topic: Polymorphism
File: 03_variation.cpp

Purpose:
Explore subtle polymorphism rules:
- hiding versus overriding
- const correctness in overrides
- qualified base calls
- default arguments on virtual functions
- object slicing
- pure virtual destructors

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>

using namespace std;

// ========== SECTION 1: HIDING VS OVERRIDING ==========

class BaseA {
public:
    virtual void show() const {
        cout << "BaseA::show const\n";
    }

    virtual ~BaseA() = default;
};

class WrongDerived : public BaseA {
public:
    // This is NOT an override because const is missing.
    void show() {
        cout << "WrongDerived::show non-const\n";
    }
};

class CorrectDerived : public BaseA {
public:
    void show() const override {
        cout << "CorrectDerived::show const\n";
    }
};

// ========== SECTION 2: QUALIFIED BASE CALL ==========

class Parent {
public:
    virtual void describe() const {
        cout << "Parent description\n";
    }

    virtual ~Parent() = default;
};

class Child : public Parent {
public:
    void describe() const override {
        Parent::describe();
        cout << "Child extension\n";
    }
};

// ========== SECTION 3: DEFAULT ARGUMENTS ==========

class DefaultBase {
public:
    virtual void print(int value = 1) const {
        cout << "DefaultBase: "
             << value << '\n';
    }

    virtual ~DefaultBase() = default;
};

class DefaultDerived : public DefaultBase {
public:
    void print(int value = 2) const override {
        cout << "DefaultDerived: "
             << value << '\n';
    }
};

// ========== SECTION 4: OBJECT SLICING ==========

class Identity {
public:
    virtual void identify() const {
        cout << "Identity\n";
    }

    virtual ~Identity() = default;
};

class SpecialIdentity : public Identity {
public:
    void identify() const override {
        cout << "SpecialIdentity\n";
    }
};

void slicedCall(Identity value) {
    value.identify();
}

void polymorphicCall(const Identity& value) {
    value.identify();
}

// ========== SECTION 5: PURE VIRTUAL DESTRUCTOR ==========

class AbstractResource {
public:
    virtual void use() const = 0;

    virtual ~AbstractResource() = 0;
};

// A pure virtual destructor still needs a definition.
AbstractResource::~AbstractResource() {
    cout << "AbstractResource destructor\n";
}

class ConcreteResource : public AbstractResource {
public:
    void use() const override {
        cout << "Concrete resource used\n";
    }

    ~ConcreteResource() override {
        cout << "ConcreteResource destructor\n";
    }
};

int main() {
    cout << "=== VARIATION 1: SIGNATURE MATTERS ===\n";

    WrongDerived wrong;
    BaseA& wrongBase = wrong;

    wrong.show();
    wrongBase.show();

    CorrectDerived correct;
    BaseA& correctBase = correct;

    correctBase.show();

    cout << "\n=== VARIATION 2: QUALIFIED BASE CALL ===\n";

    Child child;
    child.describe();

    cout << "\n=== VARIATION 3: DEFAULT ARGUMENTS ===\n";

    DefaultDerived derived;
    DefaultBase& base = derived;

    cout << "Called through Derived object: ";
    derived.print();

    cout << "Called through Base reference: ";
    base.print();

    cout << "\n=== VARIATION 4: OBJECT SLICING ===\n";

    SpecialIdentity identity;

    cout << "By value: ";
    slicedCall(identity);

    cout << "By reference: ";
    polymorphicCall(identity);

    cout << "\n=== VARIATION 5: PURE VIRTUAL DESTRUCTOR ===\n";

    AbstractResource* resource = new ConcreteResource;

    resource->use();

    delete resource;
    resource = nullptr;

    cout << "\nNext: 22_ABSTRACTION_ENCAPSULATION\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: SIGNATURE MATTERS ===
WrongDerived::show non-const
BaseA::show const
CorrectDerived::show const

=== VARIATION 2: QUALIFIED BASE CALL ===
Parent description
Child extension

=== VARIATION 3: DEFAULT ARGUMENTS ===
Called through Derived object: DefaultDerived: 2
Called through Base reference: DefaultDerived: 1

=== VARIATION 4: OBJECT SLICING ===
By value: Identity
By reference: SpecialIdentity

=== VARIATION 5: PURE VIRTUAL DESTRUCTOR ===
Concrete resource used
ConcreteResource destructor
AbstractResource destructor

Next: 22_ABSTRACTION_ENCAPSULATION
*/
