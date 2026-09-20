/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_most_frequent_element_freq.cpp
│
│ REAL-WORLD SCENARIO:
│ Small-range voting machine me candidates IDs 0..10 hain. Frequency array count karke most frequent candidate direct find hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Range small ho to count array use karo.
│ 2. Har value ke count increment karo.
│ 3. Count array scan karke max frequency find karo.
│ 4. Tie ke liye smaller value choose kar sakte hain.
│ 5. No hashmap overhead needed.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[2,3,2,5,3,2]
│ count[2]=3
│ count[3]=2
│ count[5]=1
│ max count=3 at value2
│ answer=2
│
│ DRY RUN:
│ read values and counts update.
│ scan count 0..5:
│ best=2 when count3 found.
│ final most frequent 2.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Build count scans n elements.
│ - Scan range R+1 cells.
│ - Total = n + R.
│ -> Time Complexity = O(n+R).
│
│ SPACE COMPLEXITY CALCULATION:
│ - count array stores R+1 integers.
│ -> Space Complexity = O(R), O(1) if R fixed small.
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
    vector<int> arr = {2,3,2,5,3,2};
    int maxValue = 5;
    vector<int> count(maxValue + 1, 0);
    for (int x : arr) count[x]++;
    int bestValue = 0;
    for (int value = 1; value <= maxValue; value++) {
        if (count[value] > count[bestValue]) bestValue = value;
    }
    cout << "Most frequent element = " << bestValue << " with count " << count[bestValue] << "\n";
    return 0;
}

/*
OUTPUT:
Most frequent element = 2 with count 3
*/

