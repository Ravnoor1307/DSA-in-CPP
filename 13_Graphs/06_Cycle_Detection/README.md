# 06_Cycle_Detection

## Real-world analogy summary

Cycle deadlock or impossible prerequisites jaisa hai. Agar A waits for B, B waits for C, and C waits for A, system stuck ho sakta hai.

## Undirected graph cycle

Parent tracking:

```text
DFS/BFS node u with parent p
for neighbor v:
    if not visited -> explore
    else if v != parent -> cycle
```

Why parent needed?

```text
Undirected edge u--parent naturally back dikhta hai.
Usko cycle nahi bolna.
```

## Directed graph cycle

3-color DFS:

```text
WHITE = unvisited
GRAY = current recursion path
BLACK = fully processed

Edge to GRAY node = cycle
```

Kahn concept:

```text
indegree 0 nodes queue me aate hain.
If processed nodes < V, cycle exists.
```

## Comparison table

| Graph | Approach | Key state | Cycle condition | Time | Space |
|---|---|---|---|---:|---:|
| Undirected | DFS | visited + parent | visited neighbor not parent | O(V+E) | O(V) |
| Undirected | BFS | queue(node,parent) | visited neighbor not parent | O(V+E) | O(V) |
| Directed | DFS colors | WHITE/GRAY/BLACK | edge to GRAY | O(V+E) | O(V) |
| Directed | Kahn | indegree | processed < V | O(V+E) | O(V) |

## Common mistakes

1. Undirected graph me parent edge ko cycle bol dena.
2. Directed graph me simple visited use karna; recursion path/colors chahiye.
3. GRAY and BLACK states confuse karna.
4. Kahn me indegree update bhoolna.
5. Disconnected graph me all vertices se cycle detection launch na karna.

## Interview questions

1. Cycle detection need real-world example se explain karo.
2. Undirected DFS parent tracking explain karo.
3. Undirected BFS cycle detection explain karo.
4. Directed DFS 3-color method explain karo.
5. Kahn algorithm cycle detection concept kya hai?
6. Cycle detection O(V+E) kyun hota hai?
