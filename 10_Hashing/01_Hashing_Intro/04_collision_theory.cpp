/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_collision_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Cloak room me do students ko same cabin number token mil jaye to conflict hota hai. Hash table me do keys same index par aa jaye to collision hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Collision = different keys same hash index.
│ 2. Example: 23%10=3 and 33%10=3.
│ 3. Dono bucket 3 me jaana chahte hain.
│ 4. Collision handling techniques: chaining, linear probing, quadratic probing.
│ 5. Collision badhne se O(1) average degrade ho sakta hai.
│ 6. Good hash function + resizing collision control me help karte hain.
│
│ ASCII VISUAL / HASH TABLE STATE:
│ tableSize=10
│
│ 23 % 10 = 3
│ 33 % 10 = 3
│
│ Bucket 3 conflict:
│ bucket[3]: 23
│            ↑
│           33 bhi yahin aana chahta hai -> COLLISION
│
│ Possible fixes:
│ Chaining: bucket[3]: 23 -> 33
│ Probing:  33 ko next free slot me daalo
│
│ DRY RUN:
│ Insert 23:
│ index=3, bucket empty, store 23.
│ Insert 33:
│ index=3, bucket already has 23.
│ collision detected.
│ Chaining would attach 33 in same bucket list.
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - Detecting hash index takes O(1).
│ - Handling cost depends on method and bucket/probe length.
│ - Average short chain/probe means O(1).
│ - Worst all collide means scan/probe n items.
│ -> Worst Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Collision handling may use linked lists or table slots.
│ -> Space Complexity remains O(tableSize + n).
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
    int a = 23, b = 33;
    int ia = a % tableSize;
    int ib = b % tableSize;
    cout << a << " % " << tableSize << " = " << ia << "\n";
    cout << b << " % " << tableSize << " = " << ib << "\n";
    if (ia == ib) cout << "Collision: both keys want bucket " << ia << "\n";
    cout << "Chaining visual: bucket[3]: 23 -> 33\n";
    return 0;
}

/*
OUTPUT:
23 % 10 = 3
33 % 10 = 3
Collision: both keys want bucket 3
Chaining visual: bucket[3]: 23 -> 33
*/

