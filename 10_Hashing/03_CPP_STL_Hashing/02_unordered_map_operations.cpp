/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_unordered_map_operations.cpp
│
│ REAL-WORLD SCENARIO:
│ Inventory shop me item name se quantity update, erase, and print karni hoti hai. `unordered_map` insert/erase/iterate operations provide karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. `insert({key,value})` new pair insert karta hai.
│ 2. `m[key]++` frequency/count update pattern hai.
│ 3. `erase(key)` key remove karta hai.
│ 4. Iteration key-value pairs visit karti hai; order fixed/sorted nahi hota.
│ 5. Average insert/erase/find O(1), worst collision O(n).
│
│ ASCII VISUAL / HASH STATE:
│ Inventory visual:
│ rice  -> 5
│ milk  -> 2
│ bread -> 4
│
│ erase milk:
│ rice  -> 5
│ bread -> 4
│
│ Note: unordered_map iteration random-looking ho sakta hai, sorted order guarantee nahi.
│
│ DRY RUN:
│ insert rice5, milk2, bread4.
│ update rice += 1 -> 6.
│ erase milk.
│ iterate remaining keys rice/bread.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - insert/erase average uses hash + small bucket/probe.
│ - If load factor controlled, checked entries constant.
│ -> Average Time Complexity = O(1) per operation.
│ - Iterating all pairs visits n entries.
│ -> Iteration Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map stores n pairs.
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
    unordered_map<string, int> stock;
    stock.insert({"rice", 5});
    stock.insert({"milk", 2});
    stock.insert({"bread", 4});
    stock["rice"]++;
    stock.erase("milk");

    vector<string> keys = {"bread", "rice"}; // deterministic print order for demo
    for (const string& key : keys) {
        if (stock.count(key)) cout << key << " -> " << stock[key] << "\n";
    }
    cout << "unordered_map iteration order itself is not sorted.\n";
    return 0;
}

/*
OUTPUT:
bread -> 4
rice -> 6
unordered_map iteration order itself is not sorted.
*/

