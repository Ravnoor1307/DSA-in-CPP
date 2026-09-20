/*
═══════════════════════════════════════════════
 TASK SET — GRAPHS (INTRO)
═══════════════════════════════════════════════

🌍 REAL-WORLD SCENARIO:
 A metro authority stores all stations and the rail lines between them.
 They need to answer: how many rail lines exist in total, whether two
 stations are directly connected, and how many direct lines touch each
 station (the degree). These numbers help them plan maintenance trips.
 Graphs (nodes + edges) are the perfect way to model this.

🧠 HOW TO SOLVE:
 - Represent the metro as a 4×4 adjacency matrix: matrix[u][v]=1 means
   a direct line exists between stations u and v.
 - Total edges in an undirected graph = count of 1's in the UPPER
   triangle only (each edge counted once), or sum of degrees ÷ 2.
 - Degree of a node = count of 1's in that node's row.
 - "Are u and v connected?" → just check matrix[u][v].

 TASK 1: (EASY) Count total edges
   Given an adjacency matrix (undirected), count and print the total
   number of edges.
   💡 HINT: loop u < v, count every matrix[u][v]==1 (upper triangle).
   ✏️ STARTER CODE:
     int countEdges(int m[4][4]) {
         int e = 0;
         for (int u = 0; u < 4; u++)
             for (int v = u+1; v < 4; v++)
                 // TODO: if edge exists, e++
         return e;
     }

 TASK 2: (EASY) Degree of a node
   Given a node number X, print the degree of X in the graph.
   💡 HINT: degree = number of 1's in row X.
   ✏️ STARTER CODE:
     int degree(int m[4][4], int x) {
         int d = 0;
         // TODO: count 1's in row x
         return d;
     }

 TASK 3: (MEDIUM) Are two nodes connected?
   Print "Connected" or "Not connected" for nodes u and v.
   💡 HINT: one if on m[u][v].
   ✏️ STARTER CODE:
     void isConnected(int m[4][4], int u, int v) {
         // TODO: if m[u][v]==1 print Connected else Not connected
     }

 TASK 4: (MEDIUM) Add a new edge
   Add an edge between two given nodes u and v (both directions) and
   print the new total edge count.
   💡 HINT: set m[u][v]=1 and m[v][u]=1, then reuse TASK 1 count.
   ✏️ STARTER CODE:
     void addEdge(int m[4][4], int u, int v) {
         // TODO: set both directions
     }

 TASK 5: (MEDIUM) Node with highest degree
   Find and print the node number having maximum degree.
   💡 HINT: loop all nodes, track max degree, reuse degree() from TASK 2.
   ✏️ STARTER CODE:
     int maxDegreeNode(int m[4][4]) {
         // TODO: compute degree of each node, return the max one
         return 0;
     }

 TASK 6: (HARD) Count isolated nodes
   Count nodes whose degree is 0 (no connections at all).
   💡 HINT: for each node, if its row has zero 1's, isolated++.
   ✏️ STARTER CODE:
     int isolatedNodes(int m[4][4]) {
         // TODO: count nodes with degree 0
         return 0;
     }

═══════════════════════════════════════════════
 DIAGRAM OF TEST GRAPH:
       0 ─ 1
       │ ╲ │
       3 ─ 2
   Edges: (0,1) (0,2) (0,3) (1,2) (2,3) → total 5 edges
   Degrees: 0→3, 1→2, 2→3, 3→2 | Max degree node = 0 (and 2)
   Isolated nodes: 0
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

int V = 4;   // 4 nodes

// TASK 1: total edges count karo (upper triangle)
int countEdges(int m[4][4]) {
    int e = 0;
    for (int u = 0; u < 4; u++) {
        for (int v = u + 1; v < 4; v++) {
            if (m[u][v] == 1) e++;
        }
    }
    return e;
}
// Explanation: undirected graph mein edge A–B dono jagah likha hota
// hai (m[A][B] aur m[B][A]). Isliye sirf upper triangle (u < v) count
// karo warna har edge double-count ho jayegi.

// TASK 2: node x ki degree
int degree(int m[4][4], int x) {
    int d = 0;
    for (int v = 0; v < 4; v++) {
        if (m[x][v] == 1) d++;
    }
    return d;
}
// Explanation: row x mein jitne 1 hain utne edges node x ko touch
// karti hain — yahi degree hai.

// TASK 3: connection check
void isConnected(int m[4][4], int u, int v) {
    if (m[u][v] == 1) {
        cout << "Connected" << endl;
    } else {
        cout << "Not connected" << endl;
    }
}
// Explanation: direct index lookup — O(1) ka sawal hai matrix mein.

// TASK 4: naya edge add karo
void addEdge(int m[4][4], int u, int v) {
    m[u][v] = 1;
    m[v][u] = 1;   // undirected, dono taraf
}
// Explanation: u se v aur v se u dono update karna zaroori hai.

// TASK 5: sabse bade degree wala node
int maxDegreeNode(int m[4][4]) {
    int best = 0, bestDeg = -1;
    for (int x = 0; x < 4; x++) {
        int d = degree(m, x);
        if (d > bestDeg) {
            bestDeg = d;
            best = x;
        }
    }
    return best;
}
// Explanation: har node ki degree nikaalo, jo sabse zyada ho use save
// karte jao. Tie mein pehla wala chunenge.

// TASK 6: isolated nodes count
int isolatedNodes(int m[4][4]) {
    int iso = 0;
    for (int x = 0; x < 4; x++) {
        if (degree(m, x) == 0) iso++;   // degree 0 = koi connection nahi
    }
    return iso;
}
// Explanation: degree 0 wala node kisi se bhi nahi juda.

int main() {
    // Test graph:
    //       0 ─ 1
    //       │ ╲ │
    //       3 ─ 2
    int m[4][4] = {0};
    m[0][1] = 1; m[1][0] = 1;   // 0–1
    m[0][2] = 1; m[2][0] = 1;   // 0–2
    m[0][3] = 1; m[3][0] = 1;   // 0–3
    m[1][2] = 1; m[2][1] = 1;   // 1–2
    m[2][3] = 1; m[3][2] = 1;   // 2–3

    cout << "Task 1 — Total edges: " << countEdges(m) << endl;          // 5
    cout << "Task 2 — Degree of node 1: " << degree(m, 1) << endl;      // 2
    cout << "Task 3 — 0 and 2 connected? "; isConnected(m, 0, 2);        // Connected
    cout << "Task 3 — 1 and 3 connected? "; isConnected(m, 1, 3);        // Not connected

    addEdge(m, 1, 3);                                                   // add 1–3 edge
    cout << "Task 4 — After adding 1–3, total edges: "
         << countEdges(m) << endl;                                      // 6

    cout << "Task 5 — Max degree node: " << maxDegreeNode(m) << endl;   // 0
    cout << "Task 6 — Isolated nodes: " << isolatedNodes(m) << endl;    // 0

    // Edge case: graph jisme koi edge nahi
    int empty[4][4] = {0};
    cout << "Edge case — empty graph edges: " << countEdges(empty) << endl;      // 0
    cout << "Edge case — all isolated: " << isolatedNodes(empty) << endl;        // 4

    return 0;
}

// ⏱ Time: TASK 1, 6 → O(V²) loops; TASK 2, 3 → O(V); TASK 5 → O(V²).
// 🧠 Space: matrix hi O(V²), baaki constant.