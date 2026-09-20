/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_CPP_STL_Hashing task.cpp
│
│ REAL-WORLD SCENARIO:
│ STL hashing lab me contacts, inventory, unique roll numbers, sorted map, and frequency pattern practice karni hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. unordered_map me name->phone store karo.
│ 2. find/count se key presence check karo.
│ 3. insert, erase, iterate operations demo karo.
│ 4. unordered_set me duplicates auto-remove show karo.
│ 5. map vs unordered_map sorted output difference show karo.
│ 6. freq[key]++ pattern se words count karo.
│ 7. Average O(1), worst O(n) reason comments me likho.
│
│ HINTS:
│ - unordered_map order sorted nahi hota.
│ - map sorted keys deta hai.
│ - count returns 0/1 for unique-key containers.
│
│ STARTER CODE:
│ unordered_map<string,int> freq;
│ freq[word]++;
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / HASH STATE:
│ votes ram,sita,ram:
│ ram -> 2
│ sita -> 1
│
│ unordered_set insert 5,2,5 -> unique {2,5}
│
│ DRY RUN:
│ map insert 3,1,2 -> iteration 1,2,3 sorted.
│ unordered_map gives no sorted guarantee.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - n freq updates, each average O(1) -> O(n).
│ - map operation tree height log: n/2^k=1 -> k=log₂n.
│ -> map O(log n), unordered_map O(1) avg.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stores d distinct keys/pairs.
│ -> Space Complexity = O(d).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    unordered_map<string,int> freq;
    for (string word : {"ram", "sita", "ram"}) freq[word]++;
    cout << "ram freq=" << freq["ram"] << "\n";

    unordered_set<int> st;
    for (int x : {5,2,5}) st.insert(x);
    cout << "unique size=" << st.size() << "\n";

    map<int,int> ordered;
    for (int x : {3,1,2}) ordered[x] = x;
    cout << "map keys: ";
    for (auto p : ordered) cout << p.first << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
ram freq=2
unique size=2
map keys: 1 2 3
*/

