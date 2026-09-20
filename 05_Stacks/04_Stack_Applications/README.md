# 04_Stack_Applications — Bracket Matching, Reverse Words, Next Greater Element

## Summary
- Single-type matching ＝ depth counter; multi-type valid-parens needs a real stack of expected closers.
- Edge cases that break naive code: close with empty stack, wrong nesting `([)]`, leftover unclosed openers.
- Reverse words: push words, pop → order flips (LIFO gives reversal for free).
- NGE brute force is O(n·n); monotonic decreasing stack scan right→left is O(n) — each element pushed/popped once.

## What You Learn
- Pushing the *expected closer* (`(`→`)`) makes the pop check an equality, not a switch.
- Why leftover stack at end means unbalanced.
- Store-indices-vs-values trade-off in the monotonic stack pattern.
- Counting min removals = unmatched closes + leftover openers (single pass).

## Files
- `01_theory.cpp` — English doc block + demos: single-type balanced, multi-type valid, word revervsal, NGE — all output verified against expected.
- `task.cpp` — 6 tasks EASY→HARD: balanced, pair count, multi-type valid, reverse string, NGE-by-index, min-removals.

## Key Complexity Ideas
| Problem | Time | Aux space | Trick |
|---|---|---|---|
| single-type balanced | O(n) | O(1) | depth counter |
| valid parens (multi) | O(n) | O(n) | expected-closer stack |
| reverse string | O(n) | O(n) | char stack |
| reverse words | O(n) | O(n) | word stack |
| NGE stack | O(n) | O(n) | monotonic decreasing |
| NGE brute force | O(n·n) | O(1) | baseline to beat |

## Must-Remember Patterns
```cpp
// single type, O(1) space
if (c=='(') d++; else if (--d < 0) return false;  return d==0;
// multi-type: push the expected closer
if (c=='(') s.push(')'); else if (c=='[') s.push(']'); else if (c=='{') s.push('}');
else { if (s.empty() || s.top()!=c) return false; s.pop(); }
return s.empty();
// NGE (monotonic), values
for (i = n-1 → 0) { while (st.top()<=a[i]) st.pop(); res[i]=st.top(); st.push(a[i]); }
```

## Completion Checklist
- [x] Real-world scenario (editor lint, JSON/HTML validation)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (each pattern traced)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory