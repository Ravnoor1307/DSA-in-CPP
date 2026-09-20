/*
═══════════════════════════════════════════════
 std::pair — TWO VALUES GLUED TOGETHER
 ⏱️ TIME COMPLEXITY: construction O(1), make_pair O(1),
     comparison O(1), sort of vector<pair> O(n log n).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 At a sports day the scorer has two pieces of paper that must stay
 together: a runner's roll number and the marks they scored. If the
 papers drift apart you can't tell which mark belongs to whom. A
 std::pair is a tiny stapler that fixes exactly two values side by
 side — (roll, marks). A map of the whole course uses (x, y)
 coordinate pairs, and nested pairs like ((student, subject), marks)
 handle three values when a group comes to the photo booth together.

 📖 THEORY:

 - std::pair<T1, T2> bundles EXACTLY TWO values (first, second).
   #include <utility>

   ┌──────────────────────────────┐
   │        std::pair<int,int>    │
   │  ┌───────────┐ ┌───────────┐ │
   │  │  .first   │ │ .second   │ │
   │  │   42      │ │   97      │ │
   │  └───────────┘ └───────────┘ │
   └──────────────────────────────┘
        (roll=42, marks=97)

 - CONSTRUCTION ways:
   pair<int,int> p(40, 55);            // constructor
   pair<int,int> q = {40, 55};         // brace init (C++11)
   auto r     = make_pair(40, 55);     // type auto-deduced
   pair<string,int> s = {"Aman", 90};

 - ACCESS: p.first  and  p.second  (public members)

 - NESTED PAIR for three values:
   pair<pair<int,int>,int> t = { {1,2}, 3 };
   t.first.first  == 1
   t.first.second == 2
   t.second       == 3

   ┌────────────────────────────┐
   │         t                 │
   │ ┌───────────────┐ ┌─────┐ │
   │ │ .first(pair)  │ │.sec │ │
   │ │ ┌───┬───┐     │ │  3  │ │
   │ │ │ 1 │ 2 │     │ └─────┘ │
   │ │ └───┴───┘     │        │
   │ └───────────────┘        │
   └────────────────────────────┘

 - COMPARISON (lexicographic): pairs compare first on .first; only if
   .first values tie do they check .second.
   make_pair(1,9) < make_pair(2,0)  → true (1<2, .second ignored)
   make_pair(1,0) < make_pair(1,5)  → true (1==1, then 0<5)
   This is EXACTLY the default behaviour sort() uses on a vector<pair>.

 - tie(): unpacks a pair into variables (or tuple):
   int a, b; tie(a, b) = make_pair(10, 20);  // a=10, b=20
   You can also ignore a field with tie(a, ignore).

 - USAGE WITH map/sort:
   map keys are pairs too: map<pair<int,int>, string>.
   Sorting a vector<pair> default = by .first then .second.

 - WHEN TO USE: two linked values — coordinates, roll+marks, name+score,
   ranges (start,end). For MORE than two values use tuple or struct.

 🧠 LOGIC — STEP BY STEP:

 Step 1: Pick value types. Decide what the two glued values represent.
         WHY: types decide how sorting and printing behave.

 Step 2: Create the pair. Use make_pair() when types are messy
         (e.g. string + int) so the compiler infers them.
         WHY: avoids writing pair<string,int> over and over.

 Step 3: Read .first / .second. Always go through the public members.
         WHY: pairs expose only these two; there are no index brackets.

 Step 4: Compare or sort. Rely on default lexicographic order.
         WHY: sort(v.begin(), v.end()) on vector<pair> needs no
         custom comparator for "sort by first, then second".

 Step 5: Unpack with tie() when you want plain variables.
         WHY: tie() assigns each part in order in one clean line.

 Step 6: Build tuples only when needing 3+ values.
         WHY: nested pairs get unreadable; tuple is clearer.

 VISUAL WALKTHROUGH:

   vector<pair<int,int>> v = { {30,99}, {10,50}, {10,80} };
   default sort() by first, then second:
       before:    [ (30,99)  (10,50)  (10,80) ]
       after :    [ (10,50)  (10,80)  (30,99) ]
                    ↑first tie → chose smaller .second

   min of { (9,40), (5,90), (5,10) } → (5,10):
       lexicographic: smallest .first wins; ties → smaller .second

 DRY RUN (demo):
   1. pair p1 = make_pair(21, 88) → first 21, second 88 (printed).
   2. point = {3, 4} on paper coordinate (x=3,y=4)
   3. nested t = {{1,2},3} → t.first.first=1, t.first.second=2, t.second=3
   4. vector pairs {30,99},{10,50},{10,80} sorted → (10,50)(10,80)(30,99)
   5. min(vector of pairs) → dereference iterator → least pair (10,50)
   6. tie(roll, marks) = make_pair(7, 65) → roll=7, marks=65

 TIME COMPLEXITY CALCULATION:
 - Construction (constructor / make_pair / brace): only writes 2
   fields, constant work → O(1).
 - Each pair comparison: at most 2 comparisons (first, then second
   only on tie) → 2 steps → O(1).
 - Reading .first/.second: direct field access → O(1).
 - sort of vector<pair> of n pairs: each compare costs O(1); total
   compares are n·log2(n) → O(n log n) × O(1) → O(n log n).
 - min_element: scans all n pairs, one O(1) compare each → O(n).
 → Time Complexity = O(n log n) for the sorting demo

 SPACE COMPLEXITY CALCULATION:
 - One pair holds exactly 2 objects plus no extra per-pair bookkeeping
   beyond the two members (padding negligible) → O(1) per pair.
 - vector of n pairs stores 2n objects → O(n).
 → Space Complexity = O(n) for the vector of pairs

 APPROACH COMPARISON:
 ┌────────────────────────────┬──────────────────────┬─────────────────────┐
 │  Idea                      │  Pros                │  Cons                │
 ├────────────────────────────┼──────────────────────┼─────────────────────┤
 │ Two parallel arrays        │  0 intermediate type │  easy to misalign    │
 │                            │                      │  both arrays         │
 │ std::pair<T1,T2>           │  single object,      │  only 2 values       │
 │                            │  sortable by lexicog │                      │
 │ std::tuple<T1,T2,T3>       │  3+ values, tie()    │  heavier syntax      │
 │ struct {int roll; int m;}  │  readable names      │  must write operator │
 │                            │                      │  < for sorting       │
 └────────────────────────────┴──────────────────────┴─────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

int main() {
    // ======= DEMO 1: basic pair (roll, marks) =======
    pair<int, int> p1 = make_pair(21, 88);     // type inferred
    cout << "Student roll " << p1.first
         << " scored " << p1.second << "\n";

    // ======= DEMO 2: coordinate point =======
    pair<int, int> point = {3, 4};             // brace init
    cout << "Point is (" << point.first << ", " << point.second
         << ")\n";

    // ======= DEMO 3: nested pair ((a,b),c) =======
    pair<pair<int, int>, int> t = {{1, 2}, 3};
    cout << "Nested: t.first.first=" << t.first.first
         << " t.first.second=" << t.first.second
         << " t.second=" << t.second << "\n";

    // ======= DEMO 4: sort vector of pairs (lexicographic) =======
    vector<pair<int, int>> v = {{30, 99}, {10, 50}, {10, 80}};
    sort(v.begin(), v.end());                  // first, phir second
    cout << "Sorted pairs: ";
    for (const auto& pr : v)
        cout << "(" << pr.first << "," << pr.second << ") ";
    cout << "\n";

    // ======= DEMO 5: minimum pair via min_element =======
    auto mn = min_element(v.begin(), v.end());
    if (mn != v.end()) {                       // empty vector ka guard
        cout << "Minimum pair = (" << mn->first << "," << mn->second
             << ")\n";
    }

    // ======= DEMO 6: tie() unpacking =======
    int roll, marks;
    tie(roll, marks) = make_pair(7, 65);       // ek line me unpack
    cout << "After tie(): roll=" << roll << " marks=" << marks << "\n";

    // EDGE CASE: empty vector → min_element gives end(), never deref
    vector<pair<int, int>> empty;
    auto e = min_element(empty.begin(), empty.end());
    if (e == empty.end()) {
        cout << "min_element on empty vector returns end() — safe check!\n";
    }

    return 0;
}