/*
Topic: static, const, and friend

Covers:
- static data members
- static member functions
- local static variables
- const objects
- const member functions
- const overloads
- const references
- mutable
- friend functions
- friend classes

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: STATIC DATA MEMBERS ==========

class Tracker {
private:
    inline static int liveCount = 0;

public:
    Tracker() {
        ++liveCount;
    }

    // We define copy construction explicitly so that a copied
    // Tracker also counts as a new live Tracker object.
    Tracker(const Tracker&) {
        ++liveCount;
    }

    ~Tracker() {
        --liveCount;
    }

    static int getLiveCount() {
        return liveCount;
    }
};

// ========== SECTION 2: STATIC MEMBER FUNCTIONS ==========

class MathUtility {
public:
    static int square(int value) {
        return value * value;
    }

    static int maxOf(int a, int b) {
        return a > b ? a : b;
    }
};

// ========== SECTION 3: LOCAL STATIC VARIABLE ==========

class CallCounter {
public:
    void call() const {
        static int calls = 0;

        ++calls;

        cout << "Total calls = "
             << calls << '\n';
    }
};

// ========== SECTION 4: CONST MEMBER FUNCTIONS ==========

class Point {
private:
    int x;
    int y;

public:
    Point(int x, int y)
        : x(x), y(y) {
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int value) {
        x = value;
    }

    void print() const {
        cout << '(' << x << ", " << y << ')';
    }
};

// ========== SECTION 5: CONST / NON-CONST OVERLOADS ==========

class NumberBox {
private:
    int value;

public:
    explicit NumberBox(int value)
        : value(value) {
    }

    int& get() {
        cout << "Non-const get\n";
        return value;
    }

    const int& get() const {
        cout << "Const get\n";
        return value;
    }
};

// ========== SECTION 6: CONST REFERENCE RETURN ==========

class Person {
private:
    string name;

public:
    explicit Person(const string& name)
        : name(name) {
    }

    const string& getName() const {
        return name;
    }
};

// ========== SECTION 7: mutable ==========

class Document {
private:
    string text;
    mutable int readCount = 0;

public:
    explicit Document(const string& text)
        : text(text) {
    }

    const string& read() const {
        ++readCount;
        return text;
    }

    int getReadCount() const {
        return readCount;
    }
};

// ========== SECTION 8: FRIEND FUNCTION ==========

class Secret {
private:
    int value;

public:
    explicit Secret(int value)
        : value(value) {
    }

    friend void reveal(const Secret& secret);
};

void reveal(const Secret& secret) {
    cout << "Secret value = "
         << secret.value << '\n';
}

// ========== SECTION 9: FRIEND CLASS ==========

class Vault {
private:
    int code = 2468;

    friend class Inspector;
};

class Inspector {
public:
    void inspect(const Vault& vault) const {
        cout << "Vault code = "
             << vault.code << '\n';
    }
};

int main() {
    cout << "=== DEMO 1: STATIC OBJECT COUNTER ===\n";

    cout << "Initially = "
         << Tracker::getLiveCount() << '\n';

    {
        Tracker first;

        cout << "After first = "
             << Tracker::getLiveCount() << '\n';

        {
            Tracker second;
            Tracker third;

            cout << "Inside nested block = "
                 << Tracker::getLiveCount() << '\n';
        }

        cout << "After nested block = "
             << Tracker::getLiveCount() << '\n';
    }

    cout << "After all trackers = "
         << Tracker::getLiveCount() << '\n';

    cout << "\n=== DEMO 2: STATIC MEMBER FUNCTIONS ===\n";

    cout << "square(6) = "
         << MathUtility::square(6) << '\n';

    cout << "maxOf(10, 25) = "
         << MathUtility::maxOf(10, 25) << '\n';

    cout << "\n=== DEMO 3: LOCAL STATIC ===\n";

    CallCounter a;
    CallCounter b;

    a.call();
    a.call();
    b.call();

    cout << "\n=== DEMO 4: CONST OBJECT ===\n";

    const Point point(3, 7);

    point.print();

    cout << "\nx = "
         << point.getX() << '\n';

    // point.setX(100);
    // ERROR: setX is not a const member function.

    cout << "\n=== DEMO 5: CONST OVERLOADS ===\n";

    NumberBox normal(10);
    const NumberBox fixed(20);

    cout << "normal value = "
         << normal.get() << '\n';

    cout << "fixed value = "
         << fixed.get() << '\n';

    cout << "\n=== DEMO 6: CONST REFERENCE RETURN ===\n";

    Person person("Asha");

    const string& name = person.getName();

    cout << "Name = "
         << name << '\n';

    cout << "\n=== DEMO 7: mutable ===\n";

    const Document document("DSA notes");

    cout << "Read #1: "
         << document.read() << '\n';

    cout << "Read #2: "
         << document.read() << '\n';

    cout << "Read count = "
         << document.getReadCount() << '\n';

    cout << "\n=== DEMO 8: FRIEND FUNCTION ===\n";

    Secret secret(99);
    reveal(secret);

    cout << "\n=== DEMO 9: FRIEND CLASS ===\n";

    Vault vault;
    Inspector inspector;

    inspector.inspect(vault);

    cout << "\nNext: 24_OPERATOR_OVERLOADING\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: STATIC OBJECT COUNTER ===
Initially = 0
After first = 1
Inside nested block = 3
After nested block = 1
After all trackers = 0

=== DEMO 2: STATIC MEMBER FUNCTIONS ===
square(6) = 36
maxOf(10, 25) = 25

=== DEMO 3: LOCAL STATIC ===
Total calls = 1
Total calls = 2
Total calls = 3

=== DEMO 4: CONST OBJECT ===
(3, 7)
x = 3

=== DEMO 5: CONST OVERLOADS ===
Non-const get
normal value = 10
Const get
fixed value = 20

=== DEMO 6: CONST REFERENCE RETURN ===
Name = Asha

=== DEMO 7: mutable ===
Read #1: DSA notes
Read #2: DSA notes
Read count = 2

=== DEMO 8: FRIEND FUNCTION ===
Secret value = 99

=== DEMO 9: FRIEND CLASS ===
Vault code = 2468

Next: 24_OPERATOR_OVERLOADING
*/
