# TYPES OF DATA STRUCTURE

- Data structures split into **Primitive** (built into the language: int, char, float, double, bool, void) and **Non-Primitive** (built by combining primitives).
- Non-primitive further split into **Linear** (one-to-one sequential: array, linked list, stack, queue) and **Non-Linear** (branching: tree, graph).
- Linear does NOT mean contiguous memory — a linked list is scattered chunks joined by pointers, but logically still a straight line.
- Stack is **LIFO** (Last In, First Out); Queue is **FIFO** (First In, First Out); a BST's in-order traversal prints sorted data because of its left-smaller/right-larger rule.
- Pick by shape of the problem: undo → stack, ticket counter → queue, folder structure → tree, road network → graph.

**Real-world analogy:** A stack of plates in a kitchen (you take the top one — LIFO), a classroom line for a water fountain (first one to arrive drinks first — FIFO), a library index card system (hierarchy — tree), and the metro map (interconnected lines — graph). All are data organizations with different shapes.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Types: primitive + linear (array, linked list) + non-linear (binary tree) all demonstrated in one compiling program, plus classification diagram. |
| `task.cpp` | 6 problems (EASY → HARD): reverse traversal, linked list build, 3-node tree, stack (LIFO), queue (FIFO), BST insert + in-order. Full solutions inside. |
| `README.md` | Summary, classification, complexity table, mistakes and interview Q&A. |

## Concept cheat sheet

```cpp
// LINEAR — linked list node          // NON-LINEAR — tree node
struct LL { int data; LL* next; };    struct TN { int data; TN* left; TN* right; };

// Stack (LIFO) push/pop              // Queue (FIFO) enqueue/dequeue
stk[++top] = v;   // push              q[++rear] = v;   // enqueue
top--;            // pop               front++;         // dequeue

// BST insert + in-order print
void insert(Node*& r, int v) {
    if (!r) { r = new Node{v, nullptr, nullptr}; return; }
    if (v < r->data) insert(r->left, v);
    else             insert(r->right, v);
}
void inorder(Node* r) {
    if (!r) return;
    inorder(r->left); cout << r->data << " "; inorder(r->right);
}
```

## Complexity comparison

| Operation | Steps performed | Complexity |
|-----------|-----------------|------------|
| Array forward/reverse print | 2 loops × n visits → 2n steps | O(n) |
| Linked list traversal | n nodes, 1 pointer hop each → n steps | O(n) |
| Stack push / pop | index inc/dec + assignment → 1 step | O(1) |
| Queue enqueue / dequeue | index inc + assignment → 1 step | O(1) |
| BST insert (balanced h) | walk from root to leaf → h steps | O(log n) |
| BST insert (skewed, height n) | walk entire chain → n steps | O(n) |
| BST in-order traversal | every node visited once → n steps | O(n) |
| Space for n linked/tree nodes | n nodes × (data + pointers) → n units | O(n) |

## ⚠️ Common mistakes

- Confusing "linear" with "contiguous memory" — a linked list is linear in logic but scattered in RAM.
- Reading stack confusion: pushing increments `++top` but popping from a queue means `front++`, mixing these destroys FIFO/LIFO rules.
- Forgetting base case `if (r == nullptr) return;` in recursive tree functions — infinite recursion / crash.
- Not checking `top == -1` before pop or `front > rear` before dequeue → reading garbage.
- Building a BST but comparing the wrong direction (larger values to left) — in-order then gives descending or wrong order.
- Leaking memory: `new Node` without cleanup in real code.

## Interview Q&A

- **Q: How are data structures classified?** A: Primitive (built-in types) vs non-primitive; non-primitive are linear (array, linked list, stack, queue) or non-linear (tree, graph).
- **Q: Difference between stack and queue?** A: Stack is LIFO (top changes), queue is FIFO (front/rear both move).
- **Q: Is a linked list linear even though memory is scattered?** A: Yes — linearity is about logical ordering via pointers, not physical adjacency.
- **Q: Why does in-order traversal of a BST print sorted output?** A: BST rule puts smaller values on the left, so left-root-right visits ascending order.
- **Q: When to use array vs linked list?** A: Array for fast indexed access (O(1)) and fixed size; linked list for frequent insert/delete with no shifting.