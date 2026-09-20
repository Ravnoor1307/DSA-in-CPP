# 01_Heap_Intro

## Real-world analogy summary

Hospital emergency room me queue arrival order se nahi chalti. Jis patient ki priority/criticality highest hai, wo pehle treat hota hai. Heap/Priority Queue isi idea ka data structure version hai.

## Key ideas

```text
Heap = Complete Binary Tree + Heap Property

Max Heap: parent >= children
Min Heap: parent <= children
```

Heap BST nahi hota:

| Structure | Rule | Example use |
|---|---|---|
| BST | left subtree < root < right subtree | sorted search |
| Heap | parent-child priority only | repeated max/min |

## Array formulas

For 0-based indexing:

```text
parent(i) = (i - 1) / 2
left(i)   = 2*i + 1
right(i)  = 2*i + 2
```

Dry run for `i=4`:

```text
parent = (4-1)/2 = 1
left   = 2*4+1 = 9
right  = 2*4+2 = 10
```

## Complexity calculations

Peek root:

```text
root is arr[0]
1 direct access -> O(1)
```

Heap height:

```text
complete tree halves search path each level
n / 2^k = 1 -> n = 2^k -> k = log₂n
height = O(log n)
```

Insert/extract root moves at most height levels:

```text
O(log n)
```

## Common mistakes

1. Heap ko BST samajh lena.
2. Left child and right child ke beech sorted order assume karna.
3. Complete binary tree condition ignore karna.
4. 0-based formulas and 1-based formulas mix karna.
5. `parent(0)` calculate karna without root check.

## Interview questions

1. Heap kya hota hai?
2. Max heap and min heap difference kya hai?
3. Heap BST se different kaise hai?
4. Complete binary tree heap ke liye kyun zaruri hai?
5. Heap array me kaise store hota hai?
6. 0-based parent/left/right formulas derive karo.
7. Peek operation O(1) kyun hai?
