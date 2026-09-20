/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_stl_hashing_frequency_pattern.cpp
│
│ REAL-WORLD SCENARIO:
│ Voting counter me candidate name aate hi `freq[name]++` kar do. Ye hashing ka universal frequency pattern hai aur DSA me bahut common hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. `unordered_map<Key,int> freq` banao.
│ 2. Har element/key ke liye `freq[key]++`.
│ 3. Missing key par default value 0 hoti hai, then increment hota hai.
│ 4. Frequency map strings, ints, chars sab par apply hota hai.
│ 5. Problems: anagram, distinct count, first repeat, majority, window counts.
│
│ ASCII VISUAL / HASH STATE:
│ votes: ram, sita, ram, geeta, ram
│
│ step states:
│ ram   -> {ram:1}
│ sita  -> {ram:1, sita:1}
│ ram   -> {ram:2, sita:1}
│ geeta -> {ram:2, sita:1, geeta:1}
│ ram   -> {ram:3, sita:1, geeta:1}
│
│ Pattern: freq[key]++
│
│ DRY RUN:
│ For each name in votes:
│ map lookup average O(1), value increment.
│ final ram=3, sita=1, geeta=1.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - Loop visits n items.
│ - Each freq update average O(1).
│ - Total = n * O(1).
│ -> Average Time Complexity = O(n).
│ - Worst hashing collisions can degrade updates, but STL average is expected O(1).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map stores d distinct keys.
│ -> Space Complexity = O(d), d <= n.
│ APPROACH COMPARISON TABLE:
│ Nested counting = ask whole crowd for each candidate, O(n²) time.
│ Hash freq = attendance/vote counter updated once per item, O(n) average time/O(d) space.
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
    vector<string> votes = {"ram", "sita", "ram", "geeta", "ram"};
    unordered_map<string, int> freq;
    for (const string& name : votes) freq[name]++; // universal pattern

    vector<string> names = {"geeta", "ram", "sita"};
    for (const string& name : names) cout << name << " -> " << freq[name] << "\n";
    return 0;
}

/*
OUTPUT:
geeta -> 1
ram -> 3
sita -> 1
*/

