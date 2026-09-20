/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_Hashing_Intro task.cpp
│
│ REAL-WORLD SCENARIO:
│ Hashing lab me cloak room tokens ko bucket indexes me map karna hai, collisions identify karni hain, and average O(1) ka reason explain karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. key%tableSize hash function likho.
│ 2. Keys 12,25,37,49 ke indexes print karo.
│ 3. 23 and 33 collision show karo for tableSize 10.
│ 4. Simple vector<list<int>> hash table me insert implement karo.
│ 5. Search function implement karo.
│ 6. Delete function implement karo.
│ 7. Average O(1) vs worst O(n) comments me explain karo.
│
│ HINTS:
│ - index = key % tableSize.
│ - Collision means same index.
│ - Chaining uses linked list per bucket.
│
│ STARTER CODE:
│ vector<list<int>> table(size);
│ int idx = key % size;
│
│ SOLUTION: Neeche compact demo solution hai.
│
│ ASCII VISUAL / HASH TABLE STATE:
│ 23%10=3 and 33%10=3:
│ bucket[3]: 23 -> 33
│
│ Hash table:
│ 0: _
│ 1: _
│ 2: 12
│ ...
│
│ DRY RUN:
│ Insert 12 -> idx2.
│ Insert 22 -> idx2 collision, chain.
│ Search 22 -> idx2, scan bucket, found.
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - hash calculation O(1).
│ - average bucket length alpha=n/tableSize.
│ - if alpha constant, search/insert avg O(1).
│ - worst all n in one bucket -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - tableSize buckets + n keys.
│ -> Space Complexity = O(tableSize+n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int tableSize = 10;
    vector<list<int>> table(tableSize);
    vector<int> keys = {12, 22, 25};
    for (int key : keys) table[key % tableSize].push_back(key);

    cout << "bucket[2]: ";
    for (int x : table[2]) cout << x << " -> ";
    cout << "NULL\n";
    cout << "23%10=" << 23 % 10 << ", 33%10=" << 33 % 10 << " collision\n";
    return 0;
}

/*
OUTPUT:
bucket[2]: 12 -> 22 -> NULL
23%10=3, 33%10=3 collision
*/

