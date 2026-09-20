# 13_Graphs

## Module goal

Tree me parent-child hierarchy fixed hoti hai. But real world me connections free-form hote hain: Google Maps roads, Instagram follows, computer networks, course prerequisites, word transformations. Graphs in non-hierarchical relationships ko model karte hain.

```text
Tree:
          CEO
        /     \
   ManagerA  ManagerB
      |
   Employee

Graph:
Ludhiana ---- Delhi
   |   \       |
   |    \      |
Amritsar ---- Chandigarh
```

Important relationship:

```text
Graph ⊃ Tree
Tree = connected + acyclic graph
```

---

## Folder tree

```text
13_Graphs/
├── README.md
├── 01_Graph_Intro/
│   ├── 01_why_graphs_theory.cpp
│   ├── 02_graph_terminology_theory.cpp
│   ├── 03_types_of_graphs_theory.cpp
│   ├── README.md
│   └── task.cpp
├── 02_Graph_Representation/
│   ├── 01_adjacency_matrix_theory.cpp
│   ├── 02_adjacency_matrix_implementation.cpp
│   ├── 03_adjacency_list_theory.cpp
│   ├── 04_adjacency_list_implementation.cpp
│   ├── 05_matrix_vs_list_comparison.cpp
│   ├── 06_weighted_graph_representation.cpp
│   ├── README.md
│   └── task.cpp
├── 03_BFS_Breadth_First_Search/
│   ├── 01_bfs_intuition_theory.cpp
│   ├── 02_bfs_algorithm_theory.cpp
│   ├── 03_bfs_implementation.cpp
│   ├── 04_bfs_levels_shortest_path_unweighted.cpp
│   ├── 05_bfs_disconnected_graph.cpp
│   ├── 06_bfs_on_grid_2d.cpp
│   ├── README.md
│   └── task.cpp
├── 04_DFS_Depth_First_Search/
│   ├── 01_dfs_intuition_theory.cpp
│   ├── 02_dfs_algorithm_theory.cpp
│   ├── 03_dfs_implementation_recursive.cpp
│   ├── 04_dfs_vs_bfs_master_comparison.cpp
│   ├── 05_dfs_iterative_stack.cpp
│   ├── 06_dfs_on_grid_2d.cpp
│   ├── README.md
│   └── task.cpp
├── 05_Connected_Components/
│   ├── 01_components_theory.cpp
│   ├── 02_count_components_approach_bfs.cpp
│   ├── 03_count_components_approach_dfs.cpp
│   ├── 04_number_of_islands_grid.cpp
│   ├── 05_max_area_island.cpp
│   ├── README.md
│   └── task.cpp
├── 06_Cycle_Detection/
│   ├── 01_cycle_why_detect_theory.cpp
│   ├── 02_cycle_undirected_dfs.cpp
│   ├── 03_cycle_undirected_bfs.cpp
│   ├── 04_cycle_directed_dfs_colors.cpp
│   ├── 05_cycle_directed_kahns_concept.cpp
│   ├── README.md
│   └── task.cpp
├── 07_Shortest_Paths_Concepts/
│   ├── 01_shortest_path_unweighted_bfs.cpp
│   ├── 02_dijkstras_intuition_concept.cpp
│   ├── 03_dijkstras_implementation_pq.cpp
│   ├── 04_bellman_ford_negative_edges_concept.cpp
│   ├── README.md
│   └── task.cpp
└── 08_Graph_Problems_Classic/
    ├── 01_roton_oranges_multi_bfs.cpp
    ├── 02_course_schedule_topological_concept.cpp
    ├── 03_flood_fill.cpp
    ├── 04_surrounded_regions_concept.cpp
    ├── 05_bipartite_check_bfs.cpp
    ├── 06_word_ladder_concept.cpp
    ├── README.md
    └── task.cpp
```

---

## Graph terminology sheet

| Term | Meaning | Real-world analogy |
|---|---|---|
| Vertex / Node | entity | city, user, computer |
| Edge | connection | road, follow, network cable |
| Directed edge | one-way connection | Instagram follow |
| Undirected edge | two-way connection | two-way road |
| Weighted edge | edge with cost | distance/time/toll |
| Unweighted edge | equal edge cost | number of hops |
| Degree | number of incident edges | direct friends count |
| Neighbor | directly connected node | adjacent city/friend |
| Path | sequence of connected nodes | route from source to destination |
| Cycle | path returns to start | round trip/deadlock |
| Connected graph | all nodes reachable | one road network |
| Disconnected graph | separate components | separate friend circles |
| DAG | directed acyclic graph | course prerequisites |

---

## Graph types visual grid

```text
Undirected:        A ----- B
Directed:          A ----> B
Weighted:          A --7-- B
Unweighted:        A ----- B
Cyclic:            A -> B -> C -> A
Acyclic / DAG:     A -> B -> C
Connected:         all nodes reachable
Disconnected:      (A--B)   (C--D)
```

---

## Representation formulas

### Adjacency matrix

```text
matrix[i][j] = 1 means edge i -> j exists
matrix[i][j] = 0 means no direct edge
```

Space calculation:

```text
V rows * V columns = V² cells
Space = O(V²)
```

Operations:

```text
Edge check matrix[u][v] = one direct lookup -> O(1)
Iterate neighbors of u = scan V columns -> O(V)
```

### Adjacency list

```cpp
vector<vector<int>> adj;
adj[u].push_back(v);
```

Space calculation:

```text
V lists + 2E entries for undirected graph
Space = O(V + 2E) = O(V+E)
```

Operations:

```text
Add edge = push_back, amortized O(1)
Edge check u-v = scan adj[u], O(degree(u))
Iterate neighbors of u = degree(u) entries, O(degree(u))
```

### Weighted graph list

```cpp
vector<vector<pair<int,int>>> adj;
// pair = {neighbor, weight}
```

---

## Matrix vs list comparison

| Feature | Adjacency Matrix | Adjacency List |
|---|---:|---:|
| Space | O(V²) | O(V+E) |
| Add edge | O(1) | O(1) amortized |
| Check edge | O(1) | O(degree) |
| Iterate neighbors | O(V) | O(degree) |
| Best for | dense graph | sparse graph |
| Real-world analogy | all possible road slots reserved | each city stores actual road list |

---

## BFS decision sheet

BFS = ripple in water / WhatsApp forward wave.

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

Why queue?

```text
Queue = FIFO
Earlier discovered nodes are processed first.
So BFS processes level d before level d+1.
```

BFS complexity:

```text
Each vertex pushed once and popped once = 2V operations
Each undirected edge appears in two lists = 2E neighbor checks
Total = 2V + 2E = O(V+E)
Space = visited O(V) + queue O(V) = O(V)
```

BFS use cases:

| Need | Use BFS? | Why |
|---|---|---|
| Level-wise traversal | yes | queue preserves levels |
| Shortest path in unweighted graph | yes | first reach = shortest level |
| Multi-source spread | yes | all sources start at time 0 |
| Grid minimum time/steps | yes | cells expand by levels |
| Weighted shortest path | no | use Dijkstra/Bellman-Ford |

---

## DFS decision sheet

DFS = maze solving / deep route + backtracking.

```text
dfs(node):
    visited[node] = true
    process node
    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor)
```

DFS complexity:

```text
Each vertex receives dfs call once = V
Each undirected edge scanned twice = 2E
Total = V + 2E = O(V+E)
Space = visited O(V) + recursion stack O(V) worst = O(V)
```

DFS use cases:

| Need | Use DFS? | Why |
|---|---|---|
| Explore connected component | yes | deep marks whole component |
| Cycle detection | yes | parent/colors easy |
| Backtracking | yes | recursion natural |
| Flood fill/islands | yes | grid connected region |
| Shortest unweighted path | not ideal | BFS guarantees shortest |

---

## BFS vs DFS master table

| Feature | BFS | DFS |
|---|---|---|
| Data structure | queue | recursion/stack |
| Style | level-wise | depth-wise |
| Real-world analogy | ripple/WhatsApp wave | maze/backtracking |
| Shortest unweighted path | best | not guaranteed |
| Cycle detection | possible | very common |
| Grid use | minimum time/steps | flood fill/islands |
| Complexity | O(V+E) | O(V+E) |
| Space | O(V) | O(V) |

Decision flow:

```text
Need shortest path in unweighted graph or minimum time spread?
    -> BFS
Need deep exploration, components, cycle, backtracking?
    -> DFS often easier
Need weighted shortest path?
    -> Dijkstra if non-negative, Bellman-Ford if negative edges
```

---

## Connected components and islands

Graph components:

```text
components = 0
for each vertex i:
    if not visited[i]:
        components++
        BFS/DFS(i)
```

Grid islands:

```text
1 = land, 0 = water
Each unvisited land cell starts BFS/DFS = one island
4-direction movement: up, down, left, right
```

Grid complexity:

```text
R*C total cells
Each cell visited at most once
For each cell, 4 directions checked
Total = 4RC = O(R*C)
Space = visited/queue/stack O(R*C)
```

---

## Cycle detection sheet

### Undirected cycle

```text
DFS/BFS with parent:
if neighbor visited and neighbor != parent:
    cycle exists
```

Why parent check?

```text
Undirected edge naturally points back to parent.
Parent edge is not a cycle.
```

### Directed cycle with colors

```text
WHITE = unvisited
GRAY = current recursion path
BLACK = fully processed

Edge to GRAY node = cycle
```

### Directed cycle with Kahn

```text
Build indegree.
Push indegree 0 nodes.
Process and reduce neighbors.
If processed count < V -> cycle exists.
```

Comparison:

| Graph type | Method | Cycle condition | Time | Space |
|---|---|---|---:|---:|
| Undirected | DFS/BFS parent | visited neighbor not parent | O(V+E) | O(V) |
| Directed | DFS colors | edge to GRAY | O(V+E) | O(V) |
| Directed | Kahn | processed count < V | O(V+E) | O(V) |

---

## Shortest path sheet

| Graph type | Algorithm | Real-world analogy | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Unweighted | BFS | equal-cost roads | V + E | O(V+E) | O(V) |
| Weighted non-negative | Dijkstra + PQ | Google Maps time | (V+E) log V | O((V+E)logV) | O(V+E) |
| Negative weights | Bellman-Ford | discount/cashback roads | V * E | O(VE) | O(V+E) |

### BFS path reconstruction

```text
parent[v] = u when v first discovered from u
path target -> parent[target] -> ... -> source
reverse path
```

### Dijkstra relaxation

```text
if dist[u] + weight < dist[v]:
    dist[v] = dist[u] + weight
    push {dist[v], v} into min priority queue
```

Priority queue connection from heaps:

```text
Dijkstra needs current minimum-distance node fast.
Min heap gives top in O(1), updates in O(log V).
```

### Bellman-Ford

```text
Repeat V-1 times:
    relax every edge

One extra scan:
    if still relaxes, negative cycle exists
```

Why V-1?

```text
Shortest simple path can contain at most V-1 edges.
More improvement means a cycle is reducing cost.
```

---

## Classic graph patterns

| Problem | Pattern | Real-world analogy | Time | Space |
|---|---|---|---:|---:|
| Rotten oranges | multi-source BFS | infection waves | O(R*C) | O(R*C) |
| Course schedule | topological sort/Kahn | prerequisites unlock | O(V+E) | O(V+E) |
| Flood fill | DFS/BFS grid | paint bucket | O(R*C) | O(R*C) |
| Surrounded regions | boundary DFS | safe boundary O | O(R*C) | O(R*C) |
| Bipartite check | BFS 2-coloring | split into two teams | O(V+E) | O(V) |
| Word ladder | BFS on generated word graph | one-letter transformation | O(NL) | O(N) |

Key trick reminders:

```text
Rotten oranges:
    Push all rotten oranges initially with time 0.

Course schedule:
    indegree 0 courses first.

Surrounded regions:
    Boundary-connected O is safe, mark it before flipping.

Bipartite:
    color[v] = 1 - color[u]. Same-color edge fails.

Word ladder:
    Try 26 letters at every position and BFS levels are transformation count.
```

---

## Complete complexity formula sheet

### Graph traversal with adjacency list

```text
Vertices visited = V
Undirected edge appears twice = 2E
Total work = V + 2E
Time = O(V+E)
```

### Adjacency matrix traversal

```text
For each vertex, scan full row of V cells
V rows * V columns = V²
Time = O(V²)
Space = O(V²)
```

### Grid traversal

```text
Rows = R, columns = C
Total cells = R*C
Each cell checks 4 directions
Total direction checks = 4*R*C
Time = O(R*C)
Space = O(R*C)
```

### Dijkstra with priority queue

```text
Relaxations can push O(E) states
Each heap push/pop costs O(log V)
Total = O((V+E)logV)
```

### Bellman-Ford

```text
Relax all E edges for V-1 rounds
Work = (V-1)*E = VE - E
Time = O(VE)
```

### Word ladder

```text
N dictionary words, word length L
For each word, try L positions * 26 letters
Total = N * L * 26
Time = O(NL)
```

---

## Common mistakes checklist

1. Graph and tree same assume karna.
2. Directed edge me reverse edge add karna.
3. Undirected edge me reverse edge add karna bhoolna.
4. Weighted graph me weight store na karna.
5. Sparse graph me adjacency matrix use karke memory waste karna.
6. Adjacency list edge check ko O(1) bolna.
7. BFS me visited push time mark na karna.
8. Disconnected graph me only source traversal karna.
9. Weighted graph shortest path ke liye BFS use karna.
10. DFS me visited guard miss karna.
11. Recursive DFS call stack overflow risk ignore karna for huge graph.
12. Grid BFS/DFS me boundary check miss karna.
13. Island problem me diagonal cells connect kar dena when 4-direction asked.
14. Undirected cycle detection me parent edge ko cycle bol dena.
15. Directed cycle detection me simple visited use karna; GRAY path needed.
16. Kahn algorithm me indegree decrement bhoolna.
17. Dijkstra me negative weights use karna.
18. Dijkstra me stale priority queue entry skip na karna.
19. Bellman-Ford V-1 rounds reason ignore karna.
20. Course schedule prerequisite direction ulta banana.
21. Rotten oranges me all rotten sources initially queue me na daalna.
22. Surrounded regions me boundary O safe mark karna bhoolna.
23. Bipartite disconnected graph handle na karna.
24. Word ladder me visited word remove na karna.
25. Complexity without calculation likhna.

---

## Interview question bank

1. Graph kya hota hai?
2. Tree graph ka special case kaise hai?
3. Vertex, edge, path, cycle, degree define karo.
4. Directed vs undirected graph real-world example do.
5. Weighted vs unweighted graph examples do.
6. Connected vs disconnected graph difference kya hai?
7. DAG kya hota hai?
8. Adjacency matrix explain karo.
9. Adjacency list explain karo.
10. Matrix vs list comparison table banao.
11. Sparse graph ke liye adjacency list better kyun?
12. Weighted graph representation C++ me likho.
13. BFS intuition ripple se explain karo.
14. BFS me queue kyun use hoti hai?
15. BFS O(V+E) proof do.
16. BFS shortest path in unweighted graph kyun deta hai?
17. Disconnected graph BFS kaise karte hain?
18. Grid BFS kaise work karta hai?
19. DFS intuition maze se explain karo.
20. DFS recursion and visited array explain karo.
21. DFS call stack dry run karo.
22. DFS O(V+E) proof do.
23. Iterative DFS stack se kaise karte hain?
24. BFS vs DFS decision flowchart explain karo.
25. Connected components count ka algorithm kya hai?
26. Number of islands graph problem kaise hai?
27. Max area island ka recursion formula kya hai?
28. Cycle detection real-world need explain karo.
29. Undirected cycle DFS parent tracking explain karo.
30. Undirected cycle BFS parent tracking explain karo.
31. Directed DFS colors WHITE/GRAY/BLACK explain karo.
32. Kahn cycle detection processed count logic explain karo.
33. BFS parent array se path reconstruct kaise hota hai?
34. Dijkstra intuition Google Maps se explain karo.
35. Dijkstra me priority queue ka role kya hai?
36. Dijkstra complexity derive karo.
37. Bellman-Ford negative edges kaise handle karta hai?
38. Negative cycle detection Bellman-Ford se kaise hota hai?
39. Rotten oranges multi-source BFS kyun hai?
40. Course schedule topological sort se kaise solve hota hai?
41. Flood fill DFS/BFS kaise hota hai?
42. Surrounded regions boundary DFS trick kya hai?
43. Bipartite graph 2-coloring kaise work karta hai?
44. Word ladder graph problem kaise hai?
45. Graph problem solve karte time representation kaise choose karoge?

---

## Study plan

1. `01_Graph_Intro` me terminology and graph types draw karo.
2. `02_Graph_Representation` me matrix vs list dry run karo.
3. `03_BFS_Breadth_First_Search` me queue state and visited array trace karo.
4. `04_DFS_Depth_First_Search` me recursion stack draw karo.
5. `05_Connected_Components` me friend circles and islands solve karo.
6. `06_Cycle_Detection` me undirected parent and directed colors compare karo.
7. `07_Shortest_Paths_Concepts` me BFS, Dijkstra, Bellman-Ford decision table yaad karo.
8. `08_Graph_Problems_Classic` me pattern recognition practice karo.
9. Har section ka `task.cpp` pehle khud solve karo, phir lesson files se compare karo.
