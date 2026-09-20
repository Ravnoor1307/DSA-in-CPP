/*
═══════════════════════════════════════════════
 STD::DEQUE — Double-Ended Queue
 ⏱️ TIME COMPLEXITY:
   push_front: O(1)  — add to front
   push_back:  O(1)  — add to back
   pop_front:  O(1)  — remove from front
   pop_back:   O(1)  — remove from back
   access []:  O(1)  — random access supported
   insert(mid): O(n) — must shift elements
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a checkout counter at a supermarket. Customers join
 from one end (back) but sometimes a VIP customer is ushered
 in at the front. If a customer changes their mind, they can
 leave from either end. The counter clerk can also look at
 any customer in line by counting from the front. std::deque
 supports all of this: efficient insertion and removal at
 BOTH ends, PLUS random access by index. It is like a vector
 that also supports O(1) push_front. Real uses include
 sliding window maximum, BFS when you need deque as a
 double-ended buffer, and implementing both stack and queue.

 📖 THEORY: (pure English, beginner-level)
 - std::deque is a double-ended queue in <deque>.
 - It is NOT a linked list — it uses segmented arrays.
 - Supports push_front, push_back, pop_front, pop_back — all O(1).
 - Supports random access with [] — O(1).
 - Iterators are random-access (unlike list).
 - Why O(1) at both ends? Segmented memory design.
 - insert/erase in the middle is O(n) — must shift.
 - Used as default underlying container for stack and queue.

 ASCII SEGMENTED MEMORY:

   deque internally uses a "map" of fixed-size blocks:

   Block 0       Block 1       Block 2       Block 3
  ┌──┬──┬──┬──┐ ┌──┬──┬──┬──┐ ┌──┬──┬──┬──┐ ┌──┬──┬──┬──┐
  │  │  │30│40│ │50│60│  │  │ │  │  │  │  │ │  │  │  │  │
  └──┴──┴──┴──┘ └──┴──┴──┴──┘ └──┴──┴──┴──┘ └──┴──┴──┴──┘
       ↑              ↑
     front           back
     = 30            = 60

   Elements: [30, 40, 50, 60]
   Front block may not start at index 0 (partial fill).
   When a block fills, a new block is allocated.

   Why push_front is O(1):
   → Just prepend to current front block (or new block if full).
   → No element shifting needed.

   Why access [] is O(1):
   → Calculate block index = (front_pos + i) / block_size
   → Calculate offset within block = (front_pos + i) % block_size
   → Two integer ops + one array access.

 ASCII DEQUE vs VECTOR FRONT INSERTION:

   VECTOR: push_front(5) into [10, 20, 30, 40]
   ┌─────────────────────────┐
   │ 5 │ 10 │ 20 │ 30 │ 40  │  ← ALL elements shift right!
   └─────────────────────────┘
   Cost: O(n) — every element moves

   DEQUE: push_front(5) into [10, 20, 30, 40]
   Block 0: [5]  Block 1: [10, 20, 30, 40]
   ┌──┐           ┌──────┬──────┬──────┬──────┐
   │5 │           │  10  │  20  │  30  │  40  │
   └──┘           └──────┴──────┴──────┴──────┘
   Cost: O(1) — just prepend in block 0

 🧠 LOGIC — STEP BY STEP:
 Step 1: Push elements at both ends.
   WHY: push_front and push_back are both O(1). This is
   the key advantage over vector which is O(n) for push_front.
 Step 2: Pop from both ends.
   WHY: pop_front and pop_back are both O(1). Perfect for
   implementing sliding window algorithms.
 Step 3: Access elements by index.
   WHY: deque supports [] with O(1) random access, just
   like vector. Two-level address calculation.
 Step 4: Use for palindrome check.
   WHY: palindrome check compares first and last characters,
   removing both. deque supports both ends in O(1).

 VISUAL WALKTHROUGH:

   push_back(10):   push_front(5):    push_back(20):
   ┌─────┐          ┌───┬─────┐       ┌───┬─────┬─────┐
   │ 10  │          │ 5 │ 10  │       │ 5 │ 10  │ 20  │
   └─────┘          └───┴─────┘       └───┴─────┴─────┘

   pop_front():     pop_back():
   ┌─────┬─────┐    ┌─────┐
   │ 10  │ 20  │    │ 10  │
   └─────┴─────┘    └─────┘

 DRY RUN (demo in main):
   deque<int> d;
   d.push_back(10);   → [10]
   d.push_back(20);   → [10, 20]
   d.push_front(5);   → [5, 10, 20]
   d.push_front(1);   → [1, 5, 10, 20]
   d.push_back(30);   → [1, 5, 10, 20, 30]
   d[0]=1, d[2]=10, d[4]=30 — random access works
   pop_front()        → [5, 10, 20, 30]
   pop_back()         → [5, 10, 20]
   front=5, back=20

 TIME COMPLEXITY CALCULATION:
 - push_front(): Prepend to front block.
   If front block has space: write to index, update front_pos
   → constant pointer math = O(1)
   If front block full: allocate new block, update map → O(1)
   → Total = O(1)

 - push_back(): Append to back block.
   Same logic as push_front for back block.
   → Total = O(1)

 - pop_front(): Remove from front block.
   Update front_pos pointer → O(1).
   If block becomes empty, optionally deallocate → O(1).
   → Total = O(1)

 - pop_back(): Remove from back block.
   Same logic for back block.
   → Total = O(1)

 - operator[](i): Two-level indexing.
   block_idx = (front_pos + i) / BLOCK_SIZE → O(1)
   offset = (front_pos + i) % BLOCK_SIZE → O(1)
   return blocks[block_idx][offset] → O(1)
   → Total = O(1)

 - insert(mid, val): Must shift elements to make room.
   Worst case: shift n/2 elements → O(n).
   → Total = O(n)

 → Time Complexity Summary:
   push/pop ends: O(1) | random access: O(1) | mid insert: O(n)

 SPACE COMPLEXITY CALCULATION:
 - deque stores n elements across fixed-size blocks.
 - Block overhead: one pointer per block in the map.
 - If BLOCK_SIZE = 512 bytes, then for n elements:
   number of blocks = ceil(n / BLOCK_SIZE)
   map overhead = ceil(n/512) pointers
 - No per-element overhead (unlike list).
 - Less contiguous than vector but better cache than list.
 → Space Complexity = O(n) with moderate constant

 APPROACH COMPARISON:
 ┌───────────────┬───────────┬───────────┬───────────┐
 │   Operation   │  vector   │  deque    │   list    │
 ├───────────────┼───────────┼───────────┼───────────┤
 │ push_front    │  O(n)     │  O(1)     │  O(1)     │
 │ push_back     │  O(1)*    │  O(1)     │  O(1)     │
 │ pop_front     │  O(n)     │  O(1)     │  O(1)     │
 │ pop_back      │  O(1)     │  O(1)     │  O(1)     │
 │ access [i]    │  O(1)     │  O(1)     │  O(n)     │
 │ insert(mid)   │  O(n)     │  O(n)     │  O(1)**   │
 │ cache friend  │  best     │  good     │  poor     │
 │ memory/block  │  1 block  │  many     │  per-node │
 └───────────────┴───────────┴───────────┴───────────┘
 * amortized  ** after finding position
 ────────────────────────────────────────────────────
*/

#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int>& d, const string& label) {
    cout << label << ": ";
    if (d.empty()) { cout << "(empty)"; }
    for (size_t i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

bool isPalindrome(deque<char>& dq) {
    while (dq.size() > 1) {
        if (dq.front() != dq.back()) return false;
        dq.pop_front();
        dq.pop_back();
    }
    return true;
}

int main() {
    cout << "========== STD::DEQUE DEMO ==========\n\n";

    deque<int> d;

    // --- Push at both ends ---
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);
    d.push_front(1);
    d.push_back(30);
    printDeque(d, "After pushes  ");

    // --- Random access ---
    cout << "\nRandom access:\n";
    for (size_t i = 0; i < d.size(); i++) {
        cout << "  d[" << i << "] = " << d[i] << endl;
    }
    cout << "  front = " << d.front() << endl;
    cout << "  back  = " << d.back() << endl;
    cout << "  size  = " << d.size() << endl;

    // --- Pop from both ends ---
    d.pop_front();
    printDeque(d, "\nAfter pop_front");
    d.pop_back();
    printDeque(d, "After pop_back ");

    // --- Insert at position ---
    auto it = d.begin() + 1;
    d.insert(it, 15);
    printDeque(d, "Insert 15 @pos1");

    // --- Iterator support (random-access) ---
    cout << "\nIterator range loop: ";
    for (auto it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // --- Palindrome check using deque ---
    cout << "\n--- Palindrome Check Demo ---\n";
    deque<char> word1 = {'r','a','c','e','c','a','r'};
    cout << "  \"racecar\": " << (isPalindrome(word1) ? "palindrome" : "not palindrome") << endl;

    deque<char> word2 = {'h','e','l','l','o'};
    cout << "  \"hello\"  : " << (isPalindrome(word2) ? "palindrome" : "not palindrome") << endl;

    // --- Edge case: empty deque ---
    cout << "\n--- Edge Case: Empty Deque ---\n";
    deque<int> empty;
    cout << "  empty.empty() = " << (empty.empty() ? "true" : "false") << endl;
    cout << "  empty.size()  = " << empty.size() << endl;
    // DO NOT call empty[0], empty.front(), empty.back() on empty!

    cout << "\n========== DEMO COMPLETE ==========\n";
    return 0;
}
