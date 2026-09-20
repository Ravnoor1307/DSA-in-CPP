/*
═══════════════════════════════════════════════
 STACK (LIFO) — INTRODUCTION
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of a stack of plates in a cafeteria. You always add a new plate
 on top (PUSH) and you always remove the top plate first (POP). You
 can never take a plate from the middle or bottom — only the top one.
 The last plate you put on is the first one you take off. This is
 called LIFO — Last In, First Out. Stacks are used everywhere: undo
 buttons in editors, browser back button, function call stacks, and
 expression evaluation.

 📖 THEORY:
 - A Stack is a linear data structure that follows LIFO (Last In First Out).
 - PUSH: Insert an element on top of the stack.
 - POP: Remove the top element from the stack.
 - PEEK/TOP: View the top element without removing it.
 - isEmpty: Check if the stack has no elements.
 - isFull: Check if the stack has reached its maximum capacity (array-based).
 - "top" pointer/index tracks the current top of the stack.
 - We will implement an array-based stack here.

 ASCII DIAGRAM:

  Array-based Stack:
  
  Index:   0      1      2      3      4
        ┌──────┬──────┬──────┬──────┬──────┐
        │  10  │  20  │  30  │      │      │
        └──────┴──────┴──────┴──────┴──────┘
                              ▲
                              │
                             TOP = 2

  PUSH(40):                    POP():
  ┌──────┬──────┬──────┬──────┬──────┐     ┌──────┬──────┬──────┬──────┬──────┐
  │  10  │  20  │  30  │  40  │      │     │  10  │  20  │      │      │      │
  └──────┴──────┴──────┴──────┴──────┘     └──────┴──────┴──────┴──────┴──────┘
                                  ▲                ▲
                                  │                │
                                 TOP = 3          TOP = 1 (popped 30)

 🧠 LOGIC — STEP BY STEP:

 Step 1: Define the stack as an array + top index.
   WHY: Array gives O(1) access by index. The top index tells us where
   the current top element is. top = -1 means empty stack.

 Step 2: PUSH — increment top, place element at array[top].
   WHY: We need to make room above the current top, then place the new
   element there. Always check if stack is full before pushing.

 Step 3: POP — read array[top], decrement top.
   WHY: We remove only the top element. Decrementing top "removes" it
   (the data stays in memory but is logically gone). Check if empty first.

 Step 4: PEEK — return array[top] without changing top.
   WHY: Sometimes we just need to see what is on top without removing it.

 Step 5: Display the stack by iterating from index 0 to top.
   WHY: Visual verification that our operations are correct.

 VISUAL WALKTHROUGH:

  Initial: top = -1 (empty)
  Index:  [0]  [1]  [2]  [3]  [4]
           _    _    _    _    _

  PUSH(10): top = 0
  Index:  [0]  [1]  [2]  [3]  [4]
          [10]  _    _    _    _
           ▲
           TOP

  PUSH(20): top = 1
  Index:  [0]  [1]  [2]  [3]  [4]
          [10] [20]  _    _    _
                ▲
                TOP

  PUSH(30): top = 2
  Index:  [0]  [1]  [2]  [3]  [4]
          [10] [20] [30]  _    _
                     ▲
                     TOP

  POP(): returns 30, top = 1
  Index:  [0]  [1]  [2]  [3]  [4]
          [10] [20] [30]  _    _
                ▲
                TOP

  POP(): returns 20, top = 0
  Index:  [0]  [1]  [2]  [3]  [4]
          [10] [20] [30]  _    _
           ▲
           TOP

  POP(): returns 10, top = -1 (empty again)
  Index:  [0]  [1]  [2]  [3]  [4]
           _    _    _    _    _

 DRY RUN:
  Line | Action              | top  | Stack State    | Output
  ─────┼─────────────────────┼──────┼────────────────┼─────────
   42  | push(10)            |  0   | [10]           |
   43  | push(20)            |  1   | [10, 20]       |
   44  | push(30)            |  2   | [10, 20, 30]   |
   45  | display()           |  2   | [10, 20, 30]   | 10 20 30
   48  | peek()              |  2   | [10, 20, 30]   | 30
   51  | pop()               |  1   | [10, 20]       | 30
   52  | pop()               |  0   | [10]           | 20
   53  | pop()               | -1   | []             | 10
   55  | isEmpty()?           | -1   | []             | true
   57  | pop() (underflow!)  | -1   | []             | Error!

 TIME COMPLEXITY CALCULATION:
 - PUSH: 1 assignment (array[top] = value) + 1 increment (top++) = O(1)
 - POP: 1 read (array[top]) + 1 decrement (top--) = O(1)
 - PEEK: 1 read (array[top]) = O(1)
 - isEmpty: 1 comparison (top == -1) = O(1)
 - Display: Loop from 0 to top = (top+1) iterations = n iterations = O(n)
 → Time Complexity = O(1) for push/pop/peek, O(n) for display

 SPACE COMPLEXITY CALCULATION:
 - Array of fixed size MAX = MAX integers stored
 - top variable = 1 integer extra
 → Space Complexity = O(MAX) where MAX is the capacity

 APPROACH COMPARISON:
 ┌─────────────────────┬──────────────────┬──────────────────────┐
 │ Property            │ Array-based      │ Linked List-based    │
 ├─────────────────────┼──────────────────┼──────────────────────┤
 │ PUSH                │ O(1)             │ O(1)                 │
 │ POP                 │ O(1)             │ O(1)                 │
 │ PEEK                │ O(1)             │ O(1)                 │
 │ Memory              │ Fixed size       │ Dynamic (per node)   │
 │ Overflow check      │ Needed (isFull)  │ Only if out of RAM   │
 │ Extra space         │ Wasted if unused │ Per-node pointer     │
 │ Cache performance   │ Better (array)   │ Worse (scattered)    │
 └─────────────────────┴──────────────────┴──────────────────────┘
═══════════════════════════════════════════════
*/

#include <iostream>
using namespace std;

const int MAX = 100;

struct Stack {
    int arr[MAX];
    int top;

    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        top++;
        arr[top] = value;
        cout << "Pushed: " << value << " (top = " << top << ")" << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return -1;
        }
        int value = arr[top];
        top--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Stack (LIFO) — Array-Based ===" << endl;
    cout << endl;

    Stack s;

    cout << "--- Pushing 3 values ---" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << endl;

    s.display();
    cout << endl;

    cout << "--- Peek top ---" << endl;
    cout << "Top element: " << s.peek() << endl;
    cout << endl;

    cout << "--- Popping all (LIFO order!) ---" << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << endl;

    cout << "--- Edge cases ---" << endl;
    cout << "isEmpty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Popping empty stack: " << s.pop() << endl;

    cout << "\n--- Push to overflow ---" << endl;
    for (int i = 0; i <= MAX; i++) {
        s.push(i);
    }

    cout << "\nAll operations done. Program ends." << endl;
    return 0;
}
