/*
═══════════════════════════════════════════════
 TASK SET — STL INTRODUCTION
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A school clerk must compile a students list:
   add names, sort them alphabetically, and check whether a specific
   student is enrolled — every single day.

🧠 HOW TO SOLVE: Use vector for storage, sort() for ordering and
   find() for searching. Always guard results with end() checks.

 TASKS (EASY → HARD):

 5) EASY — "Sort My Marks"
    Given marks of 6 students in a vector, sort them in ascending
    order and print. Also print the highest mark (last element).
    💡 HINT: sort(v.begin(), v.end()); highest is v.back().
    ✏️ STARTER CODE:
    // vector<int> marks = {78, 91, 63, 85, 72, 96};
    // TODO: sort marks and print them + highest mark

 6) EASY — "Find The Ruler"
    Village head wants to know if a person named "Raj" is on the
    voter list. Use find() on a vector<string>.
    💡 HINT: auto it = find(v.begin(), v.end(), "Raj");
    ✏️ STARTER CODE:
    // vector<string> voters = {"Anu", "Raj", "Bob", "Sam"};
    // TODO: find "Raj" and print found/not found

 4) MEDIUM — "Sort Then Search"
    sort() requires random access; find() works on any order. Sort
    a vector of marks first, then find the position of a key.
    💡 HINT: index = it - v.begin();
    ✏️ STARTER CODE:
    // vector<int> marks = {34, 67, 12, 89, 45, 23};
    // TODO: sort, then find 45 and print its sorted position

 3) MEDIUM — "Count The Boys"
    Given a list of names, count how many times "Aman" appears
    using the <algorithm> count() function.
    💡 HINT: int c = count(v.begin(), v.end(), "Aman");
    ✏️ STARTER CODE:
    // vector<string> names = {"Aman","Ria","Aman","Dev","Aman"};
    // TODO: count occurrences of "Aman"

 2) HARD — "Reverse The List"
    Someone gave you a list in descending order accidentally. Use
    reverse(v.begin(), v.end()) to fix ordering, then verify the
    list is ascending.
    💡 HINT: reverse flips the whole range in O(n).
    ✏️ STARTER CODE:
    // vector<int> v = {9, 7, 5, 3, 1};
    // TODO: reverse it and print; check if ascending after

 1) HARD — "Empire Sort With Functor"
    Sort marks DESCENDING using the functor greater<int>() as the
    third argument of sort().
    💡 HINT: sort(v.begin(), v.end(), greater<int>());
    ✏️ STARTER CODE:
    // vector<int> marks = {44, 91, 58, 37, 82};
    // TODO: sort descending with greater<int> and print
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // ========== TASK 5 — Sort My Marks ==========
    // EASY: basic sort + highest mark
    vector<int> marks = {78, 91, 63, 85, 72, 96};
    sort(marks.begin(), marks.end());          // ascending sort
    cout << "Marks sorted: ";
    for (int x : marks) cout << x << " ";
    cout << "| Highest = " << marks.back() << "\n\n";

    // ========== TASK 6 — Find The Ruler ==========
    // EASY: find() par string; result end() pe check karo
    vector<string> voters = {"Anu", "Raj", "Bob", "Sam"};
    auto it = find(voters.begin(), voters.end(), "Raj");
    if (it != voters.end()) {
        cout << "Raj is on the voter list (index "
             << (it - voters.begin()) << ")\n\n";
    } else {
        cout << "Raj NOT on the list\n\n";
    }

    // ========== TASK 4 — Sort Then Search ==========
    // MEDIUM: sort pehle, phir find; index = it - begin
    vector<int> marks2 = {34, 67, 12, 89, 45, 23};
    sort(marks2.begin(), marks2.end());
    auto pos = find(marks2.begin(), marks2.end(), 45);
    if (pos != marks2.end()) {
        cout << "45 is at sorted position " << (pos - marks2.begin())
             << "\n\n";
    } else {
        cout << "45 missing\n\n";
    }

    // ========== TASK 3 — Count The Boys ==========
    // MEDIUM: count() ek hi call me frequency de deta hai
    vector<string> names = {"Aman", "Ria", "Aman", "Dev", "Aman"};
    int c = count(names.begin(), names.end(), "Aman");
    cout << "\"Aman\" appears " << c << " times\n\n";

    // ========== TASK 2 — Reverse The List ==========
    // HARD: descending diya tha; reverse se ascending ban jayega
    vector<int> v = {9, 7, 5, 3, 1};
    reverse(v.begin(), v.end());               // O(n) flip
    cout << "After reverse: ";
    for (int x : v) cout << x << " ";          // ab 1 3 5 7 9
    cout << "(ascending? yes)\n\n";

    // ========== TASK 1 — Empire Sort With Functor ==========
    // HARD: greater<int>() ek FUNCTOR hai jo ulte order me compare karta hai
    vector<int> marks3 = {44, 91, 58, 37, 82};
    sort(marks3.begin(), marks3.end(), greater<int>());
    cout << "Marks descending: ";
    for (int x : marks3) cout << x << " ";
    cout << "\n";

    return 0;
}