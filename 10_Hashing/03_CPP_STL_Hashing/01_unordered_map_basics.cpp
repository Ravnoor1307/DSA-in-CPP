/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_unordered_map_basics.cpp
│
│ REAL-WORLD SCENARIO:
│ Phone contact app me name se phone number seedha milta hai. `unordered_map` key-value pairs ko average O(1) lookup ke saath store karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. `unordered_map<Key,Value>` hash table based container hai.
│ 2. `m[key] = value` insert/update karta hai.
│ 3. `m.find(key)` iterator return karta hai; end means absent.
│ 4. `m.count(key)` 0 ya 1 batata hai for unique keys.
│ 5. Duplicate key insert karne par value update ho sakti hai using operator[].
│
│ ASCII VISUAL / HASH STATE:
│ Contact map visual:
│
│ key       value
│ Aman  ->  987
│ Neha  ->  876
│ Ravi  ->  765
│
│ Search:
│ key "Neha" -> hash("Neha") -> bucket -> value 876
│
│ m["Aman"] = 999 updates Aman phone.
│
│ DRY RUN:
│ insert Aman=987
│ insert Neha=876
│ count("Neha") returns 1
│ find("Ravi") initially end
│ m["Aman"]=999 updates old value.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - Insert/find/count compute hash of key.
│ - Average bucket length controlled by load factor.
│ - Average operation checks constant number of entries.
│ -> Average Time Complexity = O(1).
│ - Worst case many collisions can scan n entries.
│ -> Worst Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stores n key-value pairs.
│ -> Space Complexity = O(n).
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
    unordered_map<string, int> phone;
    phone["Aman"] = 987;
    phone["Neha"] = 876;
    phone["Ravi"] = 765;

    cout << "Neha phone = " << phone["Neha"] << "\n";
    cout << "count(Aman) = " << phone.count("Aman") << "\n";
    auto it = phone.find("Ravi");
    if (it != phone.end()) cout << "Ravi found with value " << it->second << "\n";
    phone["Aman"] = 999;
    cout << "Aman updated phone = " << phone["Aman"] << "\n";
    return 0;
}

/*
OUTPUT:
Neha phone = 876
count(Aman) = 1
Ravi found with value 765
Aman updated phone = 999
*/

