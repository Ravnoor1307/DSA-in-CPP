/*
Topic: Smart Pointers and RAII
File: 04_practice_problems.cpp

Practice:
1. Exclusive ownership
2. Transfer ownership
3. Shared ownership counts
4. Weak observation
5. Polymorphic smart pointers

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <memory>
#include <string>

// ========== PROBLEM 1: UNIQUE OWNERSHIP ==========
//
// Create an object whose cleanup is automatic.

class Book {
private:
    std::string title;

public:
    explicit Book(const std::string& title)
        : title(title) {
        std::cout << "Book created: "
                  << title << '\n';
    }

    ~Book() {
        std::cout << "Book destroyed: "
                  << title << '\n';
    }

    const std::string& getTitle() const {
        return title;
    }
};

void uniqueOwnership() {
    auto book =
        std::make_unique<Book>(
            "Algorithms"
        );

    std::cout << "Reading "
              << book->getTitle()
              << '\n';
}

// ========== PROBLEM 2: OWNERSHIP TRANSFER ==========

void receive(std::unique_ptr<int> value) {
    std::cout << "Received = "
              << *value << '\n';
}

void transferOwnership() {
    auto owner =
        std::make_unique<int>(75);

    std::cout << std::boolalpha;

    std::cout << "Before move = "
              << static_cast<bool>(owner)
              << '\n';

    receive(std::move(owner));

    std::cout << "After move = "
              << static_cast<bool>(owner)
              << '\n';
}

// ========== PROBLEM 3: SHARED OWNERSHIP ==========

void sharedOwnership() {
    auto first =
        std::make_shared<std::string>(
            "shared-data"
        );

    std::cout << "Owners = "
              << first.use_count()
              << '\n';

    {
        auto second = first;
        auto third = second;

        std::cout << "Owners = "
                  << first.use_count()
                  << '\n';

        std::cout << *third << '\n';
    }

    std::cout << "Owners = "
              << first.use_count()
              << '\n';
}

// ========== PROBLEM 4: WEAK OBSERVER ==========

void weakObservation() {
    std::weak_ptr<int> observer;

    {
        auto owner =
            std::make_shared<int>(500);

        observer = owner;

        if (auto temporaryOwner =
                observer.lock()) {
            std::cout << "Value = "
                      << *temporaryOwner
                      << '\n';
        }
    }

    std::cout << std::boolalpha;

    std::cout << "Expired = "
              << observer.expired()
              << '\n';
}

// ========== PROBLEM 5: POLYMORPHIC OWNERSHIP ==========

class Notification {
public:
    virtual void send() const = 0;
    virtual ~Notification() = default;
};

class Email : public Notification {
public:
    void send() const override {
        std::cout << "Email sent\n";
    }

    ~Email() override {
        std::cout << "Email object destroyed\n";
    }
};

void polymorphicOwnership() {
    std::unique_ptr<Notification>
        notification =
            std::make_unique<Email>();

    notification->send();
}

int main() {
    std::cout << "=== PROBLEM 1: UNIQUE OWNERSHIP ===\n";

    uniqueOwnership();

    std::cout << "\n=== PROBLEM 2: TRANSFER OWNERSHIP ===\n";

    transferOwnership();

    std::cout << "\n=== PROBLEM 3: SHARED OWNERSHIP ===\n";

    sharedOwnership();

    std::cout << "\n=== PROBLEM 4: WEAK OBSERVER ===\n";

    weakObservation();

    std::cout << "\n=== PROBLEM 5: POLYMORPHIC OWNERSHIP ===\n";

    polymorphicOwnership();

    std::cout << "\nNext: 31_MOVE_SEMANTICS_BASICS\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: UNIQUE OWNERSHIP ===
Book created: Algorithms
Reading Algorithms
Book destroyed: Algorithms

=== PROBLEM 2: TRANSFER OWNERSHIP ===
Before move = true
Received = 75
After move = false

=== PROBLEM 3: SHARED OWNERSHIP ===
Owners = 1
Owners = 3
shared-data
Owners = 1

=== PROBLEM 4: WEAK OBSERVER ===
Value = 500
Expired = true

=== PROBLEM 5: POLYMORPHIC OWNERSHIP ===
Email sent
Email object destroyed

Next: 31_MOVE_SEMANTICS_BASICS
*/
