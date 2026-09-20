# 04_Linked_List — Linked Lists for DSA

Complete linked-list module in C++. Every topic follows the strict notes format:
real-world scenario → English theory doc → step-by-step logic with WHY → ASCII visuals →
dry run → full complexity derivation → approach comparison. Inline code comments in
Hinglish, all code compile-ready.

## Folder Tree

```txt
04_Linked_List/
├── 01_Linked_List_Intro/
│   ├── 01_theory.cpp       → why LL, self-referential node, heap creation, memory layout vs array
│   ├── task.cpp            → 5-6 tasks EASY→HARD with solutions
│   └── README.md
├── 02_Singly_Linked_List_Basics/
│   ├── 01_theory.cpp       → traverse, insert head/tail/position, delete, search
│   ├── task.cpp
│   └── README.md
├── 03_SLL_Class_Implementation/
│   ├── 01_theory.cpp       → wrapper class, destructor, length, nth-from-end (length vs 2-pointer)
│   ├── task.cpp
│   └── README.md
├── 04_SLL_Classic_Problems/
│   ├── 01_theory.cpp       → reverse (iter+rec), middle, floyd cycle/start/remove, palindrome
│   ├── task.cpp
│   └── README.md
├── 05_Doubly_Linked_List/
│   ├── 01_theory.cpp       → prev pointer, insert/delete O(1) on known node, both-direction walk
│   ├── task.cpp
│   └── README.md
└── 06_Circular_Linked_List/
    ├── 01_theory.cpp       → ring structure, do-while lap, insert/delete keeping wrap, Josephus
    ├── task.cpp
    └── README.md
```

## Master comparison table

| Section | Main patterns | Key complexity ideas |
|---|---|---|
| 01_Intro | self-referential node, heap creation | node create O(1), full pass O(n) |
| 02_SLL Basics | traverse, insert head/tail/pos, delete, search | front O(1), walks O(n) |
| 03_SLL Class | destructor, size, nth-from-end | class ops O(1)/O(n), 2-ptr O(n) |
| 04_Classic Problems | reverse, middle, floyd, palindrome | O(n) time; O(1)/O(n) space variants |
| 05_Doubly | prev pointer, insert/delete known node | known-node ops O(1) |
| 06_Circular | ring wrap, do-while lap, Josephus | tail-ptr front ops O(1), walks O(n) |

## Must-remember formulas / lines

```cpp
struct Node { int data; Node* next; };          // self-referential
// traversal
while (t) { /* use t->data */ t = t->next; }
// insert head
newNode->next = head;  head = newNode;
// insert after prev: ORDER MATTERS
newNode->next = prev->next;  prev->next = newNode;
// delete after prev: save target first
Node* target = prev->next;  prev->next = target->next;  delete target;
// reverse (iterative)
Node *prev=null,*curr=head;
while (curr) { Node *nxt=curr->next; curr->next=prev; prev=curr; curr=nxt; }
head = prev;
// middle & floyd
while (fast && fast->next) { slow=slow->next; fast=fast->next->next; }
// DLL insert after p
n->prev=p; n->next=p->next; if (p->next) p->next->prev=n; p->next=n;
// circular lap traversal (do-while!)
do { /* use t */ t=t->next; } while (t != head);
// circular insert head with tail ptr
n->next=head; tail->next=n; head=n;
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