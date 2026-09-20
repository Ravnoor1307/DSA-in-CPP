# Creating a Node (Singly Linked List)

A linked list is a linear data structure where each element (called a **node**) holds a value and a pointer to the next node. Unlike arrays, nodes are not stored in contiguous memory — they are scattered and connected only through pointers, making insertions/deletions inexpensive without shifting.

- **Node anatomy**: each node has `data` (the value) and `next` (pointer to the next node).
- **Head pointer**: points to the first node; `head = nullptr` means an empty list.
- **Termination**: the last node's `next` is `nullptr` (marks the end of the chain).
- **`createNode()`**: helper function that allocates a node with `new`, sets data, and initializes `next = nullptr`.
- **Linking**: `node1->next = node2; node2->next = node3;` builds the chain.

**Real-world analogy:** Each clue in a treasure hunt tells you where the next clue is — you follow the chain from the first clue to the last, exactly like following `next` pointers from `head` to `NULL`.

---

## Files in this folder

| File                | Purpose                                                                  |
|---------------------|--------------------------------------------------------------------------|
| `01_theory.cpp`     | Pure concept + working demo: creates 3 nodes, links them, prints list.   |
| `task.cpp`          | 8 solved tasks (EASY→HARD): single node, linking, length, insert, search, delete, reverse. |
| `README.md`         | This summary + cheat sheet + mistakes + interview Q&A.                   |

---

## Cheat sheet / syntax

```cpp
struct Node {
    int data;
    Node* next;          // pointer to next node (self-referential struct)
};

Node* createNode(int value) {
    Node* n = new Node;  // allocate on heap
    n->data = value;
    n->next = nullptr;   // agar last node hoga to NULL
    return n;
}

// Link manually
node1->next = node2;
node2->next = node3;
node3->next = nullptr;

// Traverse
Node* temp = head;
while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
}
```

---

## Complexity comparison

| Operation           | Linked List | Array       |
|---------------------|-------------|-------------|
| Create one node     | O(1)        | —           |
| Access by index     | O(n)        | O(1)        |
| Insert at front     | O(1)        | O(n)        |
| Insert at end       | O(n)*       | O(1) amortized |
| Traverse entire list| O(n)        | O(n)        |
| Space per element   | data + ptr  | data only   |

*O(n) without tail pointer loop; with a tail pointer it becomes O(1). Loop over n nodes = **n × O(1) = O(n)**.

---

## ⚠️ Common mistakes

- Forgetting to set the last node's `next = nullptr` → traversal runs forever.
- Using a pointer `Node* head;` (uninitialized) instead of `Node* head = nullptr;`.
- Allocating with `new` but never calling `delete` → **memory leak**.
- Trying to access `temp->data` when `temp` is `nullptr` → segfault.
- Losing the head pointer when inserting at front (must update `head`).

---

## Interview Q&A

1. **Why is a singly linked list called "singly"?** — Each node points in only one direction (to its `next`), so traversal is forward-only.
2. **What happens if the last node's next is not NULL?** — Printing/traversing never terminates (infinite loop) or crashes.
3. **How do you insert a node at the front in O(1)?** — Create node, `newNode->next = head`, then update `head = newNode`.
4. **Why is linked-list insertion faster than array insertion at the front?** — No shifting needed; only pointer updates in O(1), array needs O(n) shifts.
5. **How you free a whole linked list?** — Save `next`, delete current, move to next; repeat until NULL. Trying `delete head` in a loop while using `head = head->next` reads freed memory.
6. **What is a self-referential structure?** — A struct whose member is a pointer to its own type, e.g. `Node* next;` inside `struct Node`.