/*
═══════════════════════════════════════════════
 STRUCTURES — Custom Data Types
 ⏱️ TIME COMPLEXITY: member access O(1), array traversal O(n), copy O(size of struct)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of a passport application form. One form has many fields — name,
 date of birth, passport number, address, phone. Instead of managing
 6 separate variables per person, you fill ONE form (= one struct).
 The passport office keeps an array of such forms (= array of structs).
 If you need to update someone's phone number, you can point to that
 specific form and change it (= pointer to struct with arrow operator).

 📖 THEORY: (pure English, beginner-level)
 - A struct groups related variables (members) under ONE name.
 - Syntax:  struct Student { int id; char name[20]; float marks; };
 - Access members with dot operator:  s.id, s.name
 - Array of structs: Student class[3];  → 3 consecutive Student records
 - Pointer to struct + arrow operator:  Student *p = &s;  p->id
 - Nested struct: a struct inside another struct.
 - struct vs class: struct members are PUBLIC by default, class PRIVATE.
 - Semicolon after closing brace is REQUIRED:  struct X { ... };
 - Padding: compiler adds bytes between members for alignment. sizeof might
   be larger than sum of member sizes.

 ASCII MEMORY LAYOUT — struct Student { int id; char name[20]; float marks; };

   sizeof(Student) = 4 + 20 + 4 = 28 bytes (no padding needed, all align to 4)

   Address: 0x1000                     0x101C
   ┌───────┬──────────────────────┬─────────┐
   │ id    │ name[20]             │ marks   │
   │ 4 B   │ 20 B                 │ 4 B     │
   │ [0x0] │ [0x4]                │ [0x18]  │
   └───────┴──────────────────────┴─────────┘

   PADDING EXAMPLE — struct Bad { char a; int b; char c; double d; };
   sizeof(Bad) = 24 (not 1+4+1+8 = 14!)
   ┌────┬─────┬──────┬────┬───────┬──────────┐
   │ a  │ pad │ b    │ c  │ pad   │ d        │
   │ 1B │ 3B  │ 4B   │ 1B │ 7B    │ 8B       │
   └────┴─────┴──────┴────┴───────┴──────────┘

   ORDER MATTERS:  struct Good { double d; int b; char a; char c; };  → 16 bytes!
   Same data, 33% less memory — just reordering fields.

 vs class default:
   struct X { int a; };   → 'a' is PUBLIC by default
   class  Y { int a; };   → 'a' is PRIVATE by default

 🧠 LOGIC — STEP BY STEP:
 Step 1: DEFINE the struct with named members.
         WHY: creates a blueprint — like a blank form.
 Step 2: CREATE variables (objects) of the struct type.
         WHY: now you have actual forms filled with data.
 Step 3: ACCESS members with dot (.) operator.
         WHY: read or write individual fields of the record.
 Step 4: USE array of structs for multiple records.
         WHY: one loop traverses all records efficiently.
 Step 5: USE pointer to struct + arrow (->) operator.
         WHY: modify records via functions without copying the whole struct.

 VISUAL WALKTHROUGH — struct Student array:

   Student class[3] = { {1,"Amit",85.5}, {2,"Priya",92.0}, {3,"Rahul",78.5} };

   Memory layout (consecutive blocks, each 28 bytes):
   ┌─────────────────────────────┬─────────────────────────────┬─────────────────────────────┐
   │      class[0]               │      class[1]               │      class[2]               │
   │  1, "Amit",   85.5          │  2, "Priya",  92.0          │  3, "Rahul",  78.5          │
   │  @ 0x1000                  │  @ 0x101C                  │  @ 0x1038                  │
   └─────────────────────────────┴─────────────────────────────┴─────────────────────────────┘
   Distance between class[i] and class[i+1] = sizeof(Student) = 28 bytes

 DRY RUN — Access via pointer:
   Student *p = &class[1];       // p points to Priya's record
   p->marks = 95.0;              // arrow operator: p->marks == (*p).marks
   cout << p->name;              // "Priya"
   class[1].marks is now 95.0

 TIME COMPLEXITY CALCULATION:
 - s.id / s.name: compile-time offset → one address computation → O(1)
 - Traversing array of n structs: n iterations, each O(1) → O(n)
 - Copying one struct by value: copies all members → O(sizeof(struct))
 - p->id: dereference pointer + offset → O(1)
 → Time Complexity = O(1) per access, O(n) for array traversal

 SPACE COMPLEXITY CALCULATION:
 - One struct: sizeof(struct) bytes → depends on members
 - Array of n structs: n × sizeof(struct) bytes → O(n)
 - Pointer to struct: 8 bytes (64-bit) regardless of struct size
 → Space Complexity = O(n) for array of n structs

 APPROACH COMPARISON:
 ┌──────────────────┬──────────────────────┬──────────────────────────┐
 │ Feature          │ struct               │ class                    │
 ├──────────────────┼──────────────────────┼──────────────────────────┤
 │ Default access   │ PUBLIC               │ PRIVATE                  │
 │ Use case         │ Data grouping, POD   │ Encapsulation, methods   │
 │ Inheritance      │ public by default    │ private by default       │
 │ Constructor      │ Yes (C++)            │ Yes                      │
 │ Size of          │ yes                  │ yes                      │
 └──────────────────┴──────────────────────┴──────────────────────────┘
*/

#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[20];
    float marks;
};

// pass struct BY VALUE — entire struct copied (expensive for large structs)
void printByValue(Student s) {
    cout << "  [by value]  id=" << s.id << " name=" << s.name << " marks=" << s.marks << endl;
}

// pass struct BY POINTER — no copy, direct access via arrow operator
void printByPointer(Student *p) {
    cout << "  [by pointer] id=" << p->id << " name=" << p->name << " marks=" << p->marks << endl;
}

// nested struct demo
struct Date {
    int day, month, year;
};

struct Employee {
    char name[30];
    Date joining;         // nested struct
    double salary;
};

int main() {

    // ═══════════════════════════════════════════════
    // DEMO 1: Create and print struct
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 1: Struct Basics ===" << endl;
    Student s1;
    s1.id = 1;
    strcpy(s1.name, "Amit");
    s1.marks = 85.5;
    cout << "  id=" << s1.id << " name=" << s1.name << " marks=" << s1.marks << endl;
    cout << "  sizeof(Student) = " << sizeof(Student) << " bytes\n" << endl;

    // ═══════════════════════════════════════════════
    // DEMO 2: Array of structs
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 2: Array of Structs ===" << endl;
    Student class1[3] = {
        {1, "Amit",   85.5f},
        {2, "Priya",  92.0f},
        {3, "Rahul",  78.5f}
    };

    for (int i = 0; i < 3; i++) {
        cout << "  class[" << i << "] -> id=" << class1[i].id
             << " name=" << class1[i].name
             << " marks=" << class1[i].marks << endl;
    }
    cout << endl;

    // ═══════════════════════════════════════════════
    // DEMO 3: Pointer to struct + arrow operator
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 3: Pointer + Arrow Operator ===" << endl;
    Student *ptr = &class1[1];       // ptr points to Priya's record
    cout << "  Access via arrow: ptr->name = " << ptr->name << endl;
    cout << "  Access via arrow: ptr->marks = " << ptr->marks << endl;

    ptr->marks = 95.0f;   // modify through pointer
    cout << "  After ptr->marks = 95.0: class1[1].marks = " << class1[1].marks << endl;
    cout << "  (arrow operator directly modified the struct)\n" << endl;

    // ═══════════════════════════════════════════════
    // DEMO 4: Struct as function parameter
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 4: Struct as Parameter ===" << endl;
    cout << "  Calling printByValue(class1[0]):" << endl;
    printByValue(class1[0]);        // entire struct copied

    cout << "  Calling printByPointer(&class1[0]):" << endl;
    printByPointer(&class1[0]);     // just 8 bytes (pointer) passed

    cout << "  Passing large structs by pointer/reference is faster (no copy).\n" << endl;

    // ═══════════════════════════════════════════════
    // DEMO 5: Nested struct
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 5: Nested Struct ===" << endl;
    Employee emp;
    strcpy(emp.name, "Sunita");
    emp.joining.day = 15;
    emp.joining.month = 8;
    emp.joining.year = 2020;
    emp.salary = 75000.0;

    cout << "  Employee: " << emp.name << endl;
    cout << "  Joined:   " << emp.joining.day << "/"
         << emp.joining.month << "/" << emp.joining.year << endl;
    cout << "  Salary:   " << emp.salary << endl;
    cout << "  sizeof(Employee) = " << sizeof(Employee) << " bytes\n" << endl;

    // ═══════════════════════════════════════════════
    // DEMO 6: Updating via pointer in a loop
    // ═══════════════════════════════════════════════
    cout << "=== DEMO 6: Update via Pointer ===" << endl;
    for (int i = 0; i < 3; i++) {
        Student *sp = &class1[i];    // pointer to each student
        sp->marks += 5.0f;           // bonus marks for everyone
    }
    for (int i = 0; i < 3; i++) {
        cout << "  After bonus: class[" << i << "] name="
             << class1[i].name << " marks=" << class1[i].marks << endl;
    }
    cout << endl;

    // ═══════════════════════════════════════════════
    // EDGE CASE 1: Empty struct size
    // ═══════════════════════════════════════════════
    cout << "=== EDGE CASE 1: Empty Struct Size ===" << endl;
    struct EmptyStruct {};
    EmptyStruct e;
    cout << "  sizeof(EmptyStruct) = " << sizeof(e) << " byte(s)" << endl;
    cout << "  (C++ standard requires at least 1 byte so distinct objects have distinct addresses)\n" << endl;

    // ═══════════════════════════════════════════════
    // EDGE CASE 2: Struct with padding
    // ═══════════════════════════════════════════════
    cout << "=== EDGE CASE 2: Padding Effect ===" << endl;
    struct Bad  { char a; int b; char c; double d; };
    struct Good { double d; int b; char a; char c; };
    cout << "  sizeof(Bad)  = " << sizeof(Bad)  << " bytes (char-int-char-double)" << endl;
    cout << "  sizeof(Good) = " << sizeof(Good) << " bytes (double-int-char-char)" << endl;
    cout << "  Same data, different order -> different memory usage!\n" << endl;

    cout << "All structures demos complete." << endl;
    return 0;
}
