/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_traversal_intro_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Linear list me ek hi natural route hota hai: left to right. Tree me branches hoti hain, isliye visit order choose karna padta hai: inorder, preorder, postorder, level order.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Traversal means every node ko systematic order me visit karna.
│ 2. DFS traversals: inorder, preorder, postorder.
│ 3. Names root position se yaad rakho.
│ 4. Preorder: ROOT first.
│ 5. Inorder: ROOT in middle.
│ 6. Postorder: ROOT last.
│ 7. Level order: level by level queue se.
│
│ ASCII VISUAL / TRAVERSAL STATE:
│ Same tree:
│          1
│        /   \
│       2     3
│      / \   / \
│     4   5 6   7
│
│ Inorder   L Root R : 4 2 5 1 6 3 7
│ Preorder  Root L R : 1 2 4 5 3 6 7
│ Postorder L R Root : 4 5 2 6 7 3 1
│ Level order        : 1 2 3 4 5 6 7
│
│ DRY RUN:
│ Root=1.
│ If root visited first -> preorder starts with 1.
│ If root visited middle -> inorder has 1 after left subtree.
│ If root visited last -> postorder ends with 1.
│
│ FLOW OF EXECUTION:
│ root -> traversal rule -> recursive/queue/stack movement -> output order
│
│ COMPLEXITY CALCULATION:
│ - Any full traversal visits each of n nodes exactly once.
│ - Work per node is constant print/process.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursive DFS uses stack height h.
│ - Queue level order can store up to width w, worst n.
│ -> Space Complexity = O(h) DFS, O(n) BFS worst.
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
    cout << "Traversal means visiting every node in a chosen order.\n";
    cout << "Preorder: ROOT LEFT RIGHT\n";
    cout << "Inorder: LEFT ROOT RIGHT\n";
    cout << "Postorder: LEFT RIGHT ROOT\n";
    cout << "Level order: level by level using queue\n";
    return 0;
}

/*
OUTPUT:
Traversal means visiting every node in a chosen order.
Preorder: ROOT LEFT RIGHT
Inorder: LEFT ROOT RIGHT
Postorder: LEFT RIGHT ROOT
Level order: level by level using queue
*/

