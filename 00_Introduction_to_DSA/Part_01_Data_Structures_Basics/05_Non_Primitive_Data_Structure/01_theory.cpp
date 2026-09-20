/*
═══════════════════════════════════════════════
 NON-PRIMITIVE / DERIVED & USER-DEFINED DATA STRUCTURES
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A school admin must keep many things together for every student — a name,
 a roll number and marks in 3 subjects. Primitive types (int, char, float)
 hold only ONE value each, so they cannot manage a whole student alone.
 Think of one register page that writes down a single student's full record,
 and many such pages bound together forming the complete class copy.
 Primitive types are the small inner boxes; non-primitive data structures
 join all those boxes into ONE BIG package that maps a real-world entity
 straight to code.

 📖 THEORY: (pure English, formal, beginner-level, "what is X")
 - definition: A NON-PRIMITIVE DATA STRUCTURE is any structure built on
   top of one or more primitive types. It is divided into two groups:
       1) DERIVED        (built-in combinations): ARRAY, POINTER
       2) USER-DEFINED   (created by the programmer): struct, class,
                          union, enum
 - key points / properties:
   • DERIVED — ARRAY : many values of the SAME type, stored in contiguous
     memory, giving O(1) random access through an index.
   • DERIVED — POINTER : a variable that stores the ADDRESS of another
     variable, enabling dynamic memory and indirect access.
   • USER-DEFINED — a CUSTOM BLUEPRINT that packs multiple fields/actions
     into one unit (e.g. a Student record).
   • struct: members are default PUBLIC.
   • class:  members are default PRIVATE (data hiding built-in).
   • union:  uses memory for only ONE member at a time (saves space).
   • enum:   a set of named constants (months, direction, status, grade).

        NON-PRIMITIVE DATA STRUCTURE
                    │
          ┌─────────┴──────────┐
          │                    │
       DERIVED             USER-DEFINED
      (built-in)           (custom types)
          │                    │
    ┌─────┴─────┐      ┌───────┼───────┐
  ARRAY    POINTER   STRUCT  CLASS  UNION  ENUM

 - when to use:
   a) ARRAY   → many same-type values + O(1) random access.
   b) POINTER → tracking addresses, dynamic memory (new/delete).
   c) STRUCT  → a simple record that holds all fields of an entity.
   d) CLASS   → an entity plus operations (functions) plus data hiding.
   e) UNION   → saving memory when only one field is needed at a time.
   f) ENUM    → named constants for readability.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Decide how many fields the entity has (name, roll, marks...).
         WHY: Every real-world thing has MULTIPLE attributes; a single
         primitive type holds one attribute — so a package is needed.
 Step 2: If many same-type values exist, take a DERIVED array or pointer.
         WHY: arr[i] reaches any value in O(1) using base + i*size.
 Step 3: Wrap the field set (e.g. name+roll+marks) into a USER-DEFINED
         struct/class.
         WHY: Now the whole record is ONE variable — store it in an array,
         pass it to a function, without copying field by field.
 Step 4: Access the members of the package with the dot (.) operator.
         WHY: The data inside is still primitive; only the package is
         non-primitive, and "." is the gateway into it.

 VISUAL WALKTHROUGH: (memory view of a user-defined package)
    Student s1:

    ┌────────────────┬──────────────┬──────────────┬──────────────┬──────────────┐
    │  name (string) │ rollNo : 1   │ marks[0]: 88 │ marks[1]: 91 │ marks[2]: 79 │
    └────────────────┴──────────────┴──────────────┴──────────────┴──────────────┘
              ^ one single variable "s1" — the whole Student record together

    Array of struct (n students — each cell is one full struct):
    ┌────────────┬────────────┬────────────┐
    │ student[0] │ student[1] │ student[2] │
    └────────────┴────────────┴────────────┘
       (name,     (name,       (name,
        roll,      roll,         roll,
        marks)     marks)        marks)

 DRY RUN: (line-by-line trace of the demo below)
    Line 1: int marks[5] = {10, 20, 30, 40, 50};
            → 5 contiguous int boxes: [10] [20] [30] [40] [50]  (5*4 = 20 bytes)
    Line 2: s1.name = "Aman";
            → the string box stores the char sequence "Aman"
    Line 3: s1.rollNo = 1;
            → 1 goes into the rollNo box
    Line 4: loop i=0..2: sum += s1.marks[i];

            i=0 → sum = 0   + 88  = 88
            i=1 → sum = 88  + 91  = 179
            i=2 → sum = 179 + 79  = 258

    Line 5: acc.deposit(1500.0);
            → balance = 5000.0 + 1500.0 = 6500.0
    Results: total=258, balance=6500. All 5 values packed in one user-
    defined object.

 TIME COMPLEXITY CALCULATION:
    - Creating one struct object              : 1 allocation step  → f(n) = 1
    - Accessing s1.rollNo                     : 1 memory read step → f(n) = 1
    - Traversing marks[0..n-1] (n subjects)   : loop runs n times, 1 step each
        f(n) = 1 + 1 + ... (n times) = n
    - Finding the topper of n students        : n comparisons      → f(n) = n
      Total worst case ≈ 1 + 1 + n + n = 2n + 2
    → Time Complexity = O(1) for create/access, O(n) for traversal

 SPACE COMPLEXITY CALCULATION:
    - One Student object: name + rollNo(4B) + marks(3*4=12B) → fixed size ≈ 1 unit
        f(n) = 1
    - n such objects in an array: n × (1 unit) = n units → f(n) = n
    → Space Complexity = O(1) per object, O(n) for n objects

 APPROACH COMPARISON:
 ┌────────────────────┬───────────────────────────────┬───────────────────────────────┐
 │ Point              │  DERIVED (Array / Pointer)    │  USER-DEFINED (struct/class)   │
 ├────────────────────┼───────────────────────────────┼───────────────────────────────┤
 │ What it builds     │ built-in combination           │ programmer's custom type       │
 │ Data type          │ homogeneous (all same type)    │ heterogeneous (fields mix type)│
 │ Example            │ int marks[5],  int* p          │ Student, BankAccount            │
 │ Grouping           │ value collection               │ entity: record + actions       │
 │ Member access      │ arr[i]  /  *p                  │ s1.name,  acc.deposit()        │
 │ Who creates it     │ compiler/operators             │ programmer (struct/class/enum) │
 │ Real-world use     │ 100 roll numbers               │ "a student's whole profile"     │
 └────────────────────┴───────────────────────────────┴───────────────────────────────┘
 */
#include <iostream>
#include <string>
using namespace std;

// ---- USER-DEFINED: struct ----
struct Student {
    string name;    // field 1 — text (string)
    int rollNo;     // field 2 — int
    int marks[3];   // field 3 — DERIVED array, user-defined struct ke andar
};

// ---- USER-DEFINED: class (members default PRIVATE hote hain) ----
class BankAccount {
public:                    // public lagna zaroori hai, warna access nahi hoga
    string holder;
    double balance;

    void deposit(double amt) {   // class ka apna function (action)
        balance += amt;
    }

    void show() {
        cout << "   " << holder << " ka balance = Rs." << balance << "\n";
    }
};

// ---- USER-DEFINED: enum (named constants) ----
enum Grade { FAIL = 0, PASS, DISTINCTION };

int main() {
    cout << "=== 1) DERIVED: int array (homogeneous values) ===\n";
    int marks[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        cout << "   marks[" << i << "] = " << marks[i] << "\n";
    }
    cout << "   sizeof(marks) = " << sizeof(marks)
         << " bytes (5 ints x 4)\n\n";

    cout << "=== 2) DERIVED: pointer (address holder) ===\n";
    int x = 42;
    int* p = &x;          // p me x ka ADDRESS store hua
    cout << "   x = " << x << "  |  *p (dereference) = " << *p << "\n\n";

    cout << "=== 3) USER-DEFINED: struct Student ===\n";
    Student s1;
    s1.name = "Aman";
    s1.rollNo = 1;
    s1.marks[0] = 88; s1.marks[1] = 91; s1.marks[2] = 79;

    int sum = 0;
    for (int i = 0; i < 3; i++) sum += s1.marks[i];

    Grade g = (sum >= 240) ? DISTINCTION : (sum >= 150 ? PASS : FAIL);
    cout << "   " << s1.name << " (roll " << s1.rollNo
         << ") -> total = " << sum << " -> ";
    if (g == DISTINCTION) cout << "DISTINCTION";
    else if (g == PASS)   cout << "PASS";
    else                  cout << "FAIL";
    cout << "\n";
    cout << "   sizeof(Student) = " << sizeof(Student)
         << " bytes (padding samet)\n\n";

    cout << "=== 4) USER-DEFINED: class BankAccount ===\n";
    BankAccount acc;
    acc.holder = "Priya";
    acc.balance = 5000.0;
    acc.deposit(1500.0);     // class ka khud ka function call
    acc.show();

    return 0;
}