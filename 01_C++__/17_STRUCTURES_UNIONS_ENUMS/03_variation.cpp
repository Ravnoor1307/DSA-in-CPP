/*
TOPIC: Structures, Unions, and Enums
FILE: 03_variation.cpp

Purpose:
Explore:
- nested structs
- arrays of structs
- self-referential nodes
- enum class
- tagged unions
- padding/alignment awareness

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>
#include <string>

using namespace std;


struct Date {
    int day;
    int month;
    int year;
};


struct Person {
    string name;
    Date birthDate;
};


struct Node {
    int value;
    Node* next;
};


enum class ValueType {
    Integer,
    Decimal
};


union Value {
    int integer;
    double decimal;
};


struct TaggedValue {
    ValueType type;
    Value value;
};


struct LayoutA {
    char first;
    int number;
    char second;
};


struct LayoutB {
    int number;
    char first;
    char second;
};


int main() {

    cout << boolalpha;


    // ========================================================
    // VARIATION 1: NESTED STRUCT
    // ========================================================

    Person person{
        "Ada",
        {
            10,
            12,
            1815
        }
    };

    cout << "=== VARIATION 1: Nested Struct ===\n";

    cout << person.name
         << " born "
         << person.birthDate.day
         << '/'
         << person.birthDate.month
         << '/'
         << person.birthDate.year
         << "\n\n";


    // ========================================================
    // VARIATION 2: ARRAY OF STRUCTS
    // ========================================================

    Date dates[3] = {
        {1, 1, 2024},
        {2, 2, 2025},
        {3, 3, 2026}
    };

    cout << "=== VARIATION 2: Array of Structs ===\n";

    for (const Date& date : dates) {

        cout << date.day
             << '-'
             << date.month
             << '-'
             << date.year
             << '\n';
    }

    cout << '\n';


    // ========================================================
    // VARIATION 3: LINKED NODES
    // ========================================================

    Node* first =
        new Node{
            10,
            nullptr
        };

    Node* second =
        new Node{
            20,
            nullptr
        };

    first->next =
        second;

    cout << "=== VARIATION 3: Node Links ===\n";

    cout << first->value
         << " -> "
         << first->next->value
         << '\n';

    delete second;
    second = nullptr;

    first->next = nullptr;

    delete first;
    first = nullptr;

    cout << '\n';


    // ========================================================
    // VARIATION 4: ENUM CLASS
    // ========================================================

    ValueType type =
        ValueType::Decimal;

    cout << "=== VARIATION 4: enum class ===\n";

    cout << "is decimal = "
         << (type == ValueType::Decimal)
         << "\n\n";


    // ========================================================
    // VARIATION 5: TAGGED UNION
    // ========================================================

    TaggedValue data{};

    data.type =
        ValueType::Integer;

    data.value.integer =
        42;

    cout << "=== VARIATION 5: Tagged Union ===\n";

    if (data.type ==
        ValueType::Integer) {

        cout << "integer = "
             << data.value.integer
             << '\n';
    }

    data.type =
        ValueType::Decimal;

    data.value.decimal =
        3.14;

    if (data.type ==
        ValueType::Decimal) {

        cout << "decimal = "
             << data.value.decimal
             << '\n';
    }

    cout << '\n';


    // ========================================================
    // VARIATION 6: LAYOUT
    // ========================================================

    cout << "=== VARIATION 6: Layout Awareness ===\n";

    cout << "sizeof(LayoutA) = "
         << sizeof(LayoutA)
         << '\n';

    cout << "sizeof(LayoutB) = "
         << sizeof(LayoutB)
         << '\n';

    cout << "alignof(LayoutA) = "
         << alignof(LayoutA)
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT ON A COMMON PLATFORM

=== VARIATION 1: Nested Struct ===
Ada born 10/12/1815

=== VARIATION 2: Array of Structs ===
1-1-2024
2-2-2025
3-3-2026

=== VARIATION 3: Node Links ===
10 -> 20

=== VARIATION 4: enum class ===
is decimal = true

=== VARIATION 5: Tagged Union ===
integer = 42
decimal = 3.14

=== VARIATION 6: Layout Awareness ===
sizeof(LayoutA) = 12
sizeof(LayoutB) = 8
alignof(LayoutA) = 4

Layout sizes/alignment are implementation-dependent.

WHAT'S NEXT:
01_C++__/18_OOP_CLASSES_AND_OBJECTS/
*/
