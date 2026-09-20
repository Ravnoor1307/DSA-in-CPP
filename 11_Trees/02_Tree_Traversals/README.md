# 02_Tree_Traversals

## Real-world analogy summary

Tree traversal means branches wale structure ko systematic route se visit karna. Linear list me one natural order hota hai; tree me inorder/preorder/postorder/level-order jaise multiple orders hote hain.

## Traversal cheat sheet

```text
Preorder  = ROOT -> LEFT -> RIGHT
Inorder   = LEFT -> ROOT -> RIGHT
Postorder = LEFT -> RIGHT -> ROOT
Level     = level by level using queue
```

## One tree, all orders

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

| Traversal | Root position | Output |
|---|---|---|
| Preorder | root first | `1 2 4 5 3 6 7` |
| Inorder | root middle | `4 2 5 1 6 3 7` |
| Postorder | root last | `4 5 2 6 7 3 1` |
| Level order | by levels | `1 2 3 4 5 6 7` |

## Approach comparison table

| Traversal | Data structure | Calculation | Time | Space |
|---|---|---:|---:|---:|
| Inorder recursive | call stack | n node calls + n+1 null calls | O(n) | O(h), worst O(n) |
| Preorder recursive | call stack | each node once | O(n) | O(h), worst O(n) |
| Postorder recursive | call stack | each node once | O(n) | O(h), worst O(n) |
| All 3 traversals | call stack | 3*n visits | O(n) | O(h) |
| Level order height loop | recursion per level | 1+2+...+n in skewed | O(n²) worst | O(h) |
| Level order queue | queue | n pushes + n pops = 2n | O(n) | O(width), worst O(n) |
| Iterative inorder | stack | n pushes + n pops = 2n | O(n) | O(h) |

## Memory trick

```text
PREorder  -> root PRE/first
INorder   -> root IN/middle
POSTorder -> root POST/last
```

## Common mistakes

1. Inorder/preorder/postorder order mix karna.
2. Base case `root==nullptr` skip karna.
3. Level-order height-loop ko O(n) assume karna; skewed tree me O(n²).
4. Queue level order me children push karna bhoolna.
5. Iterative inorder me right subtree par move na karna after pop.

## Interview questions

1. Inorder/preorder/postorder rules kya hain?
2. Same tree ke teeno traversal outputs likho.
3. Inorder traversal recursion call stack trace karo.
4. Level order queue se kaise hota hai?
5. Height-loop level order O(n²) worst kyun hota hai?
6. Recursive traversal ko iterative stack se kaise replace karoge?
