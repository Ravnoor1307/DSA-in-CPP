/*
═══════════════════════════════════════════════
 CONSTRUCTORS — default, parameterized, copy, initializer list
 ⏱️ TIME COMPLEXITY: O(1) simple ctors; copy ctor O(n) for n members
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A garments factory runs three kinds of production. RUN 1: the machine cuts
 a shirt with DEFAULT measurements (size S) when the order slip is blank.
 RUN 2: a tailored shirt is cut for a specific customer using the chest and
 length supplied on the slip. RUN 3: a copy run duplicates an existing
 finished shirt — but a careful operator NEVER lets the copy share the same
 roll of cloth as the original. The subsystem that starts each production
 run is the CONSTRUCTOR; the copy run is the COPY CONSTRUCTOR.

 📖 THEORY: (pure English, beginner-level)
 - CONSTRUCTOR: a special member function with the SAME NAME as the class
   and NO return type. It is called AUTOMATICALLY when an object is born —
   you never write `rect.Rectangle()`, the compiler does it for you.
 - DEFAULT constructor: takes no arguments; gives objects safe start values
   so they never begin life holding garbage.
 - PARAMETERIZED constructor: takes arguments so different objects start
   with different data, e.g. Rectangle r2(5, 4).
 - OVERLOADING: you may write SEVERAL constructors with different parameter
   lists; the compiler picks the one that matches the call.
 - INITIALIZER LIST: `Rectangle(int l, int b) : dim(new int[2]), area(0)`
   initialises members BEFORE the constructor body runs — safer and faster
   than assigning inside the body.
 - DEFAULT MEMBER INIT: `int area = 0;` inside the class gives every
   constructor a fallback value for that member.
 - COPY CONSTRUCTOR: `Class(const Class& src)` builds a NEW object from an
   existing one. DANGER: the DEFAULT copy is SHALLOW — for pointer members
   it copies the ADDRESS, so two objects share ONE heap block and a double
   delete crashes at destruction time. FIX = DEEP COPY: allocate fresh heap
   and copy the VALUES.
 - WHEN IS THE COPY CTOR CALLED? (1) pass-by-value arguments, (2) returning
   by value, (3) `Rectangle r4 = r2;` copy-initialisation.

  SHALLOW vs DEEP COPY (class with pointer member `int* dim`)
   SHALLOW (default = dangerous)          DEEP (fixed = safe)
r2 ───────┐                             r2          r4 (copy)
       dim: @0x99  ◀────┐                     dim: @0x99   dim: @0x7B  ← separate heap block
     r4 ───────┘        │                     [5][4]       [5][4]
       dim: @0x99 (same as r2) ┘              |both blocks separate, values copied
     pointer COPY → both objects          new int[2] + copy values →
     share the SAME heap block →           a change in r4 has NO effect
     double-delete crash 💥                on r2 (proof of deep copy)

  CONSTRUCTOR CALL SEQUENCE (Rectangle r1; r2(5,4); r3(-7,3); r4=r2;)
   1) r1   →  Default constructor called
   2) r2   →  Parameterized constructor called (5 x 4)
   3) r3   →  Parameterized constructor called (0 x 3)   [negatives clamped]
   4) r4   →  Copy constructor called (DEEP copy)

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Reserve space for the object and run the initializer list. WHY:
   members should be ready BEFORE the constructor body touches them.
 Step 2: For a DEFAULT ctor set the natural blank values (0 length, 0
   width). WHY: an object must never start with garbage numbers.
 Step 3: For a PARAMETERIZED ctor, VALIDATE/clamp arguments (negative dims
   → 0) and copy them in. WHY: constructors are the first line of defence.
 Step 4: For the COPY ctor, allocate a FRESH heap block and copy member by
   member (deep copy). WHY: independent objects, no double-free at the end.
 Step 5: The compiler matches the argument list to pick the right
   constructor — that is overloading. WHY: one class, many birth poses.

 VISUAL WALKTHROUGH: (object birth sequence)
  main
   │  Rectangle r1;          ┌─▶ r1.dim = new int[2] {0,0}  area = 0
   │  Rectangle r2(5,4);  ───┤─▶ r2.dim = new int[2] {5,4}  area = 20
   │  Rectangle r3(-7,3); ───┤─▶ clamped → dim {0,3}        area = 0
   │  Rectangle r4 = r2; ────┘─▶ NEW heap, copy values {5,4} area = 20
   ▼
  r1 ██{0,0}  r2 ██{5,4}  r3 ██{0,3}  r4 ██{5,4}   <- heap blocks ALL SEPARATE

 DRY RUN: (printed output of the demo below, line by line)
  1) Rectangle r1;            → "Default constructor called"
  2) Rectangle r2(5, 4);      → "Parameterized constructor called (5 x 4)"
  3) Rectangle r3(-7, 3);     → "Parameterized constructor called (0 x 3)"
  4) Rectangle r4 = r2;       → "Copy constructor called (DEEP copy)"
  5) r4.setLength(10);        → r4.dim[0]=10 → r4.area = 10*4 = 40
  6) r4.print();              → "Length=10  Width=4  Area=40"
  7) r2.print();              → "Length=5   Width=4  Area=20"  ← r2 SAFE
  8) ShallowBox x(7); y = x;  → y.data = x.data (pointer is the SAME address)
  9) *y.data = 999;           → *x.data is also 999 → proof of shared memory

 TIME COMPLEXITY CALCULATION:
 - Default/parameterized ctors: 1 heap allocation of 2 ints + few
   assignments → constant number of operations.
 - Copy ctor: copies every member → n operations for n members.
   Here n = 2 → exactly 2 copy operations.
 → Time Complexity = O(1) for these ctors in general O(n) for n members

 SPACE COMPLEXITY CALCULATION:
 - Each Rectangle: heap array (2×4 = 8 bytes) + pointer (8) + int area (4)
   + padding → O(1) per object.
 - k objects → O(k) total. Deep copy uses no extra temporary storage —
   it allocates exactly what the copy needs.
 → Space Complexity = O(1) per object

 APPROACH COMPARISON:
 ┌──────────────────┬─────────────────────┬───────────────────────────────┐
 │ shallow copy     │ deep copy           │ when each is okay              │
 ├──────────────────┼─────────────────────┼───────────────────────────────┤
 │ copies pointer   │ allocates new heap  │ shallow: class has NO pointer │
 │ two objects share│ copies the VALUES   │ members (plain ints/doubles)  │
 │ one heap block   │ objects independent │ deep: class owns heap memory  │
 │ double-delete 💥 │ safe destruction    │ (DynamicArray, Rectangle...)  │
 └──────────────────┴─────────────────────┴───────────────────────────────┘
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    int* dim;              // dim[0] = length, dim[1] = width → heap array (deep-copy lesson)
    int area = 0;          // DEFAULT MEMBER INIT — har ctor ko fallback value milti hai

public:
    // (1) DEFAULT constructor — no arguments
    Rectangle() {
        dim = new int[2]{0, 0};            // 0 length, 0 width ka naya heap block
        cout << "  Default constructor called\n";
    }

    // (2) PARAMETERIZED constructor — initializer list se allocate pehle ho jata hai
    Rectangle(int l, int b) : dim(new int[2]), area(0) {
        if (l < 0) l = 0;                  // edge case: negative dims clamp to 0
        if (b < 0) b = 0;
        dim[0] = l;                        // heap ab ready hai (initializer list ki wajah se)
        dim[1] = b;
        area = l * b;
        cout << "  Parameterized constructor called (" << l << " x " << b << ")\n";
    }

    // (3) COPY constructor — DEEP copy: naya heap, values copy, pointer NAHI
    Rectangle(const Rectangle& r) {
        dim = new int[2];                  // fresh block — original se bilkul alag
        dim[0] = r.dim[0];
        dim[1] = r.dim[1];
        area = r.area;
        cout << "  Copy constructor called (DEEP copy)\n";
    }

    ~Rectangle() {
        delete[] dim;                      // heap memory free karna zaroori — folder-23 topic
    }

    void setLength(int l) {
        dim[0] = l;
        area = dim[0] * dim[1];            // area re-compute
    }

    void print() const {
        cout << "  Length=" << dim[0] << "  Width=" << dim[1] << "  Area=" << area << "\n";
    }
};

// ⚠️ DANGER demo: is class me COPY CTOR NAHI hai → default SHALLOW copy banti hai
class ShallowBox {
public:
    int* data;
    ShallowBox(int v) { data = new int(v); }
    // dtor jaan-boojh kar nahi likha — warna x aur y mile-jhule pointer pe
    // double-delete se crash hota. Sirf aliasing dikhane ke liye hai.
};

int main() {
    cout << "1) Rectangle r1;   (default ctor)\n";
    Rectangle r1;
    r1.print();

    cout << "2) Rectangle r2(5, 4);   (param ctor)\n";
    Rectangle r2(5, 4);
    r2.print();

    cout << "3) Rectangle r3(-7, 3);   (negative → clampped to 0)\n";
    Rectangle r3(-7, 3);
    r3.print();

    cout << "4) Rectangle r4 = r2;   (copy ctor → DEEP copy)\n";
    Rectangle r4 = r2;
    r4.print();

    cout << "5) r4.setLength(10);   → copy me change...\n";
    r4.setLength(10);
    cout << "   r4 :"; r4.print();
    cout << "   r2 :"; r2.print();   // original UNCHANGED → deep copy ka proof

    cout << "\n6) Shallow-copy trap (no copy ctor in ShallowBox):\n";
    ShallowBox x(7);
    ShallowBox y = x;                 // y.data == x.data (sirf ADDRESS copy hua)
    *y.data = 999;
    cout << "   *x.data ab = " << *x.data << "   ← y ke through badal gaya (shared!)\n";
    return 0;
}