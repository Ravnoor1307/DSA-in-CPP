# 06_Merge_Intervals

## Real-world analogy summary

Intervals calendar meetings jaise hain. Timeline par bars overlap kar sakte hain. Sort by start/end ke baad overlap logic simple ho jata hai.

## Core overlap rule

```text
For sorted intervals:
if next.start <= current.end -> overlap
merged = [min(start), max(end)]
```

## Problem table

| Problem | Key trick | Time | Space |
|---|---|---:|---:|
| Merge intervals brute | compare pairs | O(n²) | O(n) |
| Merge intervals optimal | sort by start + scan | O(n log n) | O(n) |
| Insert interval | add before, merge middle, add after | O(n) | O(n) |
| Non-overlapping remove | sort by end greedy | O(n log n) | O(1) |
| Meeting rooms | sort by start, adjacent check | O(n log n) | O(1) |

## Common mistakes

1. Sort by wrong key.
2. Overlap condition `<=` vs `<` problem-specific samajhna.
3. Merge intervals me `max(end)` update bhoolna.
4. Insert interval me remaining intervals append na karna.
5. Non-overlap greedy me earliest end time proof ignore karna.

## Interview questions

1. Merge intervals sort by start kyun?
2. Insert interval three-phase logic explain karo.
3. Non-overlapping intervals me sort by end greedy kyun works?
4. Meeting rooms overlap check kaise hota hai?
