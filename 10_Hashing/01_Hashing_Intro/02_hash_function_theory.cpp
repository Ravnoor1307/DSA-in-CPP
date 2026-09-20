/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_hash_function_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Cloak room token counter token number ko cabin number me convert karta hai. Hash function bhi key ko table ke valid index me convert karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Hash function key input leta hai.
│ 2. Output ek valid array index hota hai.
│ 3. Simple example: index = key % tableSize.
│ 4. Modulo result always 0 to tableSize-1 range me hota hai.
│ 5. Good hash function keys ko uniformly spread karta hai.
│ 6. Bad spread collisions badha sakta hai.
│
│ ASCII VISUAL / HASH TABLE STATE:
│ key -> [HASH FUNCTION] -> index -> bucket
│
│ tableSize = 10
│ 23 -> 23 % 10 -> 3 -> bucket[3]
│ 45 -> 45 % 10 -> 5 -> bucket[5]
│ 99 -> 99 % 10 -> 9 -> bucket[9]
│
│ Buckets:
│ 0: _
│ 1: _
│ 2: _
│ 3: 23
│ 4: _
│ 5: 45
│ ...
│ 9: 99
│
│ DRY RUN:
│ key=23, tableSize=10
│ quotient 2, remainder 3
│ index=3
│ key=33, 33%10=3, same index -> possible collision.
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - Simple hash key%tableSize uses one modulo operation.
│ - Modulo operation is treated as constant-time arithmetic.
│ -> Hash computation Time Complexity = O(1).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Hash function uses only key/tableSize/index variables.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

int main() {
    int tableSize = 10;
    vector<int> keys = {23, 45, 99, 33};
    for (int key : keys) {
        cout << key << " -> " << key << " % " << tableSize
             << " = " << hashFunction(key, tableSize) << "\n";
    }
    cout << "Notice: 23 and 33 both go to index 3, collision possible.\n";
    return 0;
}

/*
OUTPUT:
23 -> 23 % 10 = 3
45 -> 45 % 10 = 5
99 -> 99 % 10 = 9
33 -> 33 % 10 = 3
Notice: 23 and 33 both go to index 3, collision possible.
*/

