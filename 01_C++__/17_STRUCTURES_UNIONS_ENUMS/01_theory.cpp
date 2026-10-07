/*
TOPIC: Structures, Unions, and Enums

Covers:
- struct definitions
- member access
- aggregate initialization
- default member initialization
- copying
- references/pointers to structs
- self-referential structs
- dynamic structs
- enum
- enum class
- union
- active union members
- tagged union idea
- padding/alignment awareness

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>
#include <string>

using namespace std;


// ========== SECTION 1: STRUCT ==========
//
// A struct groups related members.
//
//     struct Point {
//         int x;
//         int y;
//     };
//
// The semicolon after } is required.


// ========== SECTION 2: MEMBER ACCESS ==========
//
// Object:
//
//     Point p;
//     p.x
//
// Pointer:
//
//     Point* ptr = &p;
//     ptr->x
//
// ptr->x is equivalent to:
//
//     (*ptr).x


// ========== SECTION 3: INITIALIZATION ==========
//
// Aggregate-style initialization:
//
//     Point p{10, 20};
//
// Empty braces can zero/value-initialize simple members:
//
//     Point p{};


// ========== SECTION 4: DEFAULT MEMBER INITIALIZERS ==========
//
//     struct Point {
//         int x = 0;
//         int y = 0;
//     };
//
// A default-created Point gets those member values.


// ========== SECTION 5: STRUCT COPYING ==========
//
// For simple value members:
//
//     Point b = a;
//
// copies members.
//
// b is an independent Point object.


// ========== SECTION 6: PASSING STRUCTS ==========
//
// Copy:
//
//     void f(Point p);
//
// Modify caller:
//
//     void f(Point& p);
//
// Read without copying:
//
//     void f(const Point& p);


// ========== SECTION 7: SELF-REFERENTIAL STRUCT ==========
//
// INVALID:
//
//     struct Node {
//         Node next;
//     };
//
// Valid using indirection:
//
//     struct Node {
//         int value;
//         Node* next;
//     };


// ========== SECTION 8: DYNAMIC NODE ==========
//
//     Node* node =
//         new Node{10, nullptr};
//
// Access:
//
//     node->value
//
// Cleanup:
//
//     delete node;


// ========== SECTION 9: ENUM ==========
//
// Traditional:
//
//     enum Direction {
//         North,
//         East
//     };
//
// Unscoped enumerators can implicitly convert to integral types.


// ========== SECTION 10: ENUM CLASS ==========
//
// Preferred when strong scoping/type safety is useful:
//
//     enum class Direction {
//         North,
//         East
//     };
//
// Access:
//
//     Direction::North


// ========== SECTION 11: UNION ==========
//
// A union overlays member storage.
//
//     union Data {
//         int integer;
//         double decimal;
//     };
//
// In ordinary use, one member is active at a time.


// ========== SECTION 12: PADDING ==========
//
// Struct size may exceed the sum of apparent member sizes.
//
// Implementations may add padding for alignment.
//
// Never hard-code layout assumptions without a justified ABI need.


struct Point {
    int x = 0;
    int y = 0;
};


struct Student {
    string name;
    int age = 0;
    double score = 0.0;
};


struct Node {
    int value;
    Node* next;
};


enum LegacyDirection {
    North,
    East,
    South,
    West
};


enum class Direction {
    North,
    East,
    South,
    West
};


union Number {
    int integer;
    double decimal;
};


struct DivisionResult {
    int quotient;
    int remainder;
};


void moveRight(
    Point& point
);

void printPoint(
    const Point& point
);

DivisionResult divideValues(
    int a,
    int b
);


int main() {

    cout << "=== DEMO 1: Struct ===\n";

    Point point{
        10,
        20
    };

    cout << "x = "
         << point.x << '\n';

    cout << "y = "
         << point.y
         << "\n\n";


    cout << "=== DEMO 2: Default Member Initializers ===\n";

    Point zeroPoint;

    cout << zeroPoint.x
         << ' '
         << zeroPoint.y
         << "\n\n";


    cout << "=== DEMO 3: Struct Copy ===\n";

    Point copied = point;

    copied.x = 99;

    cout << "original x = "
         << point.x << '\n';

    cout << "copy x = "
         << copied.x
         << "\n\n";


    cout << "=== DEMO 4: Reference Parameter ===\n";

    moveRight(point);

    printPoint(point);

    cout << '\n';


    cout << "=== DEMO 5: Struct With string ===\n";

    Student student{
        "Ada",
        20,
        95.5
    };

    cout << student.name
         << ' '
         << student.age
         << ' '
         << student.score
         << "\n\n";


    cout << "=== DEMO 6: Struct Pointer ===\n";

    Point* pointPtr =
        &point;

    cout << "pointPtr->x = "
         << pointPtr->x << '\n';

    pointPtr->y = 50;

    cout << "point.y = "
         << point.y
         << "\n\n";


    cout << "=== DEMO 7: Dynamic Node ===\n";

    Node* node =
        new Node{
            42,
            nullptr
        };

    cout << "node value = "
         << node->value << '\n';

    cout << boolalpha;

    cout << "next is null = "
         << (node->next == nullptr)
         << '\n';

    cout << noboolalpha;

    delete node;
    node = nullptr;

    cout << '\n';


    cout << "=== DEMO 8: Traditional enum ===\n";

    LegacyDirection legacy =
        East;

    cout << "East numeric value = "
         << legacy
         << "\n\n";


    cout << "=== DEMO 9: enum class ===\n";

    Direction direction =
        Direction::South;

    switch (direction) {

        case Direction::North:
            cout << "North\n";
            break;

        case Direction::East:
            cout << "East\n";
            break;

        case Direction::South:
            cout << "South\n";
            break;

        case Direction::West:
            cout << "West\n";
            break;
    }

    cout << '\n';


    cout << "=== DEMO 10: Union ===\n";

    Number number{};

    number.integer = 25;

    cout << "integer = "
         << number.integer << '\n';

    number.decimal = 3.5;

    cout << "decimal = "
         << number.decimal
         << "\n\n";


    cout << "=== DEMO 11: Return Multiple Values ===\n";

    DivisionResult result =
        divideValues(
            17,
            5
        );

    cout << "quotient = "
         << result.quotient
         << '\n';

    cout << "remainder = "
         << result.remainder
         << "\n\n";


    cout << "=== DEMO 12: sizeof Awareness ===\n";

    cout << "sizeof(Point) = "
         << sizeof(Point)
         << '\n';

    cout << "sizeof(Number) = "
         << sizeof(Number)
         << '\n';

    return 0;
}


void moveRight(
    Point& point
) {
    ++point.x;
}


void printPoint(
    const Point& point
) {
    cout << '('
         << point.x
         << ", "
         << point.y
         << ")\n";
}


DivisionResult divideValues(
    int a,
    int b
) {
    return {
        a / b,
        a % b
    };
}


/*
EXPECTED OUTPUT ON A COMMON PLATFORM

=== DEMO 1: Struct ===
x = 10
y = 20

=== DEMO 2: Default Member Initializers ===
0 0

=== DEMO 3: Struct Copy ===
original x = 10
copy x = 99

=== DEMO 4: Reference Parameter ===
(11, 20)

=== DEMO 5: Struct With string ===
Ada 20 95.5

=== DEMO 6: Struct Pointer ===
pointPtr->x = 11
point.y = 50

=== DEMO 7: Dynamic Node ===
node value = 42
next is null = true

=== DEMO 8: Traditional enum ===
East numeric value = 1

=== DEMO 9: enum class ===
South

=== DEMO 10: Union ===
integer = 25
decimal = 3.5

=== DEMO 11: Return Multiple Values ===
quotient = 3
remainder = 2

=== DEMO 12: sizeof Awareness ===
sizeof(Point) = 8
sizeof(Number) = 8

The sizeof values are implementation-dependent.

WHAT'S NEXT:
01_C++__/18_OOP_CLASSES_AND_OBJECTS/
*/
