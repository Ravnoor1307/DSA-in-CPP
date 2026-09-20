# 05_Connected_Components

## Real-world analogy summary

Connected components separate friend circles ya islands jaise hote hain. Ek component ke andar nodes reachable hain; alag component ke nodes reachable nahi.

## Component algorithm

```text
components = 0
for each vertex i:
    if not visited[i]:
        components++
        BFS/DFS from i and mark whole component
```

## Grid island pattern

```text
1 = land
0 = water
4-direction connection = up/down/left/right
Each unvisited land BFS/DFS launch = one island
```

## Comparison table

| Problem | Representation | Traversal | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Count graph components | adjacency list | BFS | V visits + 2E scans | O(V+E) | O(V) |
| Count graph components | adjacency list | DFS | V calls + 2E scans | O(V+E) | O(V) |
| Number of islands | grid | BFS/DFS | R*C cells, 4 dirs each | O(R*C) | O(R*C) |
| Max area island | grid | DFS | each land once | O(R*C) | O(R*C) |

## Common mistakes

1. Only source node se traversal karke disconnected parts miss karna.
2. visited array/matrix use na karna.
3. Island problem me diagonal connection accidentally allow karna.
4. Max area me area reset wrong place karna.
5. Grid boundary check miss karna.

## Interview questions

1. Connected component kya hota hai?
2. Components count BFS se kaise karte hain?
3. Components count DFS se kaise karte hain?
4. Number of islands graph problem kaise hai?
5. Max area island me size kaise track karte hain?
6. Grid traversal O(R*C) kyun hota hai?
