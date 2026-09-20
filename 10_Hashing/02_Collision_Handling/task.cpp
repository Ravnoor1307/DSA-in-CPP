/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_Collision_Handling task.cpp
│
│ REAL-WORLD SCENARIO:
│ Collision handling lab me same bucket conflict ko linked-list aur probing se solve karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Chaining hash table insert/search implement karo.
│ 2. Bucket linked-list visual print karo.
│ 3. Linear probing insert/search implement karo.
│ 4. Keys 10,17,24 se clustering show karo.
│ 5. Quadratic probing formula `(h+i*i)%m` implement karo.
│ 6. Chaining vs probing table comments me likho.
│ 7. Average O(1), worst O(n) reason explain karo.
│
│ HINTS:
│ - Chaining: vector<list<int>>.
│ - Linear: idx=(idx+1)%size.
│ - Quadratic: idx=(h+i*i)%size.
│
│ STARTER CODE:
│ int h = key % size;
│
│ SOLUTION: Neeche compact collision demo hai.
│
│ ASCII VISUAL / HASH TABLE STATE:
│ Chaining:
│ bucket[3]: 10 -> 17 -> 24
│
│ Linear probing:
│ 3:10 4:17 5:24 cluster
│
│ Quadratic:
│ 3:10 4:17 0:24
│
│ DRY RUN:
│ size7 keys 10,17,24 all hash to 3.
│ linear uses slots 3,4,5.
│ quadratic uses 3,4,0.
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - Hash O(1).
│ - Average chain/probe constant when alpha small -> O(1).
│ - Worst all n keys same path -> O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Chaining O(size+n), probing O(size).
│ -> Space depends on method.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int size = 7;
    vector<int> linear(size, -1);
    for (int key : {10,17,24}) {
        int idx = key % size;
        while (linear[idx] != -1) idx = (idx + 1) % size;
        linear[idx] = key;
    }
    cout << "Linear probing table: ";
    for (int i = 0; i < size; i++) cout << i << ":" << linear[i] << " ";
    cout << "\nChaining uses linked list inside bucket.\n";
    cout << "Quadratic uses (hash+i*i)%size.\n";
    return 0;
}

/*
OUTPUT:
Linear probing table: 0:-1 1:-1 2:-1 3:10 4:17 5:24 6:-1
Chaining uses linked list inside bucket.
Quadratic uses (hash+i*i)%size.
*/

