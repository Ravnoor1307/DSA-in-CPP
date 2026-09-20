# 18. Structures — Custom Data Types

> **Ek line me:** `struct Node { int data; Node* next; };` — ye **ek line** Linked List, Tree aur Graph ka darwaza khol deti hai. Struct = apni khud ki bana hua data type jo related cheezon ko ek FORM me baandhta hai.

A struct bundles related variables (members) under one type. It's your own custom data type. Use dot `.` on an object, arrow `->` on a pointer to a struct. `sizeof(struct)` may exceed member-sum because of PADDING. struct vs class differ only in default access (public vs private).

- **Real-world analogy:** A passport application form: one form has many fields (name, DOB, passport no, address). One person = one form (struct). The passport office stores many forms in order = array of structs. To update a person's phone you go straight to their specific form = pointer + arrow operator.
- **Files in this folder:**
  - `01_theory.cpp` — struct basics, array of structs, pointer + arrow, by-value vs by-pointer function params, nested struct, memory layout with padding example, empty-struct edge case (size 1).
  - `task.cpp` — 6 tasks EASY→HARD (basic Employee, print all, average salary, by-value vs by-pointer, highest salary, nested Date + selection sort) with full solutions.
  - `README.md` — this cheat sheet.
- **Cheat sheet / syntax:**

| Situation | Code |
|---|---|
| Define | `struct Student { int id; char name[20]; float marks; };` (semicolon!) |
| Create object | `Student s; s.id = 1;` |
| Array | `Student cls[3];  cls[0].marks = 85;` |
| Pointer | `Student* p = &cls[1];  p->marks = 95;` |
| Arrow == deref | `p->id` is same as `(*p).id` |
| Nested | `struct Date{...}; struct Emp{ Date join; };` → `e.join.d` |
| vs class | struct: PUBLIC by default · class: PRIVATE by default |

Memory layout (no padding):
```
struct Student { int id; char name[20]; float marks; };
offset:     0       4               24
         ┌───────┬──────────────────────┬─────────┐
         │ id 4B │ name 20B             │ marks 4B│
         └───────┴──────────────────────┴─────────┘
sizeof = 28 byte. class[0]@0x1000, class[1]@0x101C (28 apart).
```
Padding example: `struct Bad { char a; int b; char c; double d; };` = **24 bytes** (not 14!). Reorder → `struct Good { double d; int b; char a; char c; };` = **16 bytes**. Field order matters.

- **Complexity:**

```
TIME : s.id / p->id        -> O(1)   (compile-time offset — single add)
       traverse n structs  -> n × O(1) = O(n)
       copy 1 struct       -> O(sizeof(struct))   (by-value is expensive!)
       const& bhejna       -> O(1)
SPACE: array of n structs  -> n × sizeof(struct) = O(n)
DERIVATION : stamping field ka OFFSET compiler ko pehle se pata hai (offsetof)
             s.marks = "s ka pata + fix kadam" -> ek jod -> O(1)
```

- ⚠️ **Common mistakes:**
  1. `struct Node { ... }` — closing semicolon `;` bhoolna → compile error.
  2. `Node next;` inside Node — incomplete type error. Use `Node* next;` (pointer is 8 bytes, isliye size pata hai).
  3. Dot vs arrow: `s->id` on a plain object, `p.id` on a pointer — ulta karo to error.
  4. `sizeof` ko fields ka jod samajhna — **padding** extra bytes daalti hai.
  5. Bada struct by-value bhejna → unnecessary O(size) copy. Use `const Struct&`.
  6. Nested members: `e.joining.d` — DO dot chahiye, ek nahi.
  7. Constructor ke bina freshly made struct ka field padhna → garbage/UB (use `{}`).
- **Interview Q&A:**
  - *Q: struct vs class?* — A: Only default access differs. struct → public, class → private. Everything else (constructor, inheritance) is identical.
  - *Q: Why is `sizeof` bigger than the sum of fields?* — A: PADDING — CPU likes aligned access. Reorder fields big→small to shrink the struct.
  - *Q: Why can `struct Node { Node* next; }` exist but not `struct Node { Node next; }`?* — A: Pointer size is always known (8 bytes). `Node next` would need Node's own size = infinitely recursive.
  - *Q: Dot or arrow?* — A: Real object → `.`. Pointer → `->`. `p->x` == `(*p).x`.
  - *Q: What's the empty struct size?* — A: In C++, at least **1 byte** (C standard allows 0; C++ needs distinct objects to have distinct addresses).