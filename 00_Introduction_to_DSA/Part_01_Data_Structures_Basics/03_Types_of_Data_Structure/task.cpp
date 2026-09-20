/*
═══════════════════════════════════════════════
 TASK SET — TYPES OF DATA STRUCTURE
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A shopping mall handles different real-world
 queues: customers pay in a FIFO ticket counter, the canteen piles
 plates in a LIFO stack, and the app's category list is a plain linear
 array. Understanding which type of data structure fits each situation
 is the core skill of organizing data.

🧠 HOW TO SOLVE: Identify the shape first — sequential (array, stack,
 queue) or branching (tree). For stacks use top pointer with LIFO rules,
 for queues use front/rear with FIFO rules, for trees connect nodes with
 pointers. Test empty/duplicate edge cases.

 Tasks 1-6 (difficulty increasing EASY → HARD):

 TASK 1: Array traversal — forward and reverse.
   Read n numbers into an array. Print them forward, then print them in
   reverse order. (Singly housed data, two directions.)
   💡 HINT: forward loop i=0..n-1, reverse loop i=n-1..0.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       int main() {
           int n; cin >> n;
           int a[100];
           for (int i = 0; i < n; i++) cin >> a[i];
           cout << "forward:  ";
           // TODO: forward print karo
           cout << "\nreverse:  ";
           // TODO: reverse print karo
           cout << "\n";
           return 0;
       }

 TASK 2: Build a 3-node linked list and traverse it.
   Create three linked-list nodes with values 5, 10, 15, link them, and
   print the whole list using a pointer walk.
   💡 HINT: struct node { int data; node* next; }; do nodes ko aur teesre
            ko link karke pointer loop se chalo.
   ✏️ STARTER CODE:
       #include <iostream>
       using namespace std;
       struct Node { int data; Node* next; };
       int main() {
           Node a{5, nullptr}, b{10, nullptr}, c{15, nullptr};
           // TODO: a.next = &b; b.next = &c; TODO se link karo
           // TODO: pointer loop se 5 -> 10 -> 15 print karo
           return 0;
       }

 TASK 3: Binary tree with 3 nodes — print parent and children.
   Make a tree where root has data 7, left child 3, right child 12.
   Print "root=7 left=3 right=12".
   💡 HINT: struct tnode { int data; tnode *left, *right; }; root ke
            left/right me addresses daal do.
   ✏️ STARTER CODE:
       struct TNode { int data; TNode* left; TNode* right; };
       int main() {
           TNode left{3, nullptr, nullptr};
           TNode right{12, nullptr, nullptr};
           TNode root{7, nullptr, nullptr};
           // TODO: root ko left aur right se jodo
           // TODO: root.data, root.left->data, root.right->data print karo
           return 0;
       }

 TASK 4: Stack (LIFO) using an array.
   Implement push and pop: read a number; push it onto a stack array.
   Print the top, then pop twice and print the new top. Top pointer
   always points to the last inserted element.
   💡 HINT: top = -1 se shuru; push → arr[++top]=v; pop → top--; top>=0 check.
   ✏️ STARTER CODE:
       int main() {
           int stk[100], top = -1;
           int a, b, c; cin >> a >> b >> c;
           // TODO: teeno ko push karo (arr[++top] = value wala pattern)
           cout << "top = " << stk[top] << "\n";
           // TODO: ek baar pop karke phir top print karo
           return 0;
       }

 TASK 5: Queue (FIFO) using an array.
   Implement a circular-free simple queue: enqueue 3 numbers, print the
   front, dequeue twice, print the new front. Use front and rear indexes.
   💡 HINT: front=0, rear=-1; enqueue → arr[++rear]=v; dequeue → front++;
            jab tak front <= rear elements hain.
   ✏️ STARTER CODE:
       int main() {
           int q[100], front = 0, rear = -1;
           int a, b, c; cin >> a >> b >> c;
           // TODO: teeno ko enqueue karo
           cout << "front = " << q[front] << "\n";
           // TODO: do baar dequeue karke naya front print karo
           return 0;
       }

 TASK 6: Insert into a binary search tree (BST) and print in-order.
   Given 6 numbers, insert them following BST rule (smaller → left,
   larger/equal → right), then print the in-order sequence
   (left, root, right). In-order of a BST prints sorted order.
   💡 HINT: recursion ka use karo — insert(Node*& root, int v); aur
            inorder(Node* root) jo pahle left, phir root, phir right print kare.
   ✏️ STARTER CODE:
       struct Node { int data; Node* left; Node* right; };
       void insert(Node*& r, int v) {
           if (r == nullptr) { r = new Node{v, nullptr, nullptr}; return; }
           // TODO: v < r->data to left me insert, warna right me
       }
       void inorder(Node* r) {
           // TODO: left -> root -> right print karo (recursion)
       }
       int main() {
           Node* root = nullptr;
           int arr[6] = {50, 30, 70, 20, 40, 60};
           for (int i = 0; i < 6; i++) insert(root, arr[i]);
           // TODO: inorder(root) call karo — sorted output aana chahiye
           return 0;
       }

═══════════════════════════════════════════════
*/
#include<iostream>
using namespace std;
int main(){
 
return 0;
}