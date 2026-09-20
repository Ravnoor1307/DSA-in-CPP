/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_merge_k_sorted_arrays_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ K schools ki sorted merit lists ko ek combined sorted merit list banana hai. Har list ka current head min heap me rakho, smallest head nikalo, usi list ka next head add karo.
│
│ VISUAL / DRY RUN:
│ Arrays:
│ A0: [1,4,5]
│ A1: [1,3,4]
│ A2: [2,6]
│
│ Heap of heads stores (value, arrayIndex, elementIndex):
│ start: (1,A0,0), (1,A1,0), (2,A2,0)
│ pop 1 from A0 -> push 4 from A0
│ pop 1 from A1 -> push 3 from A1
│ pop 2 from A2 -> push 6 from A2
│ pop 3 from A1 -> push 4 from A1
│ ...
│
│ merged: [1,1,2,3,4,4,5,6]

│
│ COMPLEXITY CALCULATION:
│ Let total elements = N, number of arrays = k.
│ Initially push k heads -> k log k.
│ For each of N popped elements:
│ pop O(log k), maybe push next O(log k).
│ Total = O(N log k).
│ Space = heap stores at most k heads -> O(k), output O(N).

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
struct Item {
    int value;
    int arrayIndex;
    int elementIndex;
};

struct MinItemCompare {
    bool operator()(const Item& a, const Item& b) const {
        return a.value > b.value; // Smaller value top.
    }
};

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    priority_queue<Item, vector<Item>, MinItemCompare> pq;
    for (int i = 0; i < (int)arrays.size(); i++) {
        if (!arrays[i].empty()) pq.push({arrays[i][0], i, 0});
    }

    vector<int> merged;
    while (!pq.empty()) {
        Item cur = pq.top(); pq.pop();
        merged.push_back(cur.value);
        int nextIndex = cur.elementIndex + 1;
        if (nextIndex < (int)arrays[cur.arrayIndex].size()) {
            pq.push({arrays[cur.arrayIndex][nextIndex], cur.arrayIndex, nextIndex});
        }
    }
    return merged;
}

int main() {
    vector<vector<int>> arrays = {{1,4,5}, {1,3,4}, {2,6}};
    vector<int> merged = mergeKSortedArrays(arrays);
    cout << "Merged: "; printVector(merged); cout << "\n";
    return 0;
}

/*
OUTPUT:
Merged: [1, 1, 2, 3, 4, 4, 5, 6]
*/

