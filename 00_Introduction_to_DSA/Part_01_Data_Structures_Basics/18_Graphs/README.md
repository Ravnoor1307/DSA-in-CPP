# Graphs — Intro

## Summary
- A Graph is a collection of **nodes (vertices)** connected by **edges** — no root, no hierarchy, any node can connect to any other.
- **Undirected** edges work both ways (`A–B`); **directed** edges are one-way (`A→B`).
- **Degree** = number of edges touching a node. In directed graphs we split it into **indegree** (incoming) and **outdegree** (outgoing).
- Demo stores a 4-node graph in an **adjacency matrix** `matrix[u][v] = 1` when edge `u–v` exists, then prints connections.
- Handy fact: sum of all degrees = 2 × number of edges (always even).

## Real-World Analogy
A **metro map**: stations are the dots (nodes), rail lines between them are the edges. Social networks, flight routes, and the web (pages ⇄ hyperlinks) are all graphs.

## Files in This Folder
| File              | Purpose                                                       |
|-------------------|---------------------------------------------------------------|
| `01_theory.cpp`   | Pure theory + working demo (adjacency matrix, print edges, degree, edge cases) |
| `task.cpp`        | 6 tasks EASY→HARD (edges count, degree, connection check, add edge, max-degree node, isolated nodes) with solutions |
| `README.md`       | This summary page                                             |

## Cheat Sheet / Syntax
```cpp
// Adjacency matrix for V nodes
int m[V][V] = {0};
m[u][v] = 1;  // undirected edge: must also set m[v][u] = 1
m[v][u] = 1;

// Count edges (undirected): count upper triangle only
int edges = 0;
for (int u = 0; u < V; u++)
    for (int v = u+1; v < V; v++)
        if (m[u][v] == 1) edges++;

// Degree of node x = 1's in row x
for (int v = 0; v < V; v++) if (m[x][v] == 1) d++;
```

## Complexity Comparison Table
| Operation                    | Calculation                        | Time      | Space  |
|------------------------------|------------------------------------|-----------|--------|
| Print entire matrix           | V rows × V cols                   | O(V²)     | O(V²)  |
| Count edges                   | visit each cell once              | O(V²)     | O(V²)  |
| Check edge (u, v)             | single index lookup               | O(1)      | O(V²)  |
| Degree of one node            | scan one row (V entries)          | O(V)      | O(V²)  |
| Adjacency list alternative    | V lists + E entries               | —         | O(V+E) |

## ⚠️ Common Mistakes
- Forgetting to set **both** directions `m[u][v]` and `m[v][u]` for an undirected edge.
- **Double-counting** edges when counting — count only the upper triangle.
- Using a full matrix for a huge sparse graph → memory blow-up (use adjacency list instead).
- Confusing node *number* (array index) with node *value*.

## Interview Q&A
- **Q:** What does an adjacency matrix look like? **A:** A V×V grid where cell `(u,v)` is 1 if edge `u–v` exists, else 0.
- **Q:** How to count edges in an undirected graph? **A:** Count 1's in the upper triangle only, or `sum of degrees / 2`.
- **Q:** When is a matrix bad? **A:** When V is large but edges are few (sparse) — memory O(V²) is wasted; use adjacency list.
- **Q:** What is degree? **A:** Number of edges incident to a node; for directed graphs, split into indegree and outdegree.