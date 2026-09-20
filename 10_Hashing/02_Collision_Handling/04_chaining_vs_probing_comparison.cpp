/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_chaining_vs_probing_comparison.cpp
│
│ REAL-WORLD SCENARIO:
│ Collision handle karne ke do parking styles hain: same slot par mini-line banao (chaining) ya next available slot dhundo (probing). Use case ke according choose karte hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Chaining bucket ke andar linked list/vector list use karta hai.
│ 2. Probing same array ke andar alternate slots dhundhta hai.
│ 3. Linear probing simple but clustering create karta hai.
│ 4. Quadratic probing jumps use karta hai, clustering reduce karne ki attempt.
│ 5. Chaining deletion easier hoti hai.
│ 6. Probing cache-friendly ho sakta hai because data array me close rehta hai.
│
│ ASCII VISUAL / HASH TABLE STATE:
│ MASTER TABLE:
│ +----------------+----------------------+-----------------------+
│ | Feature        | Chaining             | Open Addressing       |
│ +----------------+----------------------+-----------------------+
│ | Storage        | bucket + linked list | same array slots      |
│ | Collision fix  | list me add          | next probe slot       |
│ | Load factor    | can be > 1           | should stay < 1       |
│ | Delete         | easier               | needs tombstone care  |
│ | Cache          | pointer jumps        | cache-friendly array  |
│ | Worst case     | O(n) chain           | O(n) probe            |
│ +----------------+----------------------+-----------------------+
│
│ DRY RUN:
│ For keys 10,17,24 with size7:
│ Chaining bucket3: 10 -> 17 -> 24
│ Linear probing slots: 3:10,4:17,5:24
│ Quadratic probing slots: 3:10,4:17,0:24
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - All methods compute hash in O(1).
│ - Average search/insert O(1) when load factor is controlled.
│ - Worst case chain/probe length can become n.
│ -> Worst Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Chaining: tableSize buckets + n nodes -> O(tableSize+n).
│ - Probing: tableSize slots -> O(tableSize).
│ APPROACH COMPARISON TABLE:
│ Chaining = same ticket counter par mini queue/LL, avg O(1), worst O(n), extra node pointers.
│ Linear probing = next parking slot walk, avg O(1), worst O(n), clustering risk.
│ Quadratic probing = square jumps in parking lot, avg O(1), worst O(n), less primary clustering.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    cout << "Chaining vs Probing comparison:\n";
    cout << "Chaining: bucket me linked list, deletion easy, avg O(1), worst O(n).\n";
    cout << "Linear probing: next slot walk, cache-friendly, clustering issue.\n";
    cout << "Quadratic probing: i^2 jumps, clustering reduce attempt.\n";
    cout << "Use chaining when deletion/simple collision handling important.\n";
    cout << "Use probing when memory locality important and load factor controlled.\n";
    return 0;
}

/*
OUTPUT:
Chaining vs Probing comparison:
Chaining: bucket me linked list, deletion easy, avg O(1), worst O(n).
Linear probing: next slot walk, cache-friendly, clustering issue.
Quadratic probing: i^2 jumps, clustering reduce attempt.
Use chaining when deletion/simple collision handling important.
Use probing when memory locality important and load factor controlled.
*/

