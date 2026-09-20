/*
═══════════════════════════════════════════════
 std::unordered_set — HASH-BASED FAST UNIQUE STORAGE
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A banking app sends a 6-digit OTP to a user's phone. The server must
 verify "did this user submit the matching OTP?" within seconds — and
 the pool of valid OTPs is constantly giving new ones and expiring
 old ones. Order of OTPs does NOT matter at all; what matters is raw
 SPEED of insert + "is it present?" checks. A std::unordered_set is
 perfect: it hashes every OTP into a bucket, so lookups jump straight
 to the answer in constant average time. Another real case: a spell
 checker storing the 100k most common English words — "is this word
 in the dictionary?" must be answered in microseconds.

 📖 THEORY:
 - std::unordered_set stores UNIQUE elements but WITHOUT any sorted
   order. Order of iteration is arbitrary (depends on hashes + buckets).
 - Implementation: a HASH TABLE = an array of "buckets", plus a hash
   function that maps every element to one bucket index.
   hash(x) % tableSize  =  bucket of x.
 - Average case: insert/erase/find/count = O(1) — only hash + jump.
 - Worst case: many elements collide into the same bucket → linear
   chain → O(n). Hash functions are chosen to make this vanishingly rare.
 - Merge is fast but iteration order is NOT sorted (unlike std::set).
 - count(x) returns 0 or 1 (unique values) but the question is answered
   in one bucket visit, not a tree walk.

              ASCII: HASH TABLE with buckets (size = 7)
   ┌────────────────────────────────────────────────────────────┐
   │  unordered_set<int> us = {37, 22, 15, 29, 40, 6};          │
   │                                                            │
   │  hash(x) = x ; bucket = x % 7                              │
   │                                                            │
   │   index 0 │  →  [  ]                                       │
   │   index 1 │  →  [ 15 ] → [ 22 ]        (collision chain)  │
   │   index 2 │  →  [  ]                                       │
   │   index 3 │  →  [  ]                                       │
   │   index 4 │  →  [  ]                                       │
   │   index 5 │  →  [ 40 ]                                     │
   │   index 6 │  →  [ 6 ]  → [ 29 ] → [ 37 ]   (3-chain)       │
   │                                                            │
   │  find(29): 29%7 = 1?? no → 29%7 = 1.. let me recompute:    │
   │  37%7=2, 22%7=1, 15%7=1, 29%7=1, 40%7=5, 6%7=6              │
   │                                                            │
   │   index 0 │  [ ]        index 4 │ [ ]                      │
   │   index 1 │  [22]→[15]→[29]     index 5 │ [40]             │
   │   index 2 │  [37]        index 6 │ [6]                     │
   │   index 3 │  [ ]                                            │
   │                                                            │
   │  find(29): compute 29%7=1 → walk tiny chain → FOUND instantly│
   │  Average lookups hit their bucket in O(1) ✅               │
   └────────────────────────────────────────────────────────────┘

 WHEN TO USE std::unordered_set:
 - You only need "does it exist?" / "add it" / "remove it" — FAST.
 - You do NOT need sorted order or lower_bound/upper_bound queries.
 - When lazy: C++11+ hashing is built-in for int, string, double.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Compute bucket = hash(value) % tableSize. WHY: hash maps the
         whole value space into a small range of bucket indices, like
         a library catalog (Dewey number) pointing to a shelf.
 Step 2: Look inside that bucket (chaining: a small list). WHY: collisions
         are possible; chaining lets two values share one bucket safely.
 Step 3: insert: if value already in bucket → ignore (unique). Else append.
         WHY: keep the 0/1 uniqueness invariant.
 Step 4: find/count: same hash → same bucket → scan tiny chain. WHY: O(1)
         average, bucket chain is short when load factor is small.
 Step 5: erase: hash → bucket → remove node. WHY: same O(1) path.
 Step 6: When too many elements (load factor > threshold), the table
         REHASHES: grows and re-distributes all elements. This is the
         only O(n) amortized event; it is amortized O(1) on average.
 Step 7: Iteration just walks buckets → ARBITRARY order, not sorted.
         WHY: order is decided by hashes, not by value magnitude.

 VISUAL WALKTHROUGH (insert 20, 8, 13, 20 — table size 7, hash = x%7):
   ┌────────────────────────────────────────────────────────────┐
   │ insert 20 → 20%7 = 6 → bucket 6: [20]                      │
   │ insert 8  →  8%7 = 1 → bucket 1: [8]                       │
   │ insert 13 → 13%7 = 6 → bucket 6: [20]→[13]   (collision)   │
   │ insert 20 → 20%7 = 6 → ALREADY in bucket 6 → IGNORED       │
   │                                                            │
   │ Final: bucket1: [8]   bucket6: [20]→[13]   size=3          │
   │ count(20)=1 (skips the chain in O(1))                      │
   └────────────────────────────────────────────────────────────┘

 DRY RUN (demo input: 30 10 20 30 40 10):
   op           | bucket(30%7=2) ...  | size | result
   -------------|---------------------|------|-----------------
   insert 30    | b2: [30]            |  1   |
   insert 10    | b3: [10]            |  2   |
   insert 20    | b6: [20]            |  3   |
   insert 30    | b2 already has 30 → IGNORE | 3 | ✅ unique
   insert 40    | b5: [40]            |  4   |
   insert 10    | b3 already has 10 → IGNORE | 4 | ✅ unique
   count(30)    | hash(30)=bucket2, found → 1 |   | fast
   count(70)    | hash(70)=bucket0 empty → 0  |   |
   find(70)     | bucket0 empty → end()        |   |
   erase(10)    | b3: [10] removed → size 3    |   |
   iteration    | order depends on bucket walk — NOT sorted ⚠️

 TIME COMPLEXITY CALCULATION:
 - hash(value): one constant-time computation.
 - bucket index: one modulo → constant.
 - With a good hash function and a sensible table size, the average
   bucket chain length stays a small constant (load factor ~0.7–1).
 - insert/find/count/erase: hash + constant chain scan = O(1) average.
 - Worst case (all values same bucket): chain length n → O(n).
 - Rehash: O(n) work but happens ~log n times over n inserts →
   amortized over all inserts stays O(1) per insert.
 - Demo: 6 inserts, each O(1) average → O(6) ≈ O(n).
 → Time Complexity = O(1) average per op (O(n) worst for collisions).

 SPACE COMPLEXITY CALCULATION:
 - Bucket array of size B (kept proportional to n).
 - Each element stored once in its bucket chain → n slots.
 - Distinct count k ≤ n; duplicates stored once → k entries.
 → Space Complexity = O(B + k) = O(n) overall (B ≈ n for load factor).

 APPROACH COMPARISON: unordered_set vs set
 ┌──────────────────┬──────────────────────────┬──────────────────────────┐
 │                  │ std::set (tree)          │ std::unordered_set       │
 ├──────────────────┼──────────────────────────┼──────────────────────────┤
 │ order of data    │ SORTED (in-order walk)   │ arbitrary (hash order)   │
 │ insert           │ O(log n)                 │ O(1) average             │
 │ find/count       │ O(log n)                 │ O(1) average             │
 │ lower/upper_bound│ YES — built-in           │ NO (no order concept)    │
 │ iteration        │ ascending                │ bucket order (random-ish)│
 │ memory           │ per-node pointers        │ bucket array + chains    │
 │ best for         │ order / ranges matter    │ pure membership + speed  │
 └──────────────────┴──────────────────────────┴──────────────────────────┘
 Conclusion: membership-heavy workloads (spell check, OTP, visited-set
 in graphs) → unordered_set. Needing min/max/sorted/range queries → set.

 GOTCHA ⚠️: std::unordered_set does NOT come for free via <iostream>
 or <vector>. You MUST #include <unordered_set> explicitly. Hona
 chahiye, warna "unordered_set: not a member of std" jaise compile
 error aayega. Kabhi bhi transitive includes par bharosa mat karo.
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    // demo 1: OTP storage — quick "is present?" checks
    cout << "===== DEMO 1: OTP STORAGE (fast lookup) =====" << endl;
    unordered_set<int> validOtps;           // saare valid OTPs yahan hain

    validOtps.insert(482913);               // OTP 1 generate+store
    validOtps.insert(738102);               // OTP 2
    validOtps.insert(913845);               // OTP 3

    int userEntered = 738102;
    if (validOtps.count(userEntered)) {     // O(1) — turant pata chal gaya
        cout << "OTP " << userEntered << " VALID ✅" << endl;
        validOtps.erase(userEntered);       // use ke baad consum ho gaya
    } else {
        cout << "OTP invalid ❌" << endl;
    }

    int fakeOtp = 111111;
    cout << "count(" << fakeOtp << ") = " << validOtps.count(fakeOtp)
         << " (0 = not valid)" << endl;

    // demo 2: insert + duplicates ignored + find
    cout << "\n===== DEMO 2: INSERT WITH DUPLICATES =====" << endl;
    unordered_set<int> us;
    int data[] = {30, 10, 20, 30, 40, 10};
    for (int v : data) us.insert(v);        // duplicate ignore hoga
    cout << "size after inserting 30,10,20,30,40,10 = " << us.size() << endl;

    auto it = us.find(20);                  // find() mil gaya
    if (it != us.end()) cout << "find(20) -> " << *it << endl;
    it = us.find(99);
    if (it == us.end()) cout << "find(99) -> END() (not present)" << endl;

    // demo 3: iteration — order ARBITRARY
    cout << "\n===== DEMO 3: ITERATION (order arbitrary!) =====" << endl;
    cout << "Elements (order galat lag sakti hai — hash order): ";
    for (int v : us) cout << v << " ";
    cout << "\nNote: yeh sorted nahi hai aur har run par badal sakti hai." << endl;

    // demo 4: erase
    us.erase(30);
    cout << "\nAfter erase(30), size = " << us.size()
         << ", count(30) = " << us.count(30) << endl;

    // EDGE CASES
    cout << "\n===== EDGE CASES =====" << endl;
    unordered_set<int> emptyUs;
    cout << "empty size: " << emptyUs.size() << endl;
    cout << "count on empty: " << emptyUs.count(42) << endl;
    cout << "erase absent value is a no-op (safe): done, size still "
         << emptyUs.size() << endl;
    emptyUs.insert(1);
    cout << "single element set, empty()? " << (emptyUs.empty() ? "yes" : "no")
         << endl;
    emptyUs.clear();                        // sab kuch hata do
    cout << "after clear(): size = " << emptyUs.size() << endl;

    cout << "\nDemo complete. O(1) average membership — order NOT guaranteed." << endl;
    return 0;
}