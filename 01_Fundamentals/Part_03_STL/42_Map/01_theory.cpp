/*
═══════════════════════════════════════════════
 std::map — SORTED KEY→VALUE STORAGE (Red-Black Tree)
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine your phone's contact list. You store each contact as a NAME
 → NUMBER pair, and the app always shows everyone alphabetically:
 you type "Rahul, Amit, Priya, Zoya" but the list comes out sorted as
 Amit, Priya, Rahul, Zoya. A dictionary works the same way — every
 WORD has a MEANING, and you can jump straight to any word because the
 whole book is alphabetically ordered. Even a booking system that
 counts "how many tickets sold per movie" prints stats in sorted movie
 name order. In every case two things matter: the KEY (name/word) is
 unique and the KEYS stay SORTED automatically. That is exactly what
 std::map gives you.

 📖 THEORY:
 - std::map stores KEY→VALUE pairs. Each element is a node that
   holds a pair<const Key, Value> — the KEY is const (read-only).
 - Keys stay SORTED automatically (default: ascending via <).
 - Internally it is a RED-BLACK TREE = self-balancing binary search
   tree; every operation walks one root→leaf path = O(log n).
 - operator[] : m[k] returns a REFERENCE to the value. If key k is
   missing, it first creates a DEFAULT entry (int → 0), then returns
   a reference to it. "Even a mere read creates an entry" — the
   biggest trap. ⚠️
 - insert({k,v}) / emplace: means "insert ONLY if absent". It does
   NOT change the old value. insert_or_assign (C++17) overwrites.
 - find(k) → iterator to the element, or end() if absent.
   count(k) → 0 ya 1. at(k) → value, missing pe exception throw.
 - erase(k) by key / erase(it) by iterator / in a loop use `it = m.erase(it)`.
 - Iteration = IN-ORDER tree walk → keys always come out SORTED.

                            ASCII: RED-BLACK TREE of {key,value}
   ┌──────────────────────────────────────────────────────────────┐
   │  map<string,int> pb;                                         │
   │  pb["Rahul"]=90; pb["Amit"]=70; pb["Priya"]=80; pb["Zoya"]=95;│
   │                                                              │
   │                       {Priya: 80}                            │
   │                      /            \                          │
   │            {Amit: 70}            {Rahul: 90}                 │
   │                                      \                       │
   │                                     {Zoya: 95}               │
   │                                                              │
   │  In-order walk (left → root → right) = SORTED:               │
   │     {Amit:70} {Priya:80} {Rahul:90} {Zoya:95}  ✅           │
   │  find("Rahul"): root {Priya} → right {Rahul} — 1 guided step │
   └──────────────────────────────────────────────────────────────┘

 WHEN TO USE std::map:
 - You need KEY→VALUE pairs AND the keys still sorted.
 - You need lower_bound/upper_bound queries (next/prev event).
 - You have a custom key (struct) — only operator< is needed, no hash.
 - You need a worst-case O(log n) guarantee (no fear of hash attacks).

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create the map. WHY: we need key→value and sorted keys.
Step 2: Insert with m[key]=value — for a missing key a default node is
         created, then the value is written; operator[] returns a REFERENCE.
         WHY: a reference is needed, so m[k]++ enables one-line counting.
Step 3: For counting: freq[c]++ — unknown key → default 0 entry,
         ++ makes it 1. Duplicates only change values.
         WHY: the map's #1 use-case = frequency counter.
Step 4: Read with find()/count(), NOT [] — [] creates entries even
         for pure reads. WHY: the map silently bloats (size grows).
Step 5: insert vs insert_or_assign — insert keeps old, assign replaces.
         WHY: the two have different intent and different results.
Step 6: Iterate with range-for → keys come out sorted (in-order walk).
         WHY: tree height log n, the walk visits every node exactly once.
 Step 7: erase in a loop — use `it = m.erase(it)`. WHY: erase invalidates
         the old iterator; the returned one is the safe next position.

 VISUAL WALKTHROUGH: demo — char freq of "mississippi", keys m,i,s,p
   ┌────────────────────────────────────────────────────────────┐
   │ insert 'm' →    {m:1}                                      │
   │ insert 'i' →    {m:1}                 (i < m)             │
   │                /                                           │
   │            {i:1}                                           │
   │ insert 's' →    {m:1}                 (s > m)             │
   │                /    \                                      │
   │            {i:1}   {s:1}                                   │
   │ insert 'p' →    {m:1}                 (p between i & s)   │
   │                /    \                                      │
   │            {i:1}   {s:1}                                   │
   │                    /                                       │
   │                {p:1}                                       │
   │ red-black balances, height stays = log2(4)  → O(log n) ✅  │
   │ In-order: i, m, p, s — SORTED output guaranteed every time  │
   └────────────────────────────────────────────────────────────┘

 DRY RUN (demo: string "mississippi" — characters m,i,s,s,i,s,s,i,p,p,i):
   step | op                | map state (sorted)        | size | note
   -----|-------------------|---------------------------|------|----------------
#1   | freq['m']++       | {m:1}                     |  1   | 'm' first time → 0+1
 #2   | freq['i']++       | {i:1, m:1}                |  2   | 'i' first time
 #3   | freq['s']++       | {i:1, m:1, s:1}           |  3   | 's' first time
 #4   | freq['s']++       | {i:1, m:1, s:2}           |  3   | 's' present → 1+1
 #5   | freq['i']++       | {i:2, m:1, s:2}           |  3   | 'i' present
 #6   | freq['s']++       | {i:2, m:1, s:3}           |  3   |
 #7   | freq['s']++       | {i:2, m:1, s:4}           |  3   |
 #8   | freq['i']++       | {i:3, m:1, s:4}           |  3   |
 #9   | freq['p']++       | {i:3, m:1, p:1, s:4}      |  4   | 'p' first time
 #10  | freq['p']++       | {i:3, m:1, p:2, s:4}      |  4   | 'p' present → 1+1
 #11  | freq['i']++       | {i:4, m:1, p:2, s:4}      |  4   | FINAL: i:4,m:1,p:2,s:4
 #12  | freq['z']         | +z:0 entry                |  5   | ⚠️ operator[] CREATED an entry
 #13  | freq.find('p')    | it = (p,2)                |  5   | O(log n)
 #14  | freq.count('q')   | 0 — no entry created       |  5   | safe read
   #15  | freq.erase('m')   | {i:4, p:2, s:4, z:0}      |  4   |

 TIME COMPLEXITY CALCULATION:
 - Across h levels 2^h ≈ n nodes → h = log2(n). Every tree op follows a
   root→leaf path.
 - find(k): root-to-leaf descent = O(log n). count(k): same = O(log n).
 - insert(k,v): find (O(log n)) + node attach (O(1)) + rebalance (O(log n))
   → O(log n). operator[] does the same work → O(log n).
 - erase(k): find (O(log n)) + rebalance (O(log n)) → O(log n).
 - Demo: string length n (11 chars) × O(log k) each → O(n log n).
 - Full in-order iteration over all k keys = O(k).
 - lower_bound/upper_bound: guided descent = O(log n).
 → Time Complexity = O(log n) per operation; O(n log n) for n inserts.

 SPACE COMPLEXITY CALCULATION:
 - Each distinct key = one tree node (key + value + 2 child ptr + color).
 - Duplicates create no new entries — only value++ happens.
 - Distinct keys = k. In the demo i,m,p,s + 'z' → k = 5 nodes.
 → Space Complexity = O(k) where k = number of distinct keys.

 APPROACH COMPARISON: std::map vs std::unordered_map
 ┌───────────────────────┬──────────────────────┬──────────────────────┐
 │                       │ std::map (tree)      │ std::unordered_map   │
 ├───────────────────────┼──────────────────────┼──────────────────────┤
 │ internal              │ red-black tree       │ hash table (buckets) │
 │ order of iteration    │ SORTED by key        │ arbitrary (hash)     │
 │ m[k]/find/erase       │ O(log n)             │ O(1) average         │
 │ worst case            │ O(log n) guaranteed  │ O(n) (collisions)    │
 │ lower/upper_bound     │ YES — built-in       │ NO                   │
 │ custom key needs      │ operator< only       │ hash + operator==    │
 │ memory per entry      │ ~48+ bytes           │ ~40+ bytes           │
 │ best for              │ sorted/range queries │ pure-speed lookups   │
 └───────────────────────┴──────────────────────┴──────────────────────┘
Conclusion: need order or range queries → map. Only need O(1) speed with
order irrelevant → unordered_map. Small int keys (0..999) → vector.

GOTCHA ⚠️: std::map comes from the <map> header — do NOT rely on a
transitive <iostream> include. And remember: "use [] for WRITING,
count/find for READING — otherwise an entry gets created". ⚠️
*/

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    // demo 1: character frequency counter — output SORTED by key
    cout << "===== DEMO 1: CHARACTER FREQUENCY (sorted keys) =====" << endl;
    string s = "mississippi";
    map<char, int> freq;                       // khali map
    for (char c : s) freq[c]++;                // [] unique key pe default 0, phir ++ / exist to 1+1
    for (const auto& e : freq)               // map iterate — keys sorted aati hain
        cout << "freq['" << e.first << "'] = " << e.second << endl;

    // demo 2: operator[] UNKNOWN KEY — entry ban jati hai!
    cout << "\n===== DEMO 2: operator[] UNKNOWN KEY =====" << endl;
    cout << "freq['z'] = " << freq['z']        // 'z' nahi tha → default 0 mila
         << " (default 0 created)" << endl;
    cout << "size ab: " << freq.size() << "  <-- 'z' ki ENTRY ban gayi! ⚠️" << endl;

    // demo 3: find / count — safe reading (entry NAHI banti) ⭐
    cout << "\n===== DEMO 3: FIND / COUNT =====" << endl;
    auto it = freq.find('p');                  // iterator milta hai
    if (it != freq.end())
        cout << "find('p') -> " << it->first << ":" << it->second << endl;
    it = freq.find('q');                        // 'q' nahi hai
    if (it == freq.end())
        cout << "find('q') -> end() (abhi bhi size = " << freq.size() << " — koi entry nahi bani)" << endl;
    cout << "count('i') = " << freq.count('i')
         << " , count('q') = " << freq.count('q') << " (count se entry NAHI banti ✅)" << endl;

    // demo 4: erase
    cout << "\n===== DEMO 4: ERASE =====" << endl;
    freq.erase('m');                            // key 'm' hat gayi
    cout << "erase('m') ke baad: count('m') = " << freq.count('m')
         << " , size = " << freq.size() << endl;

    // demo 5: insert vs insert_or_assign (replace semantics)
    cout << "\n===== DEMO 5: insert vs insert_or_assign =====" << endl;
    map<string, int> scores = {{"Rahul", 90}, {"Amit", 70}};
    scores.insert({"Amit", 999});               // insert purani NAHI badalta
    cout << "after insert{\"Amit\",999}: scores[\"Amit\"] = " << scores["Amit"]
         << " (still 70!)" << endl;
    scores["Amit"] = 100;                        // [] = REFERENCE → overwrite possible
    cout << "after scores[\"Amit\"]=100: scores[\"Amit\"] = " << scores["Amit"] << endl;

    // EDGE CASES
    cout << "\n===== EDGE CASES =====" << endl;
    map<int, int> emptyMap;
    cout << "empty map size: " << emptyMap.size() << endl;
    cout << "count on empty: " << emptyMap.count(42) << endl;
    if (emptyMap.find(42) == emptyMap.end())
        cout << "find on empty -> end() (dereference UB hai!)" << endl;
    int v7 = emptyMap[7];                       // entry default 0 se BAN gayi
    cout << "emptyMap[7] = " << v7 << " -> ab size = "
         << emptyMap.size() << " (default entry ban gayi)" << endl;
    try {
        map<string, int> m2 = {{"a", 1}};
        int v = m2.at("b");                      // const-compatible, missing → exception
        cout << "m2.at(\"b\") = " << v << endl;
    } catch (const out_of_range&) {
        cout << "m2.at(\"b\") -> out_of_range exception (entry NAHI bani)" << endl;
    }

    cout << "\nDemo complete. Sorted key→value storage, O(log n) ops." << endl;
    return 0;
}