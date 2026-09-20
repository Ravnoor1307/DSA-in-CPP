/*
═══════════════════════════════════════════════
 TASK SET — ITERATORS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A godown manager must inspect every carton,
   replace all damaged goods, reverse the delivery order, total the
   stock — all without ever knowing the boxes count by heart.

🧠 HOW TO SOLVE: Use begin()/end() loops with *it for access and
   writing, ++ to move, rbegin()/rend() for reverse walks.

 TASKS (EASY → HARD):

 5) EASY — "Print With Iterators"
    Print all elements of {10,20,30,40} using ONLY iterators
    (no index, no range-for).
    💡 HINT: for (auto i = v.begin(); i != v.end(); ++i) cout << *i;
    ✏️ STARTER CODE:
    // vector<int> v = {10,20,30,40};
    // TODO: iterate and print, using iterators only

 6) EASY — "Sum Via Iterator"
    Find the sum of all values in a vector by walking it with an
    iterator and adding *it to a total.
    💡 HINT: int total = 0; total += *i inside the loop.
    ✏️ STARTER CODE:
    // vector<int> v = {5, 10, 15, 20};
    // TODO: sum all elements with iterators, print the sum

 4) MEDIUM — "Replace All X With Y"
    In {7, -2, 7, 3, 7}, replace every 7 with 99 using a write
    through the iterator.
    💡 HINT: if (*i == 7) *i = 99;
    ✏️ STARTER CODE:
    // vector<int> v = {7, -2, 7, 3, 7};
    // TODO: replace ALL 7s with 99 via iterator and print

 3) MEDIUM — "Reverse Print Backwards"
    Print the vector {1,2,3,4,5} in REVERSE order using reverse
    iterators rbegin()/rend(), no std::reverse needed.
    💡 HINT: for (auto r = v.rbegin(); r != v.rend(); ++r)
    ✏️ STARTER CODE:
    // vector<int> v = {1,2,3,4,5};
    // TODO: print backwards with reverse iterators

 2) HARD — "Advance Three Steps"
    With the vector {10,20,30,40,50}, use std::advance to move an
    iterator 3 positions from begin and print the value; then move
    it BACK 2 positions and print again.
    💡 HINT: advance needs <iterator>; negative k is allowed only
        for bidirectional/random-access iterators.
    ✏️ STARTER CODE:
    // vector<int> v = {10,20,30,40,50};
    // auto it = v.begin();
    // TODO: advance +3, print *it; advance -2, print *it

 1) HARD — "Double Every Value"
    Given {2,4,6,8}, double each element IN PLACE using only an
    iterator (no index), then print the new vector and its sum.
    💡 HINT: *i = *i * 2 writes back through the iterator.
    ✏️ STARTER CODE:
    // vector<int> v = {2,4,6,8};
    // TODO: double in place via iterator, print each and the sum
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    // ========== TASK 5 — Print With Iterators ==========
    // EASY: pure iterator walking
    vector<int> v = {10, 20, 30, 40};
    cout << "T5 Print: ";
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << "\n";

    // ========== TASK 6 — Sum Via Iterator ==========
    // EASY: har value ko total me jodo
    vector<int> w = {5, 10, 15, 20};
    int total = 0;
    for (auto i = w.begin(); i != w.end(); ++i)
        total += *i;
    cout << "T6 Sum = " << total << "\n";            // 50

    // ========== TASK 4 — Replace All X With Y ==========
    // MEDIUM: write through iterator
    vector<int> r = {7, -2, 7, 3, 7};
    for (auto i = r.begin(); i != r.end(); ++i)
        if (*i == 7) *i = 99;                        // replace in place
    cout << "T4 After replace 7->99: ";
    for (auto x : r) cout << x << " ";
    cout << "\n";                                    // 99 -2 99 3 99

    // ========== TASK 3 — Reverse Print Backwards ==========
    // MEDIUM: rbegin/rend ulti taraf se
    vector<int> rev = {1, 2, 3, 4, 5};
    cout << "T3 Reverse: ";
    for (auto i = rev.rbegin(); i != rev.rend(); ++i)
        cout << *i << " ";
    cout << "\n";                                    // 5 4 3 2 1

    // ========== TASK 2 — Advance Three Steps ==========
    // HARD: advance generic hai, negative allowed for vector
    vector<int> adv = {10, 20, 30, 40, 50};
    auto it = adv.begin();
    advance(it, 3);
    cout << "T2 advance +3 -> " << *it << "\n";      // 40
    advance(it, -2);
    cout << "T2 advance -2 -> " << *it << "\n";      // 20

    // ========== TASK 1 — Double Every Value ==========
    // HARD: in-place write *i = *i * 2
    vector<int> d = {2, 4, 6, 8};
    int sum = 0;
    for (auto i = d.begin(); i != d.end(); ++i) {
        *i = *i * 2;                                 // element double
        sum += *i;
    }
    cout << "T1 Doubled: ";
    for (auto x : d) cout << x << " ";
    cout << "| Sum = " << sum << "\n";               // 4 8 12 16 | 40

    return 0;
}