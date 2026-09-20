/*
═══════════════════════════════════════════════
 TASK SET — TREES (INTRO)
═══════════════════════════════════════════════

🌍 REAL-WORLD SCENARIO:
 A school principal wants a report of how many students sit in each
 "leaf" classroom (classes with no sub-sections). Also, the attendance
 register needs every student's name listed in a "root-first" order so
 the principal meets seniors before juniors. Trees model exactly this
 school hierarchy: principal (root) → departments → classes.

🧠 HOW TO SOLVE:
 - Represent the school as a Node{int data; Node* left; Node* right;}.
 - Use recursion: a node's total = node + total(left) + total(right).
 - Leaves are nodes where BOTH left and right are NULL.
 - "Root-first order" = preorder (print node, then left, then right).

 TASK 1: (EASY) Count Nodes
   Given the root of a binary tree, count and print the TOTAL number
   of nodes in the tree.
   💡 HINT: total(root) = 1 + total(root->left) + total(root->right);
   ✏️ STARTER CODE:
     int countNodes(Node* root) {
         if (root == NULL) return 0;
         // TODO: return 1 + count left + count right
         return 0;
     }
     // main: build 5-node tree, print countNodes(root) — expect 5

 TASK 2: (EASY) Count Leaf Nodes
   Count all LEAF nodes (nodes with no children).
   💡 HINT: if left and right both NULL, return 1; else recurse both.
   ✏️ STARTER CODE:
     int countLeaves(Node* root) {
         if (root == NULL) return 0;
         // TODO: leaf check + recurse
         return 0;
     }

 TASK 3: (MEDIUM) Print Preorder (recursive)
   Print all nodes in preorder order (Node, Left, Right).
   💡 HINT: if root==NULL return; print root->data first.
   ✏️ STARTER CODE:
     void preorder(Node* root) {
         if (root == NULL) return;
         // TODO: print -> left -> right
     }

 TASK 4: (MEDIUM) Sum of all node values
   Add every node's data and print the total sum.
   💡 HINT: sum(root) = root->data + sum(left) + sum(right).
   ✏️ STARTER CODE:
     int sumNodes(Node* root) {
         if (root == NULL) return 0;
         // TODO: data + left sum + right sum
         return 0;
     }

 TASK 5: (MEDIUM) Find the maximum value in the tree
   Return the largest data value present in the tree.
   💡 HINT: max(root) = max(root->data, max(left), max(right)).
   ✏️ STARTER CODE:
     int maxNode(Node* root) {
         if (root == NULL) return -999999;
         // TODO: compare data, left max, right max
         return 0;
     }

 TASK 6: (HARD) Print only leaves, left-to-right
   Print only the leaf node values in order (left leaves first).
   💡 HINT: recurse left THEN right; only print when both NULL.
   ✏️ STARTER CODE:
     void printLeaves(Node* root) {
         if (root == NULL) return;
         // TODO: leaf check + left recursion + right recursion
     }

═══════════════════════════════════════════════
 DIAGRAM OF TEST TREE (used in all tasks):
                   10
                  /  \
                 20   30
                /       \
               40        50
   Nodes: 5 | Leaves: 40, 50 | Preorder: 10 20 40 30 50
   Sum: 150 | Max: 50
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
using namespace std;

// TreeNode struct: data + left + right links
struct Node {
    int data;
    Node* left;
    Node* right;
};

// naya node banane ka helper
Node* newNode(int val) {
    Node* n = new Node;
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// TASK 1: total nodes count karo
int countNodes(Node* root) {
    if (root == NULL) return 0;          // base case: khali tree
    return 1 + countNodes(root->left) + countNodes(root->right);
}
// Explanation: har node khud 1 count karta hai, plus left subtree,
// plus right subtree. Recursion sab counts jod deta hai.

// TASK 2: leaves count karo
int countLeaves(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) {
        return 1;                        // ye ek leaf hai
    }
    return countLeaves(root->left) + countLeaves(root->right);
}
// Explanation: dono children NULL wala node = leaf. Baaki har node
// apne left aur right subtree ke leaves jodta hai.

// TASK 3: preorder print — Node, Left, Right
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";           // pehle khud
    preorder(root->left);                // phir left
    preorder(root->right);               // phir right
}
// Explanation: isee "root-first" order bolte hain — principal pehle.

// TASK 4: sab nodes ka sum
int sumNodes(Node* root) {
    if (root == NULL) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
// Explanation: har node apna data + left sum + right sum return karta hai.

// TASK 5: maximum value dhundo
int maxNode(Node* root) {
    if (root == NULL) return -999999;    // sangat chhota number
    int leftMax  = maxNode(root->left);
    int rightMax = maxNode(root->right);
    int m = root->data;
    if (leftMax  > m) m = leftMax;
    if (rightMax > m) m = rightMax;
    return m;
}
// Explanation: teeno mein jo sabse bada hai wahi max — tree ka max
// ya to root pe, ya left mein, ya right mein hoga.

// TASK 6: sirf leaves print karo, left-to-right
void printLeaves(Node* root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";       // leaf mil gaya, print
        return;
    }
    printLeaves(root->left);             // pehle left jaao
    printLeaves(root->right);            // phir right jaao
}
// Explanation: leaf aa jaaye to print, warna pehle left subtree ke
// leaves print honge phir right ke — isliye left-to-right order.

int main() {
    // Test tree:
    //           10
    //          /  -
    //         20   30
    //        /       -
    //       40        50
    Node* root = newNode(10);
    root->left  = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->right->right = newNode(50);

    cout << "Task 1 — Total nodes: " << countNodes(root) << endl;   // 5
    cout << "Task 2 — Leaf nodes: " << countLeaves(root) << endl;   // 2
    cout << "Task 3 — Preorder: ";
    preorder(root);                                                 // 10 20 40 30 50
    cout << endl;
    cout << "Task 4 — Sum: " << sumNodes(root) << endl;             // 150
    cout << "Task 5 — Max: " << maxNode(root) << endl;              // 50
    cout << "Task 6 — Leaves only: ";
    printLeaves(root);                                              // 40 50
    cout << endl;

    // Edge case test: khali tree
    Node* empty = NULL;
    cout << "Empty tree nodes: " << countNodes(empty) << endl;      // 0
    cout << "Empty tree leaves: " << countLeaves(empty) << endl;    // 0

    return 0;
}

// ⏱ Time: har task mein har node exactly 1 baar visit hoti hai → O(N).
// 🧠 Space: recursion stack tree height jitna → O(h), worst case O(N).