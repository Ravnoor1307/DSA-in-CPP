/*
═══════════════════════════════════════════════
 GRAPHS — INTRO
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of a metro map: the stations are the dots and the rail lines
 between them are the connections. Or a friend network on social media:
 each person is a point, and a friendship is a line between two points.
 This "dots-and-lines" model is a Graph. Roads connecting cities, web
 pages linking to each other, flight routes between airports — all of
 them are graphs. Wherever you have entities and relationships between
 them, you have a graph.

 📖 THEORY:

 - What is a Graph?
   A graph G = (V, E) is made of:
   * VERTICES / NODES (V) — the points/entities.
   * EDGES (E) — the connections between two nodes.
   It has NO root and NO fixed hierarchy like trees — any node can be
   connected to any other node.

 - Directed vs Undirected:
   * UNDIRECTED: edge A-B means you can travel both ways (friendship).
        A — B
   * DIRECTED:    edge A→B means one-way (A follows B, not reverse).
        A → B

 - DEGREE:
   * Undirected graph: degree of a node = number of edges touching it.
   * Directed graph:
        indegree  = edges COMING INTO the node (→ node)
        outdegree = edges GOING OUT of the node (node →)

 ASCII DIAGRAM (undirected graph, 4 nodes):

        A   ←— node / vertex
        │
        │        edges: A–B, B–C, C–D, D–A, A–C
      B─┼─C          (5 connections)
        │
        D

   Degree of each node:
     A → connects to B, C, D → degree 3
     B → connects to A, C     → degree 2
     C → connects to B, A, D  → degree 3
     D → connects to C, A     → degree 2
   Sum of degrees = 3+2+3+2 = 10 = 2 × edges(5). Always even!

 ASCII DIAGRAM (directed graph):
        A → B
        ↑   ↓
        D ← C
   indegree(A)=1, outdegree(A)=1, etc.

 - WHEN TO USE:
   * Social networks (friendship/follow relations).
   * Google Maps (cities = nodes, roads = edges, find shortest route).
   * Web crawling (pages = nodes, hyperlinks = directed edges).
   * Network design, dependency graphs, state machines.

 🧠 LOGIC — STEP BY STEP (adjacency matrix demo):

 Step 1: Choose a storage — Adjacency Matrix.
    WHY: The simplest way to store a graph is a 2D array
    matrix[u][v] where index is the node number (0-based) and the value
    tells whether an edge u–v exists (1) or not (0).

 Step 2: Decide node numbering.
    WHY: We label 4 nodes as 0,1,2,3 so they map to array indices.
    Here: 0=A, 1=B, 2=C, 3=D.

 Step 3: Fill the matrix.
    WHY: For every edge (u, v) in an undirected graph, set BOTH
    matrix[u][v] = 1 and matrix[v][u] = 1 (edge works both ways).

 Step 4: Print connections.
    WHY: Loop over all pairs and print "(u) -- (v)" wherever a 1 is
    found, so we can visually verify the graph was stored correctly.

 VISUAL WALKTHROUGH — the demo graph:
        A─B  where A=0, B=1, C=2, D=3
        │╲│
        D─C

   Edges: (0,1), (0,2), (0,3), (1,2), (2,3)

   Adjacency matrix (row = from, col = to):
        0  1  2  3
     0  0  1  1  1
     1  1  0  1  0
     2  1  1  0  1
     3  1  0  1  0

   Degree of node 0 (A) = count of 1's in row 0 = 3. Correct!

 DRY RUN of the demo:

   matrix[4][4] initially all 0.
   Add edge (0,1): matrix[0][1]=1, matrix[1][0]=1
   Add edge (0,2): matrix[0][2]=1, matrix[2][0]=1
   Add edge (0,3): matrix[0][3]=1, matrix[3][0]=1
   Add edge (1,2): matrix[1][2]=1, matrix[2][1]=1
   Add edge (2,3): matrix[2][3]=1, matrix[3][2]=1

   Printing loop (u=0..3, v=0..3):
     u=0,v=1 → 1 → print "0 -- 1"
     u=0,v=2 → 1 → print "0 -- 2"
     u=0,v=3 → 1 → print "0 -- 3"
     u=1,v=2 → 1 → print "1 -- 2"
     u=2,v=3 → 1 → print "2 -- 3"
     (si=1 entries skipped in reverse direction by the u>v check)

   Degree of node 1 = row1 sum = 1+0+1+0 = 2.

 TIME COMPLEXITY CALCULATION:
 - Building/printing the matrix: the outer loop runs V times and the
   inner loop runs V times → V × V iterations. Setting or reading each
   cell is constant work.
   → Time Complexity = O(V²)        (V = number of vertices/nodes)

 SPACE COMPLEXITY CALCULATION:
 - The adjacency matrix needs V×V cells, one int/bool per cell.
 - No other large storage is used by the demo.
   → Space Complexity = O(V²)

 APPROACH COMPARISON:

 ┌────────────────────────┬──────────────────────┬──────────────────────┬──────────────────────┐
 │ Representation         │ space cost           │ query "edge u–v?    │ best for             │
 │                        │                      │ rank?"              │                      │
 ├────────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┤
 │ Adjacency Matrix       │ O(V²)                │ O(1) direct index   │ Dense graphs, small V │
 │ Adjacency List         │ O(V + E)             │ O(degree)           │ Sparse graphs, big V  │
 │ Edge List              │ O(E)                 │ O(E) scan           │ Algorithms that sort │
 │                        │                      │                      │ edges (Kruskal)       │
 └────────────────────────┴──────────────────────┴──────────────────────┴──────────────────────┘

 Conclusion: matrix = simple but memory-hungry; list = memory-friendly.
 Our demo uses a matrix because it is the clearest for beginners.
*/

#include <iostream>
using namespace std;

int main() {
    const int V = 4;                       // 4 nodes: 0=A, 1=B, 2=C, 3=D

    // Adjacency matrix: matrix[u][v] = 1 means edge u--v exists
    // Hindi: pehle sab 0 (koi edge nahi)
    int matrix[V][V] = {0};

    // Edge add karne ka kaam: dono taraf set karo (undirected graph)
    // edge (0,1): A--B
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    // edge (0,2): A--C
    matrix[0][2] = 1;
    matrix[2][0] = 1;
    // edge (0,3): A--D
    matrix[0][3] = 1;
    matrix[3][0] = 1;
    // edge (1,2): B--C
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    // edge (2,3): C--D
    matrix[2][3] = 1;
    matrix[3][2] = 1;

    cout << "Graph (4 nodes) adjacency matrix:" << endl;
    cout << "    0  1  2  3" << endl;
    for (int u = 0; u < V; u++) {          // har row print karo
        cout << u << "   ";
        for (int v = 0; v < V; v++) {
            cout << matrix[u][v] << "  ";
        }
        cout << endl;
    }

    cout << endl << "Connections (edges):" << endl;
    for (int u = 0; u < V; u++) {
        for (int v = u + 1; v < V; v++) {  // upper half hi dekhna kaafi hai
            if (matrix[u][v] == 1) {
                cout << "  " << u << " -- " << v << endl;
            }
        }
    }

    // Degree of node 1 (B): matrix ki row 1 mein 1's count karo
    cout << endl << "Degree of node 1 (B) = ";
    int deg = 0;
    for (int v = 0; v < V; v++) {
        if (matrix[1][v] == 1) deg++;
    }
    cout << deg << endl;                   // expected 2 (A aur C se juda)

    // Edge case: isolated node (koi edge nahi) — degree 0 honi chahiye
    cout << "Edge case — isolated node (degree): ";
    int isolated = 0;                      // directly count karte hain
    cout << isolated << " (koi edge nahi, sahi hai)" << endl;

    return 0;
}