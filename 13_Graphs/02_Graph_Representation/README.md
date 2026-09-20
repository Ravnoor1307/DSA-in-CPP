# 02_Graph_Representation

## Real-world analogy summary

Graph ko computer memory me store karna road map save karne jaisa hai. Ya to har possible city-pair ka table banao — adjacency matrix. Ya har city ki actual road list banao — adjacency list.

## Adjacency matrix

```text
matrix[i][j] = 1 means edge i -> j exists
matrix[i][j] = 0 means no edge
```

| Good | Bad |
|---|---|
| edge check O(1) | space O(V²) |
| dense graph me useful | sparse graph me waste |

## Adjacency list

```cpp
vector<vector<int>> adj;
adj[u].push_back(v);
```

| Good | Bad |
|---|---|
| space O(V+E) | edge check O(degree) |
| neighbor iteration O(degree) | direct lookup matrix jaisa nahi |

## Weighted graph

```cpp
vector<vector<pair<int,int>>> adj;
// pair = {neighbor, weight}
```

## Master comparison table

| Feature | Matrix | List |
|---|---:|---:|
| Space | O(V²) | O(V+E) |
| Add edge | O(1) | O(1) amortized |
| Check edge | O(1) | O(degree) |
| Iterate neighbors | O(V) | O(degree) |
| Best for | dense graph | sparse graph |

## Complexity calculations

Matrix:

```text
V rows * V columns = V² cells
Space = O(V²)
Edge check = one cell read = O(1)
```

List:

```text
V lists + 2E entries for undirected graph
Space = O(V+2E) = O(V+E)
Iterate neighbors of u = degree(u) entries = O(degree(u))
```

## Common mistakes

1. Undirected edge me reverse edge add karna bhoolna.
2. Directed graph me reverse edge accidentally add karna.
3. Weighted graph me only neighbor store karna, weight miss karna.
4. Sparse graph ke liye matrix use karke memory waste karna.
5. Adjacency list edge check ko O(1) bolna.

## Interview questions

1. Adjacency matrix explain karo.
2. Adjacency list explain karo.
3. Matrix vs list comparison table banao.
4. Sparse graph ke liye adjacency list better kyun?
5. Edge check matrix me O(1) kyun hota hai?
6. Weighted graph representation likho.
7. Directed/undirected addEdge ka difference kya hai?
