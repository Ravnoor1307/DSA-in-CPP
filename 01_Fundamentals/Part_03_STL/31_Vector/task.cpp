/*
═══════════════════════════════════════════════
 TASK SET — STD::VECTOR
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A class teacher maintains a daily attendance
   register. Every day names are added, someone leaves, the list must
   be reversed for checking, rotated for a new seating plan, and the
   sum of roll numbers computed for a quick sanity check.

🧠 HOW TO SOLVE: Use push_back/insert/erase for edits; at() for safe
   reads; two-pointer idea for reverse; index arithmetic for rotating.

 TASKS (EASY → HARD):

 5) EASY — "Remove Duplicates By Index"
    Given marks {10,20,10,30,20}, remove duplicate values so each
    mark appears once. Use erase() inside a loop.
    💡 HINT: compare v[i] with v[j]; when equal, erase and DON'T
        increment j (because the next element shifts into its place).
    ✏️ STARTER CODE:
    // vector<int> v = {10,20,10,30,20};
    // TODO: nested loop i, j; if (v[i]==v[j]) erase(v.begin()+j);

 6) EASY — "Reverse The Vector"
    Reverse a vector WITHOUT using reverse(). Swap first/last, then
    move inwards.
    💡 HINT: two pointers i=0, j=v.size()-1; swap(v[i],v[j]).
    ✏️ STARTER CODE:
    // vector<int> v = {5,4,3,2,1};
    // TODO: swap from both ends until middle

 4) MEDIUM — "Rotate Left By K"
    Rotate the vector left by k positions. {1,2,3,4,5} with k=2
    becomes {3,4,5,1,2}.
    💡 HINT: use vector<int> temp(k); copy first k, shift rest,
        paste temp at the end; or use two reverses.
    ✏️ STARTER CODE:
    // vector<int> v = {1,2,3,4,5}; int k = 2;
    // TODO: rotate left by k (modulo k if k > size)

 3) MEDIUM — "Running Sum"
    Given {1,2,3,4}, compute running sum {1,3,6,10} where each new
    element adds the previous running total.
    💡 HINT: v[i] += v[i-1] starting from i=1.
    ✏️ STARTER CODE:
    // vector<int> v = {1,2,3,4};
    // TODO: transform v into its running-sum version, print it

 2) HARD — "Biggest Element Without Sort"
    Find the largest element of a vector using only a loop (NO sort,
    NO std::max_element).
    💡 HINT: int mx = v[0]; compare every v[i] and update mx.
    ✏️ STARTER CODE:
    // vector<int> v = {34, 89, 21, 95, 67};
    // TODO: loop to find and print the maximum value and index

 1) HARD — "Roll Number Bigger Than K"
    Given a vector of roll numbers, delete every roll number that is
    SMALLER than a given threshold K using erase() carefully.
    💡 HINT: iterate while i < v.size(); if v[i] < K erase else i++.
    ✏️ STARTER CODE:
    // vector<int> rolls = {101, 207, 99, 305, 88}; int K = 150;
    // TODO: erase all rolls < K and print remaining rolls
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <vector>

using namespace std;

void printV(const vector<int>& v) {
    // helper: vector print karne ke liye
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    // ========== TASK 5 — Remove Duplicates By Index ==========
    // EASY: nested loop, erase pe j ko badhana nahi (shift hota hai)
    vector<int> v = {10, 20, 10, 30, 20};
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = i + 1; j < v.size(); ) {
            if (v[i] == v[j]) {
                v.erase(v.begin() + j);     // duplicate mila → hatao
            } else {
                ++j;                        // mila nahi → aage badho
            }
        }
    }
    cout << "T5 unique marks: ";
    printV(v);                              // 10 20 30

    // ========== TASK 6 — Reverse The Vector ==========
    // EASY: two-pointer swap approach
    vector<int> r = {5, 4, 3, 2, 1};
    size_t lo = 0, hi = r.size() - 1;
    while (lo < hi) {
        swap(r[lo], r[hi]);                 // ends swap karo
        ++lo; --hi;                          // andar ki taraf jao
    }
    cout << "T6 reversed: ";
    printV(r);                              // 1 2 3 4 5

    // ========== TASK 4 — Rotate Left By K ==========
    // MEDIUM: temp me first k save, rest shift, temp end pe daalo
    vector<int> rot = {1, 2, 3, 4, 5};
    int k = 2;
    k = k % (int)rot.size();                // k > size ho to modulo
    vector<int> temp(k);
    for (int i = 0; i < k; ++i) temp[i] = rot[i];
    for (size_t i = 0; i + k < rot.size(); ++i)
        rot[i] = rot[i + k];                // baaki elements left shift
    for (int i = 0; i < k; ++i)
        rot[rot.size() - k + i] = temp[i];  // temp wapas end me
    cout << "T4 after left rotate by 2: ";
    printV(rot);                            // 3 4 5 1 2

    // ========== TASK 3 — Running Sum ==========
    // MEDIUM: har element apne aage wale ka sum bano
    vector<int> rs = {1, 2, 3, 4};
    for (size_t i = 1; i < rs.size(); ++i)
        rs[i] += rs[i - 1];                 // prefix sum building
    cout << "T3 running sum: ";
    printV(rs);                             // 1 3 6 10

    // ========== TASK 2 — Biggest Element Without Sort ==========
    // HARD: loop se max dhundho, index bhi yaad rakho
    vector<int> big = {34, 89, 21, 95, 67};
    int mx = big[0], idx = 0;
    for (size_t i = 1; i < big.size(); ++i) {
        if (big[i] > mx) { mx = big[i]; idx = i; }
    }
    cout << "T2 max = " << mx << " at index " << idx << "\n";

    // ========== TASK 1 — Roll Number Bigger Than K ==========
    // HARD: erase karte waqt index badhana hai YA LIST shortening
    vector<int> rolls = {101, 207, 99, 305, 88};
    int Kval = 150;
    for (size_t i = 0; i < rolls.size(); ) {
        if (rolls[i] < Kval) {
            rolls.erase(rolls.begin() + i); // erase se element shift
        } else {
            ++i;                            // tabhi hi aage badho
        }
    }
    cout << "T1 rolls >= " << Kval << ": ";
    printV(rolls);                          // 207 305

    return 0;
}