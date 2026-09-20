/*
═══════════════════════════════════════════════
 std::unordered_map — HASH-BASED KEY→VALUE (Average O(1))
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A bank sends a one-time password (OTP) to a customer's mobile number.
 The server stores "mobile number → OTP" and must verify "is this the
 correct OTP for 98765xxxx?" within seconds — and once verified, the
 entry must vanish instantly. Nobody needs the OTPs sorted; the only
 thing that matters is RAW SPEED of insert + "is it present?". A
 phone's browser cache works the same way: "URL → already-downloaded
 page content", so revisiting a site skips the re-download. That jump-
 straight-to-the-value behaviour with no order required is exactly the
 avg O(1) superpower of std::unordered_map.

 📖 THEORY:
 - std::unordered_map stores UNIQUE KEY→VALUE pairs WITHOUT any sorted
   order. The interface is exactly the same as map — just not sorted.
 - Each element is a node holding pair<const Key, Value>; the KEY is const.
 - Implementation: HASH TABLE = array of "buckets" + hash function.
   bucket = hash(key) % tableSize ; each bucket holds a small chain of pairs.
 - Average case: m[k]/find/insert/erase = O(1) — hash + jump + O(1) scan.
 - Worst case: all keys land in the same bucket → one long chain → O(n).
   So keep hash quality and load factor in mind (reserve/max_load_factor).
 - operator[] is also a trap: an unknown key creates a DEFAULT entry
   (int → 0). "Use find/count for READING, [] for WRITING".
 - count(k) → 0 or 1 (key unique). find(k) → iterator or end().
 - lower_bound/upper_bound are NOT available — order has no meaning here.
 - Iteration is ARBITRARY — determined by the hash + bucket walk.

                    ASCII: HASH TABLE storing {key:value} pairs
   ┌────────────────────────────────────────────────────────────┐
   │  unordered_map<int,int> um;  um[37]=1; um[22]=3; um[15]=2;  │
   │                              um[40]=4;                      │
   │  hash(k) = k ;  bucket = k % 7                              │
   │                                                            │
   │   index 0 │ [ ]                                            │
   │   index 1 │ [22:3] → [15:2] → [37:1]   (3-pair chain ⚠️)   │
   │   index 2 │ [ ]                                            │
   │   index 3 │ [ ]                                            │
   │   index 4 │ [ ]                                            │
   │   index 5 │ [40:4]                                         │
   │   index 6 │ [ ]                                            │
   │                                                            │
   │  22%7=1, 15%7=1, 37%7=1 → collision chain in bucket 1      │
│ find(15): hash → bucket 1 → 2-step chain scan → FOUND       │
 │ Average chains are short → O(1) per op ✅                │
   └────────────────────────────────────────────────────────────┘

 WHEN TO USE std::unordered_map:
 - You need fast key→value and could not care about sorted order.
 - Frequency counting, group-by-key, memoization, two-sum.
 - In CP always use a SafeHash + reserve (anti-hash-attack).
 - Small continuous int keys (0..999) → vector<int> is faster.

 🧠 LOGIC — STEP BY STEP:
Step 1: bucket = hash(key) % tableSize. WHY: the hash maps the whole key
         value-space into a small bucket-index space (a drawer number).
Step 2: Search the chain in that bucket (tiny linear scan). WHY:
         collisions are possible — chaining keeps them safe.
Step 3: m[k]=v — missing key → build default {k,0} first, then write the value.
         WHY: operator[] returns a reference → freq[x]++ is a one-liner.
Step 4: find(k)/count(k) — same hash → same bucket → O(1) scan.
         WHY: "to read, use count/find — otherwise a default entry gets
         created" ⚠️
Step 5: erase(k) — hash → bucket → remove node, same O(1) path.
Step 6: load factor rises → REHASH: table grows + everything redistributes.
         WHY: it keeps chains short; the cost is amortized across
         all inserts, so the average O(1) stays intact.
Step 7: Iteration = bucket walk → ARBITRARY order. WHY: the hash
         decides the order, not the value magnitude.

 VISUAL WALKTHROUGH: char freq, keys "mississippi" = m,i,s,p (size 7)
   ┌────────────────────────────────────────────────────────────┐
   │ insert 'm' → hash%7=4 → bucket 4: [m:1]                    │
   │ insert 'i' → hash%7=0 → bucket 0: [i:1]                    │
   │ insert 's' → hash%7=3 → bucket 3: [s:1]                    │
   │ insert 'p' → hash%7=1 → bucket 1: [p:1]                    │
   │ 's' again  → bucket 3 exists → ++ : [s:2]  (no new node)   │
   │ 'i' again  → bucket 0 → ++ : [i:2]                         │
   │                                                            │
│ Final buckets (this order is ONLY for the demo — a real run        │
 │ may differ because of the hashes):                                 │
 │   bucket0:[i:4] bucket1:[p:2] bucket3:[s:4] bucket4:[m:1]          │
 │ Iteration could be in a different order on another run ⚠️          │
   └────────────────────────────────────────────────────────────┘

 DRY RUN (demo: "mississippi" = m,i,s,s,i,s,s,i,p,p,i):
   step | op               | map state (kram arbitrary) | size | note
   -----|------------------|--------------------------- |------|-------------
#1   | freq['m']++      | m:1                       |  1   | first time → 0+1
 #2   | freq['i']++      | i:1, m:1                  |  2   | first time
 #3   | freq['s']++      | i:1, m:1, s:1             |  3   | first time
 #4   | freq['s']++      | i:1, m:1, s:2             |  3   | present → 1+1
 #5   | freq['i']++      | i:2, m:1, s:2             |  3   |
 #6   | freq['s']++      | i:2, m:1, s:3             |  3   |
 #7   | freq['s']++      | i:2, m:1, s:4             |  3   |
 #8   | freq['i']++      | i:3, m:1, s:4             |  3   |
 #9   | freq['p']++      | i:3, m:1, p:1, s:4        |  4   | first time
 #10  | freq['p']++      | i:3, m:1, p:2, s:4        |  4   | present → 1+1
 #11  | freq['i']++      | i:4, m:1, p:2, s:4        |  4   | FINAL counts
 #12  | freq.find('p')   | it → (p,2)  O(1)          |  4   |
 #13  | freq.count('q')  | 0 — no entry created     |  4   | safe read
 #14  | freq.erase('m')  | m gone                    |  3   |
 #15  | freq['z']        | z:0 default entry made    |  4   | ⚠️ trap
 Iteration order is NOT predictable/sorted at any step ⚠️

 TIME COMPLEXITY CALCULATION:
 - hash(key) + modulo = constant work.
 - load factor = n/buckets; with chaining the average chain length ≈ load factor,
   which is a small constant (kept ~0.7–1 by resizing).
 - find/count/insert = hash → bucket → O(1)-ish chain scan = O(1) avg.
 - Rehash = O(n) but happens ~log n times over n inserts → amortized
   O(1) per insert.
 - Worst case: every key in the same bucket → one long chain → O(n).
 - Demo: 11 chars × O(1) = O(n). Frequency counter total = O(n).
 → Time Complexity = O(1) average per op (O(n) worst — collisions).

 SPACE COMPLEXITY CALCULATION:
 - Bucket array size B (kept proportional to n, ≈ O(n)).
 - Each distinct key has one node = pair + pointers → k slots total.
 - Duplicates create zero new entries — only the value updates.
 - Demo: distinct keys k = 4 (i,m,p,s) + 'z' entry = k = 5.
 → Space Complexity = O(B + k) = O(n) overall (B ∝ n).

 APPROACH COMPARISON: unordered_map vs map vs vector<int>
 ┌───────────────────────┬──────────────────────┬──────────────────────┐
 │                       │ std::unordered_map   │ std::map (tree)      │
 ├───────────────────────┼──────────────────────┼──────────────────────┤
 │ internal              │ hash table           │ red-black tree       │
 │ m[k]/find/erase       │ O(1) average         │ O(log n)             │
 │ worst case            │ O(n) collisions      │ O(log n) guaranteed  │
 │ order of iteration    │ arbitrary            │ SORTED               │
 │ lower/upper_bound     │ NO                   │ YES                  │
 │ reserve() known-size  │ YES (saves rehash)   │ NO                   │
 │ best for              │ pure-speed lookups   │ order/range queries  │
 └───────────────────────┴──────────────────────┴──────────────────────┘
vector<int> bonus: if the key is a small continuous int (0..999), skip the hash
  entirely — use a direct index, 6× faster (measured), memory is contiguous.
  "Small int key → vector; scattered key → hash map; order → tree".

GOTCHA ⚠️: explicitly include <unordered_map> — do not rely on a
transitive include. NEVER check with "if (m[k])" — that creates an entry;
use find()/count(). In CP do not run without a SafeHash. ⚠️
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // demo 1: character frequency counter — output UNSORTED
    cout << "===== DEMO 1: CHARACTER FREQUENCY (order arbitrary!) =====" << endl;
    string s = "mississippi";
    unordered_map<char, int> freq;             // khali unordered_map
    for (char c : s) freq[c]++;                // nayi key → default 0, phir ++
    for (const auto& e : freq)               // iterate — order arbitrary (hash)!
        cout << "freq['" << e.first << "'] = " << e.second << endl;
    cout << "(output order hash ke hisaab se hai — har run / compiler me\n"
         << " badal sakti hai, koi sorted guarantee nahi. ⚠️)" << endl;

    // demo 2: find / count / erase
    cout << "\n===== DEMO 2: FIND / COUNT / ERASE =====" << endl;
    auto it = freq.find('p');                  // O(1) average
    if (it != freq.end())
        cout << "find('p') -> " << it->first << ":" << it->second << endl;
    it = freq.find('q');
    if (it == freq.end())
        cout << "find('q') -> end() (entry NAHI bani)" << endl;
    cout << "count('i') = " << freq.count('i')
         << " , count('q') = " << freq.count('q')
         << " (count se entry NAHI banti ✅)" << endl;
    freq.erase('m');                            // O(1) avg
    cout << "erase('m') ke baad count('m') = " << freq.count('m') << endl;

    // demo 3: operator[] UNKNOWN KEY — entry ban jati hai!
    cout << "\n===== DEMO 3: operator[] UNKNOWN KEY =====" << endl;
    cout << "freq['z'] = " << freq['z']         // 'z' nahi tha → default 0
         << " (default 0), ab size = " << freq.size()
         << "  <-- 'z' ki ENTRY ban gayi! ⚠️" << endl;

    // demo 4: cache pattern — URL → bytes, evict with erase
    cout << "\n===== DEMO 4: CACHE (URL -> bytes) =====" << endl;
    unordered_map<string, int> cache;
    cache["/home"] = 2048;                      // page download + store
    cache["/about"] = 960;
    cout << "cache size = " << cache.size()
         << " , /home = " << cache["/home"] << " bytes" << endl;
    cache.erase("/home");                        // evict huya
    cout << "after evict: count(/home) = " << cache.count("/home") << endl;

    // EDGE CASES
    cout << "\n===== EDGE CASES =====" << endl;
    unordered_map<int, int> emptyMap;
    cout << "empty map size: " << emptyMap.size() << endl;
    cout << "count on empty: " << emptyMap.count(42) << endl;
    if (emptyMap.find(42) == emptyMap.end())
        cout << "find on empty -> end() (dereference UB hai!)" << endl;
    int v9 = emptyMap[9];                       // entry default 0 se BAN gayi
    cout << "emptyMap[9] = " << v9 << " -> ab size = "
         << emptyMap.size() << " (default entry ban gayi)" << endl;

    cout << "\nDemo complete. Average O(1) ops, order NOT guaranteed." << endl;
    return 0;
}