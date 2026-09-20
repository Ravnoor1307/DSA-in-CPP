# 02_Heap_Operations

## Real-world analogy summary

Hospital triage desk heap operations jaisa kaam karta hai:

- New patient arrives: add at end, priority ke according bubble-up.
- Most critical patient treated: remove root, last patient root pe, then sink-down.
- Just check next patient: peek root.

## Operation comparison table

| Operation | Visual action | Calculation | Time | Extra space |
|---|---|---:|---:|---:|
| Insert / heapify-up | last me add, parent se swap | height `h = log₂n` | O(log n) | O(1) |
| Delete root / heapify-down | root remove, last root, child se swap | height `h = log₂n` | O(log n) | O(1) |
| Peek | `arr[0]` read | 1 access | O(1) | O(1) |
| Build by n inserts | each insert log n | n log n | O(n log n) | O(n) |
| Build by heapify all | bottom-up repair | n/4*1+n/8*2+... | O(n) | O(1) extra |

## Key formulas

```text
parent(i) = (i-1)/2
left(i)   = 2*i+1
right(i)  = 2*i+2
```

## O(n) build heap proof

```text
Leaves: about n/2 nodes, work 0
Height 1: about n/4 nodes, work 1
Height 2: about n/8 nodes, work 2
Height 3: about n/16 nodes, work 3

Total = n/4*1 + n/8*2 + n/16*3 + ...
      = n * constant
      = O(n)
```

## Common mistakes

1. Insert ke baad heapify-up bhoolna.
2. Delete root ke baad last element root pe na lana.
3. Heapify-down me larger child choose na karna for max heap.
4. Build heap bottom-up me leaves se start karna unnecessary hai; last non-leaf `n/2-1` se start karo.
5. Build heap by heapify-all ko galti se O(n log n) bolna.

## Interview questions

1. Heap insert ka dry run karo.
2. Extract max ka dry run karo.
3. Peek O(1) kyun hota hai?
4. Build heap by n inserts O(n log n) kyun?
5. Bottom-up build heap O(n) proof do.
6. Complete MaxHeap class implement karo.
