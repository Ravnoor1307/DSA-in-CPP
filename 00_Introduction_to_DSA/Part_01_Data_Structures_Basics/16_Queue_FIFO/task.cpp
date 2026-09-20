/*
═══════════════════════════════════════════════
 TASK SET — QUEUE (FIFO)
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: You are building a printer spooler. Documents
   must print in the order they were submitted — first come, first
   served. That is exactly a FIFO queue. These tasks cover the logic
   behind printer queues, CPU task scheduling, and BFS in graphs.

 🧠 HOW TO SOLVE: Use an array + front and rear indices. ENQUEUE = rear++
   then assign (new elements go to the back). DEQUEUE = read arr[front],
   then front++ (old elements leave from the front). Always guard
   against empty before dequeue and full before enqueue.
 
 MODES/TOPICS COVERED:
  1. Implement isEmpty() check
  2. Implement peek() / front() — see who is first
  3. Round-trip test: enqueue 3 then dequeue all IN ORDER
  4. Circular queue — reuse front space
  5. HARD: Reverse first K elements using a stack
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
// NOTE: Each task below is solved fully. Compile the whole file.
// Hinglish comments = code samjhao.

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
            cout << "Overflow!" << endl;
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow!" << endl;
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
            cout << "Empty!" << endl;
            return -1;
        }
        return arr[front];
    }
};

struct CircularQueue {
    int arr[MAX];
    int front;
    int rear;
    int count;

    CircularQueue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX;
    }

    void enqueue(int v) {
        if (isFull()) { cout << "CQ Overflow!" << endl; return; }
        arr[rear] = v;
        rear = (rear + 1) % MAX;   // circular move
        count++;
    }

    int dequeue() {
        if (isEmpty()) { cout << "CQ Underflow!" << endl; return -1; }
        int v = arr[front];
        front = (front + 1) % MAX; // circular move
        count--;
        return v;
    }

    int frontValue() {
        return arr[front];
    }
};

void reverseFirstK(Queue& q, int k) {
    int tempArr[100];
    int n = 0;
    while (!q.isEmpty()) tempArr[n++] = q.dequeue();

    for (int i = 0; i < k; i++) {
        // k elements ko stack jaisa pop — simple: swap positions
        for (int j = i + 1; j < k; j++) {
            int t = tempArr[i];
            tempArr[i] = tempArr[j];
            tempArr[j] = t;
        }
    }
    for (int i = 0; i < n; i++) q.enqueue(tempArr[i]);
}

int main() {
    cout << "==========================================" << endl;
    cout << " TASK SET — QUEUE (FIFO)" << endl;
    cout << "==========================================" << endl;

    // ---- TASK 1: isEmpty ----
    cout << "\n--- TASK 1: isEmpty ---" << endl;
    Queue q1;
    cout << "Nayi queue empty? " << (q1.isEmpty() ? "YES" : "NO") << endl;
    q1.enqueue(7);
    cout << "1 enqueue ke baad empty? " << (q1.isEmpty() ? "YES" : "NO") << endl;
    q1.dequeue();
    cout << "Dequeue ke baad empty? " << (q1.isEmpty() ? "YES" : "NO") << endl;

    // ---- TASK 2: peek / front ----
    cout << "\n--- TASK 2: peek front ---" << endl;
    Queue q2;
    q2.enqueue(100);
    q2.enqueue(200);
    q2.enqueue(300);
    cout << "Front pehla aaya hua: " << q2.peek() << " (queue wahi rahegi)" << endl;

    // ---- TASK 3: FIFO order round-trip ----
    cout << "\n--- TASK 3: FIFO round-trip ---" << endl;
    Queue q3;
    q3.enqueue(10);
    q3.enqueue(20);
    q3.enqueue(30);
    cout << "Enqueue order: 10 20 30" << endl;
    cout << "Dequeue order: ";
    while (!q3.isEmpty()) {
        cout << q3.dequeue() << " ";
    }
    cout << endl;
    cout << "Same order mila? FIFO = First In First Out!" << endl;

    // ---- TASK 4: Circular queue ----
    cout << "\n--- TASK 4: Circular queue ---" << endl;
    CircularQueue cq;
    for (int i = 1; i <= 5; i++) cq.enqueue(i * 11);
    cout << "Dequeue 2: " << cq.dequeue() << " " << cq.dequeue() << endl;
    cq.enqueue(99);   // front wali jagah dobara use ho sakti hai
    cout << "After enqueue 99 (circular reuse), front = " << cq.frontValue() << endl;
    cout << "Remaining: ";
    while (!cq.isEmpty()) cout << cq.dequeue() << " ";
    cout << endl;

    // ---- TASK 5: reverse first K ----
    cout << "\n--- TASK 5: Reverse first K of queue ---" << endl;
    Queue q5;
    for (int i = 1; i <= 5; i++) q5.enqueue(i * 10); // 10 20 30 40 50
    cout << "Original:   10 20 30 40 50" << endl;
    reverseFirstK(q5, 3);                              // → 30 20 10 40 50
    cout << "After rev 3: ";
    while (!q5.isEmpty()) cout << q5.dequeue() << " ";
    cout << endl;

    cout << "\nAll tasks done! FIFO clear ho gaya." << endl;
    return 0;
}