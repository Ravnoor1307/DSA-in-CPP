/*
═══════════════════════════════════════════════
 SEARCHING ALGORITHMS
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you own a phone book with 1000 pages sorted by name. If you want
 "Ravnoor", you do NOT flip from page 1 one-by-one — you open the middle,
 check if "Ravnoor" is before or after that page, and throw away half the
 book each time. That is binary search. But if the book were NOT sorted —
 names jumbled everywhere — you would have no choice but to check every
 page from the beginning, page by page, until the name appears. That is
 linear search. One saves minutes, the other costs you the whole afternoon.
 Binary search rewards sorted data; linear search works even on chaos.

 📖 THEORY: (pure English)
 - LINEAR SEARCH: walk the array from index 0 forward, comparing each
   element to the target. Stop when found (return index) or run out
   (return -1). No precondition needed — works on unsorted data.
 - BINARY SEARCH: on a SORTED array, repeatedly compare the middle element
   with the target. If equal → found. If target < mid → search left half
   ONLY. If target > mid → search right half ONLY. Each step discards
   half the remaining range, so we reach the answer in log₂n steps.
 - PRECONDITION: the array MUST be sorted (ascending). Using binary search
   on an unsorted array is a classic bug — the mid check gives no reliable
   signal about which half holds the target.
 - KEY POINTS:
   * Low/high are INCLUSIVE bounds. Loop condition `low <= high` matters.
   * mid = low + (high - low) / 2  ==  (low + high) / 2 mathematically,
     BUT avoids integer overflow when low + high exceeds INT_MAX in C++
     (that sum can wrap to a negative/truncated value before division).
   * Recursive variant wastes O(log n) stack space; iterative is O(1).
   * First/last occurrence are binary search with a "keep searching after
     a match" twist (lower_bound / upper_bound idea).
   * COUNT OCCURRENCES = lastIndex - firstIndex + 1. No scanning needed.
   * BINARY SEARCH ON ANSWER: if the predicate "is x ≥ target?" is
     monotonic (false...false, true...true), binary search the VALUE
     space intead of an array — sqrt, min-max partitioning, e.g.
   - ASCII DIAGRAM — array halving on [1 3 5 7 9], looking for 9:

        [ 1  3  5  7  9 ]   low=0 high=4
               ^ mid=2 → 5
      target 9 > 5  →  now low=3 high=4
        [ 1  3  5 | 7  9 ]
                     ^ mid=3 → 7
      target 9 > 7  →  now low=4 high=4
        [ 1  3  5 | 7 | 9 ]
                       ^ mid=4 → 9 ✓ FOUND

   - WHEN TO USE:
     * one-shot lookup in a fixed sorted array → binary search.
     * tiny array (n < ~10) or unsorted data → linear search (overhead
       of sorting is not worth it).
     * many repeated queries on the same sorted data → binary search.
     * "find the minimum value such that condition C holds" → BS on answer.

 🧠 LOGIC — STEP BY STEP: (pure English with WHY for each step)
 Step 1: low = 0, high = n - 1.
        WHY: these are the inclusive bounds of the still-possible window.
        high must be n-1, NOT n, so indices are always valid.
 Step 2: mid = low + (high - low) / 2.
        WHY: equals (low+high)/2 but NEVER overflows — if low+high would
        pass INT_MAX, the subtraction form keeps every intermediate in
        range. This is the standard overflow-proof C++ idiom.
 Step 3: if arr[mid] == target → return mid.
        WHY: exact hit — done.
 Step 4: if arr[mid] < target → low = mid + 1.
        WHY: sorted, so everything left of mid is also < target; that
        whole half is useless. +1 because mid was already rejected.
 Step 5: else (arr[mid] > target) → high = mid - 1.
        WHY: everything right of mid is > target; discard it. -1 because
        mid was already rejected.
 Step 6: repeat while low <= high; if low > high → return -1.
        WHY: window collapsed (empty), target does not exist. The `<=`
        is essential — when low == high one candidate remains and must
        still be tested.

 VISUAL WALKTHROUGH: (full halving search of 9 in [1,3,5,7,9,11])

  index:   0   1   2   3   4    5
  value: [ 1   3   5   7   9   11 ]
  target = 9

  Step 1   low=0  high=5  mid=(0+5)/2=2  → arr[2]=5   5 < 9 → go RIGHT
  Step 2   low=3  high=5  mid=(3+5)/2=4  → arr[4]=9   9 == 9 → FOUND ✅

  Visual:   [ 1   3   5  | 7   9   11 ]
                         └── target in RIGHT half, left 3 dropped
            [ 1 3 5 | 7  | 9   11 ]
                            ^ mid=4 → match!

 DRY RUN: (complete trace: search 9 in [1,3,5,7,9], n=5)

  Iteration | low | high | mid | arr[mid] | decision
  ----------|-----|------|-----|----------|-----------------
    1       |  0  |   4  |  2  |    5     | 5 < 9 → low = 3
    2       |  3  |   4  |  3  |    7     | 7 < 9 → low = 4
    3       |  4  |   4  |  4  |    9     | 9 == 9 → return 4 ✅

  Steps = 3 = log₂(5)+1 → O(log n) confirmed.

 TIME COMPLEXITY CALCULATION:
 - LINEAR SEARCH: worst case the target is at the last index (or absent),
   so all n elements are compared once → n comparisons → O(n).
 - BINARY SEARCH — full proof:
     After the 1st step the searchable window shrinks from n to n/2.
     After the 2nd step: n/4. After the k-th step: n / 2^k.
     The search must end when exactly 1 element remains:
          n / 2^k = 1
     →  n = 2^k
     →  take log₂ on BOTH sides:
          log₂(n) = log₂(2^k)
          log₂(2^k) = k·log₂(2) = k·1 = k
     →  k = log₂(n)
     →  comparisons ≈ log₂(n) (each step is O(1) work)
 → Time Complexity = O(log n) for binary search, O(n) for linear search

 SPACE COMPLEXITY CALCULATION:
 - Iterative binary/linear search use only low, high, mid variables —
   constant extra memory, independent of n → O(1).
 - Recursive binary search: each call pushes a frame; depth of recursion
   equals the number of halvings = log₂(n) → call stack O(log n),
   NOT O(1).
 - No auxiliary arrays are allocated in any variant.
 → Space Complexity = O(1) iterative; O(log n) recursive; O(1) linear

 APPROACH COMPARISON: (real table — linear vs binary; iterative vs recursive)
 ┌────────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Criteria           │ Linear Search                │ Binary Search                │
 ├────────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ Array requirement  │ None (unsorted OK)           │ MUST be sorted               │
 │ Time complexity    │ O(n)  (n comparisons worst)  │ O(log n)  (n/2^k=1→k=log₂n)  │
 │ Space complexity   │ O(1)                         │ O(1) iter / O(log n) rec     │
 │ Best use case      │ small/unsorted, single query │ big sorted, many queries     │
 │ Implementation     │ 1 simple loop                │ 2-pointer + mid trick        │
 └────────────────────┴──────────────────────────────┴──────────────────────────────┘

 ┌────────────────────┬──────────────────────────────┴──────────────┐
 │ Iterative vs Rec  │ Iterative                    │ Recursive    │
 ├────────────────────┼──────────────────────────────┼──────────────┤
 │ Space              │ O(1)                          │ O(log n)     │
 │ Risk               │ none                          │ stack overflow│
 │ Readability        │ a bit verbose                 │ clean, short │
 └────────────────────┴──────────────────────────────┴──────────────┘
*/

#include <iostream>
#include <vector>
using namespace std;

// ---------- LINEAR SEARCH (unsorted friendly) ----------
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) { // har index check karo
        if (arr[i] == target) return i;         // mil gaya → index return
    }
    return -1;                                  // nahi mila
}

// ---------- BINARY SEARCH : iterative ----------
int binarySearchIterative(const vector<int>& arr, int target) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high) {                       // window empty hone tak
        int mid = low + (high - low) / 2;       // overflow-safe mid
        if (arr[mid] == target) return mid;     // exact hit
        else if (arr[mid] < target) low = mid + 1;   // right half
        else high = mid - 1;                    // left half
    }
    return -1;                                  // nahi mila
}

// ---------- BINARY SEARCH : recursive ----------
int binarySearchRecursive(const vector<int>& arr, int target, int low, int high) {
    if (low > high) return -1;                  // base case: khaali window
    int mid = low + (high - low) / 2;           // overflow-safe mid
    if (arr[mid] == target) return mid;         // mil gaya
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, target, mid + 1, high); // right
    else
        return binarySearchRecursive(arr, target, low, mid - 1);  // left
}

// ---------- FIRST OCCURRENCE (leftmost / lower_bound idea) ----------
int firstOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = (int)arr.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            ans = mid;          // candidate mila, par aur left ho sakta hai
            high = mid - 1;     // isliye left side aur search karo
        } else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return ans;                 // leftmost index (ya -1)
}

// ---------- LAST OCCURRENCE (rightmost / upper_bound idea) ----------
int lastOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = (int)arr.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            ans = mid;          // candidate mila, par aur right ho sakta hai
            low = mid + 1;      // isliye right side aur search karo
        } else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return ans;                 // rightmost index (ya -1)
}

// ---------- COUNT OCCURRENCES = last - first + 1 ----------
int countOccurrences(const vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if (first == -1) return 0;                  // bilkul exist nahi karta
    int last = lastOccurrence(arr, target);
    return last - first + 1;                    // range ka size hi count hai
}

// ---------- BINARY SEARCH ON ANSWER: sqrt ----------
int sqrtBinarySearch(int x) {
    if (x < 2) return x;                        // 0 aur 1 ka sqrt khud hai
    int low = 1, high = x, ans = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((long long)mid * mid <= x) {        // predicate: kya mid² ≤ x?
            ans = mid;                          // mid kaam karta hai, chhota ho geometry
            low = mid + 1;                      // bada mid try karo
        } else {
            high = mid - 1;                     // mid² bahut bada → chhota karo
        }
    }
    return ans;                                 // floor(sqrt(x))
}

int main() {
    cout << "================= SEARCHING ALGORITHMS DEMO =================\n\n";

    // --- 1) Linear search on unsorted array (target at index 4) ---
    vector<int> lin = {11, 4, 7, 2, 9};         // unsorted → binary search nahi
    cout << "1) Linear Search:\n";
    cout << "   array: [11, 4, 7, 2, 9], target = 9\n";
    cout << "   index found = " << linearSearch(lin, 9) << "  (expect 4)\n";
    cout << "   target absent (99) -> " << linearSearch(lin, 99) << "  (expect -1)\n\n";

    // --- 2) Binary search iterative on sorted array ---
    vector<int> sorted = {1, 3, 5, 7, 9, 11};
    cout << "2) Binary Search (iterative):\n";
    cout << "   array: [1, 3, 5, 7, 9, 11], target = 9\n";
    cout << "   index found = " << binarySearchIterative(sorted, 9) << "  (expect 4)\n";
    cout << "   target at first (1) -> " << binarySearchIterative(sorted, 1) << "  (expect 0)\n";
    cout << "   target at last (11) -> " << binarySearchIterative(sorted, 11) << "  (expect 5)\n";
    cout << "   target absent (6) -> " << binarySearchIterative(sorted, 6) << "  (expect -1)\n\n";

    // --- 3) Binary search recursive ---
    cout << "3) Binary Search (recursive):\n";
    cout << "   target = 7 -> index "
         << binarySearchRecursive(sorted, 7, 0, (int)sorted.size() - 1)
         << "  (expect 3)\n";
    cout << "   target = 100 (absent) -> "
         << binarySearchRecursive(sorted, 100, 0, (int)sorted.size() - 1)
         << "  (expect -1)\n\n";

    // --- 4) First & last occurrence with duplicates ---
    vector<int> dup = {1, 2, 2, 2, 3, 4, 4, 5};
    cout << "4) First / Last Occurrence:\n";
    cout << "   array: [1, 2, 2, 2, 3, 4, 4, 5]\n";
    cout << "   first occurrence of 2 -> " << firstOccurrence(dup, 2) << "  (expect 1)\n";
    cout << "   last  occurrence of 2 -> " << lastOccurrence(dup, 2) << "  (expect 3)\n";
    cout << "   first occurrence of 4 -> " << firstOccurrence(dup, 4) << "  (expect 5)\n";
    cout << "   last  occurrence of 4 -> " << lastOccurrence(dup, 4) << "  (expect 6)\n";
    cout << "   absent target (9)     -> " << firstOccurrence(dup, 9) << "  (expect -1)\n\n";

    // --- 5) Count occurrences ---
    cout << "5) Count Occurrences (last - first + 1):\n";
    cout << "   count of 2 in dup -> " << countOccurrences(dup, 2) << "  (expect 3)\n";
    cout << "   count of 4 in dup -> " << countOccurrences(dup, 4) << "  (expect 2)\n";
    cout << "   count of 7 in dup -> " << countOccurrences(dup, 7) << "  (expect 0, absent)\n\n";

    // --- 6) Binary search on answer: sqrt ---
    cout << "6) Binary Search ON ANSWER — sqrt:\n";
    cout << "   sqrt(16) = " << sqrtBinarySearch(16) << "  (expect 4)\n";
    cout << "   sqrt(27) = " << sqrtBinarySearch(27) << "  (expect 5, floor)\n";
    cout << "   sqrt(0)  = " << sqrtBinarySearch(0)  << "  (expect 0)\n";
    cout << "   sqrt(1)  = " << sqrtBinarySearch(1)  << "  (expect 1)\n";
    cout << "   sqrt(100)= " << sqrtBinarySearch(100)<< "  (expect 10)\n\n";

    // --- 7) Empty array edge case ---
    vector<int> empty = {};
    cout << "7) Edge case — EMPTY array:\n";
    cout << "   linear search -> " << linearSearch(empty, 5) << "  (expect -1)\n";
    cout << "   binary search -> " << binarySearchIterative(empty, 5) << "  (expect -1)\n\n";

    // --- 8) mid overflow note (conceptual, no lint runs needed) ---
    cout << "8) mid formula note:\n";
    cout << "   low + (high-low)/2 === (low+high)/2 mathematically,\n";
    cout << "   but never overflows even if low+high > INT_MAX.\n";

    cout << "\n===========================================================\n";
    return 0;
}