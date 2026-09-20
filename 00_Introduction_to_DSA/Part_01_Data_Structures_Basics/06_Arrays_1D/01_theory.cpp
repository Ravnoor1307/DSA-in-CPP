/*
═══════════════════════════════════════════════
 ARRAYS (1D) — INTRODUCTION
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Ten people are standing in a customer service line. The manager asks,
 "What is the 5th person's token number?" Starting from the front and
 counting up to the 5th, he reaches it instantly because every person has
 their own fixed place in the queue. When we store many same-type values
 (10 roll numbers, 100 marks, 50 daily temperatures) in one regular
 (contiguous) line, a position pulls out its value directly — this is an
 ARRAY. Just as a railway coach has fixed compartment numbers, every box
 of an array has a fixed index.

 📖 THEORY: (pure English, formal, beginner-level, "what is X")
 - definition: An ARRAY is a collection of values of the SAME type stored
   in CONTIGUOUS (adjacent) memory boxes.
 - key points / properties:
   • Every element has an INDEX — in C++ it starts from 0.
   • Random access: arr[i] is found in O(1) because its address is
     calculated in one shot = base_address + i * sizeof(type).
   • Size is fixed at compile time (static array); it cannot change.
   • All elements sit side by side — index +1 means the next box.
   • Traversal: a loop visits every element one by one.

   VISUAL — array of 5 ints:
   Index:   0       1       2       3       4
            ┌──────┬──────┬──────┬──────┬──────┐
   Value : │ 10   │ 20   │ 30   │ 40   │ 50   │
            └──────┴──────┴──────┴──────┴──────┘
   Addr  : 1000   1004   1008   1012   1016
             ↑ base

 - when to use:
   a) Many same-type values are needed together.
   b) O(1) random access is needed (instant value from an index).
   c) The fixed number of elements is known in advance.
   d) For sorting/searching, contiguous memory is the fastest layout.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Decide the size (n) — how many elements are needed.
         WHY: C++ static arrays require their size at compile time.
 Step 2: Declare and initialize the array (arr[n] = { ... }).
         WHY: The declaration creates n boxes in contiguous memory.
 Step 3: ACCESS arr[i] — derive the value directly via base + i*size.
         WHY: A single arithmetic step — this is why random access is O(1).
 Step 4: TRAVERSE — for loop from index 0 to n-1, visiting every box.
         WHY: To do anything with each element (print/sum/compare) you
         must reach every box.
 Step 5: INSERT — push directly at the end; in the middle a shift is needed.
         WHY: A middle element cannot be replaced in place — the values
         after it must be shifted right first.

 VISUAL WALKTHROUGH: (capacity arr[10], currently 5 filled)
   Index:  0    1    2    3    4    5    6    7    8    9
          ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   Value: │ 10 │ 20 │ 30 │ 40 │ 50 │    │    │    │    │    │
          └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
                  ^n=5 (filled), rest empty (from n to capacity-1)
   Insert 99 @ end   : arr[5] = 99,  n = 6    (no shift at all)
   Insert 77 @ pos 2 : shift 30,40,50,99 one step right, then place 77

 DRY RUN: (trace of the demo below)
   Step A — traverse + access:
     arr[5] = {10,20,30,40,50}, base=1000, int size=4
     loop i=0..4 :
       i=0 -> print 10 (addr 1000)
       i=1 -> print 20 (addr 1004)
       i=2 -> print 30 (addr 1008)
       i=3 -> print 40 (addr 1012)
       i=4 -> print 50 (addr 1016)
     access arr[3] = 40   (addr = 1000 + 3*4 = 1012)

   Step B — insert 99 @ end:
     arr[5] = 99, n=6  →  {10,20,30,40,50,99}

   Step C — insert 77 @ pos 2 (p=2, n=6):
     shift right: i=6 -> arr[6]=arr[5]=99
                  i=5 -> arr[5]=arr[4]=50
                  i=4 -> arr[4]=arr[3]=40
                  i=3 -> arr[3]=arr[2]=30
                  i=2 -> loop stops (condition i > p is false)
     arr[2] = 77,  n=7
     Result: {10, 20, 77, 30, 40, 50, 99}

 TIME COMPLEXITY CALCULATION:
   - ACCESS arr[i]        : address = base + i*size → 1 mult + 1 add → f(n) = 1
   - TRAVERSE n elements  : loop n times, 1 step each → f(n) = n
   - INSERT @ end         : just 1 assignment (if capacity is left) → f(n) = 1
   - INSERT @ middle p    : (n - p) elements shift; worst p=0 → n shifts → f(n) = n
   - DELETE @ middle      : (n - p) elements shift left; worst → n → f(n) = n
   → Time Complexity = O(1) for access/end-insert, O(n) for traverse/insert-middle/delete

 SPACE COMPLEXITY CALCULATION:
   - array of n ints      : n × 4 bytes → f(n) = n
   - no extra auxiliary   : the shift only needs 1 temp variable → f(n) = 1
   → Space Complexity = O(n) for storage, O(1) for algorithm helpers

 APPROACH COMPARISON:
 ┌──────────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Point                │  1D ARRAY                    │  2D ARRAY                    │
 ├──────────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ Structure            │ one row only (0..n-1)        │ rows × columns (grid)        │
 │ Index                │ a[i]                         │ a[i][j]                      │
 │ Storage              │ n elements contiguous        │ R*C elements contiguous      │
 │ Random access        │ O(1)                         │ O(1) (i*C+j offset)          │
 │ Real-world           │ 10 marks, 50 temperatures    │ seating chart, spreadsheet    │
 │ In one line          │ many same-type values in a   │ a grid of rows and columns   │
 │                      │ single line                  │                              │
 └──────────────────────┴──────────────────────────────┴──────────────────────────────┘
 */
#include <iostream>
using namespace std;

int main() {
    // capacity 10, abhi 5 elements filled hain
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;                       // n = currently filled count

    cout << "STEP 1: Traverse (i=0 to n-1) : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    cout << "STEP 2: Access arr[3] = " << arr[3]
         << "   (base + 3*4 bytes, random access O(1))\n";

    cout << "STEP 3: Insert 99 at END:\n";
    arr[n] = 99;                     // capacity hai, isliye direct
    n++;
    cout << "   after -> ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    cout << "STEP 4: Insert 77 at position 2 (beech me -> shift right):\n";
    int p = 2, val = 77;
    for (int i = n; i > p; i--) {    // right se shuru karke ek-ek shift
        arr[i] = arr[i - 1];
    }
    arr[p] = val;                    // khali hue slot me daal do
    n++;
    cout << "   after -> ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    cout << "Size info: capacity = " << sizeof(arr) / sizeof(arr[0])
         << ", filled = " << n << "\n";
    cout << "Edge case: arr[-1] ya arr[capacity] mile tab UB hota hai — pehle bounds check karo!\n";
    return 0;
}