/*
 * ══════════════════════════════════════════════════
 *  TASKS — 03_SLL_Class_Implementation
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

/* TASK 1 — mini list class with pushFront + size (EASY)
   Implement the two methods; expected after pushing 4,3,2:
   print 2 -> 3 -> 4 , size = 3 */
class MiniList {
public:
    Node* head = nullptr;
    void pushFront(int v) {
        Node* n = new Node(v);
        n->next = head;
        head = n;
    }
    int size() {
        int c = 0;
        for (Node* t = head; t; t = t->next) c++;
        return c;
    }
    void print() {
        Node* t = head;
        while (t) { cout << t->data; if (t->next) cout << " -> "; t = t->next; }
        cout << endl;
    }
    ~MiniList() { while (head) { Node* nxt = head->next; delete head; head = nxt; } }
};

/* TASK 2 — find middle node (MEDIUM)
   Return the data of the MIDDLE node (floor(n/2)-th, 0-based).
   Input {1,2,3,4,5} → 3. Input {1,2,3,4} → 3 (upper middle = index 2).
   Use only ONE walk idea (slow/fast). */
int task2_middleData(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;          // slow 1 step
        fast = fast->next->next;    // fast 2 steps — double speed
    }
    return slow ? slow->data : -1;
}

/* TASK 3 — check for a cycle (MEDIUM) via Floyd
   heads A and B given; return true if a cycle exists.
   A: 1->2->3->4 (none)      B: 1->2->3->4->back-to-2 (cycle) */
bool task3_hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;   // meet → cycle
    }
    return false;
}

/* TASK 4 — nth node from end without Length (MEDIUM-HARD)
   Return k-th (1-based) node from the END, or -1 if k invalid. */
int task4_nthFromEnd(Node* head, int k) {
    Node* slow = head;
    Node* fast = head;
    for (int i = 0; i < k; i++) {
        if (!fast) return -1;
        fast = fast->next;
    }
    while (fast) { slow = slow->next; fast = fast->next; }
    return slow ? slow->data : -1;
}

/* TASK 5 — destructor-equivalent WITHOUT leaks (HARD)
   Free the whole chain by hand. Save next BEFORE delete — that is the
   whole trick that makes the class destructor leak-free. */
Node* task5_destroyLinked(Node* head, int& freed) {
    freed = 0;
    while (head) {
        Node* nxt = head->next;    // next ko pehle save karo
        delete head;               // uske baad delete
        head = nxt;
        freed++;
    }
    return nullptr;
}
// helpers --------------------------------------------------------------
Node* buildFromArray(const int a[], int n) {
    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--) { Node* t = new Node(a[i]); t->next = head; head = t; }
    return head;
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    MiniList ml;
    ml.pushFront(4); ml.pushFront(3); ml.pushFront(2);
    ml.print();
    cout << "size = " << ml.size() << endl;

    cout << "---- TASK 2 ----" << endl;
    Node* h2a = buildFromArray(new int[5]{1, 2, 3, 4, 5}, 5);
    Node* h2b = buildFromArray(new int[4]{1, 2, 3, 4}, 4);
    cout << "middle {1..5} = " << task2_middleData(h2a) << endl;  // 3
    cout << "middle {1..4} = " << task2_middleData(h2b) << endl;  // 3

    cout << "---- TASK 3 ----" << endl;
    Node* h3a = buildFromArray(new int[4]{1, 2, 3, 4}, 4);
    Node* h3b = buildFromArray(new int[4]{1, 2, 3, 4}, 4);
    Node* tail = h3b;
    while (tail->next) tail = tail->next;
    tail->next = h3b->next;                                    // 4 -> 2 cycle
    cout << "cycle in A = " << (task3_hasCycle(h3a) ? "true" : "false") << endl; // false
    cout << "cycle in B = " << (task3_hasCycle(h3b) ? "true" : "false") << endl; // true

    cout << "---- TASK 4 ----" << endl;
    Node* h4 = buildFromArray(new int[5]{10, 20, 30, 40, 50}, 5);
    cout << "1st-from-end = " << task4_nthFromEnd(h4, 1) << endl; // 50
    cout << "3rd-from-end = " << task4_nthFromEnd(h4, 3) << endl; // 30
    cout << "6th-from-end = " << task4_nthFromEnd(h4, 6) << endl; // -1

    cout << "---- TASK 5 ----" << endl;
    Node* h5 = buildFromArray(new int[6]{1, 2, 3, 4, 5, 6}, 6);
    int freed = 0;
    h5 = task5_destroyLinked(h5, freed);
    cout << "freed nodes = " << freed << "  head = " << (h5 ? "LEAK" : "nullptr (clean)") << endl;

    return 0;
}
