/*
═══════════════════════════════════════════════
 REVERSE & ROTATE ARRAY
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Picture a round sushi counter with 5 plates on the belt: sushi, maki, nigiri,
 tempura, edamame. When service starts, the belt rotates clockwise so the first
 plate moves to the end of the line and every plate shifts one slot — that is
 exactly "rotate left by 1". If the belt spins 7 slots, the plates land exactly
 as if it had spun only 2, so we reduce k with k %= n. A train yard rotates car
 order when the front wagon is detached and re-attached at the back, and
 reversing a walk-in fridge's shelf order is plain array reversal. Circular
 queues, round-robin scheduling and a dish turntable all reuse this logic every
 day.

 📖 THEORY: (pure English)
 - Definition: REVERSE flips an array so the last element becomes first. ROTATE
   shifts every element cyclically by k positions; elements pushed off one end
   wrap around to the other end.
 - Reverse extra-array: copy a[n-1-i] into b[i] for every i in one pass. Simple,
   but needs a second array, O(n) memory.
 - Reverse two-pointer: lo at 0, hi at n-1, swap a[lo] and a[hi], then lo++ and
   hi-- until the pointers cross. Only n/2 swaps and O(1) memory.
 - Rotate left by 1: save a[0], shift every element one slot left, place the
   saved value at the end. One O(n) pass.
 - Rotate left by k naive: repeat rotate-left-by-1 exactly k times, so k full
   passes, O(n*k) worst case.
 - Rotate by k extra-array: place b[i] = a[(i + k) % n], then copy back. One
   mapping pass, O(n) time but O(n) memory.
 - Rotate by k reversal algorithm (best): reverse first k, reverse the rest,
   reverse the whole array => O(n) time and O(1) space.
 - Right vs left relation: rotate right by k equals rotate left by (n-k).
   Right-2 of {1,2,3,4,5} = {4,5,1,2,3} which is left-3 of the same array.
 - Always reduce k with k %= n first: rotating by n or 2n returns the same
   array, so only the remainder k mod n matters.
 - When to use: generating cyclic orders, simulating a circular queue, turning
   a reversed sequence back into the original, and as a building block in
   block-swap and rotated-sorted-array problems.

   ASCII — reverse two pointers closing in:
     lo                 hi
     |                  |
     [ 1,  2,  3,  4,  5 ]   swap ends        -> [ 5,  2,  3,  4,  1 ]
        lo            hi
     [ 5,  2,  3,  4,  1 ]   swap ends        -> [ 5,  4,  3,  2,  1 ]
           lo     hi
     [ 5,  4,  3,  2,  1 ]   lo(2) hi(2): 2<2 false -> STOP

   ASCII — rotate LEFT by k = 2 via the reversal algorithm (n = 5):
     original           [ 1,  2,  3,  4,  5 ]
     step1 reverse 0..1 [ 2,  1,  3,  4,  5 ]
     step2 reverse 2..4 [ 2,  1,  5,  4,  3 ]
     step3 reverse 0..4 [ 3,  4,  5,  1,  2 ]   ✅ left-2

   ASCII — rotate RIGHT by k = 2 (mirror order of reverses):
     original           [ 1,  2,  3,  4,  5 ]
     step1 reverse 0..4 [ 5,  4,  3,  2,  1 ]
     step2 reverse 0..1 [ 4,  5,  3,  2,  1 ]
     step3 reverse 2..4 [ 4,  5,  1,  2,  3 ]   ✅ right-2

 🧠 LOGIC — STEP BY STEP: (pure English with WHY)
 Reversal algorithm — rotate left by k:
   Step 1: k %= n.  WHY: after n rotations the array looks exactly the same as
     before, so only the remainder can matter; this also handles k > n and
     k == n safely.
   Step 2: reverse the first k elements [0..k-1]. WHY: prepares the k head
     elements so they can be poured to the back later in the correct order.
   Step 3: reverse the rest [k..n-1]. WHY: prepares the tail block too.
   Step 4: reverse the whole array [0..n-1]. WHY: the two block reversals have
     flipped each half's internal order once, so reversing everything swaps the
     two block positions while the two internal flips cancel out — producing
     one clean cyclic left shift.

 Reversal algorithm — rotate right by k (mirror order):
   Step 1: k %= n. WHY: same reduction logic, avoids wasted passes.
   Step 2: reverse the whole array. WHY: pushes the last k elements toward the
     front (in reversed internal order).
   Step 3: reverse [0..k-1]. WHY: fixes the order of the k front elements.
   Step 4: reverse [k..n-1]. WHY: fixes the order of the remaining block; the
     whole sequence is exactly rotate-left of (n-k), i.e. rotate-right by k.

 Two-pointer reverse:
   Step 1: lo = 0, hi = n-1. WHY: the outermost pair must swap first.
   Step 2: swap a[lo] and a[hi], then lo++, hi--. WHY: each swap fixes two
     positions and moves the pointers one step inward.
   Step 3: loop while lo < hi. WHY: once the pointers cross or meet, every
     element has been swapped exactly once; a lone middle element (odd n) needs
     no swap.

 VISUAL WALKTHROUGH: (reversal algorithm — each reverse step)
 Array {1,2,3,4,5}, rotate left k = 2  (2 % 5 = 2)
   step1 reverse [0..1]: [1,2,3,4,5] -> [2,1,3,4,5]
   step2 reverse [2..4]: [2,1,3,4,5] -> [2,1,5,4,3]
   step3 reverse [0..4]: [2,1,5,4,3] -> [3,4,5,1,2]
   Result [3,4,5,1,2] = left rotate by 2                      ✅

 Two-pointer narrowing on {1,2,3,4,5}:
   lo=0 hi=4 swap 1<->5 -> [5,2,3,4,1]
   lo=1 hi=3 swap 2<->4 -> [5,4,3,2,1]
   lo=2 hi=2 stop          [5,4,3,2,1]                        ✅

 DRY RUN: (line-by-line trace)
 Reverse {1,2,3} with two pointers:
   line | lo | hi | array     | action
   1    | 0  | 2  | [1,2,3]   | lo<hi true -> swap, lo=1, hi=1
   2    | 1  | 1  | [3,2,1]   | lo<hi false -> exit loop
   Output: [3,2,1]

 Rotate left {1,2,3,4,5} with k = 7:
   k %= n  ->  7 % 5 = 2, then the three reverses above:
   [1,2,3,4,5] -> [2,1,3,4,5] -> [2,1,5,4,3] -> [3,4,5,1,2]
   Output: [3,4,5,1,2]  (= rotate left by 7  ==  rotate left by 2)

 TIME COMPLEXITY CALCULATION:
 - Reverse extra array: one loop copying n elements = n steps -> O(n).
 - Reverse two-pointer: floor(n/2) swaps, each swap is constant work -> O(n).
 - Rotate left by 1: one pass shifting n-1 elements -> O(n).
 - Rotate left by k naive: k separate shift passes, each O(n) -> O(n*k).
 - Rotate by k extra array: one loop of n placements -> O(n).
 - Rotate by k reversal: three reverses over slices whose total length is n,
   so about n swaps of constant cost -> O(n).
 -> Time Complexity = O(n) for the best methods, O(n*k) for the naive method.

 SPACE COMPLEXITY CALCULATION:
 - Reverse extra array: allocates a second array of size n -> O(n).
 - Reverse two-pointer: only two index variables and a swap temp -> O(1).
 - Rotate left by 1: a single temp variable -> O(1).
 - Rotate left by k naive: single temp, in place -> O(1).
 - Rotate by k extra array: allocates a second array of size n -> O(n).
 - Rotate by k reversal: three in-place reverses, only a swap temp -> O(1).
 -> Space Complexity = O(1) for two-pointer and reversal, O(n) for extra-array.

 APPROACH COMPARISON:
 ┌─────────────────────────┬────────────────────────────┬────────────────────────────┐
 │ Approach                │ Time                       │ Space                       │
 ├─────────────────────────┼────────────────────────────┼────────────────────────────┤
 │ Reverse extra array     │ 1 copy pass, n steps  O(n) │ second array           O(n) │
 │ Reverse two-pointer     │ n/2 swaps            O(n)  │ in place edit          O(1) │
 │ Rotate left by 1        │ 1 shift pass          O(n) │ single temp            O(1) │
 │ Rotate by k naive       │ k shift passes      O(n*k) │ single temp            O(1) │
 │ Rotate by k extra array │ 1 mapping pass       O(n)  │ extra vector           O(n) │
 │ Rotate by k reversal    │ 3 reverse slices      O(n) │ in place edit          O(1) │
 └─────────────────────────┴────────────────────────────┴────────────────────────────┘
*/

// ══════════════ DEMO CODE (C++17, compile & run) ══════════════
#include <iostream>
#include <vector>

using namespace std;

// reverse extra array se — O(n) time, O(n) space
vector<int> reverseExtra(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        b[i] = a[n - 1 - i];                     // ulta order copy karo
    return b;
}

// two-pointer reverse — O(n) time, O(1) space (best)
void reverseTwoPointer(vector<int>& a) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        swap(a[lo], a[hi]);                       // ends ka swap karo
        ++lo; --hi;                               // andar ki taraf bado
    }
}

// rotate left by 1 — pehla element end par daalo
void rotateLeftBy1(vector<int>& a) {
    if (a.empty()) return;
    int temp = a[0];                              // pehla element bachao
    for (int i = 1; i < (int)a.size(); ++i)
        a[i - 1] = a[i];                          // baaki sab left shift
    a[(int)a.size() - 1] = temp;                  // temp ko end par rakho
}

// naive rotate left by k — k baar by-1 call, O(n*k) time, O(1) space
void rotateLeftNaive(vector<int>& a, int k) {
    int n = (int)a.size();
    if (n == 0) return;
    k %= n;                                       // k > n wala case handle
    for (int step = 0; step < k; ++step)
        rotateLeftBy1(a);
}

// extra array se rotate left by k — O(n) time, O(n) space
vector<int> rotateLeftExtra(const vector<int>& a, int k) {
    int n = (int)a.size();
    if (n == 0) return {};
    k %= n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        b[i] = a[(i + k) % n];                    // cyclic mapping
    return b;
}

// [l..r] inclusive range reverse helper
void reverseRange(vector<int>& a, int l, int r) {
    while (l < r) {
        swap(a[l], a[r]);
        ++l; --r;
    }
}

// REVERSAL ALGORITHM — rotate left by k — O(n) time, O(1) space (best)
void rotateLeftByK(vector<int>& a, int k) {
    int n = (int)a.size();
    if (n == 0) return;
    k %= n;
    reverseRange(a, 0, k - 1);      // pehle k elements reverse
    reverseRange(a, k, n - 1);      // baaki reverse
    reverseRange(a, 0, n - 1);      // whole reverse
}

// REVERSAL ALGORITHM — rotate right by k — reverse order of steps
void rotateRightByK(vector<int>& a, int k) {
    int n = (int)a.size();
    if (n == 0) return;
    k %= n;
    reverseRange(a, 0, n - 1);      // whole reverse
    reverseRange(a, 0, k - 1);      // pehle k elements reverse
    reverseRange(a, k, n - 1);      // baaki reverse
}

void printVec(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};

    cout << "1)  reverse two-pointer  : ";
    vector<int> r1 = a;
    reverseTwoPointer(r1);
    printVec(r1);                                  // [5 4 3 2 1]

    cout << "1b) reverse extra-array  : ";
    printVec(reverseExtra(a));                     // [5 4 3 2 1] same result

    cout << "2a) rotate left k=2 reversal: ";
    vector<int> l2 = a;
    rotateLeftByK(l2, 2);
    printVec(l2);                                  // [3 4 5 1 2]

    cout << "2b) rotate left k=2 naive : ";
    vector<int> ln = a;
    rotateLeftNaive(ln, 2);
    printVec(ln);                                  // [3 4 5 1 2] same result

    cout << "2c) rotate left k=2 extra  : ";
    printVec(rotateLeftExtra(a, 2));               // [3 4 5 1 2] same result

    cout << "3)  rotate RIGHT k=3       : ";
    vector<int> rk = a;
    rotateRightByK(rk, 3);
    printVec(rk);                                  // right-3 == left-2 -> [3 4 5 1 2]

    cout << "4)  rotate left k=12 (k%n) : ";
    vector<int> big = a;
    rotateLeftByK(big, 12);                        // 12 % 5 = 2
    printVec(big);                                 // [3 4 5 1 2]

    vector<int> emptyVec;
    rotateLeftByK(emptyVec, 2);                    // empty => no change
    cout << "5)  edge: empty, k=2       : ";
    printVec(emptyVec);

    vector<int> single = {7};
    rotateLeftByK(single, 5);                      // single element static
    cout << "6)  edge: single, k=5      : ";
    printVec(single);                              // [7]

    vector<int> k0 = a;
    rotateLeftByK(k0, 0);                          // k=0 => same array
    cout << "7)  edge: k=0               : ";
    printVec(k0);                                  // [1 2 3 4 5]

    vector<int> kn = a;
    rotateLeftByK(kn, 5);                          // k=n => same array
    cout << "8)  edge: k=n               : ";
    printVec(kn);                                  // [1 2 3 4 5]

    return 0;
}