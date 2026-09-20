/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_hash_table_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Library index rack me har alphabet bucket hai. Book key hash hoke apne bucket me jaati hai; search/delete bhi same bucket se start hote hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Hash table = array of buckets.
│ 2. Insert: hash(key) nikaalo, bucket me key store karo.
│ 3. Search: same hash nikaalo, bucket me key check karo.
│ 4. Delete: same bucket me key find karke remove karo.
│ 5. Average O(1) tab hota hai jab keys buckets me evenly distribute hon.
│ 6. Worst case all keys one bucket me aa jaye to bucket scan O(n).
│
│ ASCII VISUAL / HASH TABLE STATE:
│ tableSize=5, hash=key%5
│ Insert 10 -> bucket0
│ Insert 21 -> bucket1
│ Insert 32 -> bucket2
│ Insert 15 -> bucket0 (collision chained)
│
│ Hash table buckets:
│ 0: 10 -> 15
│ 1: 21
│ 2: 32
│ 3: _
│ 4: _
│
│ Search 15: 15%5=0, scan bucket0 only.
│
│ DRY RUN:
│ insert 10: idx0, bucket0=[10]
│ insert 15: idx0, bucket0=[10,15]
│ search 15: idx0, compare 10 then 15 found
│ delete 10: idx0, remove from bucket0 -> [15]
│
│ FLOW OF EXECUTION:
│ input key(s) -> hash function -> index/bucket -> insert/search/delete result
│
│ COMPLEXITY CALCULATION:
│ - Hash computation O(1).
│ - Average bucket length = load factor alpha = n / tableSize.
│ - If table resizes so alpha stays constant, bucket scan is constant average.
│ -> Average insert/search/delete = O(1).
│ - Worst case all n keys collide in one bucket, search scans n keys.
│ -> Worst Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Table stores tableSize buckets and n keys.
│ -> Space Complexity = O(tableSize + n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class SimpleHashTable {
    vector<list<int>> table;
public:
    explicit SimpleHashTable(int size) : table(size) {}

    int hash(int key) const { return key % (int)table.size(); }

    void insert(int key) {
        int idx = hash(key);
        table[idx].push_back(key);
        cout << "insert " << key << " at bucket " << idx << "\n";
    }

    bool search(int key) const {
        int idx = hash(key);
        for (int value : table[idx]) if (value == key) return true;
        return false;
    }

    void eraseKey(int key) {
        int idx = hash(key);
        table[idx].remove(key);
        cout << "delete " << key << " from bucket " << idx << "\n";
    }

    void print() const {
        for (int i = 0; i < (int)table.size(); i++) {
            cout << i << ": ";
            for (int value : table[i]) cout << value << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    SimpleHashTable ht(5);
    ht.insert(10);
    ht.insert(21);
    ht.insert(32);
    ht.insert(15);
    ht.print();
    cout << "search 15 = " << (ht.search(15) ? "FOUND" : "NOT FOUND") << "\n";
    ht.eraseKey(10);
    ht.print();
    return 0;
}

/*
OUTPUT:
insert 10 at bucket 0
insert 21 at bucket 1
insert 32 at bucket 2
insert 15 at bucket 0
0: 10 -> 15 -> NULL
1: 21 -> NULL
2: 32 -> NULL
3: NULL
4: NULL
search 15 = FOUND
delete 10 from bucket 0
0: 15 -> NULL
1: 21 -> NULL
2: 32 -> NULL
3: NULL
4: NULL
*/

