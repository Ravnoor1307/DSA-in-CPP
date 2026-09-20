# Stack (LIFO) — Introduction

A **stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle — only the most recently added element can be removed. All operations happen at one end called the **top**.

- **PUSH**: add an element on top.
- **POP**: remove the top element.
- **PEEK**: view the top without removing it.
- **isEmpty / isFull**: guard operations against underflow/overflow.
- `top` index tracks the current top; `top = -1` means the stack is empty.

**Real-world analogy:** a stack of plates in a cafeteria — you put a plate on top and take the top one off; the last plate placed is the first one removed.

---

## Files in this folder

| File                | Purpose                                                                           |
|---------------------|-----------------------------------------------------------------------------------|
| `01_theory.cpp`     | Pure concept + demo: array-based stack, push 3, pop shows reverse (LIFO) order.   |
| `task.cpp`          | 5 solved tasks: isEmpty/isFull, peek, reverse a string, balanced brackets, two stacks in one array. |
| `README.md`         | This summary + syntax + complexity + mistakes + interview Q&A.                    |

---

## Cheat sheet / syntax

```cpp
const int MAX = 100;

struct Stack {
    int arr[MAX];
    int top;
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(int v) {
        if (isFull()) { cout << "Overflow!" << endl; return; }
        arr[++top] = v;
    }

    int pop() {
        if (isEmpty()) { cout << "Underflow!" << endl; return -1; }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) { cout << "Empty!" << endl; return -1; }
        return arr[top];
    }
};
```

---

## Complexity analysis

| Operation | Time    | Explanation                                            |
|-----------|---------|--------------------------------------------------------|
| PUSH      | O(1)    | `top++` + one array assignment (2 constant ops)        |
| POP       | O(1)    | one read + `top--` (2 constant ops)                    |
| PEEK      | O(1)    | one array read                                         |
| isEmpty   | O(1)    | one comparison                                         |
| Display   | O(n)    | loop from top down to 0 = n iterations × O(1) each     |

**Space**: fixed array of `MAX` slots + `top` variable → **O(MAX)** (or O(n) for n elements used).

---

## ⚠️ Common mistakes

- Popping an empty stack → use `isEmpty()` guard first.
- Pushing into a full stack → use `isFull()` guard first.
- Using the array itself (index 0) as "top" and not tracking the top index properly.
- Forgetting to decrement top on pop or increment on push.
- Mixing LIFO thinking into queue problems (push to rear, pop from front).

---

## Interview Q&A

1. **What does LIFO mean?** — Last In, First Out: the element added most recently is removed first.
2. **Where are stacks used in real systems?** — Undo/redo in editors, browser back button, function call stack (recursion), expression evaluation, bracket matching.
3. **How do you reverse a string with a stack?** — Push every character, then pop all — the last char comes out first, producing the reversed string (O(n)).
4. **What is stack overflow / underflow?** — Overflow = push on a full stack; underflow = pop on an empty stack. Both must be guarded.
5. **Array vs linked-list stack: which is better?** — Array: cache-friendly, fixed size; Linked list: dynamic, no overflow, but per-node pointer overhead. Operations are O(1) in both.
6. **How do you check balanced brackets with a stack?** — Push open brackets; on a close bracket, pop and verify matching type; at the end the stack must be empty.