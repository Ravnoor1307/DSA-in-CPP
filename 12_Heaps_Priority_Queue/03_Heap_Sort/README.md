# 03_Heap_Sort

## Real-world analogy summary

Prize distribution me har baar current highest scorer ko final sorted position me place karte hain. Max heap highest value fast deta hai.

## Heap sort steps

```text
1. Build max heap.
2. Swap root with last active index.
3. Reduce heap size.
4. Heapify root.
5. Repeat.
```

## Approach comparison table

| Sorting | Real-world analogy | Time calculation | Time | Space |
|---|---|---:|---:|---:|
| Merge sort | merge two sorted result sheets | log n levels * n merge | O(n log n) | O(n) |
| Quick sort | pivot-based partitions | average balanced partitions | avg O(n log n), worst O(n²) | O(log n) avg |
| Heap sort | repeatedly pick highest priority | build O(n) + n heapify log n | O(n log n) | O(1) extra |

## Key formulas

```text
heapSort time = buildHeap + extraction loop
              = O(n) + (n-1)*O(log n)
              = O(n log n)
```

## Common mistakes

1. Min heap use karke ascending heap sort confuse karna.
2. Swap ke baad heap size reduce na karna.
3. Sorted zone ko heapify me include kar dena.
4. Heap sort stable hai assume karna — usually not stable.
5. Build heap O(n) proof ignore karna.

## Interview questions

1. Heap sort algorithm explain karo.
2. Heap sort in-place kaise hai?
3. Heap sort O(n log n) guaranteed kyun hai?
4. Heap sort vs merge sort compare karo.
5. Heap sort vs quick sort compare karo.
6. Memory tight case me heap sort useful kyun hai?
