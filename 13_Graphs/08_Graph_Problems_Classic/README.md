# 08_Graph_Problems_Classic

## Real-world analogy summary

Classic graph problems pattern recognition hain: infection spread, course ordering, paint fill, safe boundary regions, two-team coloring, and word transformation BFS.

## Pattern table

| Problem | Graph model | Best pattern | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Rotten oranges | grid cells | multi-source BFS | R*C cells, 4 dirs | O(R*C) | O(R*C) |
| Course schedule | directed prerequisites | Kahn topological BFS | V nodes + E edges | O(V+E) | O(V+E) |
| Flood fill | grid same-color region | DFS/BFS | R*C cells | O(R*C) | O(R*C) |
| Surrounded regions | boundary-connected O safe | boundary DFS | R*C scan + DFS | O(R*C) | O(R*C) |
| Bipartite check | graph coloring | BFS 2-color | V nodes + 2E scans | O(V+E) | O(V) |
| Word ladder | words as nodes | BFS shortest transformation | N words * L positions * 26 | O(NL) | O(N) |

## Key tricks

```text
Rotten oranges:
Push all rotten cells initially. This is multi-source BFS.

Course schedule:
indegree 0 courses unlock first.
processed count < V means cycle.

Surrounded regions:
Boundary O cannot be captured. Mark boundary-connected O first.

Bipartite:
color neighbor with 1-color[u]. Same color edge means false.

Word ladder:
Generate neighbors by changing one character at a time.
BFS because shortest number of transformations needed.
```

## Common mistakes

1. Rotten oranges me one rotten source se BFS start karna; all rotten sources initially queue me hone chahiye.
2. Course schedule me prerequisite direction ulta banana.
3. Flood fill me oldColor == newColor guard miss karna.
4. Surrounded regions me inner O se DFS start karna; boundary O safe mark karna hota hai.
5. Bipartite me disconnected components handle na karna.
6. Word ladder me visited word remove na karna, TLE/loop ho sakta hai.

## Interview questions

1. Rotten oranges multi-source BFS kyun hai?
2. Course schedule topological sort se kaise solve hota hai?
3. Flood fill grid graph kaise hai?
4. Surrounded regions boundary DFS trick explain karo.
5. Bipartite graph 2-coloring se kaise check hota hai?
6. Word ladder BFS on words kaise hota hai?
7. Classic graph problems identify karne ke signals kya hain?
