# 12_Heaps_Priority_Queue

## Module goal

Hospital emergency room me patients arrival order se treat nahi hote; jo sabse critical hai, wo pehle aata hai. Heap / Priority Queue isi priority-first idea ko efficient banata hai.

```text
Normal queue:       first come -> first serve
Priority queue:     highest/lowest priority -> first serve
Heap:               priority queue ka common implementation
```

Repeated max/min queries ke liye sorting har baar slow hoti hai. Heap root par best priority maintain karta hai:

```text
Max Heap: arr[0] = maximum
Min Heap: arr[0] = minimum
```

---

## Folder tree

```text
12_Heaps_Priority_Queue/
├── README.md
├── 01_Heap_Intro/
│   ├── 01_why_heap_theory.cpp
│   ├── 02_heap_definition_theory.cpp
│   ├── 03_complete_binary_tree_theory.cpp
│   ├── 04_heap_as_array_theory.cpp
│   ├── README.md
│   └── task.cpp
├── 02_Heap_Operations/
│   ├── 01_heapify_up_insert.cpp
│   ├── 02_heapify_down_delete_root.cpp
│   ├── 03_peek_operation.cpp
│   ├── 04_build_heap_approach1_n_inserts.cpp
│   ├── 05_build_heap_approach2_heapify_all.cpp
│   ├── 06_heap_as_class_implementation.cpp
│   ├── README.md
│   └── task.cpp
├── 03_Heap_Sort/
│   ├── 01_heap_sort_concept_theory.cpp
│   ├── 02_heap_sort_implementation.cpp
│   ├── 03_heap_sort_vs_others_comparison.cpp
│   ├── README.md
│   └── task.cpp
├── 04_STL_Priority_Queue/
│   ├── 01_stl_max_priority_queue.cpp
│   ├── 02_stl_min_priority_queue.cpp
│   ├── 03_custom_comparator_pq.cpp
│   ├── 04_pq_vs_queue_vs_stack.cpp
│   ├── README.md
│   └── task.cpp
└── 05_Heap_Classic_Problems/
    ├── 01_kth_largest_approach1_sort.cpp
    ├── 02_kth_largest_approach2_minheap.cpp
    ├── 03_kth_smallest_approach1_maxheap.cpp
    ├── 04_kth_smallest_approach2_minheap_pop.cpp
    ├── 05_k_most_frequent_elements.cpp
    ├── 06_merge_k_sorted_arrays_concept.cpp
    ├── 07_running_median_concept.cpp
    ├── README.md
    └── task.cpp
```

---

## Heap definition

Heap has two conditions:

```text
1. Complete Binary Tree
2. Heap Property
```

### Complete Binary Tree

```text
All levels filled except maybe last level.
Last level filled left-to-right.
```

Valid complete tree:

```text
        1
      /   \
     2     3
    / \   /
   4   5 6
```

Not complete:

```text
        1
      /   \
     2     3
      \     \
       5     7
```

### Heap property

```text
Max Heap: parent >= children
Min Heap: parent <= children
```

Max heap:

```text
        90
       /  \
     70    80
    / \   /
   20 30 60
```

Min heap:

```text
        10
       /  \
     20    30
    / \   /
   50 60 40
```

---

## Heap vs BST

| Feature | Heap | BST |
|---|---|---|
| Main rule | parent-child priority | left subtree < root < right subtree |
| Root | max/min element | not necessarily min/max |
| Left/right order | no strict left-right order | strict ordered subtrees |
| Best use | repeated max/min | search sorted data |
| Inorder result | not sorted | sorted |

Important warning:

```text
Heap is NOT BST.
Heap only says parent has higher/lower priority than its children.
It does not say left child < right child or full left subtree < root.
```

---

## Heap as array

Because heap is complete binary tree, pointers are not needed. Level order array storage works.

```text
              90(index0)
            /            \
      70(index1)       80(index2)
       /      \          /
 20(index3) 30(index4) 60(index5)

index:  0   1   2   3   4   5
value: [90, 70, 80, 20, 30, 60]
```

### 0-based formulas

```text
parent(i) = (i - 1) / 2
left(i)   = 2*i + 1
right(i)  = 2*i + 2
```

Dry run for `i = 4`:

```text
value at index 4 = 30
parent(4) = (4-1)/2 = 3/2 = 1 -> value 70
left(4)   = 2*4+1 = 9 -> out of range
right(4)  = 2*4+2 = 10 -> out of range
```

---

## Core operations

| Operation | Real-world analogy | Visual action | Calculation | Time | Extra space |
|---|---|---|---:|---:|---:|
| Peek | check emergency board | read root `arr[0]` | 1 access | O(1) | O(1) |
| Insert | new patient arrives | append + bubble-up | height log n | O(log n) | O(1) |
| Extract root | treat critical patient | root remove + sink-down | height log n | O(log n) | O(1) |
| Build heap by inserts | register one-by-one | n insert calls | n log n | O(n log n) | O(n) |
| Build heap bottom-up | repair shelves from bottom | level-wise small work | n | O(n) | O(1) extra |

### Heap height proof

Complete binary tree grows roughly double every level:

```text
level 0 -> 1 node
level 1 -> 2 nodes
level 2 -> 4 nodes
level k -> 2^k nodes

n / 2^k = 1
n = 2^k
k = log₂n
```

So one root-to-leaf path has `O(log n)` nodes.

---

## Heapify-up insert

```text
Insert value at last open slot.
While child priority > parent priority:
    swap child and parent
```

Dry run insert 80 into `[70,30,50]`:

```text
append 80 -> [70,30,50,80]
compare 80 with parent 30 -> swap -> [70,80,50,30]
compare 80 with parent 70 -> swap -> [80,70,50,30]
```

Time calculation:

```text
append = O(1)
max swaps = height = log₂n
Time = O(log n)
```

---

## Heapify-down delete root

```text
Save root answer.
Move last element to root.
Pop last slot.
While parent smaller than larger child:
    swap with larger child
```

Dry run extract 70 from `[70,50,60,20,30]`:

```text
move last 30 to root -> [30,50,60,20]
compare children 50 and 60 -> larger child 60
swap 30 with 60 -> [60,50,30,20]
```

Time calculation:

```text
move last = O(1)
heapify-down path = height = log₂n
Time = O(log n)
```

---

## Build heap approaches

### Approach 1: n inserts

```text
For each element:
    insert into heap

Each insert = O(log n)
n inserts = O(n log n)
```

### Approach 2: bottom-up heapify

```text
Start from last non-leaf index = n/2 - 1.
Move backward to index 0.
Heapify-down each node.
```

Why O(n)?

```text
Leaves: about n/2 nodes, work 0
Height 1: about n/4 nodes, work 1
Height 2: about n/8 nodes, work 2
Height 3: about n/16 nodes, work 3

Total = n/4*1 + n/8*2 + n/16*3 + ...
      = n * (1/4 + 2/8 + 3/16 + ...)
      = n * constant
      = O(n)
```

---

## Heap sort

Real-world: highest scorer ko repeatedly final position pe place karo.

```text
1. Build max heap.
2. Swap root max with last active index.
3. Reduce heap size.
4. Heapify root.
5. Repeat.
```

Dry run summary for `[4,10,3,5,1]`:

```text
Build max heap: [10,5,3,4,1]
Pass 1: [5,4,3,1 | 10]
Pass 2: [4,1,3 | 5,10]
Pass 3: [3,1 | 4,5,10]
Pass 4: [1 | 3,4,5,10]
Sorted: [1,3,4,5,10]
```

Complexity:

```text
buildHeap = O(n)
extraction loop = (n-1) * O(log n)
Total = O(n + n log n) = O(n log n)
Extra space = O(1)
```

### Sorting comparison

| Sort | Real-world analogy | Time | Space | Best case use |
|---|---|---:|---:|---|
| Merge sort | merge sorted report sheets | O(n log n) | O(n) | stable sorting |
| Quick sort | pivot based partition line | avg O(n log n), worst O(n²) | O(log n) avg | fastest practical average |
| Heap sort | priority desk repeatedly picks max | O(n log n) | O(1) | memory tight + guaranteed n log n |

---

## STL priority_queue

### Max priority queue

```cpp
priority_queue<int> pq;
pq.push(50);
pq.top(); // maximum
pq.pop(); // remove maximum
```

### Min priority queue

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.top(); // minimum
```

### Custom comparator

```cpp
struct Compare {
    bool operator()(const Item& a, const Item& b) const {
        return a.priority < b.priority; // higher priority should come first
    }
};
```

Comparator rule reminder:

```text
return true means: a has lower priority than b
```

### Stack vs queue vs priority queue

| Structure | Rule | Real-world analogy | Access | push | remove |
|---|---|---|---:|---:|---:|
| stack | LIFO | plates/browser back | top O(1) | O(1) | O(1) |
| queue | FIFO | ticket counter | front O(1) | O(1) | O(1) |
| priority_queue | priority first | hospital emergency | top O(1) | O(log n) | O(log n) |

---

## Classic heap problems

### kth largest

Sorting approach:

```text
sort array -> answer at index n-k
Time = O(n log n)
```

Optimized min heap size k:

```text
For each element:
    push into min heap
    if heap size > k: pop smallest

At end, heap contains top k largest.
Heap top = kth largest.
```

Calculation:

```text
n elements
heap size at most k
push/pop = O(log k)
Total = O(n log k)
Space = O(k)
```

### kth smallest

Optimized max heap size k:

```text
For each element:
    push into max heap
    if heap size > k: pop largest

At end, heap contains smallest k.
Heap top = kth smallest.
```

### k most frequent elements

Hashing + heap connection:

```text
1. unordered_map counts frequency.
2. heap ranks by frequency.
3. pop k answers.
```

Calculation:

```text
n items -> frequency count O(n)
m unique items -> heap push O(m log m)
k pops -> O(k log m)
Worst m <= n -> O(n log n)
```

### Merge k sorted arrays

```text
Heap stores only current head of each array.
Pop smallest head, push next element from same array.
```

Calculation:

```text
N total elements, heap size k
Each element popped once -> N log k
Each next pushed once -> N log k
Time = O(N log k)
Space = O(k)
```

### Running median

```text
lower half -> max heap
upper half -> min heap

Rules:
max(lower) <= min(upper)
size difference <= 1
```

Median:

```text
if sizes equal -> (lower.top + upper.top)/2
else -> lower.top
```

Calculation:

```text
add value -> one heap push O(log n)
rebalance -> at most one pop + one push O(log n)
median query -> read tops O(1)
```

---

## Master pattern table

| Problem family | Best heap pattern | Real-world analogy | Time | Space |
|---|---|---|---:|---:|
| Repeated max/min | heap root | emergency board | peek O(1), update O(log n) | O(n) |
| Build priority structure | bottom-up heapify | repair managers from bottom | O(n) | O(1) extra |
| In-place sort | heap sort | repeatedly place highest scorer | O(n log n) | O(1) |
| kth largest | min heap size k | top-k survivor club | O(n log k) | O(k) |
| kth smallest | max heap size k | lowest-k survivor club | O(n log k) | O(k) |
| top k frequent | hash map + heap | trending topics | O(n + m log m) | O(m) |
| merge k sorted arrays | min heap of heads | merge k merit lists | O(N log k) | O(k) |
| running median | two heaps | balance lower/upper halves | O(log n) per add | O(n) |

---

## Common mistakes checklist

1. Heap ko BST samajhna.
2. Complete binary tree condition ignore karna.
3. Parent/left/right formulas 0-based and 1-based mix karna.
4. `parent(0)` calculate karna without root check.
5. Insert ke baad heapify-up bhoolna.
6. Delete root me last element root par move na karna.
7. Heapify-down me larger child choose na karna for max heap.
8. Build heap bottom-up ko O(n log n) bolna.
9. Bottom-up heapify leaves se start karna; last non-leaf `n/2-1` se start karo.
10. Heap sort me sorted zone ko heapify me include kar dena.
11. Heap sort stable assume karna.
12. STL min heap syntax galat likhna.
13. Comparator return meaning ulta samajhna.
14. `top()` and `pop()` confuse karna.
15. kth largest ke liye min heap size k trick miss karna.
16. kth smallest ke liye max heap size k trick miss karna.
17. Merge k sorted arrays me all elements heap me daal dena, space O(N) ho jata hai.
18. Running median me heaps balance na karna.
19. Running median me lower/upper ordering invariant todna.
20. Complexity likhte waqt calculation skip karna.

---

## Interview question bank

1. Heap kya hota hai?
2. Complete binary tree heap me kyun required hai?
3. Max heap and min heap difference explain karo.
4. Heap and BST difference with diagram explain karo.
5. Heap array mapping derive karo.
6. `parent(i)`, `left(i)`, `right(i)` formulas likho.
7. Index 4 ka parent/left/right dry run karo.
8. Peek operation O(1) kyun hai?
9. Insert in max heap dry run karo.
10. Heapify-up O(log n) kyun hota hai?
11. Extract max dry run karo.
12. Heapify-down me larger child choose kyun karte hain?
13. Build heap by n inserts O(n log n) kyun?
14. Bottom-up build heap O(n) proof do.
15. Last non-leaf index `n/2 - 1` kyun hota hai?
16. Complete MaxHeap class implement karo.
17. Heap sort algorithm explain karo.
18. Heap sort O(n log n) and O(1) space proof do.
19. Heap sort vs merge sort compare karo.
20. Heap sort vs quick sort compare karo.
21. STL `priority_queue<int>` default max heap kyun hai?
22. STL min heap syntax likho.
23. Custom comparator object ke liye likho.
24. Comparator me `return true` ka meaning kya hota hai?
25. Stack vs queue vs priority_queue compare karo.
26. kth largest using sorting explain karo.
27. kth largest using min heap size k dry run karo.
28. kth largest min heap trick intuition do.
29. kth smallest using max heap size k dry run karo.
30. kth smallest min heap all + k pops complexity batao.
31. k most frequent elements hashing + heap se solve karo.
32. Merge k sorted arrays heap of heads se solve karo.
33. Running median two-heaps approach explain karo.
34. Running median me rebalance conditions kya hain?
35. Heap problem identify karne ke signals kya hain?

---

## Study plan

1. `01_Heap_Intro` me heap vs BST and array formulas master karo.
2. `02_Heap_Operations` me insert/delete/build heap dry run copy me draw karo.
3. `03_Heap_Sort` me `[4,10,3,5,1]` pass-by-pass trace karo.
4. `04_STL_Priority_Queue` me max/min/custom comparator syntax yaad karo.
5. `05_Heap_Classic_Problems` me top-k, merge-k, running median patterns practice karo.
6. Har subfolder ka `task.cpp` pehle khud solve karo, phir solution se compare karo.
