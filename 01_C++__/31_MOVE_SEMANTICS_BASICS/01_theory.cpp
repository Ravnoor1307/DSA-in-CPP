/*
Topic: Move Semantics Basics

Covers:
- lvalues and rvalues
- lvalue/rvalue references
- copy vs move construction
- std::move
- moved-from states
- copy vs move assignment
- Rule of Five / Rule of Zero
- noexcept
- standard-library moves
- copy elision

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// ========== SECTION 1: LVALUE / RVALUE OVERLOADS ==========

void category(const int&) {
    std::cout << "const lvalue reference overload\n";
}

void category(int&&) {
    std::cout << "rvalue reference overload\n";
}

// ========== SECTION 2: RESOURCE-OWNING BUFFER ==========

class Buffer {
private:
    int* data;
    int size;

public:
    explicit Buffer(int size)
        : data(size > 0 ? new int[size] : nullptr),
          size(size > 0 ? size : 0) {
        std::cout << "Construct Buffer("
                  << this->size
                  << ")\n";

        for (int i = 0; i < this->size; ++i) {
            data[i] = i + 1;
        }
    }

    // Copy constructor: deep copy.
    Buffer(const Buffer& other)
        : data(
              other.size > 0
                  ? new int[other.size]
                  : nullptr
          ),
          size(other.size) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }

        std::cout << "Copy constructor\n";
    }

    // Move constructor: transfer pointer ownership.
    Buffer(Buffer&& other) noexcept
        : data(other.data),
          size(other.size) {
        other.data = nullptr;
        other.size = 0;

        std::cout << "Move constructor\n";
    }

    // Copy assignment.
    Buffer& operator=(const Buffer& other) {
        std::cout << "Copy assignment\n";

        if (this == &other) {
            return *this;
        }

        int* newData =
            other.size > 0
                ? new int[other.size]
                : nullptr;

        for (int i = 0; i < other.size; ++i) {
            newData[i] = other.data[i];
        }

        delete[] data;

        data = newData;
        size = other.size;

        return *this;
    }

    // Move assignment.
    Buffer& operator=(Buffer&& other) noexcept {
        std::cout << "Move assignment\n";

        if (this == &other) {
            return *this;
        }

        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        return *this;
    }

    ~Buffer() {
        std::cout << "Destroy Buffer("
                  << size
                  << ")\n";

        delete[] data;
    }

    int getSize() const noexcept {
        return size;
    }

    int first() const {
        return size > 0 ? data[0] : -1;
    }
};

// ========== SECTION 3: NAMED RVALUE REFERENCE ==========

void inspectRvalue(int&& value) {
    // Despite value's declared type being int&&,
    // the expression "value" is an lvalue because it has a name.
    category(value);

    category(std::move(value));
}

// ========== SECTION 4: RETURN BY VALUE ==========

std::string makeMessage() {
    std::string message = "returned efficiently";

    // Do not force std::move here.
    return message;
}

// ========== SECTION 5: RULE OF ZERO ==========

class Student {
private:
    std::string name;
    std::vector<int> marks;

public:
    Student(
        std::string name,
        std::vector<int> marks
    )
        : name(std::move(name)),
          marks(std::move(marks)) {
    }

    void show() const {
        std::cout << name << ": ";

        for (int mark : marks) {
            std::cout << mark << ' ';
        }

        std::cout << '\n';
    }

    // No custom destructor/copy/move logic is needed.
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "=== DEMO 1: LVALUE AND RVALUE ===\n";

    int value = 10;

    category(value);
    category(20);
    category(std::move(value));

    std::cout << "\n=== DEMO 2: NAMED RVALUE REFERENCE ===\n";

    inspectRvalue(50);

    std::cout << "\n=== DEMO 3: COPY CONSTRUCTION ===\n";

    Buffer original(3);
    Buffer copied = original;

    std::cout << "Original size = "
              << original.getSize()
              << '\n';

    std::cout << "Copied size = "
              << copied.getSize()
              << '\n';

    std::cout << "\n=== DEMO 4: MOVE CONSTRUCTION ===\n";

    Buffer moved =
        std::move(original);

    std::cout << "Moved size = "
              << moved.getSize()
              << '\n';

    std::cout << "Original after move size = "
              << original.getSize()
              << '\n';

    std::cout << "\n=== DEMO 5: COPY ASSIGNMENT ===\n";

    Buffer copyDestination(1);

    copyDestination = copied;

    std::cout << "Destination size = "
              << copyDestination.getSize()
              << '\n';

    std::cout << "\n=== DEMO 6: MOVE ASSIGNMENT ===\n";

    Buffer moveDestination(2);

    moveDestination =
        std::move(copied);

    std::cout << "Move destination size = "
              << moveDestination.getSize()
              << '\n';

    std::cout << "Copied after move size = "
              << copied.getSize()
              << '\n';

    std::cout << "\n=== DEMO 7: unique_ptr MOVE ===\n";

    auto first =
        std::make_unique<int>(42);

    auto second =
        std::move(first);

    std::cout << "first? "
              << static_cast<bool>(first)
              << '\n';

    std::cout << "second = "
              << *second
              << '\n';

    std::cout << "\n=== DEMO 8: STRING MOVE ===\n";

    std::string source =
        "Move semantics";

    std::string destination =
        std::move(source);

    std::cout << "destination = "
              << destination
              << '\n';

    std::cout
        << "source remains valid; "
        << "its exact contents are not assumed\n";

    source = "reused";

    std::cout << "source after assignment = "
              << source
              << '\n';

    std::cout << "\n=== DEMO 9: RETURN BY VALUE ===\n";

    auto message = makeMessage();

    std::cout << message << '\n';

    std::cout << "\n=== DEMO 10: RULE OF ZERO ===\n";

    Student student(
        "Asha",
        std::vector<int>{90, 95, 88}
    );

    student.show();

    std::cout << "\nNext: 32_STL_BASICS\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: LVALUE AND RVALUE ===
const lvalue reference overload
rvalue reference overload
rvalue reference overload

=== DEMO 2: NAMED RVALUE REFERENCE ===
const lvalue reference overload
rvalue reference overload

=== DEMO 3: COPY CONSTRUCTION ===
Construct Buffer(3)
Copy constructor
Original size = 3
Copied size = 3

=== DEMO 4: MOVE CONSTRUCTION ===
Move constructor
Moved size = 3
Original after move size = 0

=== DEMO 5: COPY ASSIGNMENT ===
Construct Buffer(1)
Copy assignment
Destination size = 3

=== DEMO 6: MOVE ASSIGNMENT ===
Construct Buffer(2)
Move assignment
Move destination size = 3
Copied after move size = 0

=== DEMO 7: unique_ptr MOVE ===
first? false
second = 42

=== DEMO 8: STRING MOVE ===
destination = Move semantics
source remains valid; its exact contents are not assumed
source after assignment = reused

=== DEMO 9: RETURN BY VALUE ===
returned efficiently

=== DEMO 10: RULE OF ZERO ===
Asha: 90 95 88

Next: 32_STL_BASICS

Then Buffer destructor messages appear in reverse lifetime order:
Destroy Buffer(3)
Destroy Buffer(3)
Destroy Buffer(3)
Destroy Buffer(0)
Destroy Buffer(0)

The exact listed Buffer destruction sequence corresponds to the named
Buffer objects in this program and their moved-from states.
*/
