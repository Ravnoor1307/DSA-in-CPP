/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_union_intersection_arrays_set.cpp
│
│ REAL-WORLD SCENARIO:
│ Two classes ke student lists ka union all unique students, intersection common students hota hai. Hash set se membership fast hoti hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Union: both arrays ke elements set me insert karo.
│ 2. Intersection: first array set me insert karo, second array ke elements check karo.
│ 3. Common element answer set me insert karo to duplicates avoid hon.
│ 4. Average membership O(1).
│ 5. Total O(n+m) average.
│
│ ASCII VISUAL / HASH STATE:
│ A=[1,2,3,4], B=[3,4,5]
│
│ Union set: {1,2,3,4,5}
│ Intersection set: {3,4}
│
│ Visual:
│ A circle: 1,2,(3,4)
│ B circle: (3,4),5
│
│ DRY RUN:
│ insert A into seen: 1,2,3,4
│ scan B:
│ 3 in seen -> common
│ 4 in seen -> common
│ 5 absent -> not common
│ union inserts all A and B unique.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - Insert n elements of A into set.
│ - Union inserts n+m elements average O(1) each.
│ - Intersection scans m elements after seen built.
│ -> Average Time Complexity = O(n+m).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Sets store up to n+m distinct values.
│ -> Space Complexity = O(n+m).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    vector<int> A = {1,2,3,4};
    vector<int> B = {3,4,5};
    unordered_set<int> uni;
    for (int x : A) uni.insert(x);
    for (int x : B) uni.insert(x);

    unordered_set<int> seen(A.begin(), A.end());
    unordered_set<int> inter;
    for (int x : B) if (seen.count(x)) inter.insert(x);

    vector<int> u(uni.begin(), uni.end()), in(inter.begin(), inter.end());
    sort(u.begin(), u.end());
    sort(in.begin(), in.end());
    cout << "Union: "; for (int x : u) cout << x << " ";
    cout << "\nIntersection: "; for (int x : in) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Union: 1 2 3 4 5
Intersection: 3 4
*/

