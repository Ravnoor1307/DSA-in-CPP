/*
═══════════════════════════════════════════════
 STATIC vs DYNAMIC DATA STRUCTURES
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a wedding hall with exactly 100 chairs booked in advance. If 120 guests
 arrive, you are in trouble — the hall cannot grow. That is a STATIC structure:
 size is fixed at creation. Now think of a street food stall that keeps adding
 tables whenever new customers come. When the current space fills up, the stall
 moves to a bigger space and carries all the sitting customers along. That is a
 DYNAMIC structure: it grows at runtime.

 📖 THEORY: (pure English, beginner-level)
 - Definition: A static data structure has a FIXED size decided at compile time.
   A dynamic data structure can GROW / SHRINK at runtime.
 - Static examples: plain C++ arrays (int arr[5]), C-style strings.
 - Dynamic examples: std::vector, linked list, stack/queue from STL.
 - Static: exactly 'n' memory blocks are reserved once. Very fast, zero overhead,
   but can never accept more than 'n' items.
 - Dynamic: memory is allocated on the fly (heap). When space runs out, the
   structure RE-ALLOCATES a bigger block and COPIES all existing data over.

   +------------------------+----------------------------+----------------------------+
   |  Feature               |  Static (plain array)      |  Dynamic (vector)          |
   +------------------------+----------------------------+----------------------------+
   |  Size                  |  fixed at compile time     |  grows / shrinks at runtime|
   |  Memory location       |  usually the stack         |  usually the heap          |
   |  Add beyond capacity   |  NOT allowed (out of bounds)| auto re-allocation        |
   |  Speed                 |  fastest, zero overhead    |  slight overhead on growth |
   |  Best when             |  size known in advance     |  size NOT known in advance |
   +------------------------+----------------------------+----------------------------+

 - When to use static: fixed known data (7 days of a week, marks of exactly 5
   subjects, size of a chess board).
 - When to use dynamic: user-driven input, unknown counts, runtime insertions.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: The compiler reserves memory for a static array — its size never changes.
         WHY: 'int arr[n]' maps to exactly n fixed contiguous memory slots.
 Step 2: A vector starts with some initial capacity. Each push_back() writes one
         more element at the end.
         WHY: the capacity was already reserved, so no new allocation is needed
         until the vector is completely full.
 Step 3: When size == capacity, the vector allocates about 2x memory, copies all
         old data into it, then frees the old block.
         WHY: copying preserves every existing element inside the new bigger block.
 Step 4: Print size (used elements) and capacity (reserved slots) after every
         push_back() to SEE the growth.
         WHY: this makes the invisible re-allocation clearly visible.

 VISUAL WALKTHROUGH:

 STATIC array (int arr[4]) — memory view (stack):
   +-----+-----+-----+-----+
   | [0] | [1] | [2] | [3] |
   +-----+-----+-----+-----+
   Try to write arr[4] => NOT allowed, this is OUT OF BOUNDS.

 DYNAMIC vector — growth by re-allocation:
   after push_back(10)        +-----+        size=1  capacity=1
                              | 10  |
                              +-----+
   after push_back(20)        +-----+-----+   size=2  capacity=2
                              | 10  | 20  |   (re-allocated to 2)
                              +-----+-----+
   after push_back(30, 40)    +-----+-----+-----+-----+   size=4 capacity=4
                              | 10  | 20  | 30  | 40  |   (re-allocated to 4)
                              +-----+-----+-----+-----+
   after push_back(50...)     +-----+-----+-----+-----+-----+-----+-----+-----+
                              | 10  | 20  | 30  | 40  | 50  | ... | ... | ... |
                              +-----+-----+-----+-----+-----+-----+-----+-----+
                              size=5  capacity=8 (re-allocated to 8)

 DRY RUN: (of the demo below)
   vector<int> v; starts empty: size=0, capacity=0
   push_back(0)  -> size=1, capacity=1   (first allocation)
   push_back(10) -> size=2, capacity=2   (re-alloc to 2)
   push_back(20) -> size=3, capacity=4   (re-alloc to 4)
   push_back(30) -> size=4, capacity=4
   push_back(40) -> size=5, capacity=8   (re-alloc to 8)
   push_back(50) -> size=6, capacity=8
   push_back(60) -> size=7, capacity=8
   push_back(70) -> size=8, capacity=8
   Exact capacity numbers depend on the compiler; the KEY point is that
   size <= capacity ALWAYS and capacity jumps (0 -> 1 -> 2 -> 4 -> 8 ...).

 TIME COMPLEXITY CALCULATION:
 - Static array: access / modification at index i.
   Address = base_address + i * sizeof(int)  => exactly ONE operation.
   → Time Complexity = O(1) per index access.
 - Vector push_back (amortised over many calls):
   Normal case: just write one element at the end => 1 step.
   When size == capacity: allocate new block (1) + copy n existing elements
   (n steps) + free old block (1)  => total ≈ n + 2 steps.
   Across n push_backs the total work is about n (the rare big copies are paid
   for by many cheap pushes), so per push it is constant on average.
   → Amortised Time Complexity = O(1) per push_back.

 SPACE COMPLEXITY CALCULATION:
 - Static array of n elements: exactly n slots, nothing extra.
   → Space Complexity = O(n)
 - Vector during growth: may hold up to ~2n reserved slots for only n used.
   Worst case reserved memory = 2n.
   → Space Complexity = O(n) (with small constant overhead)

 APPROACH COMPARISON:
 ┌────────────────────────┬──────────────────────────┬──────────────────────────┐
 │ Aspect                 │ Static Array             │ Dynamic Vector           │
 ├────────────────────────┼──────────────────────────┼──────────────────────────┤
 │ Size change at runtime │ No (fixed forever)       │ Yes (grows / shrinks)    │
 │ Insert beyond size     │ No -> out of bounds bug  │ Yes -> auto re-allocation│
 │ Memory overhead        │ Zero (data only)         │ spare capacity block     │
 │ Index access speed     │ Fastest (O(1))           │ same O(1)                │
 │ Copy on growth         │ Never                    │ Yes (amortised O(1))     │
 └────────────────────────┴──────────────────────────┴──────────────────────────┘
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ---- STATIC: size fixed at compile time ----
    int arr[5] = {10, 20, 30, 40, 50};   // 5 slots forever
    cout << "Static array: size fixed at 5 elements.\n";
    cout << "Elements: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << "\nCan we add a 6th element? arr[5] is OUT OF BOUNDS -> NOT possible.\n";
    cout << "(arr[99] simply reads garbage memory - undefined behaviour)\n\n";

    // ---- DYNAMIC: vector grows at runtime ----
    vector<int> v;   // starts empty, kuch bhi size nahi
    cout << "Vector growth demo (push_back + print size/capacity):\n";
    for (int i = 0; i < 8; i++) {
        v.push_back(i * 10);
        cout << "  After push_back(" << i * 10 << ") -> size = " << v.size()
             << ", capacity = " << v.capacity() << "\n";
    }
    cout << "\nConclusion: vector grows on demand, static array never does.\n";
    return 0;
}