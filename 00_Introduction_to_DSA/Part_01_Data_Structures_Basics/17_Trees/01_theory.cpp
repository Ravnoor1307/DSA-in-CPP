/*
═══════════════════════════════════════════════
 TREES — INTRO
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a family tree: grandparents at the top, their children below,
 grandchildren further down. Each person has exactly one parent but can
 have many children. A company org-chart is the same — the CEO at the
 top, managers under them, employees under those. This branching
 structure is exactly what a "Tree" is in computer science. It helps us
 store data hierarchically where each item is reached through a chain
 of ancestors, like a path in a real family.

 📖 THEORY:

 - What is a Tree?
   A tree is a hierarchical data structure made of NODES connected by
   EDGES. Every node holds data, and it points downward to its children.
   There is exactly ONE special node at the very top called the ROOT.
   Every other node is reachable from the root through exactly one path.

 - Key terms (memorize these):
   * ROOT     → topmost node, the only node with NO parent.
   * PARENT   → the node directly above another node.
   * CHILD    → a node directly below a parent.
   * LEAF     → a node with NO children (end of a branch).
   * HEIGHT   → longest number of edges from root down to a leaf.
   * DEPTH    → number of edges from root down to a node.
   * SUBTREE  → a node together with all of its descendants.

 - Binary Tree: each node has AT MOST 2 children, usually called
   LEFT and RIGHT.

 ASCII DIAGRAM of a binary tree:
                    ┌──────┐
                    │  50  │  ← ROOT
                    │ROOT  │
                    └──┬───┘
                       │
             ┌─────────┴─────────┐
        ┌────┴────┐         ┌────┴────┐
        │  30     │         │  70     │  ← children of 50
        │(parent) │         │(parent) │
        └────┬────┘         └────┬────┘
             │                   │
        ┌────┴────┐              └────┬────┐
        │  20     │                   │  80 │
        │ (LEAF)  │                   │(LEAF)│
        └─────────┘                   └──────┘
             30             40    70       80
            (LEAF)        (LEAF)              (LEAF)

   Here: root = 50, height = 2 (edges: 50→30→20 = 2 edges),
   leaves = 20, 40, 80.

 - WHEN TO USE:
   * File systems (folders inside folders).
   * HTML/DOM structure, XML, JSON nesting.
   * Game decision trees, AI minimax.
   * Search trees (BST) for fast lookup.
   * Expression trees in compilers.

 🧠 LOGIC — STEP BY STEP (building + printing a tree):

 Step 1: Define node shape.
    WHY: A tree needs a data piece plus links to left and right kids.
    Use struct Node { int data; Node* left; Node* right; }.

 Step 2: New node factory.
    WHY: Writing new Node{} again and again is messy; make a helper
    function newNode(data) that sets both pointers to NULL.

 Step 3: Join nodes manually (pointer to pointer).
    WHY: To build a fixed small tree, connect root->left = b etc.
    This shows the parent-child relationship clearly.

 Step 4: Preorder print (Node, then Left, then Right).
    WHY: Preorder = "visit me first, then my left subtree, then my
    right subtree" — it is the classic first traversal to learn.

 VISUAL WALKTHROUGH:

   Tree we build in the demo:
                ┌──────┐
                │  1   │  root
                └──┬───┘
                   │
        ┌──────────┴──────────┐
   ┌────┴────┐          ┌────┴────┐
   │   2     │          │   3     │
   └────┬────┘          └───┬─────┘
        │                   │
   ┌────┴────┐         ┌────┴────┐
   │   4     │         │   5     │
   └─────────┘         └─────────┘

   Preorder walk order:
   visit 1 → left subtree → visit 2 → visit 4 → back → visit 3 → visit 5
   Output: 1 2 4 3 5

 DRY RUN of the demo:

   newNode(1) → returns node with data=1, left=NULL, right=NULL.
   newNode(2) → same for 2. newNode(3) → for 3.
   newNode(4) → for 4. newNode(5) → for 5.

   root->left  = node2
   root->right = node3
   node2->left = node4
   node3->right= node5

   printPreorder(root):
     node=1 → print "1", go left to 2
     node=2 → print "2", go left to 4
     node=4 → print "4", left NULL  → stop, right NULL → stop, return
     back at 2 → right NULL → return
     back at 1 → go right to 3
     node=3 → print "3", left NULL → right to 5
     node=5 → print "5", children NULL → return
   Final output: 1 2 4 3 5

 TIME COMPLEXITY CALCULATION:
 - Building the tree: we create 5 nodes, each a constant amount of work
   (one allocation + two pointer assignments).
   Total = 5 × O(1) = O(5) → O(1) work per node.
 - Traversal (preorder): each of the N nodes is visited exactly once, and
   for each node we check its left and right pointer (constant work).
   So total visits = N, work = 1 + 2 per node = 3N.
   → Time Complexity = O(N)     (where N = number of nodes)

 SPACE COMPLEXITY CALCULATION:
 - The tree itself stores N nodes → O(N) for the data.
 - The recursion stack: at any moment the recursion goes as deep as the
   tree height h. In worst case (a "skewed" tree like a chain) h = N,
   so recursion stack can hold up to N frames.
   → Space Complexity = O(h) for recursion, worst case O(N)
     (average/best (balanced tree): O(log N)).

 APPROACH COMPARISON:

 ┌─────────────────────┬──────────────────────┬──────────────────┬──────────────────┐
 │ Storage             │ Finding an item      │ Insertion        │ Best for         │
 ├─────────────────────┼──────────────────────┼──────────────────┼──────────────────┤
 │ Array (linear)      │ Scan one by one O(N) │ Append O(1)      │ Small fixed data │
 │ Linked list (linear)│ Scan one by one O(N) │ Front/back O(1)  │ Frequent inserts │
 │ Tree (hierarchical) │ Follow path O(h)     │ Place by rule    │ Hierarchy, fast  │
 │                     │ (balanced: O(log N)) │ O(h)             │ search           │
 └─────────────────────┴──────────────────────┴──────────────────┴──────────────────┘

 Conclusion: if data is naturally hierarchical (family, folders, menus),
 use a Tree instead of a flat list.
*/

#include <iostream>
using namespace std;

// Node struct: data + left + right links
// Hindi comment: har node ke paas 2 children ka pointer hota hai
struct Node {
    int data;
    Node* left;
    Node* right;
};

// naya node banane ka helper function
Node* newNode(int val) {
    Node* n = new Node;
    n->data = val;
    n->left = NULL;   // abhi tak koi child nahi
    n->right = NULL;
    return n;
}

// Preorder: pehle root print, phir left subtree, phir right subtree
void printPreorder(Node* root) {
    if (root == NULL) {
        return;       // empty tree / leaf ke aage kuch nahi
    }
    cout << root->data << " ";   // 1) node khud print karo
    printPreorder(root->left);   // 2) left branch jao
    printPreorder(root->right);  // 3) right branch jao
}

// Tree ki height: root se sabse door leaf tak ki edges ki ginti
int treeHeight(Node* root) {
    if (root == NULL) {
        return -1;               // empty tree ki height -1
    }
    int leftH  = treeHeight(root->left);
    int rightH = treeHeight(root->right);
    if (leftH > rightH) {
        return leftH + 1;
    }
    return rightH + 1;
}

int main() {
    /*
        Hum ye tree banayenge:
                   1
                  / \
                 2   3
                /     \
               4       5
    */
    Node* root = newNode(1);   // root node data = 1

    // children create karo
    Node* node2 = newNode(2);
    Node* node3 = newNode(3);
    Node* node4 = newNode(4);
    Node* node5 = newNode(5);

    // ab nodes ko jodo (parent -> child)
    root->left  = node2;
    root->right = node3;
    node2->left = node4;        // 2 ka left bacha 4
    node3->right = node5;       // 3 ka right bacha 5

    cout << "Preorder traversal: ";
    printPreorder(root);        // expected: 1 2 4 3 5
    cout << endl;

    cout << "Height of tree: " << treeHeight(root) << endl;   // 2

    // Edge case: empty tree
    Node* emptyTree = NULL;
    cout << "Empty tree ka kaam: ";
    printPreorder(emptyTree);   // kuch print nahi hoga
    cout << "(kuch nahi, sahi hai)" << endl;

    return 0;
}