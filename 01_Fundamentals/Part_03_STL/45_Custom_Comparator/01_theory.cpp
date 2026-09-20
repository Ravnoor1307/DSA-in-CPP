/*
═══════════════════════════════════════════════
 45_Custom_Comparator — Telling sort() HOW to order
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 The university publishes its merit list as a single never-ending stream of
 student pairs (name, marks). `std::sort` with its default < ordering would
 happily put Adam before Aarav alphabetically and by marks, wrong for both
 rules. One tiny third argument — a "comparator" that says how two students
 must compare — flips the entire list into *marks descending, name
 ascending* in a single pass. The same comparator idea runs the college
 canteen's min-heap (cheapest dish served first) and the friend-sorting
 logic ("shorter names first, ties by alphabet").

 📖 THEORY: (pure English, beginner-level)
 - A COMPARATOR is any callable that answers: "given two elements a and b,
   should a come BEFORE b?" It must return true when ordering is correct,
   false otherwise. Signature: bool comp(a, b).
 - WRAPPING RULE (STRICT CONTRACT): the comparator must be a STRICT WEAK
   ORDERING — it must behave like "<":
     * comp(a,a) == false  (never pass itself)
     * if comp(a,b) && comp(b,c) then comp(a,c) — transitive
     * if !comp(a,b) && !comp(b,a) then a and b are "equivalent"
   Breaking this (e.g. using "<=") = undefined behaviour / infinite loop.
 - FORM 1 — function: write `bool desc(int a, int b) { return a > b; }`
   then `sort(v.begin(), v.end(), desc);`.
 - FORM 2 — lambda (C++11, most used): `sort(v.begin(), v.end(),
   [](int a, int b){ return a > b; });`. Lambdas declared inside main()
   can also CAPTURE outer variables `[cap]` and use them in the decision.
 - FORM 3 — functor: a `struct cmp { bool operator()(a,b) const {...} };`
   object. This is what `set<int, cmp>` and `priority_queue<..., cmp>`
   demand because they keep the comparator as a TYPE.
 - FOR SORTING PAIRS: default pair<  compares FIRST then second. To sort
   by second element: `return a.second < b.second;`. Want ties broken by
   first descending: `if (a.second != b.second) return a.second < b.second;
   return a.first > b.first;`.
 - FOR STRINGS: `return a.size() < b.size();` sorts by length; ties survive
   in any order (they are "equivalent").
 - FOR OBJECTS: return the field comparison — `return a.marks > b.marks;`.
 - PRIORITY_QUEUE: default is a MAX-heap (top = largest). A custom
   comparator flips it into a MIN-heap: `priority_queue<int, vector<int>,
   greater<int>>` or your own lambda via decltype. The comparator there
   reads topologically as "(b,a) — what should be 'lower priority'".
   Compare top() with cmp(b,a) mental model: returns true if b should
   come before a.
 - SET with comparator: `set<int, greater<int>> s;` stores descending.
   Changing comparator = new ordered container keeping order live on
   every insert (O(log n) insertion).

   COMPARATOR DECISION — "a before b?"
        compare(a, b)
        /          \
     true         false
    keep a      swap a,b
   before b      (b first)
         =>
   [3, 1, 2] comp(a,b): a>b  →  [1, 2, 3]  every swap fixes a wrong pair

   FIRST vs SECOND — sort pairs {m, n} by SECOND:
   { (3, 30), (1, 40), (2, 10) }
      return a.second < b.second   (ascending second)
      => { (2, 10), (3, 30), (1, 40) }

   RANK LIST tie-break (marks desc, name asc):
   [ (Ram,72) (Shyam,72) (Ann,90) ]  marks desc phir name asc
   => [ (Ann,90) (Ram,72) (Shyam,72) ]

 - WHEN TO USE: every time the natural order is wrong — descending sorts,
   sorting by a different field, min-heaps, sets ordered by custom keys,
   stable multi-key ranking.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Define the ORDER you want in words — "marks descending, name
         ascending". WHY: so the comparator has one room for you to
         translate into (a, b) logic.
 Step 2: Write strictly less-than-style logic: comp(a, b)==true means
         "a is correctly placed before b". WHY: sort internally treats
         your function exactly like operator<; giving it <= breaks the
         strict-weak contract and the algorithm may never terminate.
 Step 3: Handle the tie first when ranking: if a.marks != b.marks →
         return a.marks > b.marks (desc); else return a.name < b.name.
         WHY: stable, predictable total order — no two students are
         "equivalent", so the result is fully deterministic.
 Step 4: For a container that stores the comparator in its type (set,
         priority_queue), pass the comparator as a TYPE (functor/greater)
         not a bare lambda: `set<int, greater<int>>`. WHY: the container
         re-uses that type for every insert; lambdas (each having a unique
         type) can be handled too but only with decltype.

 VISUAL WALKTHROUGH — sorting pairs {id, score} by score DESCENDING:
   start        compare(90,72)   compare(72,72→tie→id)   order
   (1,72)       b before a?      1<2 tie?                (1,90)  // score desc
   (2,83)  -->  yes(90>72)  -->  score tie  -->          (3,83)
   (3,90)                        1<3 tie                  (2,72)  // then id asc
   => [ (3,90), (2,83), (1,72) ]  ✓ marks desc, id asc

 DRY RUN — sort vector<int> descending with lambda [](a,b){return a>b;}:
   v = {3, 1, 4, 1, 5}
   partition around pivot 4: [1, 1, 3] 4 [5]   (bigger left)
   left  [1,1,3] → 3 before 1s → [3,1,1]
   right [5] done
   merged: [5, 4, 3, 1, 1]  ✓ each adjacent pair satisfies a>b
   With `set<int, greater<int>>` inserting {5,3,5,1,3}:  {5,3,1} (uniq+desc)
   With `priority_queue<int, vector<int>, greater<int>>` pushing 5,1,3:
   top() pops 1 → 3 → 5 (MIN-heap)

 TIME COMPLEXITY CALCULATION:
 - Comparator output is fed to the SAME underlying sorts:
   std::sort O(n log n) — Introsort, log n pivot levels × O(n) work per
   level. Worst case stays O(n log n) via heapsort fallback.
 - std::set / std::priority_queue with custom comparator: red-black tree
   does one root-to-leaf walk of ≤ 2·log₂(n+1) height per insertion →
   O(log n) insert; priority_queue heapify is O(log n) per push/pop
   (sift-up/sift-down length = tree height = log n upper bound).
 - The comparator itself is O(1) (field compare), multiplied into each
   inner comparison — same asymptotic cost.
 → Time Complexity = O(n log n) per sort; O(log n) per set / heap op

 SPACE COMPLEXITY CALCULATION:
 - std::sort with a comparator: in-place swaps of existing elements;
   Introsort recursion stack O(log n); the comparator object is passed
   by reference → O(1) own storage.
 - Lambda capture: capturing a small int/string by value adds O(1) (or
   O(len) for a copied string) per lambda, still constant relative to n.
 - set<int, cmp>: each node = element + 3 tree pointers + one byte marker,
   so O(n) nodes → O(n) actually stored (same as the data itself); no
   extra auxiliary growth with n beyond that.
 - priority_queue with custom comparator: stores the vector of n elements
   → O(n); comparator object O(1).
 → Space Complexity = O(1) auxiliary for sort; O(n) for the custom
   containers themselves (data), O(log n) recursion worst for Introsort

 APPROACH COMPARISON:
 ┌───────────────────────┬──────────────────────────────┬─────────────────────────────────┐
 │ Order needed          │ Default sort (wrong)         │ Custom comparator (right)        │
 ├───────────────────────┼──────────────────────────────┼─────────────────────────────────┤
 │ Decreasing ints       │ ascending ✗                  │ [](int a,int b){return a>b;}     │
 │ Pair by second        │ by first ✗                   │ return a.second < b.second;      │
 │ Strings by length     │ alphabet ✗                   │ return a.size() < b.size();      │
 │ Objects by field      │ member addr ✗                │ return a.marks > b.marks;        │
 │ Min-heap              │ max-heap ✗ (top largest)     │ priority_queue<...,greater<int>> │
 │ Set descending        │ ascending ✗                  │ set<int, greater<int>>           │
 ├───────────────────────┴──────────────────────────────┴─────────────────────────────────┤
 │ Note: stable_sort keeps equivalent elements in original order (guarantee: O(n log² n) │
 │ worst, O(n log n) if enough memory). Plain sort makes NO order promise for equals.     │
 └─────────────────────────────────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

void printV(const string& label, const vector<int>& v) {
    cout << label;
    for (int x : v) cout << x << " ";
    cout << "\n";
}

struct Student {
    string name;
    int marks;
};

// functor: stable_form ke liye object bhi banta rahe
struct MarksDescNameAsc {
    bool operator()(const Student& a, const Student& b) const {
        if (a.marks != b.marks) return a.marks > b.marks; // pehle marks desc
        return a.name < b.name;                            // tie ho to name asc
    }
};

// plain function comparator
bool intDesc(int a, int b) {
    return a > b;
}

int main() {
    // ---------------- SORT DESCENDING (function comparator) ----------------
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    sort(v.begin(), v.end(), intDesc);
    printV("Desc via function    : ", v);

    // ---------------- SORT DESC (lambda) ----------------
    vector<int> w = {3, 1, 4, 1, 5, 9, 2, 6};
    sort(w.begin(), w.end(), [](int a, int b) { return a > b; });
    printV("Desc via lambda      : ", w);

    // ---------------- 3-WAY HANDLER: return cmp(a,b) ? "a first" : "b first" ----------------
    // 3-way style tie-break: sort by VALUE desc, ties by VALUE-equal
    vector<int> t = {7, 7, 3, 9, 7, 3};
    sort(t.begin(), t.end(), [](int a, int b) {
        if (a != b) return a > b;   // pehla rule desc
        return false;               // barabar → "equivalent", koi bhi order
    });
    printV("3-way tie-break       : ", t);

    // ---------------- SORT PAIRS BY SECOND, TIE FIRST DESC ----------------
    vector<pair<int, int>> pps = {{1, 30}, {4, 10}, {2, 30}, {3, 20}};
    // default pair_compare: p.first pehle, phir second
    sort(pps.begin(), pps.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second; // second ASC
        return a.first > b.first;                             // tie: first DESC
    });
    cout << "Pairs by 2nd asc / 1st desc: ";
    for (auto& p : pps) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    // ---------------- SORT STRINGS BY LENGTH ----------------
    vector<string> names = {"Zoe", "Anna", "Kabir", "Me", "Alexandra"};
    sort(names.begin(), names.end(),
         [](const string& a, const string& b) { return a.size() < b.size(); });
    cout << "Strings by length    : ";
    for (auto& s : names) cout << "\"" << s << "\"(" << s.size() << ") ";
    cout << "\n";
    // note: equal lengths (Anna/Kabir) "equivalent" — koi bhi order allowed, no guarantee

    // ---------------- OBJECTS BY FIELD (marks desc, name asc) ----------------
    vector<Student> cls = {{"Ram", 72}, {"Ann", 90}, {"Shyam", 72}, {"Bob", 88}};
    sort(cls.begin(), cls.end(), MarksDescNameAsc()); // functor object
    cout << "Students (marks desc, name asc):\n";
    for (auto& s : cls) cout << "   " << s.name << " -> " << s.marks << "\n";

    // ---------------- LAMBDA WITH CAPTURES ----------------
    int offset = 100;                                   // outer variable
    vector<int> sc = {5, 9, 1, 7};
    sort(sc.begin(), sc.end(), [offset](int a, int b) {
        return (a + offset) > (b + offset);            // [capture] use offset
    });
    printV("Lambda [capture] desc : ", sc);

    // ---------------- MIN-HEAP via custom comparator ----------------
    priority_queue<int, vector<int>, greater<int>> minHeap; // greater<int> = comparator type
    for (int x : {5, 1, 9, 3}) minHeap.push(x);
    cout << "Min-heap (top smallest priority served first): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << "\n";

    // ---------------- CUSTOM min-heap via FUNCTOR ----------------
    struct Dish { string name; int price; };
    struct CheapestFirst {
        bool operator()(const Dish& a, const Dish& b) const {
            return a.price > b.price;                  // priority_queue: true => b "higher priority"
        }
    };
    priority_queue<Dish, vector<Dish>, CheapestFirst> canteen;
    canteen.push({"Bir", 120}); canteen.push({"Chai", 15}); canteen.push({"Soda", 40});
    cout << "Canteen (cheapest first): ";
    while (!canteen.empty()) {
        cout << canteen.top().name << "(" << canteen.top().price << ") ";
        canteen.pop();
    }
    cout << "\n";

    // ---------------- CUSTOM SET DESCENDING ----------------
    set<int, greater<int>> s;                            // comparator type greater<int>
    for (int x : {5, 3, 5, 1, 3, 9}) s.insert(x);
    cout << "set<int, greater>    : ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    // ---------------- EQUALITY / STABILITY TEST ----------------
    vector<int> st = {3, 1, 3, 2, 3};
    sort(st.begin(), st.end(), [](int a, int b) { return a < b; });
    printV("Equal 3s (stole sort, koi bhi order) : ", st);
    // stability note: have duplicates — plain sort does NOT promise
    // original order keeping; stable_sort does.

    return 0;
}