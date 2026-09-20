# Trees — Intro

## Summary
- A Tree is a hierarchical structure of **nodes** connected by **edges**, with exactly one **root** at the top.
- Every node has one **parent** and can have many **children**; a node with no children is a **leaf**.
- **Height** = longest path (in edges) from root to a leaf; **depth** of a node = edges from root to that node.
- A **Binary Tree** restricts each node to at most 2 children (left and right).
- Demo uses `struct Node { int data; Node* left; Node* right; }` and prints nodes in **preorder** (Node → Left → Right).

## Real-World Analogy
Think of a **family tree** or a **company org-chart**: the CEO/root at top, managers below, employees at the leaves. Data that nests inside other data (folders in folders, HTML tags in HTML tags) is a tree.

## Files in This Folder
| File              | Purpose                                                       |
|-------------------|---------------------------------------------------------------|
| `01_theory.cpp`   | Pure theory + working demo (build a 5-node tree, preorder, height, edge cases) |
| `task.cpp`        | 6 tasks EASY→HARD (count nodes, leaves, preorder, sum, max, print leaves) with solutions |
| `README.md`       | This summary page                                             |

## Cheat Sheet / Syntax
```cpp
struct Node { int data; Node* left; Node* right; };

Node* newNode(int v){ Node* n = new Node; n->data = v; n->left = n->right = NULL; return n; }

// Preorder: Node → Left → Right
void preorder(Node* r){
    if (!r) return;
    cout << r->data << " "; preorder(r->left); preorder(r->right);
}
```

## Complexity Comparison Table
| Operation          | Calculation                                 | Time        | Space (stack) |
|--------------------|---------------------------------------------|-------------|---------------|
| Build tree (N nodes)| N nodes × O(1) each                       | O(N)        | O(1)          |
| Preorder traversal  | visit each of N nodes once (const work each)| O(N)        | O(h) worst O(N) |
| Leaf count          | same single pass                            | O(N)        | O(h) worst O(N) |
| Height              | each node visited once                      | O(N)        | O(h) worst O(N) |

## ⚠️ Common Mistakes
- Forgetting the `root == NULL` base case → infinite recursion / crash.
- Confusing **height** (edges) with counting **levels** (nodes) — off-by-one errors.
- Setting `left`/`right` without `new` → using NULL pointers crashes on access.
- Thinking all trees are binary trees — trees can have any number of children.

## Interview Q&A
- **Q:** What is a leaf? **A:** A node with no children (both pointers NULL).
- **Q:** What is height vs depth? **A:** Height = longest root-to-leaf count of edges; depth = edges from root to a given node.
- **Q:** What is preorder? **A:** Visit node, then left subtree, then right subtree — output for our demo: `1 2 4 3 5`.
- **Q:** Why is tree search faster than a list? **A:** Each level cuts the search space in half in a balanced BST, giving O(log N) versus O(N) linear scan.