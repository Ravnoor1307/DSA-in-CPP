/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_analyze_this_code_2.cpp
│
│ REAL-WORLD SCENARIO:
│ Tricky complexity snippets traffic intersections jaise hote hain: loops independent hain ya dependent? Input halve ho raha hai ya nested scan?
│
│ ASCII VISUAL / DP-COMPLEXITY STATE:
│ TRICKY SNIPPETS:
│
│ A. for i=0..n
│      for j=0; j<m
│    -> n*m -> O(nm)
│
│ B. for i=0; i<n; i++
│      for j=1; j<n; j*=2
│    -> n * log n -> O(n log n)
│
│ C. while n>1: n/=2
│    -> log n
│
│ D. recursive merge sort:
│    levels log n, each level n work -> O(n log n)
│
│ E. binary search:
│    n/2^k = 1 -> k=log₂n

│
│ STEP-BY-STEP DRY RUN:
│ n=8 log loop:
│ j=1,2,4 -> 3 iterations.
│ Since 8/2^k=1 -> k=3.
│ Outer n times => 8*3 operations.

│
│ COMPLEXITY CALCULATION:
│ Nested n and log loop:
│ Outer loop n iterations.
│ Inner loop log₂n iterations.
│ Total n*log₂n -> O(n log n).
│
│ Merge sort:
│ level count log₂n.
│ each level processes n elements in merging.
│ total n log n.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    int n = 8, ops = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j *= 2) {
            ops++;
        }
    }
    cout << "n log n ops for n=8 = " << ops << "\n";

    int halves = 0, x = n;
    while (x > 1) {
        x /= 2;
        halves++;
    }
    cout << "halve count = " << halves << " -> log2(8)\n";
    return 0;
}

/*
OUTPUT:
n log n ops for n=8 = 24
halve count = 3 -> log2(8)
*/

