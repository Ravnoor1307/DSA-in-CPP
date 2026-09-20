/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_open_addressing_quadratic_probing.cpp
│
│ REAL-WORLD SCENARIO:
│ Parking lot me next-next slot linearly nahi, balki 1², 2², 3² jump karke check karte hain. Quadratic probing clustering ko reduce karne ki attempt hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Initial index = key % tableSize.
│ 2. Probe formula: `(hash + i*i) % tableSize`.
│ 3. i=0,1,2,3,... try karo.
│ 4. Linear probing primary clustering create karta hai.
│ 5. Quadratic probing jumps spread karta hai, but table size/load factor carefully choose karna hota hai.
│ 6. Search same quadratic sequence follow karta hai.
│
│ ASCII VISUAL / HASH TABLE STATE:
│ tableSize=7, keys 10,17,24
│ all hash to 3.
│
│ 10: i=0 -> (3+0²)%7=3
│ 17: i=0 slot3 full; i=1 -> (3+1)%7=4
│ 24: i=0 slot3 full; i=1 slot4 full; i=2 -> (3+4)%7=0
│
│ Table:
│ 0:24 1:_ 2:_ 3:10 4:17 5:_ 6:_
│ Jumps avoid one long straight cluster.
│
│ DRY RUN:
│ insert 24 probe sequence:
│ i=0 idx3 full
│ i=1 idx4 full
│ i=2 idx0 empty -> insert
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - Average with good load factor: few probes -> O(1).
│ - Worst case may try many slots up to tableSize.
│ -> Worst Time Complexity = O(n).
│ - Probe formula uses constant arithmetic each try.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Table array size tableSize.
│ -> Space Complexity = O(tableSize).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class QuadraticProbingHash {
    vector<int> table;
    const int EMPTY = -1;
public:
    explicit QuadraticProbingHash(int size) : table(size, EMPTY) {}
    void insert(int key) {
        int size = table.size();
        int h = key % size;
        for (int i = 0; i < size; i++) {
            int idx = (h + i * i) % size;
            if (table[idx] == EMPTY) {
                table[idx] = key;
                cout << "insert " << key << " at slot " << idx << " using i=" << i << "\n";
                return;
            }
        }
    }
    bool search(int key) const {
        int size = table.size();
        int h = key % size;
        for (int i = 0; i < size; i++) {
            int idx = (h + i * i) % size;
            if (table[idx] == EMPTY) return false;
            if (table[idx] == key) return true;
        }
        return false;
    }
    void print() const {
        for (int i = 0; i < (int)table.size(); i++) cout << i << ":" << table[i] << " ";
        cout << "\n";
    }
};

int main() {
    QuadraticProbingHash ht(7);
    ht.insert(10);
    ht.insert(17);
    ht.insert(24);
    ht.print();
    cout << "search 24 = " << (ht.search(24) ? "FOUND" : "NOT FOUND") << "\n";
    return 0;
}

/*
OUTPUT:
insert 10 at slot 3 using i=0
insert 17 at slot 4 using i=1
insert 24 at slot 0 using i=2
0:24 1:-1 2:-1 3:10 4:17 5:-1 6:-1
search 24 = FOUND
*/

