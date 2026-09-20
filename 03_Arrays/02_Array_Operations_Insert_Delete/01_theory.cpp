/*
═══════════════════════════════════════════════
 INSERT / DELETE / UPDATE IN ARRAY
 ⏱️ TIME COMPLEXITY: derived step-by-step below for every op. NEVER a bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 You are standing in a movie ticket line outside the cinema. The line is a fixed row
 of people. If a friend arrives and wants to stand in the MIDDLE of the line, everyone
 from that point to the back has to take one step backwards to make room — that takes
 real effort (moves). If someone near the front leaves, everyone behind steps forward
 one spot to close the gap. But the person at the very front is served instantly — no
 shifting, and adding someone at the very back (if there is space) is instant too. An
 array behaves exactly like this physical line: middle insert/delete shuffles everyone.

 📖 THEORY: (pure English, beginner-level)
 - An array has two numbers: CAPACITY (total slots reserved in memory) and SIZE (slots
   currently filled). Invariant: size <= capacity, always.
 - INSERT AT END: if size < capacity, write at arr[size], then size++ → cost is 1 write.
 - INSERT AT MIDDLE (position p): right-shift all elements from the last used index
   down to p by one step (copy arr[i] to arr[i+1]), then place the new value at arr[p],
   then size++. We moved up to n elements, so cost is O(n).
 - INSERT AT START: identical to a middle insert with p = 0 — every element shifts right.
 - DELETE (position p): left-shift elements from p+1 to the last index one step left
   (copy arr[i] to arr[i-1]), then size--. Cost is O(n).
 - UPDATE: a single direct write at arr[p] → O(1). No shifting ever.
 - ASCII diagram — INSERT 15 AT INDEX 1 into {10, 20, 30, 40} (capacity 5):

   STEP 1 (right-shift from the back: 40 → new slot):
          ┌────┬────┬────┬────┬────┐
   before │ 10 │ 20 │ 30 │ 40 │  _ │
          └────┴────┴────┴────┴────┘
          ┌────┬────┬────┬────┬────┐
   copy40 │ 10 │ 20 │ 30 │ 30 │ 40 │
          └────┴────┴────┴────┴────┘
   STEP 2 (30 → right, 20 → right):
          ┌────┬────┬────┬────┬────┐
   copy30 │ 10 │ 20 │ 20 │ 30 │ 40 │
          └────┴────┴────┴────┴────┘
   STEP 3 (place 15 at index 1):
          ┌────┬────┬────┬────┬────┐
   place  │ 10 │ 15 │ 20 │ 30 │ 40 │
          └────┴────┴────┴────┴────┘   size now 5 ✔

 - WHY middle insert is slow: array memory is fixed and contiguous. To create a gap we
   MUST physically move every element after the insertion point. std::vector hides this
   book-keeping, but the shuffling cost is identical (only push_back at the back is
   cheap, amortized O(1)).
 - WHY we still use arrays: O(1) random access beats everything. Best practice — do
   inserts/deletes rarely, batch the updates, and shift once.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: CHECK capacity before any insert. WHY: writing past capacity overflows memory
         (undefined behaviour / crash) — C arrays never check it for you.
 Step 2: INSERT AT END — if there is a free slot, write arr[size] = value and size++.
         WHY: the slot right after the last used one is free and reachable in O(1).
 Step 3: INSERT AT MIDDLE — loop i from size-1 DOWN to p, copying arr[i] to arr[i+1],
         then write arr[p] = value and size++.
         WHY: copying from the BACK guarantees we never overwrite a value we still need
         to move (a forward copy would destroy data).
 Step 4: DELETE — loop i from p to size-2, copying arr[i+1] to arr[i], then size--.
         WHY: every later element is pulled one step left; the duplicated tail value is
         simply excluded by shrinking size.
 Step 5: UPDATE — write arr[p] = value directly, no movement at all.
         WHY: O(1) address jump, same as array access.

 VISUAL WALKTHROUGH: DELETE AT INDEX 1 from {10, 20, 30, 40} (capacity 5)
          ┌────┬────┬────┬────┬────┐
   before │ 10 │ 20 │ 30 │ 40 │  _ │     size = 4
          └────┴────┴────┴────┴────┘
   step1  │ 10 │ 30 │ 30 │ 40 │  _ │     arr[1] = arr[2]
          ├────┼────┼────┼────┼────┤
   step2  │ 10 │ 30 │ 40 │ 40 │  _ │     arr[2] = arr[3]
          ├────┼────┼────┼────┼────┤
   done   │ 10 │ 30 │ 40 │ 40 │  _ │     size = 3 → tail 40 ignored
          └────┴────┴────┴────┴────┘

 DRY RUN: insert 15 at index 1 into {10, 20, 30} (capacity 4, size 3)
   loop (right-shift):  i=2 → arr[3] = arr[2]  → {10, 20, 30, 30}
                        i=1 → arr[2] = arr[1]  → {10, 20, 20, 30}
   place:               arr[1] = 15           → {10, 15, 20, 30}
   size++ → 4
   Shifts executed = size - p = 3 - 1 = 2. Worst case p=0 shifts n-1 elements → O(n).

 TIME COMPLEXITY CALCULATION:
 - Insert at end (if free slot): 1 write + size++ ⇒ O(1)
 - Insert at middle/start: right-shift (size - p) elements; worst case p=0 shifts
   n-1 elements ⇒ O(n)
 - Delete from middle/start: left-shift (size - p - 1) elements ⇒ O(n)
 - Delete from end: just size-- ⇒ O(1)
 - Update at index p: one write ⇒ O(1)
 - Access arr[p]: direct formula ⇒ O(1)
 → Time Complexity = insert-end O(1), insert-start/middle O(n), delete-middle O(n),
   delete-end O(1), update O(1).

 SPACE COMPLEXITY CALCULATION:
 - Fixed array of capacity C reserves C cells ⇒ O(C) storage
 - Shifting uses only 1 temporary variable ⇒ O(1) auxiliary
 → Space Complexity = O(C) for storage + O(1) extra work space.

 APPROACH COMPARISON: insert at start vs middle vs end (n = current size)
 ┌───────────────────┬───────────────────────────────────────────┬─────────┐
 │ Operation         │ Steps taken                               │ Time    │
 ├───────────────────┼───────────────────────────────────────────┼─────────┤
 │ Insert at end     │ write arr[size], then size++              │ O(1)    │
 │ Insert at middle  │ right-shift (n-p) elements, then write    │ O(n)    │
 │ Insert at start   │ right-shift all n elements                │ O(n)    │
 │ Delete from end   │ size-- only                               │ O(1)    │
 │ Delete middle     │ left-shift (n-p-1) elements               │ O(n)    │
 │ Update            │ write arr[p] once                         │ O(1)    │
 └───────────────────┴───────────────────────────────────────────┴─────────┘
*/

#include <iostream>
using namespace std;

// helper: array ko current size ke hisaab se print karta hai
void printArray(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "]";
}

int main() {
    const int CAPACITY = 6;
    int arr[CAPACITY] = {10, 20, 30, 40};
    int size = 4;                        // abhi 4 slots filled, 2 free

    cout << "=== START ===\n";
    cout << "array = "; printArray(arr, size);
    cout << "   capacity=" << CAPACITY << "  size=" << size << "\n\n";

    // ---------- 1) INSERT AT END : O(1) ----------
    if (size < CAPACITY) {
        arr[size] = 50;                  // seedha khali slot par ek write
        size++;
    }
    cout << "=== 1) INSERT AT END (50) ===\n";
    cout << "after: "; printArray(arr, size);
    cout << "   size=" << size << "\n\n";

    // ---------- 2) INSERT AT POSITION 2 : O(n), step-by-step shift dikhao ----------
    int pos = 2, val = 99;
    if (size < CAPACITY && pos >= 0 && pos <= size) {
        cout << "=== 2) INSERT " << val << " AT INDEX " << pos << " (har shift print) ===\n";
        // right-shift: PEE CHE se shuru karo, taki zaroori data overwrite na ho
        for (int i = size - 1; i >= pos; i--) {
            arr[i + 1] = arr[i];         // arr[i] ko ek slot aage copy kiya
            cout << "  shift arr[" << i << "] -> arr[" << i + 1 << "]: ";
            printArray(arr, size);
            cout << "\n";
        }
        arr[pos] = val;                  // ab gap ready hai, value yahan rakh do
        size++;
        cout << "  placed " << val << " at index " << pos << ": ";
        printArray(arr, size);
        cout << "\n\n";
    }

    // ---------- 3) DELETE AT INDEX 1 : O(n), left-shift ----------
    int delPos = 1;
    if (delPos >= 0 && delPos < size) {
        cout << "=== 3) DELETE AT INDEX " << delPos << " ===\n";
        for (int i = delPos; i < size - 1; i++) {
            arr[i] = arr[i + 1];         // aage wale element ko ek slot peeche kheench lo
        }
        size--;
        cout << "after: "; printArray(arr, size);
        cout << "   size=" << size << "\n\n";
    }

    // ---------- 4) UPDATE INDEX 0 : O(1) direct write ----------
    cout << "=== 4) UPDATE idx 0 = 7 ===\n";
    arr[0] = 7;                          // koi shifting nahi — bas ek write
    cout << "after: "; printArray(arr, size);
    cout << "\n\n";

    // ---------- 5) SIZE vs CAPACITY ----------
    cout << "=== 5) SIZE vs CAPACITY ===\n";
    cout << "size = " << size << " (filled), capacity = " << CAPACITY
         << " (allocated), free = " << (CAPACITY - size) << "\n\n";

    // ---------- 6) EDGE CASES ----------
    cout << "=== EDGE CASES ===\n";

    // (a) full-array insert guard
    if (size < CAPACITY) {
        cout << "a) Insert allowed: size (" << size << ") < capacity (" << CAPACITY << ")\n";
    } else {
        cout << "a) Insert REJECTED: array FULL — pehle delete ya memory expand karo\n";
    }

    // full condition simulate — maan lo size capacity ke barabar hai
    int fullSize = CAPACITY;
    if (fullSize >= CAPACITY) {
        cout << "b) Simulated FULL array: arr[size] par write karne se memory overflow "
                "hota — guard zaroori hai, C arrays khud check nahi karte.\n";
    }

    // (b) delete beyond-last / negative guard
    int badIdx = CAPACITY;               // size se bada (aur galat) index
    if (badIdx < 0 || badIdx >= size) {
        cout << "c) Delete at index " << badIdx << " REJECTED (out of range, size="
             << size << ")\n";
    }

    // (c) single-element delete: size 1 → 0 safely
    int oneArr[1] = {5};                 // size 1 ka array
    int oneSize = 1;
    if (oneSize > 0) {
        cout << "d) Single-element array [" << oneArr[0] << "], deleting it...\n";
        oneSize--;                       // last element gaya, ab array khali
        cout << "   new size = " << oneSize << " (empty, safe)\n";
    }

    return 0;
}