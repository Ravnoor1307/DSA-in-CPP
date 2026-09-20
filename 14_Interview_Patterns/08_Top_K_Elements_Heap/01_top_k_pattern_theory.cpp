/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_top_k_pattern_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Topper shortlist me sirf best k candidates maintain karne hain. Heap of size k low-priority survivors ko quickly remove kar deta hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ THE RULE:
│ kth largest -> MIN heap of size k
│ kth smallest -> MAX heap of size k
│ top k frequent -> hashmap + heap
│ k closest -> heap by distance
│ stream kth largest -> min heap size k maintained continuously
│
│ kth largest example:
│ nums [3,2,1,5,6,4], k=2
│ min heap survivors after all: [5,6]
│ heap top = 5 = 2nd largest

│
│ STEP-BY-STEP DRY RUN:
│ Process each element:
│ push x
│ if heap size > k, pop worst survivor
│ At end exactly k best remain.

│
│ COMPLEXITY CALCULATION:
│ n elements processed.
│ Heap size never exceeds k+1.
│ push/pop each O(log k).
│ Total = O(n log k).
│ Space = O(k).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    cout << "Top-K rule sheet:\n";
    cout << "kth largest -> min heap size k\n";
    cout << "kth smallest -> max heap size k\n";
    cout << "frequent -> hashmap then heap\n";
    cout << "stream -> keep heap across calls\n";
    return 0;
}

/*
OUTPUT:
Top-K rule sheet:
kth largest -> min heap size k
kth smallest -> max heap size k
frequent -> hashmap then heap
stream -> keep heap across calls
*/

