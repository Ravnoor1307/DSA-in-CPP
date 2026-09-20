/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_sort_array_freq_array.cpp
│
│ REAL-WORLD SCENARIO:
│ Marks list ko sort karna hai and marks range 0..10 hai. Count every mark, then value ko count times print karo. Ye counting sort preview hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Frequency array banao range ke according.
│ 2. Har element count[value]++.
│ 3. value from min to max loop karo.
│ 4. count[value] times value output me push karo.
│ 5. Works when range small.
│ 6. Counting sort preview: comparison sort ki need nahi.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[4,1,3,4,2]
│ count:
│ 0:0 1:1 2:1 3:1 4:2
│
│ rebuild:
│ 1 once -> [1]
│ 2 once -> [1,2]
│ 3 once -> [1,2,3]
│ 4 twice -> [1,2,3,4,4]
│
│ DRY RUN:
│ scan arr count build.
│ v=0 skip.
│ v=1 push once.
│ v=2 push once.
│ v=3 push once.
│ v=4 push twice.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Build frequency scans n elements.
│ - Rebuild loops over range R and pushes n elements total.
│ - Total = n + R + n = 2n+R.
│ -> Time Complexity = O(n+R).
│
│ SPACE COMPLEXITY CALCULATION:
│ - count array size R+1 and output n.
│ -> Space Complexity = O(R+n) if new output, O(R) extra if overwriting input.
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

vector<int> countingSortPreview(const vector<int>& arr, int maxValue) {
    vector<int> count(maxValue + 1, 0);
    for (int x : arr) count[x]++;
    vector<int> sorted;
    for (int value = 0; value <= maxValue; value++) {
        while (count[value] > 0) {
            sorted.push_back(value);
            count[value]--;
        }
    }
    return sorted;
}

int main() {
    vector<int> arr = {4,1,3,4,2};
    vector<int> sorted = countingSortPreview(arr, 4);
    cout << "Sorted using frequency array: ";
    for (int x : sorted) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Sorted using frequency array: 1 2 3 4 4
*/

