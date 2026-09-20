/*
═══════════════════════════════════════════════
 TASK SET — 45_Custom_Comparator
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: Every ranking system runs on comparators — an
admission portal sorts students by marks (desc) and then by name (asc),
a music app sorts songs by cost then play count, and the hospital's
triage queue serves the most-serious patient first. One tiny (a,b) rule
gives all of them their exact order.
🧠 HOW TO SOLVE: translate the "words of the rule" into a comparator body
`(a,b)`: name the primary key, name the tie-breaker, then write it exactly
as "true when a must stand before b". For priority_queue remember the
mentality flips: comparator "greater-than" (a,b) produces a min-heap.
═══════════════════════════════════════════════
*/

// ---------------- TASK 1: EASY — Sort Students by Marks Desc, then Name Asc ----------------
// Sample: list of (name, marks) must print merit order: highest marks
// first; equals by alphabetical name.
// {("Ann",90),("Zoe",90),("Ram",72)} → Ann, Zoe, Ram
// 💡 HINT: if (a.marks != b.marks) return a.marks > b.marks;
//          else return a.name < b.name;   ← tie-break wala core
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   #include <string>
//   using namespace std;
//   struct Student { string name; int marks; };
//   int main() {
//       vector<Student> v = {{"Ann",90},{"Zoe",90},{"Ram",72},{"Bob",88}};
//       sort(v.begin(), v.end(), [](const Student& a, const Student& b) {
//           // TODO: marks desc, name asc
//       });
//       for (auto& s : v) cout << s.name << " " << s.marks << "\n";
//   }

// ---------------- TASK 2: EASY-MEDIUM — Sort Numbers by Last Digit ----------------
// Sample: {35, 12, 28, 41, 73} sorted by their units digit ascending →
// 41(1), 12(2), 73(3), 35(5), 28(8)
// 💡 HINT: return (a % 10) < (b % 10);  — compare karo only last digit.
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   using namespace std;
//   int main() {
//       vector<int> v = {35, 12, 28, 41, 73};
//       sort(v.begin(), v.end(), [](int a, int b) {
//           // TODO: return by last digit
//       });
//       for (int x : v) cout << x << " ";
//   }

// ---------------- TASK 3: MEDIUM — Custom priority_queue (min-heap of tasks by priority) ----------------
// Sample: tasks {(code, priority)} where SMALLER number = URGENT.
// Push {(102,1),(103,4),(104,2)} — top() must pop 102 first (priority 1),
// then 104 (2), then 103 (4). This is a MIN-heap by priority.
// 💡 HINT: priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>
//          gives min-heap on pair.first; OR write a functor
//          struct Cmp { bool operator()(...) const { return a.second > b.second; } };
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <queue>
//   #include <vector>
//   using namespace std;
//   int main() {
//       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//       pq.push({102,1}); pq.push({103,4}); pq.push({104,2});
//       // TODO: pop and print task ids in priority order
//   }

// ---------------- TASK 4: MEDIUM-HARD — Sort Pairs by Second, Tie by First Desc ----------------
// Sample: {(1,30),(4,10),(2,30),(3,20)} → (4,10),(3,20),(2,30),(1,30)
// (second asc; same second → first desc)
// 💡 HINT: if (a.second != b.second) return a.second < b.second;
//          return a.first > b.first;
//          Actually `sort` handles ties only if you say the rest explicitly — yahi do line complete order deti hain.
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   using namespace std;
//   int main() {
//       vector<pair<int,int>> v = {{1,30},{4,10},{2,30},{3,20}};
//       sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
//           // TODO: second asc, tie first desc
//       });
//       for (auto& p : v) cout << "(" << p.first << "," << p.second << ") ";
//   }

// ---------------- TASK 5: MEDIUM-HARD — Sort Strings by Length, Tie by Alphabet ----------------
// Sample: {"Zoe","Anna","Me","Li","Alexandra","Abe"} →
// Me(2), Li(2), Zoe(3), Abe(3), Anna(4), Alexandra(8)
// (length asc; same length → alphabetically asc)
// 💡 HINT: if (a.size() != b.size()) return a.size() < b.size();
//          return a < b;  ← default string comparator (alphabetical)
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   #include <string>
//   using namespace std;
//   int main() {
//       vector<string> v = {"Zoe","Anna","Me","Li","Alexandra","Abe"};
//       sort(v.begin(), v.end(), [](const string& a, const string& b) {
//           // TODO: length asc, tie alphabet asc
//       });
//       for (auto& s : v) cout << "\"" << s << "\" ";
//   }

// ---------------- TASK 6: HARD — Merge Two Sorted lists "by length" with a comparator ----------------
// Sample: language = {"go","c","rust","cpp","python"} and {"js","java","lua","c#"}
// merged list must be sorted by length asc ({go,c,c#,lua,js,java,cpp,rust,python}).
// 💡 HINT: either merge two vectors with std::merge(a.b, a.e, c.b, c.e, out, cmp)
//          or concatenate + sort. cmp = length asc lambda. merge guarantees O(n).
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <algorithm>
//   #include <vector>
//   #include <string>
//   using namespace std;
//   int main() {
//       vector<string> A = {"go","c","rust","cpp","python"};
//       vector<string> B = {"js","java","lua","c#"};
//       // TODO: sort each by length then std::merge with same comparator
//   }

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// ---------- SOLUTION 1 ----------
// rank list — comparator O(1) field compare, sort O(n log n)
void sol1() {
    cout << "\n=== TASK 1 ===\n";
    struct Student { string name; int marks; };
    vector<Student> v = {{"Ann",90},{"Zoe",90},{"Ram",72},{"Bob",88}};
    sort(v.begin(), v.end(), [](const Student& a, const Student& b) {
        if (a.marks != b.marks) return a.marks > b.marks; // pehli kundali
        return a.name < b.name;                            // doosri: naam a-z
    });
    for (auto& s : v) cout << s.name << " -> " << s.marks << "\n";
}

// ---------- SOLUTION 2 ----------
// last digit — har jodi pe O(1) mod compare
void sol2() {
    cout << "\n=== TASK 2 ===\n";
    vector<int> v = {35, 12, 28, 41, 73};
    sort(v.begin(), v.end(), [](int a, int b) {
        return (a % 10) < (b % 10);                       // sirf ikai ank dekho
    });
    for (int x : v) cout << x << " ";
    cout << "\n";
}

// ---------- SOLUTION 3 ----------
// min-heap priority — push/pop har ek O(log n), heapify walk
void sol3() {
    cout << "\n=== TASK 3 ===\n";
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({102,1}); pq.push({103,4}); pq.push({104,2});
    cout << "Pop order: ";
    while (!pq.empty()) {
        cout << "task" << pq.top().first << " ";
        pq.pop();
    }
    cout << "\n";
}

// ---------- SOLUTION 4 ----------
// pairs by second asc, tie first desc — complete ordering, no ambiguity
void sol4() {
    cout << "\n=== TASK 4 ===\n";
    vector<pair<int,int>> v = {{1,30},{4,10},{2,30},{3,20}};
    sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second != b.second) return a.second < b.second; // second kam ho to pehle
        return a.first > b.first;                             // barabar → first bada pehle
    });
    for (auto& p : v) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";
}

// ---------- SOLUTION 5 ----------
// strings length asc, tie alpha — O(k) string compare inside O(n log n)
void sol5() {
    cout << "\n=== TASK 5 ===\n";
    vector<string> v = {"Zoe","Anna","Me","Li","Alexandra","Abe"};
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size(); // chhota pehle
        return a < b;                                          // length barabar → a-z
    });
    for (auto& s : v) cout << "\"" << s << "\" ";
    cout << "\n";
}

// ---------- SOLUTION 6 ----------
// std::merge two sorted-by-length lists — O(A+B) single walk
void sol6() {
    cout << "\n=== TASK 6 ===\n";
    vector<string> A = {"go","c","rust","cpp","python"};
    vector<string> B = {"js","java","lua","c#"};

    // same comparator both sides — ye bhi strictly less-than contract follow karta hai
    auto byLen = [](const string& a, const string& b) { return a.size() < b.size(); };

    sort(A.begin(), A.end(), byLen);
    sort(B.begin(), B.end(), byLen);

    vector<string> out(A.size() + B.size());
    merge(A.begin(), A.end(), B.begin(), B.end(), out.begin(), byLen);

    for (auto& s : out) cout << "\"" << s << "\" ";
    cout << "\n";
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