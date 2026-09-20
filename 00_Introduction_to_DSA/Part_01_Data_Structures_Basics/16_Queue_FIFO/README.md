# Queue (FIFO) — Introduction

A **queue** is a linear data structure that follows the **FIFO** (First In, First Out) principle — the element that arrives first is served first. Elements are added at the **rear** and removed from the **front**.

- **ENQUEUE**: add an element at the rear.
- **DEQUEUE**: remove the element from the front.
- **PEEK / FRONT**: view the front element without removing it.
- **isEmpty / isFull**: guard operations against underflow/overflow.
- `front` and `rear` indices track the ends; both `-1` means the queue is empty.

**Real-world analogy:** a line at a ticket counter — the first person to arrive gets served first, new joiners stand at the back.

---

## Files in this folder

| File                | Purpose                                                                               |
|---------------------|---------------------------------------------------------------------------------------|
| `01_theory.cpp`     | Pure concept + demo: array-based queue, enqueue 3, dequeue shows FIFO order.          |
| `task.cpp`          | 5 solved tasks: isEmpty, peek, FIFO round-trip, circular queue, reverse first K.      |
| `README.md`         | This summary + syntax + complexity + mistakes + interview Q&A.                        |

---

## Cheat sheet / syntax

```cpp
const int MAX = 100;

struct Queue {
    int arr[MAX];
    int front, rear;

    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull()  { return rear == MAX - 1; }

    void enqueue(int v) {
        if (isFull()) { cout << "Overflow!" << endl; return; }
        if (isEmpty()) front = 0;
        arr[++rear] = v;
    }

    int dequeue() {
        if (isEmpty()) { cout << "Underflow!" << endl; return -1; }
        int v = arr[front];
        if (front == rear) front = rear = -1;   // last element gaya
        else front++;
        return v;
    }

    int peek() {
        if (isEmpty()) { cout << "Empty!" << endl; return -1; }
        return arr[front];
    }
};
```

---

## Complexity analysis

| Operation | Time    | Explanation                                             |
|-----------|---------|---------------------------------------------------------|
| ENQUEUE   | O(1)    | `rear++` + one array assignment (2 constant ops)        |
| DEQUEUE   | O(1)    | one read + `front++` (2 constant ops)                   |
| PEEK      | O(1)    | one array read                                          |
| isEmpty   | O(1)    | one comparison                                          |
| Display   | O(n)    | loop from front to rear = n iterations × O(1) each      |

**Space**: fixed array of `MAX` slots + 2 indices → **O(MAX)** (or O(n) for n elements used).

---

## ⚠️ Common mistakes

- Linear queue **wastes front space** — after dequeues, "isFull" reports full even with empty slots. Fix: circular queue using `(rear + 1) % MAX`.
- Dequeueing an empty queue without checking → undefined behavior.
- Forgetting to reset both `front` and `rear = -1` when the last element is dequeued.
- Confusing front/rear: enqueue AT rear, dequeue FROM front (never mix).
- Using stack logic (push/pop same end) on queue problems.

---

## Interview Q&A

1. **What does FIFO mean?** — First In, First Out: the earliest-arrived element is removed first.
2. **Queue vs Stack?** — Queue removes from the front (FIFO); stack removes from the top (LIFO). Same O(1) ops, opposite ordering.
3. **What is a circular queue and why?** — It reuses the front space by wrapping indices with modulo, avoiding false "full" conditions in a linear array queue.
4. **Where are queues used?** — Printer spooling, CPU/OS task scheduling, BFS in graphs, call-center/customer queues, keyboard buffers.
5. **How do you get the front element without removing it?** — `peek()`/`front()` reads `arr[front]` in O(1) without touching indices.
6. **Can a queue be implemented with two stacks?** — Yes, enqueue O(1) into one stack; on first dequeue transfer everything to the second stack, then pop — amortized O(1) dequeue.