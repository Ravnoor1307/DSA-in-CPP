/*
Topic: static, const, and friend
File: 04_practice_problems.cpp

Practice:
1. Count live objects with static state
2. Generate unique IDs
3. Build a const-correct Student class
4. Use mutable for read statistics
5. Use a friend function for controlled comparison

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <string>

using namespace std;

// ========== PROBLEM 1: LIVE OBJECT COUNTER ==========
//
// Maintain one count shared by all objects.
//
// Complexity:
// construction: O(1)
// destruction:  O(1)
// getCount:     O(1)

class LiveObject {
private:
    inline static int count = 0;

public:
    LiveObject() {
        ++count;
    }

    LiveObject(const LiveObject&) {
        ++count;
    }

    ~LiveObject() {
        --count;
    }

    static int getCount() {
        return count;
    }
};

// ========== PROBLEM 2: UNIQUE ID GENERATOR ==========
//
// Each newly created Ticket receives a new ID.
//
// Copying is disabled here because a copied ticket having the same
// identity would make the meaning of "unique ticket" ambiguous.

class Ticket {
private:
    inline static int nextId = 1001;

    const int id;

public:
    Ticket()
        : id(nextId++) {
    }

    Ticket(const Ticket&) = delete;
    Ticket& operator=(const Ticket&) = delete;

    int getId() const {
        return id;
    }

    static int nextAvailableId() {
        return nextId;
    }
};

// ========== PROBLEM 3: CONST-CORRECT STUDENT ==========

class Student {
private:
    string name;
    int marks;

public:
    Student(
        const string& name,
        int marks
    )
        : name(name),
          marks(
              marks >= 0 && marks <= 100
                  ? marks
                  : 0
          ) {
    }

    const string& getName() const {
        return name;
    }

    int getMarks() const {
        return marks;
    }

    bool passed() const {
        return marks >= 40;
    }
};

// ========== PROBLEM 4: mutable READ COUNTER ==========
//
// Reading does not change the logical message,
// but we keep internal usage statistics.

class Message {
private:
    string text;
    mutable int reads = 0;

public:
    explicit Message(const string& text)
        : text(text) {
    }

    const string& read() const {
        ++reads;
        return text;
    }

    int readCount() const {
        return reads;
    }
};

// ========== PROBLEM 5: FRIEND COMPARISON ==========
//
// Two Box objects keep their dimensions private.
//
// The external helper receives narrowly defined friend access.

class Box {
private:
    int width;
    int height;

public:
    Box(int width, int height)
        : width(width >= 0 ? width : 0),
          height(height >= 0 ? height : 0) {
    }

    int area() const {
        return width * height;
    }

    friend bool sameDimensions(
        const Box& a,
        const Box& b
    );
};

bool sameDimensions(
    const Box& a,
    const Box& b
) {
    return a.width == b.width
        && a.height == b.height;
}

int main() {
    cout << boolalpha;

    cout << "=== PROBLEM 1: LIVE OBJECT COUNTER ===\n";

    cout << "Start = "
         << LiveObject::getCount() << '\n';

    {
        LiveObject first;
        LiveObject second;

        cout << "Inside block = "
             << LiveObject::getCount() << '\n';
    }

    cout << "After block = "
         << LiveObject::getCount() << '\n';

    cout << "\n=== PROBLEM 2: UNIQUE IDs ===\n";

    Ticket firstTicket;
    Ticket secondTicket;

    cout << "First ID = "
         << firstTicket.getId() << '\n';

    cout << "Second ID = "
         << secondTicket.getId() << '\n';

    cout << "Next available = "
         << Ticket::nextAvailableId() << '\n';

    cout << "\n=== PROBLEM 3: CONST STUDENT ===\n";

    const Student student("Asha", 82);

    cout << student.getName()
         << ": "
         << student.getMarks()
         << '\n';

    cout << "Passed? "
         << student.passed() << '\n';

    cout << "\n=== PROBLEM 4: mutable COUNTER ===\n";

    const Message message("Study DSA");

    cout << message.read() << '\n';
    cout << message.read() << '\n';
    cout << message.read() << '\n';

    cout << "Reads = "
         << message.readCount() << '\n';

    cout << "\n=== PROBLEM 5: FRIEND FUNCTION ===\n";

    Box a(5, 4);
    Box b(5, 4);
    Box c(4, 5);

    cout << "a area = "
         << a.area() << '\n';

    cout << "a and b same dimensions? "
         << sameDimensions(a, b) << '\n';

    cout << "a and c same dimensions? "
         << sameDimensions(a, c) << '\n';

    cout << "\nNext: 24_OPERATOR_OVERLOADING\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: LIVE OBJECT COUNTER ===
Start = 0
Inside block = 2
After block = 0

=== PROBLEM 2: UNIQUE IDs ===
First ID = 1001
Second ID = 1002
Next available = 1003

=== PROBLEM 3: CONST STUDENT ===
Asha: 82
Passed? true

=== PROBLEM 4: mutable COUNTER ===
Study DSA
Study DSA
Study DSA
Reads = 3

=== PROBLEM 5: FRIEND FUNCTION ===
a area = 20
a and b same dimensions? true
a and c same dimensions? false

Next: 24_OPERATOR_OVERLOADING
*/
