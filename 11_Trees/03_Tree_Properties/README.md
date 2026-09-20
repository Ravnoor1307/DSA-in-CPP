# 03_Tree_Properties

## Real-world analogy summary

Tree properties company/file tree ke measurements jaise hain: height/depth, total nodes, leaf employees, max value, search, and longest path/diameter.

## Core formulas

```text
height(root) = max(height(left), height(right)) + 1
count(root) = count(left) + count(right) + 1
leaf(root)  = 1 if left==NULL && right==NULL else leaf(left)+leaf(right)
max(root)   = max(root->data, max(max(left), max(right)))
search(root,target) = root match OR search(left) OR search(right)
```

## Diameter formulas

Measured in nodes:

```text
throughRoot = height(left) + height(right) + 1
diameter(root) = max(throughRoot, diameter(left), diameter(right))
```

## Approach comparison table

| Property | Pattern | Calculation | Time | Space |
|---|---|---:|---:|---:|
| Height | max(left,right)+1 | each node once | O(n) | O(h) |
| Total nodes | left+right+1 | each node once | O(n) | O(h) |
| Leaf nodes | leaf condition | each node once | O(n) | O(h) |
| Max element | max(root,L,R) | no ordering, all nodes | O(n) | O(h) |
| Search normal tree | DFS | worst all nodes | O(n) | O(h) |
| Diameter naive | height at every node | n+(n-1)+...+1 skewed | O(n²) | O(h) |
| Diameter optimized | height+diameter pair | each node once | O(n) | O(h) |

## Common mistakes

1. Empty tree height convention clear na rakhna.
2. Leaf condition `left==NULL && right==NULL` instead of OR.
3. Normal binary tree ko BST samajh kar half discard karna.
4. Diameter through-root only consider karna.
5. Naive diameter ko O(n) bolna while height repeated hoti hai.
6. Optimized diameter me height and diameter dono return na karna.

## Interview questions

1. Height of tree ka formula kya hai?
2. Total nodes left+right+1 pattern explain karo.
3. Leaf nodes count ka base/condition kya hai?
4. Normal binary tree search O(n) kyun hai?
5. Diameter through-root vs not-through-root cases explain karo.
6. Naive vs optimized diameter compare karo.
