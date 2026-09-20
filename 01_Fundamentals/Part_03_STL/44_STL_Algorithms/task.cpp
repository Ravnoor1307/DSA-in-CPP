/*
═══════════════════════════════════════════════
 TASK SET — 44_STL_Algorithms
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: The exam-cell coordinator holds a messy register:
unsorted roll numbers, duplicate entries, and a leaderboard that must be
printed top-to-bottom. One toolkit (<algorithm>) fixes every report in a
couple of lines.
🧠 HOW TO SOLVE: reach for the <algorithm>/<numeric> function that names
the job (sort, count, accumulate, rotate, binary_search). Read the
problem, spot the keyword (biggest → max_element, how many → count, total
→ accumulate), then wrap it in a print loop. Always check the container is
sorted before any binary_search/lower_bound.
═══════════════════════════════════════════════
*/

// ---------------- TASK 1: EASY — Sort + Print ----------------
// Sample: sort the marks list {72, 45, 88, 55, 90} ascending and print,
// then again in descending order.
// 💡 HINT: sort(v.begin(), v.end()) ascending; for descending use
//          sort(v.rbegin(), v.rend()) — reverse iterators (topic 34).
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   using namespace std;
//   int main() {
//       vector<int> marks = {72, 45, 88, 55, 90};
//       // TODO: sort ascending, print
//       // TODO: sort descending, print
//       return 0;
//   }

// ---------------- TASK 2: EASY-MEDIUM — Largest 3 Marks ----------------
// Sample: from {45, 12, 88, 23, 90, 67, 41} print the largest 3 marks.
// 💡 HINT: sort once, then take the LAST three elements of ascending order
//          (or first three of descending).
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   using namespace std;
//   int main() {
//       vector<int> m = {45, 12, 88, 23, 90, 67, 41};
//       // TODO: sort and print top 3
//       return 0;
//   }

// ---------------- TASK 3: MEDIUM — Count Occurrences ----------------
// Sample: a survey logged 15 answers; count how many times "42" appears in
// {42, 7, 42, 13, 42, 42, 8, 1, 42, 5, 0, 42, 9, 2, 3}.
// 💡 HINT: count(v.begin(), v.end(), 42) returns exactly that number.
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   using namespace std;
//   int main() {
//       vector<int> v = {42, 7, 42, 13, 42, 42, 8, 1, 42, 5, 0, 42, 9, 2, 3};
//       // TODO: count kab kitne baar aaya
//       return 0;
//   }

// ---------------- TASK 4: MEDIUM — Total Sum (accumulate) ----------------
// Sample: monthly expenses in ₹ {1200, 950, 450, 2300, 540}; print the total
// and the average to 2 decimals.
// 💡 HINT: accumulate(v.begin(), v.end(), 0) gives the total; divide by
//          v.size() for average (cast to double first!).
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <numeric>
//   #include <iomanip>
//   #include <vector>
//   using namespace std;
//   int main() {
//       vector<int> exp = {1200, 950, 450, 2300, 540};
//       // TODO: total aur average print karo
//       return 0;
//   }

// ---------------- TASK 5: MEDIUM-HARD — Rotate the Queue ----------------
// Sample: the queue {1,2,3,4,5} must rotate LEFT by 2 → {3,4,5,1,2}.
// 💡 HINT: STL has std::rotate(begin, begin+K, end) — built exactly for
//          this. For right-rotate by k use begin + (n-k).
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   using namespace std;
//   int main() {
//       vector<int> q = {1, 2, 3, 4, 5};
//       // TODO: left rotate by 2, print
//       return 0;
//   }

// ---------------- TASK 6: HARD — Sorted Student Rank Finder ----------------
// Sample: roll numbers {102, 540, 310, 88, 245} are sorted, then the system
// must answer: does roll 310 exist? How many rolls are < 300? Which rolls
// fall in [100, 400]?
// 💡 HINT: sort first; then binary_search for existence, lower_bound for
//          first >= 300 (count = index), upper_bound for first > 400
//          (count in range = ub - lb indices).
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   using namespace std;
//   int main() {
//       vector<int> rolls = {102, 540, 310, 88, 245};
//       sort(rolls.begin(), rolls.end());
//       // TODO: binary_search(310)?  kitne rolls < 300?  kitne in [100,400]?
//       return 0;
//   }

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <vector>

using namespace std;

void show(const string& tag, const vector<int>& v) {
    cout << tag;
    for (int x : v) cout << x << " ";
    cout << "\n";
}

// ---------- SOLUTION 1 ----------
// sort ascending/descending — O(n log n) (Introsort ke n levels, har level pe O(n))
void sol1() {
    cout << "\n=== TASK 1 ===\n";
    vector<int> marks = {72, 45, 88, 55, 90};
    sort(marks.begin(), marks.end());                 // upkar lok
    show("Ascending  : ", marks);
    sort(marks.rbegin(), marks.rend());               // reverse iterators = descending
    show("Descending : ", marks);
}

// ---------- SOLUTION 2 ----------
// top-3 — O(n log n) sort phir O(1) access
void sol2() {
    cout << "\n=== TASK 2 ===\n";
    vector<int> m = {45, 12, 88, 23, 90, 67, 41};
    sort(m.begin(), m.end());                          // ascending
    cout << "Largest 3: ";
    for (int i = (int)m.size() - 3; i < (int)m.size(); ++i)
        cout << m[i] << " ";                            // last 3 sabse bade
    cout << "\n";
}

// ---------- SOLUTION 3 ----------
// count — O(n) single pass
void sol3() {
    cout << "\n=== TASK 3 ===\n";
    vector<int> v = {42, 7, 42, 13, 42, 42, 8, 1, 42, 5, 0, 42, 9, 2, 3};
    cout << "42 appears : " << count(v.begin(), v.end(), 42) << " times\n";
}

// ---------- SOLUTION 4 ----------
// accumulate — O(n) pass, ek hi fold
void sol4() {
    cout << "\n=== TASK 4 ===\n";
    vector<int> exp = {1200, 950, 450, 2300, 540};
    int total = accumulate(exp.begin(), exp.end(), 0); // init 0 add sab
    double avg = (double)total / exp.size();           // int divide = truncation, pehle cast
    cout << "Total : " << total
         << "\nAverage : " << fixed << setprecision(2) << avg << "\n";
}

// ---------- SOLUTION 5 ----------
// rotate — O(n) swaps, middle element ko naya begin bana do
void sol5() {
    cout << "\n=== TASK 5 ===\n";
    vector<int> q = {1, 2, 3, 4, 5};
    rotate(q.begin(), q.begin() + 2, q.end());         // left rotate by 2
    show("Left rotate by 2 : ", q);
}

// ---------- SOLUTION 6 ----------
// sorted-range tools — O(n log n) sort + O(log n) lookups
void sol6() {
    cout << "\n=== TASK 6 ===\n";
    vector<int> rolls = {102, 540, 310, 88, 245};
    sort(rolls.begin(), rolls.end());                  // sorted hogya {88,102,245,310,540}
    show("Sorted : ", rolls);

    // existence — O(log n)
    cout << "310 exists? " << (binary_search(rolls.begin(), rolls.end(), 310)
                                    ? "HAAN" : "NAHI") << "\n";

    // how many < 300 → lower_bound(300) ka index hi count hai (0-indexed)
    auto lb = lower_bound(rolls.begin(), rolls.end(), 300);
    cout << "rolls < 300  : " << (lb - rolls.begin()) << " students\n";

    // how many in [100, 400] → upper_bound(400) - lower_bound(100)
    auto l = lower_bound(rolls.begin(), rolls.end(), 100);
    auto u = upper_bound(rolls.begin(), rolls.end(), 400);
    cout << "rolls in [100,400] : " << (u - l) << " students\n";
}

int main() {
    sol1();
    sol2();
    sol3();
    sol4();
    sol5();
    sol6();
    return 0;
}