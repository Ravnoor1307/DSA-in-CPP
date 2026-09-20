/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_why_hashing_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ School bag ke index page me chapter name se page number seedha mil jata hai. Cloak room me token number se cabin directly milta hai. Hashing ka goal bhi search ko average O(1) banana hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Array me normal search O(n) hota hai because har item check ho sakta hai.
│ 2. Sorted array me binary search O(log n) hota hai because half discard hota hai.
│ 3. Hashing key ko index me convert karke direct bucket tak pahunchata hai.
│ 4. Ideal case me one key -> one index -> direct access.
│ 5. Isliye insert/search/delete average O(1) possible hota hai.
│ 6. Average word important hai because collisions ho sakte hain.
│
│ ASCII VISUAL / HASH TABLE STATE:
│ Search comparison:
│
│ Linear search shelf:
│ [12][25][37][49][51]  target 49
│  1   2   3   4 checks -> O(n)
│
│ Binary search sorted shelf:
│ n -> n/2 -> n/4 -> ... -> 1 -> O(log n)
│
│ Hashing cloak room:
│ token 49 -> hash(49) -> bucket 9 -> direct check
│
│ key ──hash function──> index ──> bucket
│
│ DRY RUN:
│ Keys: 12, 25, 37, 49; tableSize=10
│ 12%10=2 -> bucket2
│ 25%10=5 -> bucket5
│ 37%10=7 -> bucket7
│ Search 49: 49%10=9, bucket9 checked directly.
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - Linear search worst case checks n elements -> O(n).
│ - Binary search halves: n/2^k=1 -> n=2^k -> k=log₂n -> O(log n).
│ - Hashing average case computes hash once and checks small bucket.
│ - If load factor stays small, bucket length is constant average.
│ -> Average Time Complexity = O(1).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Hash table has tableSize buckets and stores n keys.
│ -> Space Complexity = O(tableSize + n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<int> keys = {12, 25, 37, 49};
    int tableSize = 10;
    cout << "Hashing idea: key -> index using key % tableSize\n";
    for (int key : keys) {
        cout << "key " << key << " -> index " << (key % tableSize) << "\n";
    }
    cout << "Average search can be O(1) if collisions are controlled.\n";
    return 0;
}

/*
OUTPUT:
Hashing idea: key -> index using key % tableSize
key 12 -> index 2
key 25 -> index 5
key 37 -> index 7
key 49 -> index 9
Average search can be O(1) if collisions are controlled.
*/

