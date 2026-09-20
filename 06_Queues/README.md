# 06_Queues — Queues for DSA

Complete queue module in C++. Every topic follows the strict notes format:
real-world scenario → English theory doc → step-by-step logic with WHY → ASCII visuals →
dry run → full complexity derivation → approach comparison. Inline code comments in
Hinglish, all code compile-ready.

## Folder Tree

```txt
06_Queues/
├── 01_Queue_Intro/
│   ├── 01_theory.cpp       → FIFO concept, front/rear ops, stack-vs-queue, real-world uses
│   ├── task.cpp            → 5 tasks EASY→HARD with solutions
│   └── README.md
├── 02_Queue_Implementation_Array/
│   ├── 01_theory.cpp       → naive array (wasted space), circular queue, full conditions, count formula
│   ├── task.cpp
│   └── README.md
├── 03_Queue_Implementation_LL/
│   ├── 01_theory.cpp       → head=front, tail=rear, enq/deq O(1), dangling-tail reset
│   ├── task.cpp
│   └── README.md
├── 04_Queue_Variations/
│   ├── 01_theory.cpp       → circular deque, priority queue (heap vs arrays), STL queue/deque/priority_queue
│   ├── task.cpp
│   └── README.md
└── 05_Queue_Applications/
    ├── 01_theory.cpp       → stack-from-two-queues, generate binary 1..n, first non-repeating char
    ├── task.cpp
    └── README.md
```

## Master comparison table

| Section | Main patterns | Key complexity ideas |
|---|---|---|
| 01_Intro | FIFO ends, enq/deq/front | all core ops O(1) |
| 02_Array | naive drift, circular wrap, full check | O(1) ops; `(rear+1)%cap==front` |
| 03_LL | head/tail pointers, tail reset | O(1) without scanning |
| 04_Variations | deque ends, heap bubble, STL adapters | deque O(1); PQ O(log n) |
| 05_Applications | drain-swap, BFS strings, freq+queue | stack-pop O(n); stream O(n) amort. |

## Must-remember formulas / patterns

```cpp
// circular queue
if ((r + 1) % cap == f) return;      // full  (one slot sacrificed)
a[r] = v;  r = (r + 1) % cap;        // enqueue
v = a[f];  f = (f + 1) % cap;        // dequeue
(r - f + cap) % cap;                 // count on the ring
// linked queue
if (!tail) { head = tail = n; } else { tail->next = n; tail = n; }   // enq
Node* old = head; head = head->next; if (!head) tail = nullptr;      // deq
// deque circular moves
push_front: f = (f - 1 + cap) % cap;  a[f] = v;
pop_back:   b = (b - 1 + cap) % cap;  v = a[b];
// heap-as-array
children 2i+1, 2i+2 ; parent (i-1)/2 · push=bubble up, pop=bubble down
// min-heap STL
priority_queue<int, vector<int>, greater<int>> pq;
// first non-repeating char
if (freq[c]==1) q.push(c); while (!q.empty() && freq[q.front()]>1) q.pop();
// stack-from-two-queues (pop): drain all-but-last then swap
while (live.size()>1) { buf.push(live.front()); live.pop(); }
swap(live, buf);
```

## Completion checklist

- Real-world scenario in every `01_theory.cpp`
- English doc blocks (theory/logic/scenario) + Hinglish inline code comments
- ASCII visual walkthroughs everywhere
- Dry run states included
- Complexity always derived step-by-step before stating Big-O (no bare `O(?)`)
- Compile-ready C++ (`g++ -std=c++17 -Wall`), edge cases handled
- `01_theory.cpp` contains no tasks; tasks live only in `task.cpp`
- `README.md` + `task.cpp` present in every section