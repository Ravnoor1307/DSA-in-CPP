/*
Topic: Templates
File: 03_variation.cpp

Purpose:
Explore:
- out-of-class class-template members
- multiple type parameters
- specialization
- templates with custom types
- template requirements

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: OUT-OF-CLASS TEMPLATE MEMBERS ==========

template <typename T>
class Storage {
private:
    T value;

public:
    explicit Storage(const T& value);

    const T& get() const;
};

template <typename T>
Storage<T>::Storage(const T& value)
    : value(value) {
}

template <typename T>
const T& Storage<T>::get() const {
    return value;
}

// ========== SECTION 2: GENERIC COMPARISON ==========

template <typename T>
bool areEqual(const T& a, const T& b) {
    return a == b;
}

// ========== SECTION 3: MULTIPLE TYPES ==========

template <typename T, typename U>
class KeyValue {
private:
    T key;
    U value;

public:
    KeyValue(const T& key, const U& value)
        : key(key), value(value) {
    }

    void display() const {
        cout << key
             << " => "
             << value
             << '\n';
    }
};

// ========== SECTION 4: SPECIALIZATION ==========

template <typename T>
class Formatter {
public:
    void format(const T& value) const {
        cout << "Value: "
             << value
             << '\n';
    }
};

template <>
class Formatter<bool> {
public:
    void format(bool value) const {
        cout << "Boolean: "
             << (value ? "YES" : "NO")
             << '\n';
    }
};

// ========== SECTION 5: CUSTOM TYPE REQUIREMENTS ==========

class Point {
private:
    int x;
    int y;

public:
    Point(int x, int y)
        : x(x), y(y) {
    }

    bool operator==(const Point& other) const {
        return x == other.x
            && y == other.y;
    }
};

// ========== SECTION 6: NON-TYPE PARAMETER ==========

template <int N>
int multiplyBy(int value) {
    return value * N;
}

int main() {
    cout << boolalpha;

    cout << "=== VARIATION 1: OUT-OF-CLASS MEMBERS ===\n";

    Storage<int> integer(42);
    Storage<string> text("Generic C++");

    cout << integer.get() << '\n';
    cout << text.get() << '\n';

    cout << "\n=== VARIATION 2: GENERIC EQUALITY ===\n";

    cout << "10 == 10: "
         << areEqual(10, 10) << '\n';

    cout << "abc == xyz: "
         << areEqual(
                string("abc"),
                string("xyz")
            )
         << '\n';

    cout << "\n=== VARIATION 3: MULTIPLE TYPES ===\n";

    KeyValue<string, int> age("age", 20);
    KeyValue<int, double> reading(7, 3.5);

    age.display();
    reading.display();

    cout << "\n=== VARIATION 4: SPECIALIZATION ===\n";

    Formatter<int> normal;
    Formatter<bool> booleanFormatter;

    normal.format(100);
    booleanFormatter.format(true);
    booleanFormatter.format(false);

    cout << "\n=== VARIATION 5: CUSTOM TYPE ===\n";

    Point a(1, 2);
    Point b(1, 2);
    Point c(5, 6);

    cout << "a == b: "
         << areEqual(a, b) << '\n';

    cout << "a == c: "
         << areEqual(a, c) << '\n';

    cout << "\n=== VARIATION 6: NON-TYPE FUNCTION PARAMETER ===\n";

    cout << "multiplyBy<3>(10) = "
         << multiplyBy<3>(10) << '\n';

    cout << "multiplyBy<5>(7) = "
         << multiplyBy<5>(7) << '\n';

    cout << "\nNext: 26_EXCEPTION_HANDLING\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: OUT-OF-CLASS MEMBERS ===
42
Generic C++

=== VARIATION 2: GENERIC EQUALITY ===
10 == 10: true
abc == xyz: false

=== VARIATION 3: MULTIPLE TYPES ===
age => 20
7 => 3.5

=== VARIATION 4: SPECIALIZATION ===
Value: 100
Boolean: YES
Boolean: NO

=== VARIATION 5: CUSTOM TYPE ===
a == b: true
a == c: false

=== VARIATION 6: NON-TYPE FUNCTION PARAMETER ===
multiplyBy<3>(10) = 30
multiplyBy<5>(7) = 35

Next: 26_EXCEPTION_HANDLING
*/
