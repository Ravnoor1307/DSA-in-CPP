/*
 * ══════════════════════════════════════════════════
 *  TASKS — 04_SLL_Classic_Problems
 *  6 tasks EASY → HARD. Every task self-contained.
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

Node* build(const int a[], int n) {
    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--) { Node* t = new Node(a[i]); t->next = head; head = t; }
    return head;
}
void print(Node* h) {
    while (h) { cout << h->data << (h->next ? " -> " : ""); h = h->next; }
    cout << endl;
}
Node* destroy(Node* h) { while (h) { Node* nxt = h->next; delete h; h = nxt; } return nullptr; }

/* TASK 1 — reverse a list (EASY)
   Return reversed head. Input {1,2,3,4} → 4 -> 3 -> 2 -> 1 */
Node* task1_reverse(Node* head) {
    Node* prev = nullptr, *curr = head;
    while (curr) {
        Node* nxt = curr->next;    // next save, phir flip
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

/* TASK 2 — middle node data (EASY-MEDIUM)
   slow/fast. Input {1..6} upper middle = 4. */
int task2_middle(Node* head) {
    Node* slow = head, *fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    return slow ? slow->data : -1;
}

/* TASK 3 — cycle length if cycle exists (MEDIUM-HARD)
   Input: list with cycle A→B→C→D→B. Cycle length (B,C,D) = 3 → return 3.
   No cycle → 0. */
int task3_cycleLength(Node* head) {
    Node* slow = head, *fast = head;
    bool found = false;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) { found = true; break; }
    }
    if (!found) return 0;
    int len = 1;
    Node* p = slow->next;
    while (p != slow) { len++; p = p->next; }
    return len;
}

/* TASK 4 — remove cycle's LAST link, return head (MEDIUM-HARD)
   Walk to the node whose next == start and set next=null. */
Node* task4_removeCycle(Node* head) {
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return head;   // no cycle
    slow = head;
    while (slow != fast) { slow = slow->next; fast = fast->next; }
    Node* t = slow;
    while (t->next != slow) t = t->next;
    t->next = nullptr;
    return head;
}

/* TASK 5 — split into two halves (HARD)
   Given an EVEN list, return a new head for the SECOND half and cut the
   first half at the middle. Input {1,2,3,4,5,6} → print first 1 2 3 and
   second 4 5 6. (Use slow/fast to find the middle-ish cut.) */
Node* task5_split(Node* head, Node*& first) {
    if (!head) return nullptr;
    Node* slow = head, *fast = head;
    while (fast && fast->next && fast->next->next) {
        slow = slow->next; fast = fast->next->next;
    }
    Node* second = slow->next;   // slow = last node of first half
    slow->next = nullptr;        // cut
    first = head;
    return second;
}
int main() {
    cout << "---- TASK 1 ----" << endl;
    Node* h1 = build(new int[4]{1, 2, 3, 4}, 4);
    h1 = task1_reverse(h1);
    print(h1);                          // 4 -> 3 -> 2 -> 1

    cout << "---- TASK 2 ----" << endl;
    Node* h2 = build(new int[6]{1, 2, 3, 4, 5, 6}, 6);
    cout << "middle = " << task2_middle(h2) << endl;   // 4

    cout << "---- TASK 3 ----" << endl;
    Node* h3 = build(new int[4]{1, 2, 3, 4}, 4);
    cout << "no cycle len = " << task3_cycleLength(h3) << endl;   // 0
Node* h3b = build(new int[4]{1, 2, 3, 4}, 4);
    Node* tail = h3b; while (tail->next) tail = tail->next;
    tail->next = h3b->next;             // 4 -> 2, cycle B,C,D len 3
    cout << "cycle length = " << task3_cycleLength(h3b) << endl;  // 3
    h3b = task4_removeCycle(h3b);       // pehle cycle tod lo, phir destroy safe

    cout << "---- TASK 4 ----" << endl;
    Node* h4 = build(new int[5]{1, 2, 3, 4, 5}, 5);
    Node* t4 = h4; while (t4->next) t4 = t4->next;
    t4->next = h4->next->next;          // 5 -> 3
    h4 = task4_removeCycle(h4);
    print(h4);                          // 1 -> 2 -> 3 -> 4 -> 5

    cout << "---- TASK 5 ----" << endl;
    Node* h5 = build(new int[6]{1, 2, 3, 4, 5, 6}, 6);
    Node* first = nullptr;
    Node* second = task5_split(h5, first);
    cout << "first : "; print(first);
    cout << "second: "; print(second);

    destroy(h1); destroy(h2); destroy(h3); destroy(h3b); destroy(h4); destroy(first); destroy(second);
    return 0;
}
