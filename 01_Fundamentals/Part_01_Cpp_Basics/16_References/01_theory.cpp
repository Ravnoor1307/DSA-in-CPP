/*
═══════════════════════════════════════════════
 REFERENCES — Aliases of Variables
 ⏱️ TIME COMPLEXITY: creating / using a reference = O(1), no copy, no allocation
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a person named Rahul Verma. His school friends call him "Rahul",
 his grandmother calls him "Golu", and his office badge says "R. Verma".
 Every name points to the SAME body. If Rahul gets a haircut, everyone's
 picture changes instantly because there is only ONE person. A reference in
 C++ is exactly that — a second (or third) name for the same memory box.
 No copy is made, no extra space is allocated. Change via one name and the
 other name instantly reflects the change.

 📖 THEORY: (pure English, beginner-level)
 - Definition: A reference is an alias — another name for an existing variable.
   Syntax:  int &ref = original;
 - Key properties / rules:
   1. MUST be initialized at declaration.  int &r;  is an ERROR.
   2. Cannot be re-bound. Once it refers to 'x', it forever refers to 'x'.
   3. Shares the exact same address as the original variable.
   4. Cannot be null — there is always a valid object behind it.
   5. Passing by reference (&) lets a function modify the caller's variable
      without using pointers and without making copies.
   6. const reference (const int &r) gives a read-only alias — avoids copies
      of large objects while guaranteeing safety.

 ASCII DIAGRAM — Reference vs Pointer:

     REFERENCE (alias = same box, two labels):
     ╔══════════════════════════════════════╗
     ║  MEMORY BOX @ 0x7ffd...a4            ║
     ║  int num = 42                        ║
     ║  ┌────────┐                          ║
     ║  │   42   │                          ║
     ║  └────────┘                          ║
     ╚════╦══════════╦══════════════════════╝
          ║          ║
       "num"     "alias"  (int &alias = num)
    (original)  (reference)
     Both names land on the EXACT SAME box.

     POINTER (separate box holding an address):
     ╔══════════╗    ──────►    ╔══════════╗
     ║ 0x..a4   ║  address      ║   42     ║  int num
     ╚══════════╝              ╚══════════╝
      int *p                    int num
     (pointer box is SEPARATE; reference box does NOT exist)

 When to use:
 - Pass large data without copying:  void process(const vector<int>& v)
 - Modify caller's variable:         void swap(int &a, int &b)
 - Return lvalue (operator[], etc.): int& operator[](int i)

 🧠 LOGIC — STEP BY STEP:
 Step 1: DECLARE the reference with & right after the type.
         int &alias = num;
         WHY: binds alias to num's memory box immediately.
 Step 2: USE alias exactly like num — read or write.
         alias = 100;  // num also becomes 100
         WHY: they share the same memory; there is no copy.
 Step 3: PASS BY REFERENCE to a function.
         void swapRef(int &a, int &b) { ... }
         WHY: a and b become aliases to the caller's variables,
              so the swap reaches the caller.
 Step 4: CONST REFERENCE for read-only access.
         void print(const int &x) { cout << x; }
         WHY: avoids copying x while guaranteeing we don't modify it.

 VISUAL WALKTHROUGH — swap via reference:

   Before swapRef(x, y) with x=10, y=20:
     main:  x (10)          y (20)

   Inside swapRef:
     a ──alias──► x (10)    b ──alias──► y (20)
     temp = a;        temp = 10
     a = b;           x becomes 20
     b = temp;        y becomes 10

   Back in main:  x = 20, y = 10   (modified!)

 DRY RUN — swapRef(5, 9):
   &a == &x  ✓   &b == &y  ✓   (same addresses)
   temp = a → temp = 5
   a = b    → x = 9
   b = temp → y = 5
   Output: x=9, y=5

 TIME COMPLEXITY CALCULATION:
 - Creating a reference: bind one pointer-sized value → O(1).
 - Swap via reference: 3 assignments (temp=a, a=b, b=temp), each O(1) → 3 × O(1) = O(1).
 - No loop, no copy of data involved.
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - A reference does not allocate new memory for the data. The compiler may
   implement it as a hidden pointer (8 bytes) or optimize it away entirely.
 - No arrays, no recursion → constant extra space.
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌──────────────────────┬──────────────────────┬──────────────────────┐
 │ Feature              │ Reference (&)        │ Pointer (*)          │
 ├──────────────────────┼──────────────────────┼──────────────────────┤
 │ Initialization       │ Mandatory at decl.   │ Can be left null     │
 │ Rebindable           │ NO                   │ YES                  │
 │ Can be null          │ NO (always valid)    │ YES (nullptr)        │
 │ Has own address      │ NO (same as target)  │ YES (own box)        │
 │ Syntax to use        │ Direct: ref++        │ Deref: (*p)++ or ->  │
 │ Safety               │ Safer (no null)      │ Riskier (null, dangling)│
 │ Use in data struct.  │ Rare (ref members)   │ Common (next, left)  │
 └──────────────────────┴──────────────────────┴──────────────────────┘
*/

#include <iostream>
using namespace std;

// pass by reference — caller ka variable directly badalta hai
void swapRef(int &a, int &b) {
    int temp = a;   // backup lo
    a = b;          // a (caller ka variable) b ban gaya
    b = temp;       // b (caller ka variable) purani a
}

// caller ka variable badalna — return type void, reference se kaam
void incrementByRef(int &n) {
    n = n + 1;      // seedha original variable update
}

// const reference — sirf padho, likho mat
void printDouble(const int &n) {
    cout << "Double = " << n * 2 << endl;
    // n = n * 2;  // ❌ compiler error: assignment of read-only reference
}

// returning reference — STATIC variable zinda rahe
int& getFirst(int arr[]) {
    return arr[0];  // arr zinda hai function ke baad bhi — safe
}

int main() {

    // ═══════════════════════════════════════
    // DEMO 1: Reference = alias, same address
    // ═══════════════════════════════════════
    cout << "=== DEMO 1: Reference = Alias ===" << endl;
    int num = 42;
    int &alias = num;         // alias is another name for num

    cout << "num   = " << num << endl;
    cout << "alias = " << alias << endl;
    cout << "&num   = " << &num << "   (address of num)" << endl;
    cout << "&alias = " << &alias << "   (address of alias)" << endl;
    cout << "Same address? " << ((&num == &alias) ? "YES" : "NO") << endl;
    cout << endl;

    // ═══════════════════════════════════════
    // DEMO 2: Changing alias changes original
    // ═══════════════════════════════════════
    cout << "=== DEMO 2: alias changes num ===" << endl;
    alias = 100;
    cout << "After alias = 100:" << endl;
    cout << "  num   = " << num << "   (num also changed!)" << endl;
    cout << "  alias = " << alias << endl;
    cout << endl;

    // ═══════════════════════════════════════
    // DEMO 3: Pass by reference — swap
    // ═══════════════════════════════════════
    cout << "=== DEMO 3: Swap via Reference ===" << endl;
    int x = 10, y = 20;
    cout << "Before: x = " << x << ", y = " << y << endl;
    swapRef(x, y);
    cout << "After:  x = " << x << ", y = " << y << endl;
    cout << endl;

    // ═══════════════════════════════════════
    // DEMO 4: Modify caller variable
    // ═══════════════════════════════════════
    cout << "=== DEMO 4: Increment via Reference ===" << endl;
    int val = 50;
    cout << "Before: val = " << val << endl;
    incrementByRef(val);
    cout << "After:  val = " << val << "   (changed from function)" << endl;
    cout << endl;

    // ═══════════════════════════════════════
    // DEMO 5: Const reference — read only
    // ═══════════════════════════════════════
    cout << "=== DEMO 5: Const Reference ===" << endl;
    int p = 25;
    printDouble(p);     // const reference: cheap + safe
    cout << "p still = " << p << "   (unchanged)" << endl;
    cout << endl;

    // ═══════════════════════════════════════
    // DEMO 6: Returning reference from function
    // ═══════════════════════════════════════
    cout << "=== DEMO 6: Return Reference ===" << endl;
    int arr[] = {10, 20, 30};
    int &first = getFirst(arr);   // reference to arr[0]
    cout << "first = " << first << endl;
    first = 99;                   // modify via returned reference
    cout << "After first = 99, arr[0] = " << arr[0] << "   (changed!)" << endl;
    cout << endl;

    // ═══════════════════════════════════════
    // EDGE CASE 1: Reference must be initialized
    // ═══════════════════════════════════════
    cout << "=== EDGE CASE 1: Must Initialize ===" << endl;
    // int &badRef;   // ❌ COMPILE ERROR: 'badRef' declared as reference but not initialized
    cout << "int &badRef;  -->  compiler ERROR (reference not initialized)" << endl;
    cout << endl;

    // ═══════════════════════════════════════
    // EDGE CASE 2: Cannot rebind a reference
    // ═══════════════════════════════════════
    cout << "=== EDGE CASE 2: Cannot Rebind ===" << endl;
    int a = 10, b = 20;
    int &r = a;
    cout << "r (bound to a) = " << r << endl;
    r = b;           // THIS DOES NOT rebind! It copies b's value INTO a.
    cout << "After r = b: a = " << a << ", r = " << r << ", b = " << b << endl;
    cout << "(r is still an alias of a, but a's value became 20)" << endl;
    cout << endl;

    // ═══════════════════════════════════════
    // EDGE CASE 3: Dangling reference (PITFALL — DON'T RUN)
    // ═══════════════════════════════════════
    cout << "=== EDGE CASE 3: Dangling Reference (concept only) ===" << endl;
    cout << "int& dangling() { int x = 99; return x; }  // BAD!" << endl;
    cout << "Local 'x' dies when function returns -> reference points to dead memory" << endl;
    cout << "Compiler warns: 'reference to local variable returned'" << endl;
    cout << "(Commented out to keep program safe)" << endl;
    cout << endl;

    cout << "All reference demos complete." << endl;
    return 0;
}
