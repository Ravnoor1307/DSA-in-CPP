/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_map_vs_unordered_map.cpp
│
│ REAL-WORLD SCENARIO:
│ Library catalog sorted alphabetically chahiye to `map`; fastest average lookup chahiye and order matter nahi karta to `unordered_map`.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. `map` balanced BST based hota hai, keys sorted order me milti hain.
│ 2. `unordered_map` hash table based hota hai, order sorted nahi hota.
│ 3. map operations O(log n) because tree height log n.
│ 4. unordered_map operations average O(1), worst O(n).
│ 5. Sorted output/range queries: map.
│ 6. Fast frequency/lookup: unordered_map.
│
│ ASCII VISUAL / HASH STATE:
│ MASTER TABLE:
│ +----------------+----------------------+----------------------+
│ | Feature        | map                  | unordered_map        |
│ +----------------+----------------------+----------------------+
│ | Internal       | balanced tree        | hash table           |
│ | Order          | sorted keys          | no sorted order      |
│ | Search/insert  | O(log n)             | O(1) avg, O(n) worst |
│ | Use when       | sorted output needed | fastest avg lookup   |
│ +----------------+----------------------+----------------------+
│
│ Tree height proof: n/2^k=1 -> k=log₂n.
│
│ DRY RUN:
│ Insert keys 3,1,2.
│ map iteration prints 1,2,3 sorted.
│ unordered_map may print any order.
│ Choose according to output requirement.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - map tree search goes one level down each comparison.
│ - Balanced tree height k where n/2^k=1, so k=log₂n.
│ -> map Time Complexity = O(log n).
│ - unordered_map average bucket length constant with good hashing.
│ -> unordered_map Average Time Complexity = O(1).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Both store n key-value pairs.
│ -> Space Complexity = O(n).
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
    map<int, string> ordered;
    unordered_map<int, string> hashed;
    for (int key : {3, 1, 2}) {
        ordered[key] = "val" + to_string(key);
        hashed[key] = "val" + to_string(key);
    }
    cout << "map sorted keys: ";
    for (const auto& p : ordered) cout << p.first << " ";
    cout << "\nunordered_map has average O(1) lookup but no sorted order.\n";
    return 0;
}

/*
OUTPUT:
map sorted keys: 1 2 3
unordered_map has average O(1) lookup but no sorted order.
*/

