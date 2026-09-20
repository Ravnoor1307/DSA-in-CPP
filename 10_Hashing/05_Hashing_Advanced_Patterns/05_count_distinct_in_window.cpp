/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_count_distinct_in_window.cpp
│
│ REAL-WORLD SCENARIO:
│ Bus me fixed-size window of k seats check karni hai: har group of k consecutive passengers me distinct ticket types count karo. Sliding window + hash map combo use hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. First k elements ki frequency map banao.
│ 2. Distinct count = map size.
│ 3. Window slide: outgoing element freq--, zero ho to erase.
│ 4. Incoming element freq++.
│ 5. Har slide ke baad map size answer hai.
│ 6. Window maintains current k elements only.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[1,2,1,3,4,2,3], k=4
│
│ window [1,2,1,3] freq {1:2,2:1,3:1} distinct=3
│ slide out1, in4 -> [2,1,3,4] freq {1:1,2:1,3:1,4:1} distinct=4
│ slide out2, in2 -> [1,3,4,2] distinct=4
│ slide out1, in3 -> [3,4,2,3] distinct=3
│
│ DRY RUN:
│ initial map: 1:2,2:1,3:1 -> 3.
│ i=4: remove arr0=1, add4 -> size4.
│ i=5: remove arr1=2 erase then add2 -> size4.
│ i=6: remove arr2=1 erase, add3 -> size3.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Build first window k operations.
│ - Slides = n-k times.
│ - Each slide has one decrement/erase and one increment average O(1).
│ - Total operations k + 2(n-k) = O(n).
│ -> Average Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map stores at most k distinct elements.
│ -> Space Complexity = O(k).
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

vector<int> distinctInWindows(const vector<int>& arr, int k) {
    unordered_map<int,int> freq;
    vector<int> ans;
    for (int i = 0; i < k; i++) freq[arr[i]]++;
    ans.push_back((int)freq.size());
    for (int i = k; i < (int)arr.size(); i++) {
        int out = arr[i - k];
        freq[out]--;
        if (freq[out] == 0) freq.erase(out);
        int in = arr[i];
        freq[in]++;
        ans.push_back((int)freq.size());
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,1,3,4,2,3};
    vector<int> ans = distinctInWindows(arr, 4);
    cout << "Distinct counts in windows: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Distinct counts in windows: 3 4 4 3
*/

