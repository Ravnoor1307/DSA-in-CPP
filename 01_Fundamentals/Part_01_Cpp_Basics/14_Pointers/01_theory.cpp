/*
═══════════════════════════════════════════════
 POINTERS (Addresses, Dereference, Pointer Arithmetic)
 ⏱️ TIME COMPLEXITY: dereference/assignment O(1), array walk via ptr O(N)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You live in a city and your friend wants to visit you. Instead of carrying
 your house to them, you hand them a paper with your house ADDRESS. The
 address is small, easy to pass around, and lets anyone reach the house.
 In C++, the house is a variable, and the address slip is a pointer. One
 address can be copied to a hundred people; only one house exists. That's
 why passing a pointer is fast and lets a function modify the original data.

 📖 THEORY: (pure English, beginner-level)
 - Pointer = a variable that STORES the memory address of another variable.
 - &x  → address-of operator: gives x's address.
 - *p  → dereference operator: gives the VALUE at the address p holds.
 - int* p;  declares a pointer to an int.
 - nullptr is the modern way to say "points to nothing" (NULL for C).
 - Pointer arithmetic: p+1 skips ahead by sizeof(*p) bytes.
 - Pointer size = size of the address (4 bytes on 32-bit, 8 on 64-bit)
   — independent of what it points to.

 ASCII DIAGRAM — Memory with pointer:
 Address:   0x100       0x103         0x200
           ┌────────┐                ┌────────┐
  x  = 42  │  42    │   x lives at   │        │
           │  (1 int)│   address     │        │
           └────────┘   0x100        └────────┘
   p = &x  ──────────────►  p (a pointer) stores the ADDRESS 0x100
           (address slip) ─┐
                           ▼
   *p        = 42         ┌────────┐
   p+1       = 0x100 + 4  │  42    │
              (int size=4)│        │
                          └────────┘

   int x = 42;
   int* p = &x;   // p ---► x
   cout << *p;    // 42 (dereference = value at that address)

 WHEN TO USE:
 - Pass big data to functions without copying (pass-by-pointer)
 - Modify caller's variables from a function
 - Dynamic memory (new/delete)
 - Array traversal via pointer arithmetic and data structures

 🧠 LOGIC — STEP BY STEP (Change value through pointer):
 Step 1: int* p = &x. WHY: capture x's address now.
 Step 2: *p = 99. WHY: dereference p and write — this WRITES into x
         because p points AT x.
 Step 3: cout << x. WHY: x changed to 99 — same memory, two names.

 VISUAL WALKTHROUGH — Array + pointer arithmetic:
 int arr[4] = {10, 20, 30, 40};
 int* p = arr;      // p -> arr[0]
   p[0]=10  *p=10      p[1]=20  *(p+1)=20 ...
   p+0                   p+1
 ┌───────┬───────┬───────┬───────┐
 │  10   │  20   │  30   │  40   │   arr
 └───────┴───────┴───────┴───────┘
    ▲       ▲       ▲       ▲
    p       p+1     p+2     p+3

 DRY RUN — arithmetic:
 int x = 42; int* p = &x;
 cout << p;    // say 0x100
 cout << *p;   // 42
 *p = 99;      // writes 99 into x
 cout << x;    // 99
 cout << sizeof(p);  // 8 (on 64-bit)

 TIME COMPLEXITY CALCULATION:
 - & (address-of), * (deref), assignment: each is 1 constant operation.
   Work = 1, independent of data size.
 - Walking an array with p++ visiting N elements: N increments +
   N dereferences = 2N operations.
 → Time Complexity = O(1) per pointer op, O(N) for full array walk

 SPACE COMPLEXITY CALCULATION:
 - One pointer occupies sizeof(void*) bytes (8 on 64-bit).
 - Even if it points to a huge array, the pointer itself is fixed-size.
 → Space Complexity = O(1) for pointers; data storage N is separate.

 APPROACH COMPARISON:
 ┌──────────────────────┬──────────────────┬────────────────────────────┐
 │ Aspect               │ Value variable   │ Pointer variable          │
 ├──────────────────────┼──────────────────┼────────────────────────────┤
 │ Stores               │ the value        │ the ADDRESS of a value    │
 │ Access              │ x directly        │ *p to dereference         │
 │ Changing caller data │ pass-by-copy     │ pass pointer → modifies   │
 │ Size                 │ sizeof(type)     │ sizeof(void*) fixed       │
 │ Null state           │ n/a               │ nullptr possible          │
 └──────────────────────┴──────────────────┴────────────────────────────┘
*/

#include <iostream>
using namespace std;

int main() {

    // ═══════════════════════════════════════════
    // DEMO 1: Address-of & and dereference *
    // ═══════════════════════════════════════════
    cout << "=== DEMO 1: & and * ===" << endl;

    int x = 42;
    int* p = &x;   // p mein x ka address store karte hain

    cout << "x        = " << x << endl;
    cout << "&x       = " << &x << "   (x ka address)" << endl;
    cout << "p        = " << p << "   (same address)" << endl;
    cout << "*p       = " << *p << "   (dereference → x ki value)" << endl;
    cout << "sizeof(p)= " << sizeof(p) << " bytes   (pointer ka apna size)" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 2: Change value THROUGH pointer
    // ═══════════════════════════════════════════
    cout << "=== DEMO 2: Modify original via *p ===" << endl;

    cout << "Before: x = " << x << endl;
    *p = 99;                       // *p likhne ka matlab x mein likhna
    cout << "After *p = 99:  x = " << x << endl;
    cout << "dusra variable change hua? YES — same memory cell!" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 3: Pointer to pointer (int**)
    // ═══════════════════════════════════════════
    cout << "=== DEMO 3: Pointer to Pointer *pp ===" << endl;

    int y = 7;
    int* py = &y;      // py -> y
    int** pp = &py;    // pp -> py -> y

    cout << "y      = " << y << endl;
    cout << "py     = " << py << "   (address of y)" << endl;
    cout << "*py    = " << *py << endl;
    cout << "pp     = " << pp << "   (address of py)" << endl;
    cout << "*pp    = " << *pp << "   (value at pp = py ka content = y ka address)" << endl;
    cout << "**pp   = " << **pp << "   (double dereference = y ki value)" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // DEMO 4: Pointer arithmetic on array
    // ═══════════════════════════════════════════
    cout << "=== DEMO 4: Pointer Arithmetic ===" << endl;

    int arr[4] = {10, 20, 30, 40};
    int* pa = arr;     // arr = &arr[0] (array name decays)

    for (int i = 0; i < 4; i++) {
        cout << "arr[" << i << "] = " << arr[i]
             << "  |  *(pa+" << i << ") = " << *(pa + i)
             << "  |  pa+" << i << " = " << (pa + i) << endl;
    }
    cout << "Note: pa+1 skip ho gaya " << sizeof(int) << " bytes (1 int)" << endl;
    cout << endl;

    // ═══════════════════════════════════════════
    // EDGE CASE: nullptr dereference is DANGEROUS
    // ═══════════════════════════════════════════
    cout << "=== EDGE CASE: nullptr ===" << endl;

    int* np = nullptr;   // koi address nahi
    cout << "np == nullptr? " << (np == nullptr ? "YES (abi kisi ko point nahi kar raha)" : "NO") << endl;

    // BAD PRACTICE — isko uncomment mat karo, program crash hoga:
    // *np = 5;   // dereferencing nullptr = segmentation fault

    // Safe pattern: hamesha null check karo pehle
    if (np != nullptr) {
        cout << "*np = " << *np << endl;
    } else {
        cout << "Lekin agar hum *np karte to CRASH hota!" << endl;
    }
    cout << endl;

    // ═══════════════════════════════════════════
    // EDGE CASE: Pointer to double — same pointer size
    // ═══════════════════════════════════════════
    cout << "=== EDGE CASE: size independent of type ===" << endl;

    double d = 3.14;
    double* pd = &d;
    char c = 'A';
    char* pc = &c;

    cout << "sizeof(int*)   = " << sizeof(p)  << " bytes" << endl;
    cout << "sizeof(double*)= " << sizeof(pd) << " bytes" << endl;
    cout << "sizeof(char*)  = " << sizeof(pc) << " bytes" << endl;
    cout << "(sab equal — sirf address store karte hain)" << endl;

    return 0;
}