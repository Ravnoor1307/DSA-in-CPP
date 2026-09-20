/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_k_closest_points_to_origin.cpp
│
│ REAL-WORLD SCENARIO:
│ Delivery app me origin ke closest k riders chahiye. Distance square compare karo; max heap size k me farthest survivor top par rahega and remove hota rahega.
│
│ ASCII VISUAL / PATTERN STATE:
│ points = (1,3), (-2,2), (5,8), (0,1), k=2
│ distance²:
│ (1,3) -> 10
│ (-2,2) -> 8
│ (5,8) -> 89
│ (0,1) -> 1
│
│ Max heap size k by distance:
│ push 10, push 8 -> survivors 10,8
│ push 89 -> size3 pop farthest89
│ push 1 -> size3 pop farthest10
│ survivors distances 8 and1 -> points (-2,2),(0,1)

│
│ STEP-BY-STEP DRY RUN:
│ We do not need sqrt because order same for d and d².
│ Max heap top stores farthest among current closest k.
│ If size > k, pop farthest.

│
│ COMPLEXITY CALCULATION:
│ n points.
│ Each push/pop heap size k -> O(log k).
│ Distance calculation x*x+y*y constant.
│ Time = O(n log k).
│ Space = O(k).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int,int>> maxHeap; // {distSquared, index}
    for (int i = 0; i < (int)points.size(); i++) {
        int x = points[i][0], y = points[i][1];
        int dist = x*x + y*y;
        maxHeap.push({dist, i});
        if ((int)maxHeap.size() > k) maxHeap.pop(); // Farthest survivor remove.
    }
    vector<vector<int>> ans;
    while (!maxHeap.empty()) {
        ans.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> points = {{1,3},{-2,2},{5,8},{0,1}};
    vector<vector<int>> ans = kClosest(points, 2);
    for (auto p : ans) cout << '(' << p[0] << ',' << p[1] << ") ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
(-2,2) (0,1)
*/

