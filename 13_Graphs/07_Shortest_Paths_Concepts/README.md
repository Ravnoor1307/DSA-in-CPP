# 07_Shortest_Paths_Concepts

## Real-world analogy summary

Shortest path route planning hai. Unweighted roads me every edge same cost hai, so BFS works. Weighted roads me time/distance different hai, so Dijkstra priority queue use karta hai. Negative edges ke liye Bellman-Ford concept use hota hai.

## Decision table

| Graph type | Algorithm | Why | Time | Space |
|---|---|---|---:|---:|
| Unweighted | BFS | levels = edge count distance | O(V+E) | O(V) |
| Weighted non-negative | Dijkstra + priority queue | nearest known node greedy | O((V+E)logV) | O(V+E) |
| Weighted with negative edges | Bellman-Ford | repeated relaxation | O(VE) | O(V+E) |
| Negative cycle detection | Bellman-Ford extra round | Vth improvement means cycle | O(VE) | O(V+E) |

## BFS parent reconstruction

```text
parent[v] = u when v is first discovered from u
To reconstruct path:
    start from target
    follow parent until -1
    reverse path
```

## Dijkstra core idea

```text
dist[source] = 0
pq stores {distance, node}
while pq not empty:
    pop smallest distance node
    relax all outgoing edges
```

## Bellman-Ford core idea

```text
Repeat V-1 times:
    relax every edge

Then scan one more time:
    if any edge still relaxes -> negative cycle
```

## Common mistakes

1. Weighted graph me BFS use karna.
2. Negative edge graph me Dijkstra use karna.
3. Dijkstra priority queue stale entries skip na karna.
4. Parent array reconstruct me reverse path bhoolna.
5. Bellman-Ford me V-1 rounds ka reason na samajhna.

## Interview questions

1. BFS shortest path in unweighted graph proof do.
2. Parent array se path reconstruct kaise karte hain?
3. Dijkstra intuition Google Maps se explain karo.
4. Dijkstra me priority queue ka role kya hai?
5. Dijkstra complexity O((V+E)logV) kaise aati hai?
6. Bellman-Ford negative edges kaise handle karta hai?
7. Negative cycle detection kaise hota hai?
