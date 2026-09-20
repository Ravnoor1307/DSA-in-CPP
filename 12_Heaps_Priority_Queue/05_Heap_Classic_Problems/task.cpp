/*
REAL-WORLD SCENARIO:
Interview practice lab: toppers, bills, trending topics, merged rank lists, and live median solve karne hain.

TASKS easy -> hard:
1. kth largest by sorting implement karo.
2. kth largest by min heap size k implement karo.
3. kth smallest by max heap size k implement karo.
4. kth smallest by min heap all + k pops implement karo.
5. k most frequent elements using unordered_map + heap implement karo.
6. merge k sorted arrays using min heap of heads implement karo.
7. running median using two heaps implement karo.
8. Har task ke liye heap state comments me draw karo.

HINTS:
- kth largest: min heap stores only top-k survivors.
- kth smallest: max heap stores only smallest-k survivors.
- merge k arrays: heap item needs value, row, col.
- running median: lower max heap can have one extra element.

STARTER CODE:
int kthLargest(vector<int> a, int k) { return -1; }
vector<int> topKFrequent(vector<int> nums, int k) { return {}; }

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <unordered_map>
using namespace std;

int kthLargest(vector<int> a, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : a) {
        pq.push(x);
        if ((int)pq.size() > k) pq.pop(); // top-k largest survivors bachte hain.
    }
    return pq.top();
}

int kthSmallest(vector<int> a, int k) {
    priority_queue<int> pq;
    for (int x : a) {
        pq.push(x);
        if ((int)pq.size() > k) pq.pop(); // smallest-k survivors bachte hain.
    }
    return pq.top();
}

vector<int> topKFrequent(vector<int> nums, int k) {
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;
    priority_queue<pair<int,int>> pq;
    for (auto e : freq) pq.push({e.second, e.first});
    vector<int> ans;
    while (k-- && !pq.empty()) { ans.push_back(pq.top().second); pq.pop(); }
    return ans;
}

int main() {
    vector<int> a = {3, 2, 1, 5, 6, 4};
    cout << "2nd largest=" << kthLargest(a, 2) << "\n";
    vector<int> b = {7, 10, 4, 3, 20, 15};
    cout << "3rd smallest=" << kthSmallest(b, 3) << "\n";
    vector<int> freqAns = topKFrequent({1,1,1,2,2,3}, 2);
    cout << "top frequent="; for (int x : freqAns) cout << x << ' '; cout << "\n";
    return 0;
}

/*
OUTPUT:
2nd largest=5
3rd smallest=7
top frequent=1 2
*/
