/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_chaining_approach.cpp
│
│ REAL-WORLD SCENARIO:
│ Railway counter par same counter number ke multiple passengers ek mini-line bana lete hain. Hash chaining me bucket ke andar linked list banti hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Table array of buckets hota hai.
│ 2. Har bucket ek linked list/list store karta hai.
│ 3. Collision par key same bucket list me append hoti hai.
│ 4. Search bucket list me scan karta hai.
│ 5. Average O(1) when load factor small.
│ 6. Worst O(n) when all keys same bucket me collide karte hain.
│
│ ASCII VISUAL / HASH TABLE STATE:
│ tableSize=5, hash=key%5
│ Keys: 10, 15, 20, 7
│
│ 10%5=0
│ 15%5=0
│ 20%5=0
│ 7%5=2
│
│ Buckets with linked lists:
│ 0: 10 -> 15 -> 20 -> NULL
│ 1: NULL
│ 2: 7 -> NULL
│ 3: NULL
│ 4: NULL
│
│ LL real use: collision chain.
│
│ DRY RUN:
│ insert 10 bucket0.
│ insert 15 collision bucket0, append after 10.
│ insert 20 collision bucket0, append after 15.
│ search 20 scans 10,15,20.
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - Hash computation O(1).
│ - Average chain length = load factor alpha = n/tableSize.
│ - If alpha constant, search/insert/delete average O(1).
│ - Worst all n keys in one chain, search scans n.
│ -> Worst Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Buckets array tableSize plus n list nodes.
│ -> Space Complexity = O(tableSize+n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class ChainingHash {
    vector<list<int>> table;
public:
    explicit ChainingHash(int size) : table(size) {}
    int hash(int key) const { return key % (int)table.size(); }
    void insert(int key) { table[hash(key)].push_back(key); }
    bool search(int key) const {
        int idx = hash(key);
        for (int x : table[idx]) if (x == key) return true;
        return false;
    }
    void print() const {
        for (int i = 0; i < (int)table.size(); i++) {
            cout << i << ": ";
            for (int x : table[i]) cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    ChainingHash ht(5);
    for (int key : {10, 15, 20, 7}) ht.insert(key);
    ht.print();
    cout << "search 20 = " << (ht.search(20) ? "FOUND" : "NOT FOUND") << "\n";
    return 0;
}

/*
OUTPUT:
0: 10 -> 15 -> 20 -> NULL
1: NULL
2: 7 -> NULL
3: NULL
4: NULL
search 20 = FOUND
*/

