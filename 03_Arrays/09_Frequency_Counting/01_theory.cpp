/*
═══════════════════════════════════════════════
 FREQUENCY COUNTING
 ⏱️ TIME COMPLEXITY: nested O(n²), visited O(n²) no recounts,
 hashing O(n log n) [std::map] / O(n) avg [unordered_map] — derived below.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A supermarket billing machine must report how many times each product was
 sold today. The slow clerk picks one product, walks the whole receipt list,
 ticks every matching row, then repeats this for the next product — O(n²) work.
 The fast clerk keeps a tally sheet: one counter per product name, and every
 sold item adds one tick to its own row in O(1). That tally sheet is a hash
 table. The same trick powers election vote counting, "most purchased item"
 dashboards, and online judges checking which numbers repeat.

 📖 THEORY:
 - Problem: given array a[] of n integers, count how many times each distinct
   value appears. Extensions: which value has the MAXIMUM frequency, which has
   the MINIMUM frequency, and which value appears exactly once and is the
   LEFTMOST such value — the "first non-repeating" element.
 - Key insight 1: frequency is defined by direct comparison
       freq(a[i]) = number of indices j with a[j] == a[i]
   A literal reading of that formula scans the whole array for every i → n×n.
 - Key insight 2: the operation is symmetric and repetitive. When value 2's
   count is already known from index 1, recounting the same value from index 4
   is wasted work. A "visited" flag suppresses the duplicate reports but the
   inner counting scan itself is still O(n) per distinct element.
 - Key insight 3: a hash table replaces "compare with everyone" by "jump to my
   own bucket". Updating count becomes O(1) average, so every query — count,
   max frequency, min frequency, first non-repeating — needs at most two
   linear passes over the array/table.
 - ASCII diagram — the same 6-element array seen three ways:

   NESTED (every pair compared):
       0  1  2  3  4  5
     1 ┼          ┼       (index 0 & 4 match)
     2    ┼  ┼      ┼     (index 1,2,5 match)
     3                ┼
     n rows × n cols of comparisons → O(n²)

   VISITED (mark finished, still scan):
     i=0 val1 → scan all 6 → count 2 → mark idx0, idx4 done
     i=1 val2 → scan all 6 → count 3 → mark idx1, idx2, idx5 done
     i=3 val3 → scan all 6 → count 1 → mark idx3 done
     one full O(n) scan per distinct element → worst case O(n²)

   HASHING (bucket by value → O(1) steps):
     1 → 2    2 → 3    3 → 1     6 updates, each O(1) average

 - When to use: any "count occurrences / most frequent / least frequent /
   first non-repeating / appears-twice" problem, i.e. whenever the value of
   an element — not its position — drives the answer.

 🧠 LOGIC — STEP BY STEP:
 Step 1 (nested): for i in 0..n-1, loop j in 0..n-1 and count matches of a[i].
      WHY: this is the literal translation of the frequency definition, so it
      is logically bulletproof — only slow. Duplicate values make the same
      full scan repeat unnecessarily.
 Step 2 (visited): keep a bool visited[] array; for each unvisited i, scan the
      array counting matches and mark every matched index visited.
      WHY: the count for a value is decided once by its first index; all later
      copies are noise. Marking eliminates duplicate reports, but the counting
      scan itself still visits up to n positions per distinct element, so the
      worst case (all elements distinct) stays quadratic.
 Step 3 (hashing): for each x, freq[x]++ using a map.
      WHY: bucket addressing removes the inner scan entirely. unordered_map
      gives O(1) amortized per update, std::map gives O(log d). The table
      stores each distinct value once, so min/max frequency are found by one
      table walk.
 Step 4 (min/max frequency): walk the hash table comparing counts.
      WHY: min/max over all distinct values live in the table; only d distinct
      keys are visited, and d ≤ n, so the walk is O(d) ⊆ O(n).
 Step 5 (first non-repeating): build the table, then scan the ORIGINAL array.
      WHY: a hash table does not remember array positions, so "first/leftmost"
      can only be answered in the original order — return the first x whose
      table entry is exactly 1.

 VISUAL WALKTHROUGH: (hash table state while reading {1,2,2,3,1,2})
   step  read     table {value: count}
   0     –        {}
   1     1        {1:1}
   2     2        {1:1, 2:1}
   3     2        {1:1, 2:2}
   4     3        {1:1, 2:2, 3:1}
   5     1        {1:2, 2:2, 3:1}
   6     2        {1:2, 2:3, 3:1}

   final table:
     value    count
       1        2
       2        3   ← MAX frequency
       3        1   ← MIN frequency AND first non-repeating

 DRY RUN: (nested vs visited vs hash — same numbers)
   nested on {1,2,2,3,1,2}:
     i=0 val 1 → matches j=0,4 → count 2   → print 1 -> 2
     i=1 val 2 → matches j=1,2,5 → count 3 → print 2 -> 3
     i=2 val 2 → recount 3 (wasted, suppressed by dedup check)
     i=3 val 3 → matches j=3 → count 1     → print 3 -> 1
     output: 1->2, 2->3, 3->1
   visited on the same array:
     i=0 marks {0,4}; i=1 marks {1,2,5}; i=3 marks {3}
     output: 1->2, 2->3, 3->1   (identical)
   hash: {1:2, 2:3, 3:1}        (identical)

   edge cases:
     {}           → nothing to print; max/min = -1; first non-rep = -1
     {7}          → 7->1; max = (7,1); min = (7,1); firstNonRep = 7
     {1,2,3}      → all freq 1; max freq tie; firstNonRep = 1
     {5,5,5,5}    → 5->4; max = min = 5; firstNonRep = -1 (no unique value)

 TIME COMPLEXITY CALCULATION:
 - Nested: for every i (n of them) an inner sweep of length n runs, so total
   comparisons = Σ(i=0..n-1) n = n·n → O(n²).
 - Visited: a full scan happens once per DISTINCT element. Worst case all
   elements are distinct (d = n) → n scans of n → O(n²). With d distinct it
   is ~d·n, still bounded by O(n²).
 - std::map hashing: n insert/update operations, each costs O(log d) d≤n
   → n·log n → O(n log n). Min/max walk adds O(d) ⊆ O(n).
 - unordered_map hashing: n operations × O(1) average → O(n); the final table
   walk is O(d) ⊆ O(n). Collision worst case degrades to O(n²), but the
   average is linear.
 → Time Complexity = O(n²) nested/visited, O(n log n) std::map, O(n) avg unordered_map.

 SPACE COMPLEXITY CALCULATION:
 - nested: only scalar loop counters → O(1).
 - visited: bool array of n flags → O(n).
 - hashing (map or unordered_map): one node/entry per distinct key; at most n
   distinct values → O(n).
 → Space Complexity = O(1) nested; O(n) visited and hashing.

 APPROACH COMPARISON:
 ┌──────────────────┬────────────────────────────┬────────────────────────────┬────────────────────────────┐
 │ Aspect           │ Nested                     │ Visited                    │ Hashing                   │
 ├──────────────────┼────────────────────────────┼────────────────────────────┼────────────────────────────┤
 │ Core trick       │ compare with all indices   │ mark done indices          │ bucket by value            │
 │ Count cost       │ n × n comparisons          │ n × d (d = distinct count) │ O(1) avg per update       │
 │ Time             │ O(n²)                      │ O(n²) worst                │ O(n) avg; O(n log n) map  │
 │ Extra space      │ O(1)                       │ O(n)                       │ O(n)                      │
 │ Duplicates       │ recounted (wasted)         │ counted once               │ counted once              │
 │ first non-repeat │ O(n²)                      │ O(n²)                      │ O(n) (second pass)        │
 │ Verdict          │ teaching only              │ teaching only              │ interviews & production   │
 └──────────────────┴────────────────────────────┴────────────────────────────┴────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

// APPROACH 1 — NESTED: O(n²) — har element ke liye full array scan.
// Dedup ke liye bas pehli occurrence par print hota hai.
void freqNested(const vector<int>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n; ++i) {
        bool seenEarlier = false;
        for (int k = 0; k < i; ++k)              // prefix me check
            if (a[k] == a[i]) { seenEarlier = true; break; }
        if (seenEarlier) continue;               // duplicate print nahi karte
        int cnt = 0;
        for (int j = 0; j < n; ++j)              // full scan — O(n)
            if (a[j] == a[i]) ++cnt;
        cout << a[i] << " -> " << cnt << "\n";
    }
}

// APPROACH 2 — VISITED: O(n²) worst — visited array recounts ko hatata hai
void freqVisited(const vector<int>& a) {
    int n = (int)a.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;                    // is index ka count ho chuka
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            if (a[j] == a[i]) { ++cnt; vis[j] = true; }
        cout << a[i] << " -> " << cnt << "\n";
    }
}

// APPROACH 3 — HASHING: unordered_map, avg O(n) total
void freqHash(const vector<int>& a) {
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;                     // ek hi pass me build
    // deterministic output: keys ko sort karke print
    vector<pair<int,int>> items(mp.begin(), mp.end());
    sort(items.begin(), items.end());
    for (auto& pr : items)
        cout << pr.first << " -> " << pr.second << "\n";
}

// MAX frequency wala element (value, count) return karta hai
pair<int,int> maxFreqElement(const vector<int>& a) {
    if (a.empty()) return {-1, -1};
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;
    int bestVal = -1, bestCnt = -1;
    for (auto& pr : mp)
        if (pr.second > bestCnt) { bestCnt = pr.second; bestVal = pr.first; }
    return {bestVal, bestCnt};
}

// MIN frequency wala element (value, count)
pair<int,int> minFreqElement(const vector<int>& a) {
    if (a.empty()) return {-1, -1};
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;
    int bestVal = a[0], bestCnt = mp.begin()->second;
    for (auto& pr : mp)
        if (pr.second < bestCnt) { bestCnt = pr.second; bestVal = pr.first; }
    return {bestVal, bestCnt};
}

// FIRST NON-REPEATING: table banao, phir ORIGINAL array order me scan
int firstNonRepeating(const vector<int>& a) {
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;
    for (int x : a)
        if (mp[x] == 1) return x;                // leftmost unique value
    return -1;                                   // koi non-repeating nahi
}

void runEdges() {
    vector<int> cases[4] = {
        {}, {7}, {1,2,3}, {5,5,5,5}
    };
    const char* label[4] = {"empty {}", "single {7}", "all distinct {1,2,3}", "all same {5,5,5,5}"};
    for (int i = 0; i < 4; ++i) {
        auto mx = maxFreqElement(cases[i]);
        auto mn = minFreqElement(cases[i]);
        cout << "  " << label[i] << ": max=(" << mx.first << "," << mx.second
             << ") min=(" << mn.first << "," << mn.second
             << ") firstNonRep=" << firstNonRepeating(cases[i]) << "\n";
    }
}

int main() {
    vector<int> a = {1,2,2,3,1,2};

    cout << "=== 1) NESTED O(n^2) ===\n";
    freqNested(a);
    cout << "\n=== 2) VISITED O(n^2) ===\n";
    freqVisited(a);
    cout << "\n=== 3) HASH (unordered_map) O(n) avg ===\n";
    freqHash(a);

    cout << "\n=== MAX & MIN FREQUENCY ===\n";
    auto mx = maxFreqElement(a);
    auto mn = minFreqElement(a);
    cout << "  max freq element = " << mx.first << " (appears " << mx.second << "x)\n";
    cout << "  min freq element = " << mn.first << " (appears " << mn.second << "x)\n";

    cout << "\n=== FIRST NON-REPEATING ===\n";
    cout << "  " << firstNonRepeating(a) << "\n";

    cout << "\n=== EDGE CASES ===\n";
    runEdges();

    return 0;
}