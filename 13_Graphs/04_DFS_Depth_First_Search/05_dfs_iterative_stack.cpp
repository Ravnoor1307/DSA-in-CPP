/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_dfs_iterative_stack.cpp
│
│ REAL-WORLD SCENARIO:
│ Recursion allowed na ho to maze solving manually stack se kar sakte hain. Stack recursion call stack ka explicit version hai.
│
│ ASCII VISUAL / STACK-RECURSION STATE:
│ Iterative DFS idea:
│ stack.push(source)
│ while stack not empty:
│     node = stack.top(); stack.pop()
│     process if unvisited
│     push neighbors
│
│ To match recursive order, neighbors reverse order me push karo.
│
│ Graph adjacency 0: 1,2
│ stack start [0]
│ pop0, push2 then1 -> stack [2,1]
│ pop1 before2 -> recursive-like order.

│
│ STEP-BY-STEP DRY RUN:
│ stack [0]
│ pop0 -> order0, push2,1 -> [2,1]
│ pop1 -> order1, push3 -> [2,3]
│ pop3 -> order3, push5 -> [2,5]
│ pop5 -> order5, push4 -> [2,4]
│ pop4 -> order4, push2 maybe already in stack but mark guards.
│ pop2 -> order2.

│
│ COMPLEXITY CALCULATION:
│ Each vertex can be pushed multiple times if mark on pop, but each edge causes at most constant push attempt.
│ With visited check, total O(V+E).
│ Stack can hold O(V) nodes.
│ visited O(V), output O(V) -> space O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

vector<vector<int>> sampleGraph() {
    vector<vector<int>> adj(6);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0, 1);
    add(0, 2);
    add(1, 3);
    add(2, 4);
    add(3, 5);
    add(4, 5);
    return adj;
}

void printOrder(const vector<int>& order, const string& label) {
    cout << label << ": ";
    for (int x : order) cout << x << ' ';
    cout << "\n";
}
vector<int> iterativeDFS(const vector<vector<int>>& adj, int source) {
    vector<int> visited(adj.size(), 0), order;
    stack<int> st;
    st.push(source);

    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        order.push_back(u);

        for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
            int v = adj[u][i];
            if (!visited[v]) st.push(v); // Stack LIFO, reverse push se first neighbor pehle process.
        }
    }
    return order;
}

int main() {
    vector<vector<int>> adj = sampleGraph();
    vector<int> order = iterativeDFS(adj, 0);
    printOrder(order, "DFS iterative order");
    return 0;
}

/*
OUTPUT:
DFS iterative order: 0 1 3 5 4 2
*/

