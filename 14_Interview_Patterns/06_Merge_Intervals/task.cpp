/*
REAL-WORLD SCENARIO:
Calendar meeting scheduler me overlaps detect/merge/remove karne hain.

TASKS easy -> hard:
1. Overlap condition likho.
2. Merge intervals brute force solve karo.
3. Merge intervals sort + scan solve karo.
4. Insert interval solve karo.
5. Non-overlapping intervals remove count karo.
6. Meeting rooms can attend check karo.
7. Timeline visual comments me banao.

HINTS:
- Sort by start for merge.
- Sort by end for greedy remove.
- Overlap if next.start <= current.end.

STARTER CODE:
sort(intervals.begin(), intervals.end());

SOLUTIONS below.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> a) {
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for (auto in : a) {
        if (ans.empty() || in[0] > ans.back()[1]) ans.push_back(in);
        else ans.back()[1] = max(ans.back()[1], in[1]);
    }
    return ans;
}

int main() {
    vector<vector<int>> a = {{1,3},{2,6},{8,10}};
    for (auto in : mergeIntervals(a)) cout << '[' << in[0] << ',' << in[1] << "] ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
[1,6] [8,10]
*/
