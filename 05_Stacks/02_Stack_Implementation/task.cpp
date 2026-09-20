/*
 * ══════════════════════════════════════════════════
 *  TASKS — 02_Stack_Implementation
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
using namespace std;

/* TASK 1 — array stack: reverse push order print (EASY)
   Implement push + pop on a fixed array and print the pop order.
   Input {1,2,3,4} pushed in order → pop order 4 3 2 1. */
void task1_arrayStack() {
    int arr[8], top = 0;
    int input[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) arr[top++] = input[i];   // push all
    while (top > 0) cout << arr[--top] << " ";           // pop all
    cout << endl;
}

/* TASK 2 — list stack with real push_front/pop_front (EASY)
   Push 1..5 onto a linked stack, then pop and count nodes. Return count. */
int task2_listStack() {
    struct N { int d; N* n; N(int v) : d(v), n(nullptr) {} };
    N* head = nullptr;
    auto push = [&](int v) { N* x = new N(v); x->n = head; head = x; };
    for (int i = 5; i >= 1; i--) push(i);            // push 1,2,3,4,5
    int cnt = 0;
    while (head) { N* t = head; head = head->n; delete t; cnt++; }
    return cnt;                                       // 5
}

/* TASK 3 — peek vs pop: middle helper (MEDIUM)
   On the linked stack, find the middle value WITHOUT removing it.
   Stack 1,2,3,4,5 (5 at top) → middle = 3. */
int task3_middleLinked() {
    struct N { int d; N* n; N(int v) : d(v), n(nullptr) {} };
    N* head = nullptr;
    auto push = [&](int v) { N* x = new N(v); x->n = head; head = x; };
    for (int i = 5; i >= 1; i--) push(i);
    // 2-pointer: slow/hare both from head
    N *slow = head, *fast = head;
    while (fast && fast->n) { slow = slow->n; fast = fast->n->n; }
    return slow->d;
}

/* TASK 4 — two stacks: mirror fill (MEDIUM)
   Fill stack1 = {1,2,3} and stack2 = {6,5,4} in one array of size 6;
   verify they meet without collision and report both sizes. */
void task4_twoStacks() {
    int cap = 6, arr[6], top1 = 0, top2 = cap - 1;
    int s1[3] = {1, 2, 3}, s2[3] = {6, 5, 4};
    for (int i = 0; i < 3; i++) arr[top1++] = s1[i];
    for (int i = 0; i < 3; i++) arr[top2--] = s2[i];
    bool crossed = (top1 > top2);
    cout << "top1=" << top1 << " top2=" << top2
         << " crossed=" << (crossed ? "yes" : "no") << endl;   // top1=3 top2=2 crossed=yes
    for (int i = 0; i < cap; i++) cout << arr[i] << " ";       // 1 2 3 4 5 6 (full array)
    cout << endl;
}

/* TASK 5 — array vs list: measure extra pointer overhead (HARD-ish)
   An array stack stores n ints: n*4 bytes. A linked stack stores n nodes
   each carrying int(4) + pointer(8) + alignment(4)=16 bytes. Print the
   overhead ratio for n = 1000. */
void task5_memoryRatio() {
    int n = 1000;
    int arrayBytes = n * sizeof(int);
    int nodeBytes = sizeof(int) + sizeof(void*);
    int listBytes = n * nodeBytes;
    cout << "array bytes=" << arrayBytes << " list bytes=" << listBytes << endl;
    cout << "overhead ratio=" << (listBytes + arrayBytes - 1) / arrayBytes << "x" << endl;
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    task1_arrayStack();                                // 4 3 2 1

    cout << "---- TASK 2 ----" << endl;
    cout << "nodes popped = " << task2_listStack() << endl;   // 5

    cout << "---- TASK 3 ----" << endl;
    cout << "middle = " << task3_middleLinked() << endl;      // 3

    cout << "---- TASK 4 ----" << endl;
    task4_twoStacks();

    cout << "---- TASK 5 ----" << endl;
    task5_memoryRatio();
    return 0;
}