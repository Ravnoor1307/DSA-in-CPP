/*
═══════════════════════════════════════════════
 DRAWBACKS / LIMITATIONS OF ARRAY
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
Think of a cinema hall built with exactly 100 fixed seats - you cannot add a
101st seat even if the show sells out (FIXED SIZE). A family wants to sit
together in the middle of a fully packed row, so every person to their right
must stand up and shuffle one seat over (COSTLY INSERT / DELETE). The hall
owner reserves a 10,000-seat banquet block but only 200 people arrive, and the
remaining 9,800 seats stay empty while the rent is still paid (MEMORY
WASTAGE). The block also has to exist as ONE uninterrupted stretch of seats -
if the hall is already broken into scattered small pockets, a big group simply
cannot be seated (CONTIGUOUS MEMORY REQUIREMENT).

 📖 THEORY:
 - An array is a contiguous block of memory holding many elements of the SAME
   type, each reached directly through an index: arr[i].
 - The whole block is reserved ONCE at creation, so its size CANNOT change at
   runtime - this is the FIXED SIZE limitation.
 - To insert a value at position p, every element from the tail down to p must
   be shifted ONE STEP RIGHT. WHY: the memory is contiguous, so an empty hole
   can never exist in the middle; a slot must first be created.
 - To delete at position p, every element after it is shifted ONE STEP LEFT.
 - Memory is paid for the CAPACITY, not for the number of elements actually
   used, so unused slots are permanently WASTED.
 - The whole array needs one continuous stretch of RAM; scattered free chunks
   cannot be used even when total free memory is plenty (FRAGMENTATION).
 - C++ never checks bounds: reading arr[100] of a size-5 array is UNDEFINED
   BEHAVIOUR - it may print garbage or crash.

 ASCII - the building block (one contiguous block):
 +-----+-----+-----+-----+-----+
 | 10  | 20  | 30  | 40  | 50  |
 +-----+-----+-----+-----+-----+
  arr[0] arr[1] arr[2] arr[3] arr[4]

 ASCII - insert at index 1 costs (n - p) shifts:
 [10][20][30][40][50]           ← before
 [10][  ][20][30][40][50]       ← shift 4 elements, then write
      ↑
     15                shifts done = 4 = n - p

 ✅ When to use an array anyway:
 - Random access arr[i] is the most frequent operation (O(1)).
 - The size is known in advance and does not change.
 - Cache-friendly locality matters (neighbouring elements sit side by side).

 🧠 LOGIC — STEP BY STEP:
 Step 1 (INSERT): Check whether the array is full BEFORE writing. WHY: writing
         past capacity is undefined behaviour and corrupts neighbouring memory.
 Step 2 (INSERT): Shift from the BACK towards position p, i.e. for i from n
         down to p+1 do arr[i] = arr[i-1]. WHY: if we shift from the front, the
         front value is overwritten before it is copied - data is LOST.
 Step 3 (INSERT): Write val at index p and grow n by 1. WHY: the array stays
         contiguous and logically correct.

 Step 1 (DELETE): Shift from the FRONT, i.e. for i from p up to n-2 do
         arr[i] = arr[i+1]. WHY: opposite direction keeps every value alive
         during the copy.
 Step 2 (DELETE): Decrease n by 1. WHY: the stale tail copy becomes
         unreachable, so logically it is gone.

 VISUAL WALKTHROUGH (insert 15 at index 1 into a capacity-6 array):
 Initial          : [10][20][30][40][50]       n = 5
 shift i=5        : [10][20][30][40][50][50]   copy tail to the right
 shift i=4        : [10][20][30][40][40][50]
 shift i=3        : [10][20][30][30][40][50]
 shift i=2        : [10][20][20][30][40][50]
 write at index 1 : [10][15][20][30][40][50]   n = 6  ✅
 Shifts = 4 = (n - p) exactly.

 DRY RUN (exact trace of the demo code below):
   Input   : arr = [10,20,30,40,50]   n = 5   capacity = 6
   insertAt(arr, n, capacity, pos = 1, val = 15)
      n=5 < capacity=6  →  continue
      loop i = 5 down to 2 (i > pos, stops when i == 1):
        i=5 : arr[5] = arr[4]  → arr = [10,20,30,40,50,50]
        i=4 : arr[4] = arr[3]  → arr = [10,20,30,40,40,50]
        i=3 : arr[3] = arr[2]  → arr = [10,20,30,30,40,50]
        i=2 : arr[2] = arr[1]  → arr = [10,20,20,30,40,50]
      arr[1] = 15  →  arr = [10,15,20,30,40,50]   n = 6
      shifts counted = 4 ✅

   deleteAt(arr, n, pos = 2)      (remove the 20)
      loop i = 2 to 4 (i < n-1 = 5):
        i=2 : arr[2] = arr[3]  → [10,15,30,30,40,50]
        i=3 : arr[3] = arr[4]  → [10,15,30,40,40,50]
        i=4 : arr[4] = arr[5]  → [10,15,30,40,50,50]
      n = 5
      Result : [10,15,30,40,50]   (3 shifts, the 20 is unreachable) ✅

 TIME COMPLEXITY CALCULATION:
 - INSERT at position p: we shift (n - p) elements, each shift is ONE copy
   operation, plus ONE final write. So f(n) = (n - p) + 1.
   Worst case p = 0 (front): f(n) = n + 1, which grows linearly with n.
   Drop the constant and the coefficient: n + 1 ∈ O(n).
   Best case p = n (append to tail): only 1 copy → O(1).
 - DELETE at position p: we shift (n - 1 - p) elements. Worst case p = 0:
   f(n) = n - 1 → O(n). Best case (tail): 1 op → O(1).
 - ACCESS arr[i]: base address + i × elementSize = 2 fixed operations,
   independent of n → O(1).
   → Time Complexity = O(n) worst case for insert/delete, O(1) for access.

 SPACE COMPLEXITY CALCULATION:
 - The array itself reserves capacity × sizeof(type) bytes at allocation,
   and capacity grows with the number of elements, so TOTAL memory = O(capacity)
   = O(n). Unused slots (capacity - n) are part of this reservation.
 - The shifting loop works IN-PLACE using only ONE temporary value; that
   temporary does not grow when n grows, so auxiliary space = O(1).
   → Space Complexity = O(n) total, O(1) auxiliary.

 ═══════════ APPROACH COMPARISON ═══════════
 ┌──────────────────┬─────────────────────────────┬──────────────────────────────┐
 │ Criterion        │ ARRAY                       │ LINKED LIST (preview)        │
 ├──────────────────┼─────────────────────────────┼──────────────────────────────┤
 │ random access    │ O(1) direct ✅              │ O(n) walk links ❌           │
 │ insert middle    │ O(n) shifts ❌              │ O(1) pointer swaps ✅        │
 │ delete middle    │ O(n) shifts ❌              │ O(1) pointer swaps ✅        │
 │ size at runtime  │ fixed ❌                    │ grows freely ✅              │
 │ memory needed    │ one contiguous block only   │ scattered heap slots OK      │
 │ memory wastage   │ capacity - used ❌          │ none (grow as needed) ✅     │
 │ cache friendly   │ yes ✅                      │ no ❌                        │
 └──────────────────┴─────────────────────────────┴──────────────────────────────┘
*/
#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// array me insert — peeche se shift karo, shifts ka count bhi batao
void insertAt(int arr[], int &n, int capacity, int pos, int val) {
    if (n >= capacity) {
        cout << "  ❌ ARRAY FULL — aage shift nahi ho sakta (FIXED SIZE drawback)" << endl;
        return;
    }
    int shifts = 0;
    for (int i = n; i > pos; --i) {   // BACK se FRONT ki taraf chalo
        arr[i] = arr[i - 1];          // har element ek step right
        ++shifts;
    }
    arr[pos] = val;                   // khaali slot mei value daalo
    ++n;
    cout << "  ✅ inserted " << val << " at index " << pos
         << " | shifts = " << shifts << " = (n - pos)" << endl;
}

// array se delete — FRONT se shift karo (insert ka ulta)
void deleteAt(int arr[], int &n, int pos) {
    int shifts = 0;
    for (int i = pos; i < n - 1; ++i) {
        arr[i] = arr[i + 1];          // sab left khiccho
        ++shifts;
    }
    --n;
    cout << "  ✅ deleted index " << pos << " | shifts = " << shifts << endl;
}

int main() {
    cout << "--- DRAWBACK 1+3: INSERT ka shift cost (O(n)) ---" << endl;
    int arr[6] = {10, 20, 30, 40, 50};
    int n = 5;              // abhi 5 elements use ho rahe hain
    int capacity = 6;       // lekin jagah sirf 6 ki hai — fixed size
    printArr(arr, n);
    insertAt(arr, n, capacity, 1, 15);
    printArr(arr, n);

    cout << "\n--- DRAWBACK 4: DELETE ka shift cost (O(n)) ---" << endl;
    deleteAt(arr, n, 2);    // 20 ko hatao
    printArr(arr, n);

    cout << "\n--- DRAWBACK 2: MEMORY WASTAGE ---" << endl;
    int used = 3, cap = 10;
    cout << "  banaye: " << cap << " = " << cap * sizeof(int)
         << " bytes | use: " << used << " = " << used * sizeof(int)
         << " bytes | barbaad: " << (cap - used) * sizeof(int)
         << " bytes (" << (cap - used) * 100 / cap << "%)" << endl;

    cout << "\n--- DRAWBACK 1: FULL array mei insert → reject ---" << endl;
    int full[2] = {7, 8};
    int fn = 2;
    insertAt(full, fn, 2, 0, 99);   // capacity=2, pehle se full
    printArr(full, fn);

    cout << "\n--- DRAWBACK 5: CONTIGUOUS memory (fragmentation) ---" << endl;
    cout << "  bara array bana hi nahi par sakta agar RAM ke tukdo me baara baara khaali ho" << endl;
    cout << "  — isi liye linked list zyada flexible hai (scattered nodes chalte hain)" << endl;

    return 0;
}