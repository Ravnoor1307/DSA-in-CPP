# 05_Stacks — Stacks for DSA

Complete stack module in C++. Every topic follows the strict notes format:
real-world scenario → English theory doc → step-by-step logic with WHY → ASCII visuals →
dry run → full complexity derivation → approach comparison. Inline code comments in
Hinglish, all code compile-ready.

## Folder Tree

```txt
05_Stacks/
├── 01_Stack_Intro/
│   ├── 01_theory.cpp       → LIFO concept, push/pop/peek, overflow/underflow, real-world uses
│   ├── task.cpp            → 5 tasks EASY→HARD with solutions
│   └── README.md
├── 02_Stack_Implementation/
│   ├── 01_theory.cpp       → array vs linked-list stack, two-stacks-one-array (opposite ends)
│   ├── task.cpp
│   └── README.md
├── 03_Stack_Class_STL/
│   ├── 01_theory.cpp       → custom class w/ dynamic growth + std::stack (container adapter)
│   ├── task.cpp
│   └── README.md
├── 04_Stack_Applications/
│   ├── 01_theory.cpp       → bracket matching, valid parens, reverse words, next-greater-element
│   ├── task.cpp
│   └── README.md
└── 05_Infix_Postfix_Expressions/
    ├── 01_theory.cpp       → shunting-yard conversion + postfix evaluation
    ├── task.cpp
    └── README.md
```

## Master comparison table

| Section | Main patterns | Key complexity ideas |
|---|---|---|
| 01_Intro | LIFO core ops, overflow/underflow guards | all ops O(1); array O(cap), list O(n) |
| 02_Impl | top-as-count, head-as-top, two-stacks share | array resize O(n) amort. O(1) |
| 03_Class/STL | dynamic grow, adapter over deque | push/pop/top O(1); pop() returns void |
| 04_Applications | expected-closer stack, monotonic NGE | valid-parens O(n); NGE stack O(n) vs O(n²) |
| 05_Infix/Postfix | operator stack + operand stack | conversion & eval both O(n) |

## Must-remember formulas / patterns

```cpp
// array stack (top = count of elements)
arr[top++] = v;                 // push  (guard top<cap)
v = arr[--top];                 // pop   (guard top>0)
v = arr[top-1];                 // peek (no removal)
// linked stack: HEAD = TOP
newNode->next = head; head = newNode;           // push
Node* t = head; head = head->next; delete t;    // pop
// two stacks, opposite ends, full check
if (top1 > top2) return false;  // no gap
arr[top1++] = v;                // stack 1
arr[top2--] = v;                // stack 2
// STL: pop() returns void — read top first
int v = st.top(); st.pop();
// valid parentheses: push expected closer
if (c=='(') st.push(')'); else if (c=='[') st.push(']'); else if (c=='{') st.push('}');
else { if (st.empty() || st.top()!=c) return false; st.pop(); }
return st.empty();
// NGE monotonic stack, scan right→left
while (!st.empty() && st.top() <= a[i]) st.pop();
res[i] = st.empty() ? -1 : st.top();  st.push(a[i]);
// infix→postfix: pop while prec(top) >= prec(c)
while (!st.empty() && st.top() != '(' && prec(st.top()) >= prec(c)) { out+=st.top(); st.pop(); }
st.push(c);
// postfix eval: pop b FIRST then a, push (a op b)
int b = st.top(); st.pop(); int a = st.top(); st.pop(); st.push(a op b);
// min-stack: store running min beside each element
mn[top] = (top==0 ? v : min(v, mn[top-1]));
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