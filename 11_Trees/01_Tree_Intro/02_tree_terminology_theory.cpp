/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_tree_terminology_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Family tree me grandparent, parent, child, sibling, ancestor, descendant jaise terms use hote hain. Tree terminology same parent-child relationship ko programming me define karti hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Root = top node, jiska parent nahi.
│ 2. Parent/Child = direct connection.
│ 3. Leaf = node with no children.
│ 4. Sibling = same parent ke children.
│ 5. Ancestor/Descendant = ऊपर/नीचे chain relation.
│ 6. Edge = two nodes ka connection.
│ 7. Level/Depth = root se distance count style.
│ 8. Height = longest downward path length.
│
│ ASCII VISUAL / TREE STATE:
│ Complete labeled tree:
│
│ Level 0 / Depth 0:             A  ← Root
│                              /   \
│ Level 1 / Depth 1:          B     C  ← B,C siblings
│                            / \     \
│ Level 2 / Depth 2:        D   E     F  ← Leaves: D,E,F
│
│ Parent of B = A
│ Children of B = D,E
│ Ancestors of E = B,A
│ Descendants of A = B,C,D,E,F
│ Subtree at B = B with D,E
│ Edges = A-B, A-C, B-D, B-E, C-F
│
│ DRY RUN:
│ Pick node E:
│ parent(E)=B.
│ sibling(E)=D.
│ ancestors(E)=B then A.
│ depth(E)=2 edges from root.
│ E has no children, so E is leaf.
│
│ FLOW OF EXECUTION:
│ main -> create/describe tree -> pointer/term logic -> output
│
│ COMPLEXITY CALCULATION:
│ - Labeling terms for a fixed tree is conceptual.
│ - Computing all terms by traversal visits n nodes.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Tree storage n nodes.
│ - Traversal recursion/queue can use O(n) worst.
│ -> Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    cout << "Root: A\n";
    cout << "Parent of B: A, Children of B: D and E\n";
    cout << "Leaves: D, E, F\n";
    cout << "Siblings: B and C, also D and E\n";
    cout << "Ancestor of E: B and A; Descendant of A: B,C,D,E,F\n";
    cout << "Depth of E = 2 edges from root.\n";
    return 0;
}

/*
OUTPUT:
Root: A
Parent of B: A, Children of B: D and E
Leaves: D, E, F
Siblings: B and C, also D and E
Ancestor of E: B and A; Descendant of A: B,C,D,E,F
Depth of E = 2 edges from root.
*/

