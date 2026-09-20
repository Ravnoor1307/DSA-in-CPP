/*
═══════════════════════════════════════════════
 TASK SET — STD::PAIR
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A results desk must glue each student's roll
   number to their marks, zip two separate lists into readable pairs,
   rank students by score, and find who scored the least.

🧠 HOW TO SOLVE: make_pair to join values, pair.first/.second to read,
   default lexicographic sort for ranking, custom comparator for
   second-value sorting.

 TASKS (EASY → HARD):

 5) EASY — "Zip Two Arrays"
    Given roll numbers {1,2,3} and marks {85,90,78}, glue the i-th
    element of each array into a pair and print each pair.
    💡 HINT: for loop i: pair<int,int> p = {rolls[i], marks[i]};
    ✏️ STARTER CODE:
    // vector<int> rolls = {1,2,3};
    // vector<int> marks = {85,90,78};
    // TODO: print (roll,marks) for each i

 6) EASY — "Show Only First"
    Given student pairs (name, marks), print only each student's
    name (the .first) in one line.
    💡 HINT: iterate vector<pair<string,int>> and read pr.first.
    ✏️ STARTER CODE:
    // vector<pair<string,int>> s = {{"Aman",90},
    //                               {"Ria",84},{"Dev",77}};
    // TODO: print all names only

 4) MEDIUM — "Sort By Second Value"
    Given pairs (student, marks), rank them in DESCENDING order of
    marks. A default sort orders by .first — so provide a lambda.
    💡 HINT: sort(s.begin(), s.end(),
        [](auto& a, auto& b){ return a.second > b.second; });
    ✏️ STARTER CODE:
    // vector<pair<string,int>> s = {{"Aman",90},
    //                               {"Ria",84},{"Dev",77}};
    // TODO: sort by second (descending) and print

 3) MEDIUM — "Return Min Pair"
    Given (roll, marks) pairs, find and return the pair with the
    minimum marks using min_element over pairs — but you must
    compare by .second.
    💡 HINT: min_element with comparator a.second < b.second (or
        shorter: min_element by lexicographic if rolls are unique).
    ✏️ STARTER CODE:
    // vector<pair<int,int>> v = {{1,85},{2,90},{3,78}};
    // TODO: find pair with min marks, print its (roll, marks)

 2) HARD — "Filter Pairs By Marks"
    Keep only pairs whose marks are >= 80; print the remaining pairs.
    💡 HINT: build a NEW vector and push_back passing pairs, then print.
    ✏️ STARTER CODE:
    // vector<pair<string,int>> s = {{"Aman",90},
    //                               {"Ria",72},{"Dev",77}};
    // TODO: vector<pair<string,int>> good; keep marks>=80; print good

 1) HARD — "Coordinates Distance"
    Given a point (x,y) as a pair and a list of other points, print
    the point from the list that is CLOSEST (Euclidean distance:
    sqrt(dx*dx + dy*dy) — you can compare squared distances).
    💡 HINT: track bestDist = large; for each pt compute
        dx*dx+dy*dy; keep smaller.
    ✏️ STARTER CODE:
    // pair<int,int> home = {0,0};
    // vector<pair<int,int>> pts = {{3,4},{6,8},{1,1}};
    // TODO: closest point to home, print it
═══════════════════════════════════════════════
*/

// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

void printPairs(const vector<pair<string, int>>& s) {
    // helper: (name,marks) list print karta hai
    for (const auto& pr : s)
        cout << "(" << pr.first << "," << pr.second << ") ";
    cout << "\n";
}

int main() {
    // ========== TASK 5 — Zip Two Arrays ==========
    // EASY: dono arrays ko pair me jodo
    vector<int> rolls = {1, 2, 3};
    vector<int> marks = {85, 90, 78};
    cout << "T5 Zipped pairs: ";
    for (size_t i = 0; i < rolls.size(); ++i) {
        pair<int, int> p = {rolls[i], marks[i]};
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << "\n";

    // ========== TASK 6 — Show Only First ==========
    // EASY: sirf .first print karna hai
    vector<pair<string, int>> s = {{"Aman", 90}, {"Ria", 84}, {"Dev", 77}};
    cout << "T6 Names: ";
    for (const auto& pr : s) cout << pr.first << " ";
    cout << "\n";

    // ========== TASK 4 — Sort By Second Value ==========
    // MEDIUM: descending by marks → lambda comparator needed
    vector<pair<string, int>> s2 = {{"Aman", 90}, {"Ria", 84}, {"Dev", 77}};
    sort(s2.begin(), s2.end(),
         [](const auto& a, const auto& b) { return a.second > b.second; });
    cout << "T4 Sorted by marks desc: ";
    printPairs(s2);                              // Aman, Ria, Dev order

    // ========== TASK 3 — Return Min Pair ==========
    // MEDIUM: min marks wala pair dhundho (compare by .second)
    vector<pair<int, int>> v = {{1, 85}, {2, 90}, {3, 78}};
    auto it = min_element(v.begin(), v.end(),
                          [](const auto& a, const auto& b) {
                              return a.second < b.second;
                          });
    if (it != v.end()) {
        cout << "T3 Min marks pair = (" << it->first << ","
             << it->second << ")\n";
    }

    // ========== TASK 2 — Filter Pairs By Marks ==========
    // HARD: nayi vector me >= 80 wale hi rakho
    vector<pair<string, int>> s3 = {{"Aman", 90}, {"Ria", 72}, {"Dev", 77}};
    vector<pair<string, int>> good;
    for (const auto& pr : s3) {
        if (pr.second >= 80) good.push_back(pr);
    }
    cout << "T4 Filtered (marks >= 80): ";
    printPairs(good);                            // sirf Aman

    // ========== TASK 1 — Coordinates Distance ==========
    // HARD: squared distance compare karke closest dhundho
    pair<int, int> home = {0, 0};
    vector<pair<int, int>> pts = {{3, 4}, {6, 8}, {1, 1}};
    size_t bestIdx = 0;
    int bestD = INT_MAX;
    for (size_t i = 0; i < pts.size(); ++i) {
        int dx = pts[i].first - home.first;
        int dy = pts[i].second - home.second;
        int d2 = dx * dx + dy * dy;              // squared distance
        if (d2 < bestD) { bestD = d2; bestIdx = i; } // naya closest mila
    }
    cout << "T1 Closest point to (0,0) = ("
         << pts[bestIdx].first << "," << pts[bestIdx].second
         << ")  d2=" << bestD << "\n";           // (1,1)

    return 0;
}