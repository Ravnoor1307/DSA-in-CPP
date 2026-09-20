/*
 * ══════════════════════════════════════════════════
 *  TASKS — 03_Stack_Class_STL
 *  5 tasks EASY → HARD. Every task self-contained.
 *  pattern: read → think → verify against expected output.
 * ══════════════════════════════════════════════════
 */
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
using namespace std;

/* TASK 1 — custom class: copy size after popping (EASY)
   Build a MyStack, push 1..5, pop 2, report size and top. */
int task1_custom() {
    struct S {
        int buf[16]; int top = 0;
        void push(int v) { buf[top++] = v; }
        int pop() { return (top == 0) ? -1 : buf[--top]; }
        int size() const { return top; }
        int topOf() const { return (top == 0) ? -1 : buf[top - 1]; }
    };
    S s;
    for (int i = 1; i <= 5; i++) s.push(i);
    s.pop(); s.pop();
    return s.size();               // 3
}

/* TASK 2 — STL badge check (EASY)
   std::stack<int, vector<int>> vs default. Determine which container backs
   the default stack, print the typeid-free answer as text. */
void task2_backing() {
    // default = deque; explicit = vector
    cout << "default back = deque, can switch to vector/list" << endl;
    stack<int, vector<int>> sv;
    sv.push(7);
    cout << "vector-backed top = " << sv.top() << endl;  // 7
}

/* TASK 3 — STL stack: reverse 5 ints (MEDIUM)
   Push {10,20,30,40,50}, pop into another array → reversed. */
void task3_reverseSTL() {
    stack<int> st;
    for (int i = 1; i <= 5; i++) st.push(i * 10);        // 10..50
    while (!st.empty()) { cout << st.top() << " "; st.pop(); }
    cout << endl;                                        // 50 40 30 20 10
}

/* TASK 4 — two custom stacks: transfer (MEDIUM)
   Move all elements from stack A to stack B. A={1,2,3} (top=3). Popping A
   gives 3,2,1, so B ends reversed: 1,2,3 with top=1. Return B's top. */
int task4_transfer() {
    struct S {
        int buf[16]; int top = 0;
        void push(int v) { buf[top++] = v; }
        int pop() { return (top == 0) ? -1 : buf[--top]; }
        bool empty() const { return top == 0; }
    };
    S a, b;
    a.push(1); a.push(2); a.push(3);      // a top = 3
    while (!a.empty()) b.push(a.pop());   // b gets 1,2,3 and top=3
    return b.pop();                       // 3
}

/* TASK 5 — custom min-stack (HARD)
   Augment the stack to return the minimum in O(1): keep a parallel stack of
   minima along with data. Push 4,2,5,1 → min() gives 1 after each push,
   2 after popping 1. */
void task5_minStack() {
    struct MinS {
        int data[16]; int top = 0;
        int mn[16];                       // har state ka min
        void push(int v) {
            int newMin = (top == 0) ? v : (v < mn[top - 1] ? v : mn[top - 1]);
            data[top] = v; mn[top] = newMin; top++;
        }
        int pop() { return (top == 0) ? -1 : data[--top]; }
        int min() const { return (top == 0) ? -1 : mn[top - 1]; }
    };
    MinS s;
    s.push(4); cout << "min after push4 = " << s.min() << endl;      // 4
    s.push(2); cout << "min after push2 = " << s.min() << endl;      // 2
    s.push(5); cout << "min after push5 = " << s.min() << endl;      // 2
    s.push(1); cout << "min after push1 = " << s.min() << endl;      // 1
    s.pop();   cout << "min after pop1  = " << s.min() << endl;      // 2
}

int main() {
    cout << "---- TASK 1 ----" << endl;
    cout << "size after pops = " << task1_custom() << endl;    // 3

    cout << "---- TASK 2 ----" << endl;
    task2_backing();

    cout << "---- TASK 3 ----" << endl;
    task3_reverseSTL();

    cout << "---- TASK 4 ----" << endl;
    cout << "B top after transfer = " << task4_transfer() << endl;  // 1 (reversed: 3,2,1)

    cout << "---- TASK 5 ----" << endl;
    task5_minStack();
    return 0;
}