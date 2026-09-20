# 06_Tree_Problems_Medium

## Real-world analogy summary

Medium tree problems multiple DSA concepts combine karte hain: BST ordering, normal-tree recursion, queue level order, hashing/map horizontal distances, global path answers, and serialization.

## Approach comparison table

| Problem | Pattern | Calculation | Time | Space |
|---|---|---:|---:|---:|
| LCA in BST | paths diverge by ordering | height h path | O(h) | O(1) iterative |
| LCA in binary tree | left/right recursion | all n nodes worst | O(n) | O(h) |
| Top view | BFS + horizontal distance map | n pops + map log d | O(n log d) | O(n) |
| Left view | first node each BFS level | n pushes+pops | O(n) | O(n) |
| Zigzag level order | queue + direction flag | n nodes placed once | O(n) | O(n) |
| Max path sum | postorder gain | each node once | O(n) | O(h) |
| Serialize/deserialize | preorder + # nulls | 2n+1 tokens | O(n) | O(n) |

## Key tricks

```text
BST LCA:
if p,q < root -> left
if p,q > root -> right
else root is split point

Binary tree LCA:
left = lca(left)
right = lca(right)
if both non-null -> root
else return non-null side

Top view:
root hd=0, left hd-1, right hd+1
store first node per hd during BFS

Max path sum:
gain = node + max(leftGain, rightGain)
through = node + max(0,leftGain) + max(0,rightGain)
```

## Common mistakes

1. Normal binary tree LCA me BST logic use karna.
2. BST LCA me split point condition miss karna.
3. Top view me first node per horizontal distance overwrite kar dena.
4. Left view me last node of level accidentally store karna.
5. Zigzag level order me direction toggle na karna.
6. Max path sum me negative gains include karna.
7. Serialize me null markers skip karna, jisse structure ambiguous ho jata hai.

## Interview questions

1. LCA in BST paths diverge logic explain karo.
2. LCA in binary tree recursion magic dry run karo.
3. Top view horizontal distance kya hota hai?
4. Left view first node each level se kaise aata hai?
5. Zigzag level order queue + direction flag explain karo.
6. Max path sum me return gain and global answer difference kya hai?
7. Serialize/deserialize preorder with null markers explain karo.
