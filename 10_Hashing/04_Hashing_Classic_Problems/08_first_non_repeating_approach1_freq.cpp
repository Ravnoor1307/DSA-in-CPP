/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 08_first_non_repeating_approach1_freq.cpp
│
│ REAL-WORLD SCENARIO:
│ Strings me first non-repeating char jaisa pattern arrays par bhi apply hota hai. Pehle frequency banao, phir original order me first freq==1 dhundho.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. PASS 1: array element frequency count.
│ 2. PASS 2: original order scan.
│ 3. First element with freq==1 return.
│ 4. This is same as strings frequency pattern, but key int hai.
│ 5. Average O(n).
│
│ ASCII VISUAL / HASH STATE:
│ arr=[4,5,1,2,1,4,5]
│ freq:
│ 4:2,5:2,1:2,2:1
│ scan original:
│ 4 no, 5 no, 1 no, 2 yes
│ answer=2
│
│ DRY RUN:
│ pass1 counts all.
│ pass2 index0 4 count2 skip.
│ index1 5 count2 skip.
│ index2 1 count2 skip.
│ index3 2 count1 return.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - PASS 1 n increments.
│ - PASS 2 up to n checks.
│ -> Average Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map stores d distinct elements.
│ -> Space Complexity = O(d), worst O(n).
│ APPROACH COMPARISON TABLE:
│ Nested count = ask full line for each value, O(n²) time/O(1) space.
│ Frequency map = count once then scan order, O(n) average time/O(n) space.
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

int firstNonRepeating(const vector<int>& arr) {
    unordered_map<int,int> freq;
    for (int x : arr) freq[x]++;
    for (int x : arr) if (freq[x] == 1) return x;
    return -1;
}

int main() {
    vector<int> arr = {4,5,1,2,1,4,5};
    cout << "First non-repeating element = " << firstNonRepeating(arr) << "\n";
    return 0;
}

/*
OUTPUT:
First non-repeating element = 2
*/

