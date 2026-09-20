/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_freq_array_small_range.cpp
│
│ REAL-WORLD SCENARIO:
│ Exam marks 0 se 100 ke beech hote hain. Range small fixed hai, isliye hashmap ki jagah count[101] array enough hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Jab values ka range small known ho, frequency array best hota hai.
│ 2. Example marks 0..100 => count[101].
│ 3. Har arr[i] ke liye count[arr[i]]++.
│ 4. Lookup direct index se O(1).
│ 5. No hashing collision because index direct value hai.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[10,20,10,5]
│ count[0..100]
│ count[5]=1
│ count[10]=2
│ count[20]=1
│
│ Direct box access:
│ value 10 -> count[10]
│
│ DRY RUN:
│ read 10 -> count[10]=1
│ read 20 -> count[20]=1
│ read 10 -> count[10]=2
│ read 5 -> count[5]=1
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Loop scans n elements once.
│ - Each count update direct array indexing O(1).
│ - Total = n operations.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - count array size range+1 = 101 fixed here.
│ -> Space Complexity = O(1) when range fixed small.
│ - In general O(range).
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
    vector<int> arr = {10,20,10,5};
    vector<int> count(101, 0); // values 0..100
    for (int x : arr) count[x]++;
    cout << "count[5]=" << count[5] << "\n";
    cout << "count[10]=" << count[10] << "\n";
    cout << "count[20]=" << count[20] << "\n";
    return 0;
}

/*
OUTPUT:
count[5]=1
count[10]=2
count[20]=1
*/

