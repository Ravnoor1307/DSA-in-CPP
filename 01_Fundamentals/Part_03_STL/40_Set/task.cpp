/*
═══════════════════════════════════════════════
 TASK SET — std::set
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A school wants a single sorted list of all
student IDs without duplicates, and it must also answer "which two
roll numbers sum to the target?" and "how many unique names were
entered?" — std::set makes unique + sorted + membership checks
natural. Tasks below go from warm-up to interview-style.

🧠 HOW TO SOLVE: Insert everything into the set — duplicates vanish.
For union/intersection problems, insert both arrays. For sum problems,
use find()/count() to check complement in O(log n) per element.
Sorting by value needs a copy into a vector of pairs. Read every
statement; HINT diya hai, pehle khud try karo.
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// ==================== TASK 1 (EASY) ====================
// problem: ek array de rahe hain jo numbers repeat kar sakta hai.
// Sirf UNIQUE numbers print karo, SORTED order me.
void printUniqueSorted(const vector<int>& arr) {
    set<int> s(arr.begin(), arr.end());   // array se seedha set banao — duplicates hat gaye
    for (int x : s) cout << x << " ";     // set khud sorted hota hai
    cout << endl;
}

// ==================== TASK 2 (EASY) ====================
// problem: do arrays ka UNION (saare unique elements, sorted me) print karo.
void unionOfTwoArrays(const vector<int>& a, const vector<int>& b) {
    set<int> s;
    for (int x : a) s.insert(x);          // pehli array ke elements daalo
    for (int x : b) s.insert(x);          // doosri array — duplicate hon to ignore
    for (int x : s) cout << x << " ";     // sorted + unique
    cout << endl;
}

// ==================== TASK 3 (EASY-MEDIUM) ====================
// problem: distinct elements (unique values) ki GINTI batani hai.
int countDistinct(const vector<int>& arr) {
    set<int> s(arr.begin(), arr.end());   // unique sirf set me jayenge
    return (int)s.size();                 // size hi count hai
}

// ==================== TASK 4 (MEDIUM) ====================
// problem: two-sum — kya koi two elements ka sum target ke barabar hai?
// Each element sirf ek baar use ho sakta hai, par elements repeat ho sakte hain.
bool hasPairWithSum(const vector<int>& arr, int target) {
    set<int> seen;                        // ab tak dekhe hua elements
    for (int x : arr) {
        int need = target - x;            // kitna complement chahiye
        if (seen.count(need)) return true;// complement pehle mila? pair mil gaya
        seen.insert(x);                   // current element record karo
    }
    return false;
}

// ==================== TASK 5 (MEDIUM) ====================
// problem: do numbers binary me mile? If set has kth smallest kya?
// Simulation: kth SMALLEST element find karo using lower_bound.
int kthSmallest(const set<int>& s, int k) {
    if (s.size() < (size_t)k) return -1;  // k size se bada — impossible
    auto it = s.begin();
    advance(it, k - 1);                    // iterator ko k-1 aage badhao
    return *it;
}

// ==================== TASK 6 (HARD) ====================
// problem: Array of pairs; un pairs ko merge karo jinke ranges
// overlap ho (interval merging) using set ke sorted order ka fayda.
vector<pair<int,int>> mergeIntervals(const vector<pair<int,int>>& intervals) {
    set<pair<int,int>> s;                  // (start,end) — start se sorted
    for (auto& p : intervals) s.insert(p);
    vector<pair<int,int>> res;
    for (auto& p : s) {
        if (res.empty() || p.first > res.back().second) {
            res.push_back(p);              // naya non-overlapping interval
        } else {
            res.back().second = max(res.back().second, p.second); // merge
        }
    }
    return res;
}

int main() {
    cout << "=== TASK 1: print unique sorted ===" << endl;
    printUniqueSorted({5, 3, 8, 3, 9, 1, 5});

    cout << "\n=== TASK 2: union of two arrays ===" << endl;
    unionOfTwoArrays({1, 2, 3, 4, 5}, {3, 4, 5, 6, 7});

    cout << "\n=== TASK 3: count distinct ===" << endl;
    cout << "distinct count = " << countDistinct({7, 7, 7, 1, 2, 2, 3}) << endl;

    cout << "\n=== TASK 4: pair with sum ===" << endl;
    cout << "hasPairWithSum({1,4,6,8}, 10) ? " << (hasPairWithSum({1,4,6,8}, 10) ? "YES" : "NO") << endl;
    cout << "hasPairWithSum({1,4,6,8}, 99) ? " << (hasPairWithSum({1,4,6,8}, 99) ? "YES" : "NO") << endl;

    cout << "\n=== TASK 5: kth smallest ===" << endl;
    set<int> st = {9, 3, 7, 1, 5};
    cout << "2nd smallest = " << kthSmallest(st, 2) << endl;
    cout << "10th smallest = " << kthSmallest(st, 10) << " (-1 means not enough)" << endl;

    cout << "\n=== TASK 6: merge intervals ===" << endl;
    vector<pair<int,int>> iv = {{1,3},{2,6},{8,10},{15,18}};
    for (auto& p : mergeIntervals(iv))
        cout << "[" << p.first << "," << p.second << "] ";
    cout << endl;

    return 0;
}

/* ------------------ EXPLANATION NOTES ------------------
TASK 1: set(arr.begin(), arr.end()) range constructor O(n log n).
        Output pehle se sorted; duplicates automatically ignore.
TASK 2: Union = dono arrays ke elements ek hi set me — total O((a+b) log(a+b)).
TASK 3: size() of set = number of distinct elements. Edge: empty → 0.
TASK 4: Normal two-sum via set. Per element count() O(log n),
        total O(n log n). Edge: agar "need == x" ho aur x ek hi baar hai,
        to count() tabhi true hota hai jab wo pehle aa chuka ho — isliye
        record insert karne se pehle check karte hain. Correct!
TASK 5: kth smallest via advance(). advance O(k).
TASK 6: Intervals sorted by start using set<pair>. Greedy merge:
        agar current start <= last end → merge, warna push. O(n log n).
*/