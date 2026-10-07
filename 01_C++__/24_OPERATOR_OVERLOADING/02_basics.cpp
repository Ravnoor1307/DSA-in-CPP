/*
Topic: Operator Overloading
File: 02_basics.cpp

Purpose:
Practice common, intuitive operator overloads.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>

using namespace std;

// ========== SECTION 1: DISTANCE + AND += ==========

class Distance {
private:
    int meters;

public:
    explicit Distance(int meters = 0)
        : meters(meters >= 0 ? meters : 0) {
    }

    Distance& operator+=(const Distance& other) {
        meters += other.meters;
        return *this;
    }

    friend Distance operator+(
        Distance lhs,
        const Distance& rhs
    ) {
        lhs += rhs;
        return lhs;
    }

    int getMeters() const {
        return meters;
    }
};

// ========== SECTION 2: EQUALITY ==========

class Size {
private:
    int width;
    int height;

public:
    Size(int width, int height)
        : width(width), height(height) {
    }

    bool operator==(const Size& other) const {
        return width == other.width
            && height == other.height;
    }

    bool operator!=(const Size& other) const {
        return !(*this == other);
    }
};

// ========== SECTION 3: COUNTER ++ ==========

class Counter {
private:
    int value;

public:
    explicit Counter(int value = 0)
        : value(value) {
    }

    Counter& operator++() {
        ++value;
        return *this;
    }

    Counter operator++(int) {
        Counter old = *this;
        ++value;
        return old;
    }

    int get() const {
        return value;
    }
};

// ========== SECTION 4: STREAM OUTPUT ==========

class Pair {
private:
    int first;
    int second;

public:
    Pair(int first, int second)
        : first(first), second(second) {
    }

    friend ostream& operator<<(
        ostream& out,
        const Pair& pair
    ) {
        out << '['
            << pair.first
            << ", "
            << pair.second
            << ']';

        return out;
    }
};

int main() {
    cout << boolalpha;

    cout << "=== BASIC 1: DISTANCE ===\n";

    Distance first(100);
    Distance second(250);

    Distance total = first + second;

    cout << "Total = "
         << total.getMeters()
         << " meters\n";

    first += second;

    cout << "First after += = "
         << first.getMeters()
         << " meters\n";

    cout << "\n=== BASIC 2: EQUALITY ===\n";

    Size a(5, 4);
    Size b(5, 4);
    Size c(4, 5);

    cout << "a == b: "
         << (a == b) << '\n';

    cout << "a == c: "
         << (a == c) << '\n';

    cout << "a != c: "
         << (a != c) << '\n';

    cout << "\n=== BASIC 3: INCREMENT ===\n";

    Counter counter(10);

    cout << "Initial = "
         << counter.get() << '\n';

    Counter old = counter++;

    cout << "Postfix returned = "
         << old.get() << '\n';

    cout << "Counter now = "
         << counter.get() << '\n';

    Counter& updated = ++counter;

    cout << "Prefix returned = "
         << updated.get() << '\n';

    cout << "\n=== BASIC 4: STREAM OUTPUT ===\n";

    Pair pair(7, 9);

    cout << "Pair = "
         << pair << '\n';

    cout << "\nNext: 25_TEMPLATES\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: DISTANCE ===
Total = 350 meters
First after += = 350 meters

=== BASIC 2: EQUALITY ===
a == b: true
a == c: false
a != c: true

=== BASIC 3: INCREMENT ===
Initial = 10
Postfix returned = 10
Counter now = 11
Prefix returned = 12

=== BASIC 4: STREAM OUTPUT ===
Pair = [7, 9]

Next: 25_TEMPLATES
*/
