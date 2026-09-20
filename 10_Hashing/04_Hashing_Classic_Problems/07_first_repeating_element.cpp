/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_first_repeating_element.cpp
│
│ REAL-WORLD SCENARIO:
│ Ticket line me pehla person jiska ticket number baad me repeat hota hai, woh first repeating element hai. Frequency plus left-to-right scan se milta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. PASS 1: frequency of every element count karo.
│ 2. PASS 2: array left to right scan karo.
│ 3. First element with freq>1 return karo.
│ 4. This gives first by index, not smallest value.
│ 5. Alternative right-to-left seen set bhi possible hai.
│
│ ASCII VISUAL / HASH STATE:
│ arr=[10,5,3,4,3,5,6]
│ freq:
│ 10:1, 5:2, 3:2, 4:1, 6:1
│
│ scan left:
│ 10 freq1 skip
│ 5 freq2 -> first repeating element = 5
│
│ Even though 3 repeats earlier second occurrence, first repeating by first index is 5.
│
│ DRY RUN:
│ pass1 builds counts.
│ pass2 index0 10 not repeat.
│ index1 5 count2, answer 5.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - PASS 1 scans n elements.
│ - PASS 2 scans up to n elements.
│ - Total 2n average hash operations.
│ -> Average Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map stores d distinct elements.
│ -> Space Complexity = O(d), worst O(n).
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

int firstRepeating(const vector<int>& arr) {
    unordered_map<int,int> freq;
    for (int x : arr) freq[x]++;
    for (int x : arr) if (freq[x] > 1) return x;
    return -1;
}

int main() {
    vector<int> arr = {10,5,3,4,3,5,6};
    cout << "First repeating element = " << firstRepeating(arr) << "\n";
    return 0;
}

/*
OUTPUT:
First repeating element = 5
*/

