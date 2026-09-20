# 05_Heap_Classic_Problems

## Real-world analogy summary

Heap classic problems priority filtering wale problems hain: top-k toppers, smallest k bills, trending frequent elements, k sorted lists merge, and live median.

## Pattern comparison table

| Problem | Heap pattern | Why this heap? | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| kth largest sort | sort full array | easiest | n log n + 1 | O(n log n) | O(n) copy |
| kth largest optimized | min heap size k | top-k survivors, smallest survivor is kth largest | n * log k | O(n log k) | O(k) |
| kth smallest optimized | max heap size k | smallest-k survivors, largest survivor is kth smallest | n * log k | O(n log k) | O(k) |
| kth smallest min heap pop | min heap all | pop k-1 smallest | n + k log n | O(n + k log n) | O(n) |
| k most frequent | hash map + heap | count then rank | n + m log m | O(n log n) worst | O(m) |
| merge k sorted arrays | min heap of heads | smallest current head next | N log k | O(N log k) | O(k) |
| running median | max heap + min heap | balance lower/upper halves | log n per add | O(log n) add | O(n) |

## Key tricks

```text
kth largest -> min heap of size k
kth smallest -> max heap of size k
frequency problems -> hashmap first, heap second
merge k sorted -> heap contains only current heads
running median -> lower max heap + upper min heap
```

## Complexity formulas

```text
Top-k heap size k:
for each n elements -> push/pop O(log k)
Total = O(n log k)

Merge k lists:
N total elements, heap size <= k
Each element pop once and maybe push next once
Total = O(N log k)

Running median:
Each insertion uses constant number of heap push/pop
Each heap operation O(log n)
Median top read O(1)
```

## Common mistakes

1. kth largest me max heap all bana kar k pops karna okay hai, but O(n + k log n); size-k min heap often better.
2. kth largest ke liye min heap size k trick confuse karna.
3. kth smallest ke liye max heap size k trick confuse karna.
4. `pair(freq,num)` order samjhe bina top frequent solve karna.
5. Merge k sorted arrays me all elements heap me daal dena, space O(N) ho jayega.
6. Running median me heap sizes balance na karna.
7. Running median me lower.top() <= upper.top() invariant todna.

## Interview questions

1. kth largest using sort explain karo.
2. kth largest using min heap size k dry run karo.
3. kth smallest using max heap size k dry run karo.
4. kth smallest min heap pop approach kab useful hai?
5. k most frequent me hashing + heap ka connection explain karo.
6. Merge k sorted arrays me heap of heads kyun efficient hai?
7. Running median two heaps se kaise maintain hota hai?
8. Top-k problems me heap size k kyun important hai?
