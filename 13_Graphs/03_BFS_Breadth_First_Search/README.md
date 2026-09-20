# 03_BFS_Breadth_First_Search

## Real-world analogy summary

BFS ripple in water jaisa hai. Source se wave level-by-level spread hoti hai. WhatsApp forward bhi pehle direct friends, phir friends-of-friends tak jata hai.

## BFS algorithm

```text
visited[source] = true
queue.push(source)

while queue not empty:
    node = queue.front()
    queue.pop()
    process node
    for neighbor in adj[node]:
        if not visited[neighbor]:
            visited[neighbor] = true
            queue.push(neighbor)
```

## Why queue?

Queue FIFO hai. Jo node pehle discover hua, wo pehle process hota hai. Isliye BFS levels preserve karta hai.

## Complexity calculation

```text
Each vertex pushed once and popped once = 2V operations
Each undirected edge appears in two adjacency lists = 2E neighbor checks
Total = 2V + 2E = O(V+E)
Space = visited O(V) + queue O(V) = O(V)
```

## BFS use cases

| Use case | Why BFS? | Time |
|---|---|---:|
| Graph traversal | level-wise visit | O(V+E) |
| Shortest path unweighted | first reach is shortest | O(V+E) |
| Connected components | BFS from every unvisited node | O(V+E) |
| Grid traversal | cells as nodes, 4-direction edges | O(R*C) |
| Multi-source BFS | many sources wave together | O(R*C) |

## Common mistakes

1. Node ko pop time visited mark karna, duplicate queue entries aa sakti hain.
2. Disconnected graph me only source BFS karna.
3. Weighted shortest path me BFS use karna. Weighted graph me Dijkstra/Bellman-Ford chahiye.
4. Grid BFS me boundary check miss karna.
5. Queue empty condition galat likhna.

## Interview questions

1. BFS intuition ripple se explain karo.
2. BFS me queue kyun use hoti hai?
3. visited array ka role kya hai?
4. BFS O(V+E) proof do.
5. BFS shortest path in unweighted graph kyun deta hai?
6. Disconnected graph me BFS kaise karoge?
7. Grid as graph kaise represent hota hai?
