/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_course_schedule_topological_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ College course planning me prerequisites pehle complete hone chahiye. DAG me topological order valid course sequence deta hai.
│
│ ASCII VISUAL / GRAPH-GRID STATE:
│ Courses:
│ 0 before 1
│ 0 before 2
│ 1 before 3
│ 2 before 3
│
│ Graph:
│     0
│    / \
│   v   v
│   1   2
│    \ /
│     v
│     3
│
│ indegree:
│ 0:0, 1:1, 2:1, 3:2
│ queue indegree0: [0]
│ pop0 -> indegree1=0, indegree2=0 -> q=[1,2]
│ pop1 -> indegree3=1
│ pop2 -> indegree3=0 -> q=[3]
│ order: 0 1 2 3

│
│ STEP-BY-STEP DRY RUN:
│ If all courses processed, schedule possible.
│ If cycle exists, some course indegree never becomes 0.
│ This is Kahn BFS topological sorting.

│
│ COMPLEXITY CALCULATION:
│ Build adjacency and indegree by scanning prerequisites E -> O(E).
│ Queue processes each course once -> O(V).
│ Each edge relaxed once -> O(E).
│ Time = O(V+E).
│ Space = adjacency O(V+E) + indegree O(V) + queue O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> courseOrder(int n, const vector<pair<int,int>>& prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for (auto p : prerequisites) {
        int course = p.first, pre = p.second;
        adj[pre].push_back(course);
        indegree[course]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--; // Prerequisite u complete, neighbor ka lock kam.
            if (indegree[v] == 0) q.push(v);
        }
    }
    if ((int)order.size() != n) return {};
    return order;
}

int main() {
    int n = 4;
    vector<pair<int,int>> pre = {{1,0}, {2,0}, {3,1}, {3,2}};
    vector<int> order = courseOrder(n, pre);
    cout << "Course order: ";
    for (int x : order) cout << x << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Course order: 0 1 2 3
*/

