/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_open_addressing_linear_probing.cpp
│
│ REAL-WORLD SCENARIO:
│ Parking lot me assigned slot full ho to driver next slot, phir next slot check karta hai. Linear probing collision par linearly next empty slot dhundhta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Hash index = key % tableSize.
│ 2. Agar slot empty hai, insert.
│ 3. Agar occupied hai, next index `(idx+1)%tableSize` check karo.
│ 4. Repeat until empty slot or table full.
│ 5. Search bhi same probe sequence follow karta hai.
│ 6. Problem: clustering, continuous filled blocks ban jaate hain.
│
│ ASCII VISUAL / HASH TABLE STATE:
│ tableSize=7, keys 10,17,24
│ 10%7=3 -> slot3
│ 17%7=3 collision -> slot4
│ 24%7=3 collision -> slot4 full -> slot5
│
│ Table:
│ 0:_ 1:_ 2:_ 3:10 4:17 5:24 6:_
│                 └── cluster grows here
│
│ Clustering: new collided keys same block me jama hote jaate hain.
│
│ DRY RUN:
│ insert 10: idx3 empty.
│ insert 17: idx3 full, idx4 empty.
│ insert 24: idx3 full, idx4 full, idx5 empty.
│ search 24: check idx3,idx4,idx5 found.
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - Average with low load factor: few probes -> O(1).
│ - Worst case cluster/table nearly full: may inspect n slots.
│ -> Worst Time Complexity = O(n).
│ - Insert 24 dry run probes 3 slots: index3,4,5.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Table array size tableSize.
│ - No extra linked nodes.
│ -> Space Complexity = O(tableSize).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class LinearProbingHash {
    vector<int> table;
    const int EMPTY = -1;
public:
    explicit LinearProbingHash(int size) : table(size, EMPTY) {}
    void insert(int key) {
        int size = table.size();
        int idx = key % size;
        int start = idx;
        while (table[idx] != EMPTY) {
            idx = (idx + 1) % size; // agla slot check
            if (idx == start) return;
        }
        table[idx] = key;
        cout << "insert " << key << " at slot " << idx << "\n";
    }
    bool search(int key) const {
        int size = table.size();
        int idx = key % size;
        int start = idx;
        while (table[idx] != EMPTY) {
            if (table[idx] == key) return true;
            idx = (idx + 1) % size;
            if (idx == start) break;
        }
        return false;
    }
    void print() const {
        for (int i = 0; i < (int)table.size(); i++) cout << i << ":" << table[i] << " ";
        cout << "\n";
    }
};

int main() {
    LinearProbingHash ht(7);
    ht.insert(10);
    ht.insert(17);
    ht.insert(24);
    ht.print();
    cout << "search 24 = " << (ht.search(24) ? "FOUND" : "NOT FOUND") << "\n";
    return 0;
}

/*
OUTPUT:
insert 10 at slot 3
insert 17 at slot 4
insert 24 at slot 5
0:-1 1:-1 2:-1 3:10 4:17 5:24 6:-1
search 24 = FOUND
*/

