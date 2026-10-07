/*
Topic: Move Semantics Basics
File: 03_variation.cpp

Purpose:
Explore:
- observable copy/move constructor selection
- copy/move assignment
- const and std::move
- return by value
- Rule of Zero

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

// ========== SECTION 1: TRACE COPY AND MOVE ==========

class Trace {
private:
    int value;

public:
    explicit Trace(int value = 0)
        : value(value) {
        std::cout << "Construct "
                  << value << '\n';
    }

    Trace(const Trace& other)
        : value(other.value) {
        std::cout << "Copy construct "
                  << value << '\n';
    }

    Trace(Trace&& other) noexcept
        : value(other.value) {
        other.value = -1;

        std::cout << "Move construct "
                  << value << '\n';
    }

    Trace& operator=(const Trace& other) {
        value = other.value;

        std::cout << "Copy assign "
                  << value << '\n';

        return *this;
    }

    Trace& operator=(Trace&& other) noexcept {
        if (this != &other) {
            value = other.value;
            other.value = -1;
        }

        std::cout << "Move assign "
                  << value << '\n';

        return *this;
    }

    int get() const {
        return value;
    }
};

// ========== SECTION 2: RETURN BY VALUE ==========

Trace makeTrace(int value) {
    return Trace(value);
}

// ========== SECTION 3: CONST MOVE DEMONSTRATION ==========

void receive(const Trace&) {
    std::cout << "receive const Trace&\n";
}

void receive(Trace&&) {
    std::cout << "receive Trace&&\n";
}

// ========== SECTION 4: RULE OF ZERO ==========

class Record {
private:
    std::string name;
    std::vector<int> values;

public:
    Record(
        std::string name,
        std::vector<int> values
    )
        : name(std::move(name)),
          values(std::move(values)) {
    }

    void show() const {
        std::cout << name << ": ";

        for (int value : values) {
            std::cout << value << ' ';
        }

        std::cout << '\n';
    }
};

int main() {
    std::cout << "=== VARIATION 1: COPY CONSTRUCTION ===\n";

    Trace first(10);
    Trace copied(first);

    std::cout << "copied = "
              << copied.get()
              << '\n';

    std::cout << "\n=== VARIATION 2: MOVE CONSTRUCTION ===\n";

    Trace moved(std::move(first));

    std::cout << "moved = "
              << moved.get()
              << '\n';

    std::cout << "first moved-from = "
              << first.get()
              << '\n';

    std::cout << "\n=== VARIATION 3: ASSIGNMENT ===\n";

    Trace destination(100);

    destination = copied;

    std::cout << "after copy assignment = "
              << destination.get()
              << '\n';

    destination = std::move(copied);

    std::cout << "after move assignment = "
              << destination.get()
              << '\n';

    std::cout << "copied moved-from = "
              << copied.get()
              << '\n';

    std::cout << "\n=== VARIATION 4: RETURN BY VALUE ===\n";

    Trace returned =
        makeTrace(77);

    std::cout << "returned = "
              << returned.get()
              << '\n';

    std::cout << "\n=== VARIATION 5: const + std::move ===\n";

    const Trace fixed(55);

    receive(std::move(fixed));

    // std::move(fixed) is const-qualified and cannot bind to
    // receive(Trace&&), so receive(const Trace&) is selected.

    std::cout << "\n=== VARIATION 6: RULE OF ZERO ===\n";

    Record record(
        "scores",
        std::vector<int>{10, 20, 30}
    );

    record.show();

    std::cout << "\nNext: 32_STL_BASICS\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: COPY CONSTRUCTION ===
Construct 10
Copy construct 10
copied = 10

=== VARIATION 2: MOVE CONSTRUCTION ===
Move construct 10
moved = 10
first moved-from = -1

=== VARIATION 3: ASSIGNMENT ===
Construct 100
Copy assign 10
after copy assignment = 10
Move assign 10
after move assignment = 10
copied moved-from = -1

=== VARIATION 4: RETURN BY VALUE ===
Construct 77
returned = 77

=== VARIATION 5: const + std::move ===
Construct 55
receive const Trace&

=== VARIATION 6: RULE OF ZERO ===
scores: 10 20 30

Next: 32_STL_BASICS
*/
