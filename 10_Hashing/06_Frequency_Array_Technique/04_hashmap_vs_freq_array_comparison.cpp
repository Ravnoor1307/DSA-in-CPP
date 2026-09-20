/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_hashmap_vs_freq_array_comparison.cpp
│
│ REAL-WORLD SCENARIO:
│ Roll numbers agar 0..100 fixed hain to lockers count[101] enough hain. Agar IDs huge/unknown like 1000000007 hain, hashmap better hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Frequency array tab best hai jab range small and non-negative manageable ho.
│ 2. Hashmap tab best hai jab values large, negative, string, or unknown range hon.
│ 3. Frequency array direct indexing, no collision.
│ 4. Hashmap flexible but collision/overhead possible.
│ 5. Choose based on value range and data type.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ MASTER TABLE:
│ +----------------+------------------------+----------------------+
│ | Feature        | Frequency Array        | Hashmap              |
│ +----------------+------------------------+----------------------+
│ | Keys           | small integer range    | any hashable key     |
│ | Access         | direct index           | hash(key)            |
│ | Collision      | none                   | possible             |
│ | Space          | O(range)               | O(distinct keys)     |
│ | Best when      | range small            | range large/unknown  |
│ +----------------+------------------------+----------------------+
│
│ Example:
│ marks 0..100 -> count[101]
│ names/large IDs -> unordered_map
│
│ DRY RUN:
│ arr marks [10,20,10] small range -> freq array.
│ arr IDs [1000000007, -5] impossible direct compact index -> hashmap.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Frequency array build n direct updates + range scan R.
│ -> O(n+R).
│ - Hashmap build n average O(1) updates + d scan.
│ -> O(n+d) average, d distinct.
│ - If R is huge, O(R) space/time scan is wasteful.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Frequency array O(R).
│ - Hashmap O(d), d distinct keys.
│ -> Choose smaller practical storage.
│ APPROACH COMPARISON TABLE:
│ Frequency array = fixed lockers for every possible mark, O(n+R) time/O(R) space.
│ Hashmap = only occupied lockers created by key, O(n) average time/O(d) space.
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
    cout << "Use frequency array when values are small range like 0..100.\n";
    cout << "Use unordered_map when keys are large, negative, strings, or range unknown.\n";
    cout << "Frequency array: O(n+R) time, O(R) space.\n";
    cout << "Hashmap: O(n) average time, O(d) space.\n";
    return 0;
}

/*
OUTPUT:
Use frequency array when values are small range like 0..100.
Use unordered_map when keys are large, negative, strings, or range unknown.
Frequency array: O(n+R) time, O(R) space.
Hashmap: O(n) average time, O(d) space.
*/

