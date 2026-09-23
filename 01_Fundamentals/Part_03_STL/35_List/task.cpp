/*
═══════════════════════════════════════════════
 TASK SET — STD::LIST
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A playlist app stores songs in a doubly-linked
    list so you can insert a track between two songs or remove one
    instantly without re-sorting. A DJ also loves merge-sort style
    mashups — two sorted playlists can be merged in one pass, and a block
    of songs can be spliced out of one playlist and dropped into another
    in O(1).

 🧠 HOW TO SOLVE: std::list gives O(1) insertion/erasure at an iterator
    but O(n) searching. Use advance()/lower_bound walk to find sorted
    positions. For duplicates, sort() first then unique() (it only kills
    CONSECUTIVE dupes). splice() moves whole sub-lists by pointer rewiring
    — remember the source list becomes empty after a full splice.

 MODES/TOPICS COVERED:
  1. Insert into a sorted list
  2. Remove duplicates
  3. Reverse a list
  4. Merge two sorted lists
  5. Remove all elements > x
  6. Splice two lists
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <list>
#include <string>
using namespace std;

void printList(const list<int>& l, const string& label) {
    cout << label << ": ";
    if (l.empty()) { cout << "(empty)"; }
    for (const auto& v : l) { cout << v << " "; }
    cout << endl;
}

// ---------- TASK 1: sorted insertion ----------
void task1() {
    cout << "\n=== TASK 1: Insert into sorted list ===\n";
    list<int> l = {10, 20, 30, 40};
    int val = 25;

    auto it = l.begin();
    while (it != l.end() && *it < val) { ++it; } // sahi jagah tak chalo
    l.insert(it, val);                           // O(n) walk, O(1) insert

    printList(l, "After insert(25)"); // expect 10 20 25 30 40
}

// ---------- TASK 2: remove duplicates ----------
void task2() {
    cout << "\n=== TASK 2: Remove all duplicates ===\n";
    list<int> l = {5, 5, 3, 3, 3, 8, 8, 8, 8};

    l.sort();   // unique() sirf CONSECUTIVE dupes hatata hai, isliye pehle sort
    l.unique(); // ab ek hi baar me sab deplicate value remove

    printList(l, "After unique"); // expect 3 5 8
}

// ---------- TASK 3: reverse ----------
void task3() {
    cout << "\n=== TASK 3: Reverse list ===\n";
    list<int> l = {1, 2, 3, 4, 5};

    l.reverse(); // pointer direction ulta karne se O(n) me reverse

    printList(l, "Reversed"); // expect 5 4 3 2 1
}

// ---------- TASK 4: merge two sorted lists ----------
void task4() {
    cout << "\n=== TASK 4: Merge two sorted lists ===\n";
    list<int> a = {1, 4, 7};
    list<int> b = {2, 3, 9};

    // dono pehle se sorted hain, isliye direct merge safe hai
    a.merge(b); // b ke saare nodes a me merge — O(n)

    printList(a, "Merged a");    // expect 1 2 3 4 7 9
    printList(b, "b (now empty)"); // expect (empty) — nodes move ho gaye
}

// ---------- TASK 5: remove elements > x ----------
void task5() {
    cout << "\n=== TASK 5: Remove all elements > x ===\n";
    list<int> l = {3, 9, 1, 9, 5, 9, 2};
    int x = 5;

    // lambda true return karta hai → us node ko remove kar do
    l.remove_if([&](int n) { return n > x; });

    printList(l, "After remove_if(>5)"); // expect 3 1 5 2
}

// ---------- TASK 6: splice two lists ----------
void task6() {
    cout << "\n=== TASK 6: Splice front of B into A ===\n";
    list<int> a = {1, 2, 3};
    list<int> b = {100, 200, 300};

    auto first = b.begin();
    auto last  = b.begin();
    advance(last, 2); // [first, last) = {100, 200} — 2 elements ka range

    // splice O(1): bass pointers relink hote hain, koi copy nahi
    a.splice(a.begin(), b, first, last);

    printList(a, "A after splice");   // expect 100 200 1 2 3
    printList(b, "B after splice");   // expect 300
}

int main() {
    cout << "========== STD::LIST TASK SET ==========\n";
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    cout << "\n========== ALL TASKS COMPLETE ==========\n";
    return 0;
}