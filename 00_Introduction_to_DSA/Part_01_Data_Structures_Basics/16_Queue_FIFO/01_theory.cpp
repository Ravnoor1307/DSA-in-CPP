/*
═══════════════════════════════════════════════
 QUEUE (FIFO) — INTRODUCTION
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of standing in a line at a movie ticket counter. The person who
 arrives first gets the ticket first and leaves first. A new person joins
 from the back of the line. This is FIFO — First In, First Out. Unlike
 a stack (where the last person served is the one who arrived last), a
 queue serves people in the exact order they arrived. Queues are used
 in printer job scheduling, BFS traversal, task scheduling in operating
 systems, and customer service systems.

 📖 THEORY:
 - A Queue is a linear data structure that follows FIFO (First In First Out).
 - ENQUEUE: Insert an element at the REAR (back) of the queue.
 - DEQUEUE: Remove the element from the FRONT of the queue.
 - PEEK/FRONT: View the front element without removing it.
 - isEmpty: Check if the queue has no elements.
 - isFull: Check if the queue has reached its capacity (array-based).
 - "front" tracks the index of the first element.
 - "rear" tracks the index of the last element.
 - We will implement a simple linear array-based queue here.

 ASCII DIAGRAM:

  Array-based Queue:
  
  Index:   0      1      2      3      4
        ┌──────┬──────┬──────┬──────┬──────┐
        │  10  │  20  │  30  │      │      │
        └──────┴──────┴──────┴──────┴──────┘
         ▲                   ▲
         │                   │
        FRONT              REAR

  ENQUEUE(40):                DEQUEUE():
  ┌──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┐
  │  10  │  20  │  30  │  40  │      │   │      │  20  │  30  │  40  │      │
  └──────┴──────┴──────┴──────┴──────┘   └──────┴──────┴──────┴──────┴──────┘
         ▲                          ▲              ▲                   ▲
         │                          │              │                   │
        FRONT                      REAR          FRONT               REAR
        (10 dequeued)

 🧠 LOGIC — STEP BY STEP:

 Step 1: Define the queue as an array + front and rear indices.
   WHY: Array gives O(1) access by index. Front tracks where elements
   start, rear tracks where the last element is. Both = -1 means empty.

 Step 2: ENQUEUE — increment rear, place element at array[rear].
   WHY: New elements always go to the back. We move rear forward and
   place the value there. Check if queue is full before enqueueing.

 Step 3: DEQUEUE — read array[front], increment front.
   WHY: We remove from the front. Moving front forward "removes" the
   element (logically gone, data stays in memory). Check if empty first.

 Step 4: PEEK — return array[front] without changing front or rear.
   WHY: Just see who is at the front of the line without removing them.

 Step 5: Display the queue from front to rear.
   WHY: Visual verification. Iterate from front index to rear index.

 VISUAL WALKTHROUGH:

  Initial: front = -1, rear = -1 (empty)
  Index:  [0]  [1]  [2]  [3]  [4]
           _    _    _    _    _

  ENQUEUE(10): front = 0, rear = 0
  Index:  [0]  [1]  [2]  [3]  [4]
          [10]  _    _    _    _
           ▲
           F, R

  ENQUEUE(20): front = 0, rear = 1
  Index:  [0]  [1]  [2]  [3]  [4]
          [10] [20]  _    _    _
           ▲    ▲
           F    R

  ENQUEUE(30): front = 0, rear = 2
  Index:  [0]  [1]  [2]  [3]  [4]
          [10] [20] [30]  _    _
           ▲         ▲
           F         R

  DEQUEUE(): returns 10, front = 1, rear = 2
  Index:  [0]  [1]  [2]  [3]  [4]
          [10] [20] [30]  _    _
                ▲    ▲
                F    R

  DEQUEUE(): returns 20, front = 2, rear = 2
  Index:  [0]  [1]  [2]  [3]  [4]
          [10] [20] [30]  _    _
                     ▲
                     F, R

  DEQUEUE(): returns 30, front = -1, rear = -1 (empty)
  Index:  [0]  [1]  [2]  [3]  [4]
           _    _    _    _    _

 DRY RUN:
  Line | Action              | front | rear | Output
  ─────┼─────────────────────┼───────┼──────┼──────────
   45  | enqueue(10)         |   0   |  0   |
   46  | enqueue(20)         |   0   |  1   |
   47  | enqueue(30)         |   0   |  2   |
   48  | display()           |   0   |  2   | 10 20 30
   51  | peek()              |   0   |  2   | 10
   54  | dequeue()           |   1   |  2   | 10
   55  | dequeue()           |   2   |  2   | 20
   56  | dequeue()           |  -1   | -1   | 30
   58  | isEmpty()?          |  -1   | -1   | true
   60  | dequeue() (empty!)  |  -1   | -1   | Error!

 TIME COMPLEXITY CALCULATION:
 - ENQUEUE: 1 increment (rear++) + 1 assignment = O(1)
 - DEQUEUE: 1 read + 1 increment (front++) = O(1)
 - PEEK: 1 read (array[front]) = O(1)
 - isEmpty: 1 comparison = O(1)
 - Display: Loop from front to rear = up to n elements = O(n)
 → Time Complexity = O(1) for enqueue/dequeue/peek, O(n) for display

 SPACE COMPLEXITY CALCULATION:
 - Array of fixed size MAX = MAX integers stored
 - front and rear variables = 2 integers extra
 → Space Complexity = O(MAX) where MAX is the capacity

 APPROACH COMPARISON:
 ┌─────────────────────┬──────────────────┬──────────────────────┐
 │ Property            │ Linear Queue     │ Circular Queue       │
 ├─────────────────────┼──────────────────┼──────────────────────┤
 │ ENQUEUE             │ O(1)             │ O(1)                 │
 │ DEQUEUE             │ O(1)             │ O(1)                 │
 │ Space utilization   │ Wastes front     │ Reuses front space   │
 │ Implementation      │ Simple           │ Slightly complex     │
 │ Overflow risk       │ Even with space  │ Only when truly full │
 └─────────────────────┴──────────────────┴──────────────────────┘

 ┌─────────────────────┬──────────────────┬──────────────────────┐
 │ Property            │ Stack (LIFO)     │ Queue (FIFO)         │
 ├─────────────────────┼──────────────────┼──────────────────────┤
 │ Insert              │ PUSH (top)       │ ENQUEUE (rear)       │
 │ Remove              │ POP (top)        │ DEQUEUE (front)      │
 │ Order               │ Last In First Out│ First In First Out   │
 │ Use case            │ Undo, recursion  │ Scheduling, BFS      │
 └─────────────────────┴──────────────────┴──────────────────────┘
═══════════════════════════════════════════════
*/

#include <iostream>
using namespace std;

const int MAX = 100;

struct Queue {
    int arr[MAX];
    int front;
    int rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value
             << " (front=" << front << ", rear=" << rear << ")" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek." << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i];
            if (i < rear) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Queue (FIFO) — Array-Based ===" << endl;
    cout << endl;

    Queue q;

    cout << "--- Enqueuing 3 values ---" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << endl;

    q.display();
    cout << endl;

    cout << "--- Peek front ---" << endl;
    cout << "Front element: " << q.peek() << endl;
    cout << endl;

    cout << "--- Dequeuing all (FIFO order!) ---" << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << endl;

    cout << "--- Edge cases ---" << endl;
    cout << "isEmpty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Dequeue empty queue: " << q.dequeue() << endl;

    cout << "\n--- Enqueue after full drain ---" << endl;
    q.enqueue(100);
    q.enqueue(200);
    q.display();
    cout << "Front: " << q.peek() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "\n--- Push to overflow ---" << endl;
    for (int i = 0; i <= MAX; i++) {
        q.enqueue(i);
    }

    cout << "\nAll operations done. Program ends." << endl;
    return 0;
}
