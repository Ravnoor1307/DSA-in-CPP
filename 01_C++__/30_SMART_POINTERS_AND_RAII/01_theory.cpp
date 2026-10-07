/*
Topic: Smart Pointers and RAII

Covers:
- ownership
- RAII
- unique_ptr
- make_unique
- ownership transfer
- get/reset/release
- shared_ptr
- reference counting
- weak_ptr
- cycles
- polymorphic ownership
- custom deleters
- exception-safe cleanup

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

// ========== SECTION 1: LIFETIME TRACE ==========

class Resource {
private:
    std::string name;

public:
    explicit Resource(const std::string& name)
        : name(name) {
        std::cout << "Acquire "
                  << name << '\n';
    }

    ~Resource() {
        std::cout << "Release "
                  << name << '\n';
    }

    void use() const {
        std::cout << "Using "
                  << name << '\n';
    }
};

// ========== SECTION 2: EXCEPTION + RAII ==========

void exceptionDemo() {
    auto resource =
        std::make_unique<Resource>(
            "exception-resource"
        );

    resource->use();

    throw std::runtime_error(
        "simulated failure"
    );
}

// ========== SECTION 3: POLYMORPHIC OWNERSHIP ==========

class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    Dog() {
        std::cout << "Dog constructed\n";
    }

    void speak() const override {
        std::cout << "Woof\n";
    }

    ~Dog() override {
        std::cout << "Dog destroyed\n";
    }
};

// ========== SECTION 4: WEAK CYCLE BREAK ==========

class Child;

class Parent {
public:
    std::shared_ptr<Child> child;

    ~Parent() {
        std::cout << "Parent destroyed\n";
    }
};

class Child {
public:
    std::weak_ptr<Parent> parent;

    ~Child() {
        std::cout << "Child destroyed\n";
    }
};

// ========== SECTION 5: CUSTOM DELETER ==========

struct IntDeleter {
    void operator()(int* pointer) const {
        std::cout << "Custom deleter releases "
                  << *pointer << '\n';

        delete pointer;
    }
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== DEMO 1: RAII SCOPE ===\n";

    {
        Resource resource("automatic");
        resource.use();
    }

    std::cout << "Scope ended\n";

    std::cout << "\n=== DEMO 2: unique_ptr ===\n";

    {
        auto pointer =
            std::make_unique<Resource>(
                "unique"
            );

        pointer->use();
    }

    std::cout << "\n=== DEMO 3: MOVE unique_ptr ===\n";

    auto first =
        std::make_unique<int>(42);

    std::cout << "Before move, first? "
              << static_cast<bool>(first)
              << '\n';

    auto second = std::move(first);

    std::cout << "After move, first? "
              << static_cast<bool>(first)
              << '\n';

    std::cout << "second value = "
              << *second << '\n';

    std::cout << "\n=== DEMO 4: get() ===\n";

    int* observer = second.get();

    std::cout << "Observed value = "
              << *observer << '\n';

    std::cout << "Owner still exists? "
              << static_cast<bool>(second)
              << '\n';

    std::cout << "\n=== DEMO 5: reset() ===\n";

    second.reset();

    std::cout << "After reset, second? "
              << static_cast<bool>(second)
              << '\n';

    std::cout << "\n=== DEMO 6: release() ===\n";

    auto releasable =
        std::make_unique<int>(99);

    int* manuallyOwned =
        releasable.release();

    std::cout << "After release, smart pointer? "
              << static_cast<bool>(releasable)
              << '\n';

    std::cout << "Raw value = "
              << *manuallyOwned << '\n';

    delete manuallyOwned;
    manuallyOwned = nullptr;

    std::cout << "\n=== DEMO 7: shared_ptr ===\n";

    {
        auto a =
            std::make_shared<Resource>(
                "shared"
            );

        std::cout << "Count = "
                  << a.use_count()
                  << '\n';

        {
            auto b = a;

            std::cout << "Count with b = "
                      << a.use_count()
                      << '\n';

            b->use();
        }

        std::cout << "Count after b = "
                  << a.use_count()
                  << '\n';
    }

    std::cout << "\n=== DEMO 8: weak_ptr ===\n";

    std::weak_ptr<int> weak;

    {
        auto owner =
            std::make_shared<int>(123);

        weak = owner;

        if (auto locked = weak.lock()) {
            std::cout << "Locked value = "
                      << *locked << '\n';
        }

        std::cout << "Expired inside scope? "
                  << weak.expired()
                  << '\n';
    }

    std::cout << "Expired after scope? "
              << weak.expired()
              << '\n';

    if (auto locked = weak.lock()) {
        std::cout << *locked << '\n';
    } else {
        std::cout << "Object no longer exists\n";
    }

    std::cout << "\n=== DEMO 9: BREAKING A CYCLE ===\n";

    {
        auto parent =
            std::make_shared<Parent>();

        auto child =
            std::make_shared<Child>();

        parent->child = child;
        child->parent = parent;

        std::cout << "Parent strong count = "
                  << parent.use_count()
                  << '\n';

        std::cout << "Child strong count = "
                  << child.use_count()
                  << '\n';
    }

    std::cout << "\n=== DEMO 10: POLYMORPHIC unique_ptr ===\n";

    {
        std::unique_ptr<Animal> animal =
            std::make_unique<Dog>();

        animal->speak();
    }

    std::cout << "\n=== DEMO 11: EXCEPTION SAFETY ===\n";

    try {
        exceptionDemo();
    }
    catch (const std::exception& error) {
        std::cout << "Caught: "
                  << error.what() << '\n';
    }

    std::cout << "\n=== DEMO 12: CUSTOM DELETER ===\n";

    {
        std::unique_ptr<int, IntDeleter>
            value(new int(777));

        std::cout << "Value = "
                  << *value << '\n';
    }

    std::cout << "\nNext: 31_MOVE_SEMANTICS_BASICS\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: RAII SCOPE ===
Acquire automatic
Using automatic
Release automatic
Scope ended

=== DEMO 2: unique_ptr ===
Acquire unique
Using unique
Release unique

=== DEMO 3: MOVE unique_ptr ===
Before move, first? true
After move, first? false
second value = 42

=== DEMO 4: get() ===
Observed value = 42
Owner still exists? true

=== DEMO 5: reset() ===
After reset, second? false

=== DEMO 6: release() ===
After release, smart pointer? false
Raw value = 99

=== DEMO 7: shared_ptr ===
Acquire shared
Count = 1
Count with b = 2
Using shared
Count after b = 1
Release shared

=== DEMO 8: weak_ptr ===
Locked value = 123
Expired inside scope? false
Expired after scope? true
Object no longer exists

=== DEMO 9: BREAKING A CYCLE ===
Parent strong count = 1
Child strong count = 2
Parent destroyed
Child destroyed

=== DEMO 10: POLYMORPHIC unique_ptr ===
Dog constructed
Woof
Dog destroyed

=== DEMO 11: EXCEPTION SAFETY ===
Acquire exception-resource
Using exception-resource
Release exception-resource
Caught: simulated failure

=== DEMO 12: CUSTOM DELETER ===
Value = 777
Custom deleter releases 777

Next: 31_MOVE_SEMANTICS_BASICS
*/
