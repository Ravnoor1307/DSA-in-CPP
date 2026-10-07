/*
Topic: Smart Pointers and RAII
File: 03_variation.cpp

Purpose:
Explore:
- ownership versus observation
- unique_ptr parameters
- shared ownership
- weak back-references
- polymorphic ownership
- exception-safe RAII

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

// ========== SECTION 1: OBSERVATION ==========

void inspect(const int* value) {
    if (value) {
        std::cout << "Observed "
                  << *value << '\n';
    }
}

// ========== SECTION 2: TRANSFER OWNERSHIP TO FUNCTION ==========

void consume(std::unique_ptr<int> value) {
    std::cout << "Consumed "
              << *value << '\n';

    // value is destroyed at function exit.
}

// ========== SECTION 3: POLYMORPHISM ==========

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

// ========== SECTION 4: PARENT / CHILD OWNERSHIP ==========

class Parent;

class Child {
private:
    std::weak_ptr<Parent> parent;

public:
    void setParent(
        const std::shared_ptr<Parent>& value
    ) {
        parent = value;
    }

    bool hasLiveParent() const {
        return !parent.expired();
    }
};

class Parent {
private:
    std::shared_ptr<Child> child;

public:
    void setChild(
        const std::shared_ptr<Child>& value
    ) {
        child = value;
    }
};

// ========== SECTION 5: RAII TRACE ==========

class Guard {
private:
    std::string name;

public:
    explicit Guard(const std::string& name)
        : name(name) {
        std::cout << "Open "
                  << name << '\n';
    }

    ~Guard() {
        std::cout << "Close "
                  << name << '\n';
    }
};

void risky() {
    Guard guard("resource");

    throw std::runtime_error(
        "operation failed"
    );
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== VARIATION 1: NON-OWNING RAW POINTER ===\n";

    auto owner =
        std::make_unique<int>(42);

    inspect(owner.get());

    std::cout << "Owner still owns? "
              << static_cast<bool>(owner)
              << '\n';

    std::cout << "\n=== VARIATION 2: TRANSFER TO FUNCTION ===\n";

    consume(std::move(owner));

    std::cout << "Owner after consume? "
              << static_cast<bool>(owner)
              << '\n';

    std::cout << "\n=== VARIATION 3: POLYMORPHIC OWNERSHIP ===\n";

    std::unique_ptr<Shape> shape =
        std::make_unique<Rectangle>(
            5,
            4
        );

    std::cout << "Area = "
              << shape->area()
              << '\n';

    std::cout << "\n=== VARIATION 4: WEAK BACK-REFERENCE ===\n";

    std::weak_ptr<Child> outsideChild;

    {
        auto parent =
            std::make_shared<Parent>();

        auto child =
            std::make_shared<Child>();

        outsideChild = child;

        parent->setChild(child);
        child->setParent(parent);

        std::cout << "Child sees parent? "
                  << child->hasLiveParent()
                  << '\n';

        child.reset();

        std::cout << "Outside weak child expired? "
                  << outsideChild.expired()
                  << '\n';
    }

    std::cout << "After parent scope, child expired? "
              << outsideChild.expired()
              << '\n';

    std::cout << "\n=== VARIATION 5: EXCEPTION + RAII ===\n";

    try {
        risky();
    }
    catch (const std::exception& error) {
        std::cout << "Caught: "
                  << error.what()
                  << '\n';
    }

    std::cout << "\nNext: 31_MOVE_SEMANTICS_BASICS\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: NON-OWNING RAW POINTER ===
Observed 42
Owner still owns? true

=== VARIATION 2: TRANSFER TO FUNCTION ===
Consumed 42
Owner after consume? false

=== VARIATION 3: POLYMORPHIC OWNERSHIP ===
Area = 20

=== VARIATION 4: WEAK BACK-REFERENCE ===
Child sees parent? true
Outside weak child expired? false
After parent scope, child expired? true

=== VARIATION 5: EXCEPTION + RAII ===
Open resource
Close resource
Caught: operation failed

Next: 31_MOVE_SEMANTICS_BASICS
*/
