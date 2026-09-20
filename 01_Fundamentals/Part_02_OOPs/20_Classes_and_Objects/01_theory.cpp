/*
═══════════════════════════════════════════════
 CLASSES AND OBJECTS
 ⏱️ TIME COMPLEXITY: O(1) per method call — see derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A car company keeps ONE master blueprint of a sedan. From that single
 blueprint the factory presses out THOUSANDS of physical cars on the
 assembly line. Every finished car has its own engine number, its own paint
 colour and its own registration plate, even though each car follows the
 exact same design. In C++ the BLUEPRINT is the CLASS and every
 manufactured car is an OBJECT.

 📖 THEORY: (pure English, beginner-level)
 - A CLASS is a user-defined data type. It bundles DATA (members) and
   BEHAVIOUR (methods) into one reusable template.
 - An OBJECT is a concrete variable of a class type. Each object owns its
   OWN private copy of the data members; methods are shared by all objects.
 - BY DEFAULT, members of a class are PRIVATE (reachable only from inside
   the class). Members of a `struct` are PUBLIC by default.
 - MEMBERS of a class = DATA members (variables like name, marks) +
   MEMBER FUNCTIONS (methods like setData(), display()).
 - CONSTRUCTOR basics: a constructor is a special member function having
   the SAME NAME as the class and NO return type. It runs automatically
   the moment an object is created, so the object starts with known values.
 - OBJECT MEMORY LAYOUT: data members of one object sit together (with
   alignment padding) in one contiguous memory block owned by that object.

  BLUEPRINT vs MANUFACTURED CAR

   +------------------------------+
   |   CLASS Car  (BLUEPRINT)     |
   |  +------------------------+  |
   |  | data:  brand, model,   |  |     reuse the template
   |  |        engine, speed   |  |        many times
   |  | methods: start(), stop |  |           |
   |  +------------------------+  |           | instantiate
   +------------------------------+           v
   +------------------+   +------------------+   +------------------+
   | OBJECT car1      |   | OBJECT car2      |   | OBJECT car3      |
   | brand="Honda"    |   | brand="BMW"      |   | brand="Tata"     |
   | speed=0          |   | speed=0          |   | speed=0          |
   | start() stop()   |   | start() stop()   |   | start() stop()   |
   +------------------+   +------------------+   +------------------+

  OBJECT MEMORY LAYOUT  (class Student, 64-bit machine)
   +--------------------------------------+
   | OBJECT s1                            |
   |  +--------------------------------+  |
   |  | name  (std::string storage)    |  | <- own copy
   |  | marks (double)                 |  | <- own copy
   |  | padding (alignment gap)        |  |
   |  +--------------------------------+  |
   +--------------------------------------+
   | OBJECT s2  (identical layout,        |
   |             different addresses)     |
   +--------------------------------------+
  Methods live ONCE in the code segment — every object calls the SAME
  setData()/display(), but the call secretly passes the address of the
  calling object (this-pointer) to reach its own data.

 WHEN TO USE A CLASS:
 - When a real-world entity has BOTH data AND behaviour: Student, Car,
   BankAccount, File, Order — any noun you can talk about.
 - When you want encapsulation + data hiding (private members).

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: DEFINE the class template → `class Student { private: string name;
   double marks; public: void setData(...){...} void display(){...} };`.
   WHY: the class is a blueprint only — it occupies zero memory as yet.
 Step 2: INSTANTIATE objects → `Student s1, s2;` inside main().
   WHY: memory is carved out ONLY when you create an object; each object
   gets its own `name` and `marks` slots on the stack.
 Step 3: CALL a method with the DOT operator → `s1.setData("Rahul", 92.5)`.
   WHY: the method uses the hidden `this` pointer, so `s1.setData` writes
   into s1's copy and `s2.setData` writes into s2's copy.
 Step 4: REPEAT for the second object → same code, different data.
   WHY: that is the entire point of objects — one template, many copies.

 VISUAL WALKTHROUGH: (two objects, shared methods)

   STACK (data lives here)          CODE SEGMENT (methods live here)
   ┌──────────────────────────┐     ┌─────────────────────────────┐
   │ s1.name  = "Rahul"       │     │ Student::setData(...)       │
   │ s1.marks = 92.5          │     │ Student::display(...)       │
   │ s2.name  = "Priya"       │ ←──→ shared by ALL Student objects
   │ s2.marks = 88.0          │     └─────────────────────────────┘
   └──────────────────────────┘
     4 memory boxes owned by 2 objects, only 1 copy of each method

 DRY RUN: (trace of the demo below, printed output in quotes)
   main():
   1. Student s1, s2;              → two stack objects, garbage values
   2. s1.setData("Rahul", 92.5);   → s1.name="Rahul", s1.marks=92.5
   3. s1.display();                → prints "Name : Rahul" / "Marks: 92.5"
   4. s2.setData("Priya", 88.0);   → s2.name="Priya", s2.marks=88
   5. s2.display();                → prints "Name : Priya" / "Marks: 88"
   6. sizeof(Student)              → prints sizeof(Student) = 40 (approx)
   7. sizeof(Empty)                → prints sizeof(Empty) = 1 (never 0!)

 TIME COMPLEXITY CALCULATION:
 - setData():  2 assignments (name + marks)  → 2 operations, constant.
 - display():  2 print statements            → 2 operations, constant.
 - sizeof():   1 operation, constant.
 - No loops anywhere; work does NOT grow with object count.
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - sizeof(Student) = sizeof(string) + sizeof(double) + padding ≈ 40 bytes.
 - 2 objects → 2 × 40 = 80 bytes on the stack; space is independent of input.
 - Methods: exactly 1 copy in the code segment, NOT multiplied per object.
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌─────────────────┬─────────────────────┬─────────────────────────────┐
 │  CLASS          │  STRUCT             │  OBJECT                     │
 ├─────────────────┼─────────────────────┼─────────────────────────────┤
 │ user-defined    │ lightweight          │ concrete instance of a      │
 │ template type   │ template type        │ class                       │
 │ members default │ members default      │ occupies REAL memory        │
 │ PRIVATE         │ PUBLIC               │ created by instantiation    │
 │ for entities    │ for passive data     │ uses '.' to call methods    │
 │ with behaviour  │ bundles (Point, Pair)│ owns its own data copies    │
 └─────────────────┴─────────────────────┴─────────────────────────────┘
*/

#include <iostream>
#include <string>
using namespace std;

// ───── CLASS = BLUEPRINT (abhi koi memory allocate nahi hoti) ─────
class Student {
private:                // default bhi private hota hai, par explicit likhna behtar hai
    string name;        // data member 1 — sirf is class ke andar access
    double marks;       // data member 2

public:
    // method (member function) — object ki apni copy me data likhta hai
    void setData(string n, double m) {
        name = n;       // `this->name` bole to s1/s2 jo bhi object call kare, USKI copy
        marks = m;
    }

    // method — object ka data print karta hai
    void display() {
        cout << "  Name : " << name << "\n";
        cout << "  Marks: " << marks << "\n";
    }
};

// Edge case: EMPTY class — members zero, phir bhi size 0 nahi
class Empty {};

int main() {
    cout << "=== 1 template (Student), 2 objects (s1, s2) ===\n";

    Student s1, s2;         // 2 alag-2 memory blocks — same blueprint

    s1.setData("Rahul", 92.5);   // dot operator → s1 ki copy me likha gaya
    s2.setData("Priya", 88.0);   // dot operator → s2 ki copy me likha gaya

    cout << "Student-1:\n";
    s1.display();
    cout << "Student-2:\n";
    s2.display();

    // Edge case: empty class ka size kabhi 0 hota hi nahi — compiler 1 byte
    // deta hai taaki alag objects ke alag addresses ho saken.
    cout << "\nsizeof(Student) = " << sizeof(Student) << " bytes\n";
    cout << "sizeof(Empty)   = " << sizeof(Empty)   << " bytes (kabhi 0 nahi!)\n";
    return 0;
}