# 04_DFS_Depth_First_Search

## Real-world analogy summary

DFS maze solving jaisa hai: ek rasta pakdo, deep jao, dead-end par backtrack karo, next rasta try karo. Recursion stack current route hold karta hai.

## DFS algorithm

```text
dfs(node):
    visited[node] = true
    process node
    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor)
```

## BFS vs DFS table

| Feature | BFS | DFS |
|---|---|---|
| Data structure | queue | recursion/stack |
| Style | level-wise | depth-wise |
| Unweighted shortest path | yes | not guaranteed |
| Backtracking | not natural | natural |
| Cycle detection | possible | very common |
| Grid use | shortest spread | flood fill/islands |

## Complexity calculation

```text
Each vertex visited once = V
Each undirected edge scanned twice = 2E
Total = V + 2E = O(V+E)
Space = visited O(V) + recursion stack O(V) worst = O(V)
```

## Common mistakes

1. visited mark karna bhoolna, infinite recursion ho sakti hai.
2. DFS ko unweighted shortest path ke liye blindly use karna.
3. Recursive DFS me base/visited guard miss karna.
4. Iterative DFS me push order se traversal order change hota hai, isko bug na samjho.
5. Grid DFS me boundary check miss karna.

## Interview questions

1. DFS intuition maze solving se explain karo.
2. DFS recursive algorithm likho.
3. DFS O(V+E) proof do.
4. DFS call stack dry run karo.
5. BFS vs DFS decision table banao.
6. Iterative DFS stack se implement karo.
7. Flood fill DFS kaise hota hai?
