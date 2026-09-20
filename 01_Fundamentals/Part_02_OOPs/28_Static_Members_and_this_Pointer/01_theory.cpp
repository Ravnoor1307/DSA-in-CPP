/*
═══════════════════════════════════════════════
 STATIC MEMBERS & this POINTER
 ⏱️ TIME COMPLEXITY: All operations O(1) — direct memory access, no loops involved.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a large corporate office with branches in Delhi, Mumbai, and Bangalore.
 Every employee hired belongs to the same company — the company name never changes
 per employee, it is shared. Similarly, there is a global employee counter that
 increments every time a new hire joins, regardless of which branch they are in.
 This counter is NOT owned by any single employee; it belongs to the company itself.
 That is exactly what a static data member is — a single copy shared across ALL
 objects. Now, when an employee wants to update their own name but the parameter
 has the same name as the member variable, they say "MY name is this" — that is
 the this pointer, a self-referencing pointer that always points to the current
 object.

 📖 THEORY: (pure English, beginner-level)

 1. STATIC DATA MEMBER:
    - A variable declared with 'static' inside a class.
    - Only ONE copy exists, shared across ALL objects of that class.
    - Lives in the static memory segment (not inside any object).
    - Must be defined OUTSIDE the class using scope resolution operator ::

 2. STATIC MEMBER FUNCTION:
    - A function declared with 'static' inside a class.
    - Can ONLY access other static members (data + functions).
    - Cannot use 'this' pointer (because it is not tied to any object).
    - Called using ClassName::functionName() — no object needed.

 3. this POINTER:
    - A hidden pointer available inside every non-static member function.
    - Points to the OBJECT on which the function was called.
    - Type: ClassName* const (constant pointer, cannot point elsewhere).
    - Used to resolve name shadowing (parameter name == member name).
    - Used for method chaining (return *this to return current object).

 4. const MEMBER FUNCTION:
    - Declared with 'const' after parameter list: void print() const
    - Guarantees it will NOT modify any member variable of the object.
    - Can be called on const objects.

 ╔══════════════════════════════════════════════════════════════════════╗
 ║                    STATIC MEMBER — MEMORY LAYOUT                    ║
 ╠══════════════════════════════════════════════════════════════════════╣
 ║                                                                     ║
 ║   STATIC SEGMENT (one copy)     HEAP / STACK (per object)           ║
 ║  ┌──────────────────────┐      ┌────────────────────┐               ║
 ║  │  Employee::count = 3 │      │  Object emp1       │               ║
 ║  │  (shared by ALL)     │◄─────│  name = "Ravi"     │               ║
 ║  └──────────────────────┘      │  id = 101          │               ║
 ║         ▲        ▲             └────────────────────┘               ║
 ║         │        │                                                  ║
 ║         │        │      ┌────────────────────┐                      ║
 ║         │        └──────│  Object emp2       │                      ║
 ║         │               │  name = "Priya"    │                      ║
 ║         │               │  id = 102          │                      ║
 ║         │               └────────────────────┘                      ║
 ║         │                                                           ║
 ║   ┌─────┴──────────────┐                                            ║
 ║   │  Object emp3       │                                            ║
 ║   │  name = "Aman"     │                                            ║
 ║   │  id = 103          │                                            ║
 ║   └────────────────────┘                                            ║
 ║                                                                     ║
 ║  KEY: All 3 objects share the SAME count variable.                  ║
 ║  Each object has its OWN name and id.                               ║
 ╚══════════════════════════════════════════════════════════════════════╝

 ╔══════════════════════════════════════════════════════════════════════╗
 ║                    this POINTER — CONCEPTUAL VIEW                   ║
 ╠══════════════════════════════════════════════════════════════════════╣
 ║                                                                     ║
 ║   When you call:  emp1.setName("Ravi")                              ║
 ║                                                                     ║
 ║        this ──────────►┌─────────────────┐                           ║
 ║                        │  Object emp1    │                           ║
 ║                        │  name = "Ravi"  │                           ║
 ║                        │  id = 101       │                           ║
 ║                        └─────────────────┘                           ║
 ║                                                                     ║
 ║   Inside setName():                                                 ║
 ║       this->name = "Ravi";   // same as this->name = name;          ║
 ║                                                                     ║
 ║   this is a pointer:  this == 0x7fff1234 (address of emp1)          ║
 ║   this->name accesses emp1.name via pointer dereference             ║
 ╚══════════════════════════════════════════════════════════════════════╝

 ╔══════════════════════════════════════════════════════════════════════╗
 ║                 METHOD CHAINING — *this RETURN                      ║
 ╠══════════════════════════════════════════════════════════════════════╣
 ║                                                                     ║
 ║   emp1.setName("Ravi").setSalary(50000).print();                    ║
 ║       │                                                              ║
 ║       ▼                                                              ║
 ║   setName() returns *this ──► emp1 object reference                 ║
 ║       │                                                              ║
 ║       ▼                                                              ║
 ║   setSalary() on emp1 returns *this ──► emp1 reference              ║
 ║       │                                                              ║
 ║       ▼                                                              ║
 ║   print() on emp1 ──► prints details                                ║
 ║                                                                     ║
 ║   CHAIN: emp1 → emp1 → emp1  (all same object, one chain)          ║
 ╚══════════════════════════════════════════════════════════════════════╝

 WHEN TO USE:
 - Static members: counters, shared constants, factory patterns, singleton.
 - this pointer: resolving name shadowing, returning self for chaining.
 - const functions: read-only access, safe API design, const object support.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Declare static int count inside class.
   WHY: We need ONE variable shared across all Employee objects.

 Step 2: Define static count OUTSIDE class with initial value 0.
   WHY: Compiler needs exactly ONE definition in memory (ODR rule).

 Step 3: In constructor, increment count.
   WHY: Every time an object is created, count goes up by 1 — tracks total objects.

 Step 4: In destructor, decrement count.
   WHY: When object is destroyed, count goes down — tracks currently alive objects.

 Step 5: Static function getCount() returns count.
   WHY: Can be called without any object — ClassName::getCount().

 Step 6: Use this-> in setName to resolve parameter vs member shadowing.
   WHY: Parameter "name" hides the member "name" — this->name refers to member.

 Step 7: Return *this from setter methods for method chaining.
   WHY: Returning reference to current object allows dot-chaining calls.

 VISUAL WALKTHROUGH:

   Time ──────────────────────────────────────────────────►

   emp1 created          emp2 created         emp1 destroyed
   count: 0 → 1         count: 1 → 2         count: 2 → 1
   ┌──────────┐         ┌──────────┐         ┌──────────┐
   │ emp1     │         │ emp1     │         │ emp1     │ (destroyed)
   │ emp2     │ (none)  │ emp2     │         │ emp2     │
   │ count=1  │         │ count=2  │         │ count=1  │
   └──────────┘         └──────────┘         └──────────┘

 DRY RUN: (Employee class demo)

   Employee emp1("Ravi", 50000);
     → ctor called → count becomes 1 → emp1 = {"Ravi", 50000}
     → this = &emp1

   Employee emp2("Priya", 60000);
     → ctor called → count becomes 2 → emp2 = {"Priya", 60000}
     → this = &emp2

   emp1.getCount();
     → static function, no this → returns count = 2

   emp1.setName("Ravi Singh");
     → inside: this->name = "Ravi Singh"
     → this points to emp1 → emp1.name = "Ravi Singh"

   emp1.setName("Ravi").setSalary(55000).print();
     → setName("Ravi"): this->name = "Ravi", returns *this (emp1 ref)
     → setSalary(55000): this->salary = 55000, returns *this (emp1 ref)
     → print(): outputs emp1 details

   { emp3 created and destroyed inside inner scope }
     → count: 2 → 3 → 2 (emp3 created then destroyed)

   cout << Employee::getCount();
     → prints 2 (only emp1 and emp2 alive)

 TIME COMPLEXITY CALCULATION:
 - Static member access (count): single memory read           → O(1)
 - Increment/decrement in ctor/dtor: single arithmetic op     → O(1)
 - this->name resolution: pointer dereference                 → O(1)
 - Method chaining (n setters): n × O(1) operations          → O(1) each
 - getCount(): single variable read                           → O(1)
 → Time Complexity = O(1) for all operations

 SPACE COMPLEXITY CALCULATION:
 - static count: ONE int in static segment                   → 4 bytes (shared)
 - Each Employee object: name + salary                       → object size
 - this pointer: ONE pointer per function call (stack)        → 8 bytes
 - Total for n objects: n × object_size + 4 (static)         → O(n)
 → Space Complexity = O(n) where n = number of objects

 APPROACH COMPARISON:
 ┌───────────────────────┬──────────────────────────┬──────────────────────────┐
 │ Feature               │ Static Members           │ Instance Members         │
 ├───────────────────────┼──────────────────────────┼──────────────────────────┤
 │ Copy per object       │ NO — one shared copy     │ YES — each has its own   │
 │ Memory segment        │ Static/global segment    │ Heap/Stack (per object)  │
 │ Access                │ ClassName::member        │ object.member            │
 │ Can use this pointer  │ NO                       │ YES                      │
 │ Lifetime              │ Entire program           │ Lives with object        │
 │ Use case              │ Counters, shared config  │ Object-specific data     │
 ├───────────────────────┼──────────────────────────┼──────────────────────────┤
 │ Feature               │ Normal Function          │ Static Member Function   │
 ├───────────────────────┼──────────────────────────┼──────────────────────────┤
 │ this pointer          │ Available                │ NOT available            │
 │ Access static members │ YES                      │ YES                      │
 │ Access instance members│ YES                     │ NO                       │
 │ Called via             │ object.func()           │ ClassName::func()        │
 └───────────────────────┴──────────────────────────┴──────────────────────────┘
*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int salary;

    // ═══ STATIC DATA MEMBER — one copy for ALL objects ═══
    static int count;

public:
    // ═══ CONSTRUCTOR — increments static counter ═══
    Employee(string name, int salary) {
        // this pointer used here to resolve shadowing
        this->name = name;
        this->salary = salary;
        count++;  // har naye object pe count badhega
        cout << "[CTOR] " << this->name << " created. Total alive: " << count << endl;
    }

    // ═══ DESTRUCTOR — decrements static counter ═══
    ~Employee() {
        count--;  // object destroy hone pe count ghatenga
        cout << "[DTOR] " << this->name << " destroyed. Total alive: " << count << endl;
    }

    // ═══ STATIC MEMBER FUNCTION — can ONLY access static members ═══
    static int getCount() {
        // cout << name;  // ❌ ERROR! Cannot access instance member from static function
        // this->salary;  // ❌ ERROR! No this pointer in static function
        return count;    // ✅ Can access static member
    }

    // ═══ SETTER with this-> for shadowing resolution ═══
    // Parameter 'name' hides the member 'name' — this-> fixes it
    Employee& setName(string name) {
        this->name = name;  // this->name = member, name = parameter
        return *this;       // return reference to current object for chaining
    }

    // ═══ METHOD CHAINING — returns *this ═══
    Employee& setSalary(int salary) {
        this->salary = salary;
        return *this;  // emp1.setSalary(50000) returns emp1 itself
    }

    // ═══ CONST MEMBER FUNCTION — promises not to modify object ═══
    void print() const {
        cout << "Employee { Name: " << this->name
             << ", Salary: Rs." << this->salary
             << ", ID: " << this << " }" << endl;
        // this inside const function is: const Employee* const this
    }

    // ═══ Non-const print that can be called on non-const objects ═══
    void print() {
        cout << "[NON-CONST] Employee { Name: " << name
             << ", Salary: Rs." << salary << " }" << endl;
    }
};

// ═══════════════════════════════════════════════════════════════
// STATIC MEMBER MUST BE DEFINED OUTSIDE THE CLASS
// This is where the actual memory is allocated (static segment)
// ═══════════════════════════════════════════════════════════════
int Employee::count = 0;

// ═══════════════════════════════════════════════════════════════
// COMPILE-RUN DEMO WITH EDGE CASES
// ═══════════════════════════════════════════════════════════════
int main() {
    cout << "=============================================" << endl;
    cout << " STATIC MEMBERS & this POINTER — DEMO" << endl;
    cout << "=============================================" << endl;

    // ═══ EDGE CASE 1: Static count before any object ═══
    cout << "\n--- Edge Case 1: Count before any object ---" << endl;
    cout << "Initial count: " << Employee::getCount() << endl;
    // Expected: 0 — no objects created yet

    // ═══ EDGE CASE 2: Creating objects ═══
    cout << "\n--- Edge Case 2: Creating objects ---" << endl;
    Employee emp1("Ravi", 50000);
    Employee emp2("Priya", 60000);

    cout << "Count after 2 objects: " << Employee::getCount() << endl;
    // Expected: 2

    // ═══ EDGE CASE 3: this pointer — name shadowing ═══
    cout << "\n--- Edge Case 3: this-> resolves shadowing ---" << endl;
    string name = "Aman";  // local variable with same name as member
    emp1.setName(name);    // inside setName: this->name = name (local)
    emp1.print();
    // Expected: emp1's name changed to "Aman"

    // ═══ EDGE CASE 4: Method chaining ═══
    cout << "\n--- Edge Case 4: Method chaining ---" << endl;
    emp2.setName("Priya Sharma").setSalary(75000).print();
    // Chain: setName → setSalary → print (all on emp2)
    // Expected: Priya Sharma, Rs.75000

    // ═══ EDGE CASE 5: Static function called on object too ═══
    cout << "\n--- Edge Case 5: Static function via object (works but not recommended) ---" << endl;
    cout << "Count via emp1.getCount(): " << emp1.getCount() << endl;
    cout << "Count via Employee::getCount(): " << Employee::getCount() << endl;
    // Both work — compiler internally converts object calls to class calls

    // ═══ EDGE CASE 6: const object can only call const functions ═══
    cout << "\n--- Edge Case 6: const object ---" << endl;
    const Employee emp3("Neha", 90000);
    emp3.print();        // ✅ const function — allowed
    // emp3.setName("X"); // ❌ COMPILE ERROR — setName is non-const
    // emp3.print(true);  // ❌ if non-const print exists, still can't call from const obj
    cout << "Count: " << Employee::getCount() << endl;

    // ═══ EDGE CASE 7: Scope-boundary object — temporary lifetime ═══
    cout << "\n--- Edge Case 7: Inner scope object ---" << endl;
    {
        Employee temp("Temp Guy", 30000);  // created inside this block
        cout << "Inside scope — count: " << Employee::getCount() << endl;
        // Expected: 4 (emp1, emp2, emp3, temp)
    }
    // temp destroyed here
    cout << "After scope — count: " << Employee::getCount() << endl;
    // Expected: 3 (emp1, emp2, emp3)

    // ═══ EDGE CASE 8: Empty string name ═══
    cout << "\n--- Edge Case 8: Empty string name ---" << endl;
    Employee emp4("", 0);
    emp4.print();
    // Expected: Name: (empty), Salary: 0 — no crash, valid state

    // ═══ EDGE CASE 9: Negative salary ═══
    cout << "\n--- Edge Case 9: Negative salary ---" << endl;
    Employee emp5("Debt Guy", -5000);
    emp5.print();
    // Expected: Salary: -5000 — class doesn't validate, edge case to note

    cout << "\n=============================================" << endl;
    cout << " Final count before program ends: " << Employee::getCount() << endl;
    cout << "=============================================" << endl;
    // All remaining objects destroyed in reverse order
    // emp5, emp4, emp3, emp2, emp1 — count goes to 0

    return 0;
}
