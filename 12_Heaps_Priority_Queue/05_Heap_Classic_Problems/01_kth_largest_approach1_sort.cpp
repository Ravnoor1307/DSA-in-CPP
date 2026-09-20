/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_kth_largest_approach1_sort.cpp
│
│ REAL-WORLD SCENARIO:
│ Class topper list me 2nd highest marks chahiye. Simple approach: pura result sort karo, then kth largest pick karo.
│
│ VISUAL / DRY RUN:
│ Input: [3,2,1,5,6,4], k=2
│
│ Sort ascending:
│ [1,2,3,4,5,6]
│
│ largest is index n-1 = 5 -> 6
│ 2nd largest is index n-2 = 4 -> 5
│ kth largest index = n-k
│ answer = sorted[n-k]
│
│ Before -> [3,2,1,5,6,4]
│ After sort -> [1,2,3,4,5,6]

│
│ COMPLEXITY CALCULATION:
│ Sorting n elements costs O(n log n).
│ After sorting, one index access is O(1).
│ Total time = O(n log n) + O(1) = O(n log n).
│
│ sort modifies array in-place for vector introsort uses O(log n) stack average.
│ If copy is made, copied array O(n) space. This demo copies -> O(n).

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
int kthLargestSort(vector<int> a, int k) {
    sort(a.begin(), a.end()); // Pura array sorted, but kaafi work hota hai.
    cout << "Sorted: "; printVector(a); cout << "\n";
    return a[(int)a.size() - k];
}

int main() {
    vector<int> a = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "Array: "; printVector(a); cout << ", k=" << k << "\n";
    cout << "kth largest = " << kthLargestSort(a, k) << "\n";
    return 0;
}

/*
OUTPUT:
Array: [3, 2, 1, 5, 6, 4], k=2
Sorted: [1, 2, 3, 4, 5, 6]
kth largest = 5
*/

