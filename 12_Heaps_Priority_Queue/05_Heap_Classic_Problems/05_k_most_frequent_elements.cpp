/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_k_most_frequent_elements.cpp
│
│ REAL-WORLD SCENARIO:
│ News app me most repeated trending topics chahiye. Pehle frequency count hashmap se, phir heap se top k frequent topics.
│
│ VISUAL / DRY RUN:
│ Hashing journey connect:
│ nums = [1,1,1,2,2,3], k=2
│
│ Frequency map:
│ 1 -> 3
│ 2 -> 2
│ 3 -> 1
│
│ Max heap stores pair(freq,num):
│ (3,1), (2,2), (1,3)
│
│ Pop k times:
│ pop (3,1) -> answer 1
│ pop (2,2) -> answer 2
│
│ Output: [1,2]

│
│ COMPLEXITY CALCULATION:
│ Frequency map build:
│ n elements, each average O(1) update -> O(n).
│ If m unique elements, pushing m heap pairs costs m log m.
│ Pop k costs k log m.
│ Total = O(n + m log m + k log m).
│ Since m <= n, worst O(n log n).
│ Space = map O(m) + heap O(m) -> O(m).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
using namespace std;

void printVector(const vector<int>& a) {
    cout << "[";
    for (int i = 0; i < (int)a.size(); i++) cout << a[i] << (i + 1 == (int)a.size() ? "" : ", ");
    cout << "]";
}

template <typename PQ>
void printHeapCopy(PQ pq, const string& label) {
    cout << label << ": [";
    bool first = true;
    while (!pq.empty()) {
        if (!first) cout << ", ";
        cout << pq.top();
        pq.pop();
        first = false;
    }
    cout << "]\n";
}
vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++; // Hash map se frequency count.

    priority_queue<pair<int,int>> pq; // pair(freq, num), max freq top.
    for (auto entry : freq) {
        pq.push({entry.second, entry.first});
        cout << "push (freq=" << entry.second << ", num=" << entry.first << ")\n";
    }

    vector<int> ans;
    while (k-- && !pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ans = topKFrequent(nums, 2);
    cout << "Top frequent: "; printVector(ans); cout << "\n";
    return 0;
}

/*
OUTPUT:
push (freq=1, num=3)
push (freq=2, num=2)
push (freq=3, num=1)
Top frequent: [1, 2]
*/

