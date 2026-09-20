/*
═══════════════════════════════════════════════
 std::vector — THE DYNAMIC ARRAY
 ⏱️ TIME COMPLEXITY: push_back amortized O(1), insert/erase O(n),
     at()/[] O(1), resize/reserve O(n) at worst.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A metro train starts with just 4 seats and can add one coach at a
 time as passenger numbers grow. You never ask "how many coaches will
 I ever need?" — the train (vector) automatically adds coaches
 (allocates memory) when it gets full, and can shrink later. The
 guard walks coach by coach pointing at each seat: that's the
 iterator. The train even remembers its total capacity (coaches it
 currently owns) separately from how many people actually sit in it
 (size) — same way a vector separates capacity from size.

 📖 THEORY:

 - std::vector is a dynamic array: a single contiguous block of memory
   that grows and shrinks at the rear automatically.
   #include <vector>

 - GROWTH MECHANISM (capacity doubling):
   When size == capacity and we push_back, vector allocates a NEW
   block of ~2× capacity, copies every old element over, then frees
   the old block. Amortised cost stays O(1) per push.

   capacity=4, size=4 (FULL)                push_back(9)
   ┌───┬───┬───┬───┐                        ┌───┬───┬───┬───┬───┬───┬───┬───┐
   │ 1 │ 2 │ 3 │ 4 │   →→→ copy all →→→    │ 1 │ 2 │ 3 │ 4 │ 9 │   │   │   │
   └───┴───┴───┴───┘  grow to capacity 8   └───┴───┴───┴───┴───┴───┴───┴───┘
    size=4 cap=4                             size=5 cap=8 (old block freed)

 - KEY MEMBER FUNCTIONS:
   push_back(x)  append at end         pop_back()  remove last
   insert(it,x)  insert before it      erase(it)   remove one element
   at(i)         checked access        v[i]        unchecked (fast)
   front()/back() first / last         size()      element count
   capacity()    allocated slots       max_size()  theoretical max
   clear()       remove all elements   empty()     size == 0?
   resize(n)     size set to n         reserve(n)  pre-allocate n slots
   shrink_to_fit()  trim capacity down to size()

 - size vs capacity vs max_size:
   size     = how many elements are actually stored now
   capacity = how many elements fit without reallocation
   max_size = biggest size the OS can ever offer (theoretical)

 - Iterators: v.begin() (first) and v.end() (one past last).

 - WHEN TO USE: any list that changes size — scores, orders, names.
   Use at() instead of [] when index may be wrong, because at()
   throws std::out_of_range instead of corrupting memory.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Start empty. vector<int> v; has size 0, capacity 0.
         WHY: we don't know the final size yet; no wasted memory.
         We call reserve(n) only when n is known in advance.

 Step 2: push_back() repeatedly. WHY: appending is amortized O(1);
         the vector doubles capacity exactly when it runs out of space.

 Step 3: insert(it, x) puts x BEFORE the iterator it — all elements
         from it onward shift right by one. WHY: shifting is needed to
         keep data contiguous; each shifted element costs O(1) work,
         so the whole insert is O(n).

 Step 4: erase(it) removes that element and shifts everything after it
         one spot left. WHY: again, contiguity must be restored → O(n).

 Step 5: Access with at(i) inside try/catch. WHY: at() does a bounds
         check and throws, so an out-of-range index gives a clean error
         instead of garbage memory.

 Step 6: clear() and other finishing touches.
         WHY: clear() destroys elements but KEEPS capacity (fast
         re-fill later); shrink_to_fit() can release that memory.

 VISUAL WALKTHROUGH:

   v.push_back(10)         [10]           size1 cap1 (grow 0→1)
   v.push_back(20)         [10][20]       size2 cap2 (grow 1→2)
   v.push_back(30)         [10][20][30]   size3 cap4 (grow 2→4)
   v.push_back(40)         [10][20][30][40] size4 cap4
   v.push_back(50)         [10][20][30][40][50] size5 cap8 (grow 4→8)
   v.insert(v.begin()+1,99)→[10][99][20][30][40][50] size6 cap8
   v.erase(v.begin()+2)    →[10][99][30][40][50]    size5 cap8
   v.shrink_to_fit()       → capacity drops to size 5

 DRY RUN (main() demo):
   push 1..5 → printed sizes: 1/1, 2/2, 3/4, 4/4, 5/8
   insert 100 at index 2 → v = {1,2,100,3,4,5}
   erase index 3 → v = {1,2,100,4,5}
   v.at(1) = 2 (safe); v[9] would be UB so we call at(9) in try →
        caught: std::out_of_range, message printed.

 TIME COMPLEXITY CALCULATION:
 - push_back: normal cases = 1 step. On a doubling, we copy n elements
   but only every ~n-th push pays this. n copies + n normal pushes
   → about 2n total work for n pushes → 2 per push → O(1) amortized.
 - insert at position p: shift (n − p) elements to the right.
   Worst case p=0 → n shifts → O(n).
 - erase at position p: shift (n − p − 1) elements left.
   Worse case p=0 → n−1 shifts → O(n).
 - at(i) and v[i]: direct pointer arithmetic, 1 step → O(1).
 - resize(n) from smaller size: either grows with reallocation (copy n
   elements → O(n)) or shrinks by destroying tail elements → O(n) worst.
 - reserve(n): may allocate + copy n elements → O(n).
 - shrink_to_fit: allocates size-copy of data → O(n).
 → single most common operation push_back = O(1) amortized

 SPACE COMPLEXITY CALCULATION:
 - vector holds n elements but capacity can be as big as 2^n rounds →
   at most 2n slots before the next doubling. Memory ≈ n to 2n
   ints = (2n)·4 bytes at most. Counting slots: 2n → O(n).
 - shrink_to_fit() can pull that back to exactly n → still O(n).
 → Space Complexity = O(n)

 APPROACH COMPARISON:
 ┌───────────────────┬───────────────┬───────────────┬──────────────────┐
 │  Idea             │  append       │  random index │  insert front    │
 ├───────────────────┼───────────────┼───────────────┼──────────────────┤
 │ int arr[10]       │ impossible    │ O(1)          │ impossible       │
 │                   │ (fixed size)  │               │                  │
 │ std::vector       │ O(1) amortized│ O(1)          │ O(n) (shift all) │
 │ std::list         │ O(1)          │ O(n) walk     │ O(1) splice      │
 │ std::deque        │ O(1)          │ O(1)          │ O(n) shift       │
 └───────────────────┴───────────────┴───────────────┴──────────────────┘
*/

#include <iostream>
#include <vector>

using namespace std;

void printVec(const vector<int>& v) {
    // const-approach: sirf padho, modify nahi
    cout << "  -> [ ";
    for (int x : v) cout << x << " ";
    cout << "]  size=" << v.size() << " capacity=" << v.capacity() << "\n";
}

int main() {
    // ======= DEMO: capacity growth steps 1..5 =======
    vector<int> v;
    cout << "Growth while pushing 1..5:\n";
    for (int i = 1; i <= 5; ++i) {
        v.push_back(i);
        printVec(v);               // size aur capacity dono print
    }

    // ======= INSERT at middle =======
    v.insert(v.begin() + 2, 100);  // index 2 se pehle 100 daalo
    cout << "After insert(100) at index 2:\n";
    printVec(v);                   // {1,2,100,3,4,5}

    // ======= ERASE from middle =======
    v.erase(v.begin() + 3);        // 4th element (3) hatao
    cout << "After erase index 3:\n";
    printVec(v);                   // {1,2,100,4,5}

    // ======= at() vs [] =======
    cout << "v[0]    = " << v[0] << " (unchecked, fast)\n";
    cout << "v.at(1) = " << v.at(1) << " (checked)\n";
    cout << "front = " << v.front() << ", back = " << v.back() << "\n";

    // EDGE CASE 1: at() throws out_of_range
    try {
        cout << v.at(9) << "\n";   // index 9 size se bahar hai
    } catch (const out_of_range& e) {
        cout << "OUT OF RANGE caught: " << e.what() << "\n";
    }

    // EDGE CASE 2: empty vector — never call front/back on it
    vector<int> empty;
    cout << "Empty check: empty() = " << boolalpha << empty.empty()
         << ", size = " << empty.size() << "\n";

    // ======= resize / reserve / shrink_to_fit =======
    v.reserve(100);
    cout << "After reserve(100) -> capacity = " << v.capacity()
         << ", size = " << v.size() << "\n";
    v.resize(3);
    cout << "After resize(3)  -> size = " << v.size() << "\n";
    printVec(v);
    v.push_back(99);
    v.shrink_to_fit();             // capacity ko size ke barabar karo
    cout << "After shrink_to_fit -> capacity = " << v.capacity() << "\n";

    v.clear();
    cout << "After clear() -> size = " << v.size()
         << " (capacity " << v.capacity() << " still kept for reuse)\n";

    return 0;
}