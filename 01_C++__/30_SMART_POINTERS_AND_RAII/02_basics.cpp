/*
Topic: Smart Pointers and RAII
File: 02_basics.cpp

Purpose:
Practice:
- unique_ptr
- transferring ownership
- shared_ptr
- weak_ptr
- automatic RAII cleanup

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <memory>
#include <string>

class Item {
private:
    std::string name;

public:
    explicit Item(const std::string& name)
        : name(name) {
        std::cout << "Create "
                  << name << '\n';
    }

    ~Item() {
        std::cout << "Destroy "
                  << name << '\n';
    }

    const std::string& getName() const {
        return name;
    }
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== BASIC 1: unique_ptr ===\n";

    {
        auto item =
            std::make_unique<Item>(
                "Book"
            );

        std::cout << item->getName()
                  << '\n';
    }

    std::cout << "\n=== BASIC 2: OWNERSHIP TRANSFER ===\n";

    auto first =
        std::make_unique<int>(50);

    auto second =
        std::move(first);

    std::cout << "first owns? "
              << static_cast<bool>(first)
              << '\n';

    std::cout << "second owns? "
              << static_cast<bool>(second)
              << '\n';

    std::cout << "value = "
              << *second << '\n';

    std::cout << "\n=== BASIC 3: reset ===\n";

    second.reset();

    std::cout << "second owns? "
              << static_cast<bool>(second)
              << '\n';

    std::cout << "\n=== BASIC 4: shared_ptr ===\n";

    auto shared =
        std::make_shared<int>(100);

    std::cout << "count = "
              << shared.use_count()
              << '\n';

    {
        auto another = shared;

        std::cout << "count = "
                  << shared.use_count()
                  << '\n';

        std::cout << "value = "
                  << *another << '\n';
    }

    std::cout << "count = "
              << shared.use_count()
              << '\n';

    std::cout << "\n=== BASIC 5: weak_ptr ===\n";

    std::weak_ptr<int> observer =
        shared;

    std::cout << "expired? "
              << observer.expired()
              << '\n';

    if (auto locked = observer.lock()) {
        std::cout << "observed = "
                  << *locked << '\n';
    }

    shared.reset();

    std::cout << "expired now? "
              << observer.expired()
              << '\n';

    std::cout << "\nNext: 31_MOVE_SEMANTICS_BASICS\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: unique_ptr ===
Create Book
Book
Destroy Book

=== BASIC 2: OWNERSHIP TRANSFER ===
first owns? false
second owns? true
value = 50

=== BASIC 3: reset ===
second owns? false

=== BASIC 4: shared_ptr ===
count = 1
count = 2
value = 100
count = 1

=== BASIC 5: weak_ptr ===
expired? false
observed = 100
expired now? true

Next: 31_MOVE_SEMANTICS_BASICS
*/
