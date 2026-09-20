/*
 * ══════════════════════════════════════════════════
 *  TASKS — 06_Circular_Linked_List
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

/* TASK 1 — count nodes in the ring (EASY)
   Return the number of nodes. Ring {5,10,15,20} → 4. */
int task1_count(Node* head) {
    if (!head) return 0;
    int c = 0;
    Node* t = head;
    do { c++; t = t->next; } while (t != head);   // ek pura lap
    return c;
}

/* TASK 2 — find MAX in the ring (EASY)
   Return the largest data value. {7,3,9,1} → 9. */
int task2_max(Node* head) {
    if (!head) return -1;
    int mx = head->data;
    Node* t = head->next;
    while (t != head) {
        if (t->data > mx) mx = t->data;
        t = t->next;
    }
    return mx;
}

/* TASK 3 — k times "jump next" (MEDIUM)
   Starting from a given node, move k steps forward (wrapping) and return
   the data at the landing node. Ring {1,2,3,4}, start=3, k=5 → 2? no:
   compute carefully: walk from 3 for 5 nexts → 3→4→1→2→3→4 landing=4.
   k=5 landing node data = 4. */
int task3_jump(Node* start, int k) {
    Node* t = start;
    for (int i = 0; i < k; i++) t = t->next;   // k baar aage
    return t->data;
}

/* TASK 4 — delete the ONLY node / empty check (MEDIUM)
   Given head, delete the FIRST node (data == target). After deletion the
   ring must stay valid. Return the NEW head (or nullptr if ring became
   empty). Ring {1,2,3}, delete 1 → new head = 2, lap = 2 3. */
Node* task4_deleteNode(Node* head, int target) {
    if (!head) return nullptr;
    Node* cur = head;
    Node* prev = nullptr;
    Node* last = head;
    while (last->next != head) last = last->next;   // tail dhoondo
    prev = last;
    do {
        if (cur->data == target) {
            if (cur == head) {
                if (head->next == head) {            // single node
                    delete head;
                    return nullptr;
                }
                head = cur->next;
            }
            prev->next = cur->next;                  // ring splices
            delete cur;
            return head;
        }
        prev = cur;
        cur = cur->next;
    } while (cur != head);
    return head;                                     // target nahi mila
}

/* TASK 5 — Josephus survivor (HARD)
   n people in a ring numbered 1..n; every k-th person is eliminated
   (1-based counting starting at node 1). Return the data of the LAST
   remaining node. n=5, k=2 → survivor = 3. n=7, k=3 → survivor = 4. */
int task5_josephus(int n, int k) {
    Node* head = new Node(1);
    Node* tail = head;
    for (int i = 2; i <= n; i++) {
        Node* t = new Node(i);
        tail->next = t;
        tail = t;
    }
    tail->next = head;                 // ring close
    Node* cur = head;
    Node* prev = tail;                 // sidhu purane waale ka back ref
    while (cur->next != cur) {
        for (int i = 1; i < k; i++) {  // k-1 steps ke liye aage badho
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;        // cur ko eliminate
        delete cur;
        cur = prev->next;              // next se counting restart
    }
    int survivor = cur->data;
    delete cur;
    return survivor;
}

// helper: build ring from array
Node* buildRing(const int a[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Node* t = new Node(a[i]);
        if (!head) head = tail = t;
        else { tail->next = t; tail = t; }
    }
    if (tail) tail->next = head;       // ring close
    return head;
}
void printLap(Node* head) {
    if (!head) { cout << "(empty)" << endl; return; }
    Node* t = head;
    do { cout << t->data << " "; t = t->next; } while (t != head);
    cout << endl;
}
// break the ring and free every node
void destroyRing(Node*& head) {
    if (!head) return;
    Node* t = head;
    do {
        Node* nxt = t->next;
        delete t;
        t = nxt;
    } while (t != head);
    head = nullptr;
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    Node* h1 = buildRing(new int[4]{5, 10, 15, 20}, 4);
    cout << "count = " << task1_count(h1) << endl;   // 4

    cout << "---- TASK 2 ----" << endl;
    Node* h2 = buildRing(new int[4]{7, 3, 9, 1}, 4);
    cout << "max = " << task2_max(h2) << endl;       // 9

    cout << "---- TASK 3 ----" << endl;
    Node* h3 = buildRing(new int[4]{1, 2, 3, 4}, 4);
    cout << "jump 5 from 3 = " << task3_jump(h3->next->next, 5) << endl; // 4

    cout << "---- TASK 4 ----" << endl;
    Node* h4 = buildRing(new int[3]{1, 2, 3}, 3);
    h4 = task4_deleteNode(h4, 1);
    printLap(h4);                                     // 2 3

    cout << "---- TASK 5 ----" << endl;
    cout << "josephus(5,2) = " << task5_josephus(5, 2) << endl;  // 3
    cout << "josephus(7,3) = " << task5_josephus(7, 3) << endl;  // 4

    // cleanup
    destroyRing(h1);
    destroyRing(h2);
    destroyRing(h3);
    destroyRing(h4);
    return 0;
}