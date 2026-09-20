# 05_Infix_Postfix_Expressions — Conversion & Evaluation

## Summary
- Infix (a+b*c) needs precedence + parentheses; postfix (abc*+) needs neither — operand order IS evaluation order.
- Conversion (shunting-yard): operand→output; `(`→push; `)`→flush to `(`; operator→pop while stack-top prec ≥ current, then push.
- Evaluation: operand→push; operator→pop b then a, compute, push result (order matters for − and /).
- Both are single linear passes: O(n) time, O(n) stack space.

## What You Learn
- Why postfix removes parentheses and precedence entirely for a machine.
- The equal-precedence pop rule (left-associative: `a-b-c` must be `((a-b)-c)`).
- The `(` hard boundary in the operator stack.
- Operand order pitfall: pop b (top) first, then a, for a−b.

## Files
- `01_theory.cpp` — English doc block + shunting-yard (3 conversions) + eval (2 expressions), output matches expected.
- `task.cpp` — 5 tasks EASY→HARD: precedence, postfix validity, add-only eval, manual convert, full chain evaluate.

## Key Complexity Ideas
| Step | Time | Space | Why |
|---|---|---|---|
| convert infix→postfix | O(n) | O(n) stack+out | each char once, each op pushed/popped once |
| evaluate postfix | O(n) | O(n) operand stack | each token once |
| naive infix eval | O(n²)-ish | — | precedence look-ahead / re-scan |

## Must-Remember Patterns
```cpp
// precedence branch
if (c=='*'||c=='/') return 2; if (c=='+'||c=='-') return 1; return 0;
// operator rule in conversion
while (opStack.top() != '(' && prec(opStack.top()) >= prec(c))
    { out += opStack.top(); opStack.pop(); }
opStack.push(c);
// evaluation operand order
int b = st.top(); st.pop();
int a = st.top(); st.pop();
st.push(a op b);          // NOT b op a for '-' and '/'
```

## Completion Checklist
- [x] Real-world scenario (calculator engine, JVM stack machine)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (conversion + eval, both passes)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory