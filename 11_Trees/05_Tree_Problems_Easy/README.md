# 05_Tree_Problems_Easy

## Real-world analogy summary

Easy tree problems tree ke simple recursive patterns par based hain: mirror, identical check, sum, balanced check, and level sum. Mostly left subtree + right subtree + current node combine karna hota hai.

## Approach comparison table

| Problem | Core idea | Calculation | Time | Space |
|---|---|---:|---:|---:|
| Mirror tree | swap left/right recursively | n swaps | O(n) | O(h) |
| Identical trees | compare two nodes together | n pair checks | O(n) | O(h) |
| Sum all nodes | root + left + right | n additions | O(n) | O(h) |
| Balanced naive | height at every node | n+(n-1)+...+1 skewed | O(n²) | O(h) |
| Balanced optimized | height+balanced pair | each node once | O(n) | O(h) |
| Same level sum k | reduce k each level | up to n nodes | O(n) worst | O(h) |

## Key formulas

```text
mirror(root): swap(root->left, root->right), recurse children
identical(a,b): data same && identical(left) && identical(right)
sum(root): root->data + sum(left) + sum(right)
balanced: abs(height(left)-height(right)) <= 1 at every node
levelSum(root,k): if k==1 return root->data else levelSum(left,k-1)+levelSum(right,k-1)
```

## Common mistakes

1. Mirror tree me sirf root swap karke children recursion bhoolna.
2. Identical trees me structure null cases handle na karna.
3. Sum nodes me null subtree 0 return na karna.
4. Balanced check me every node condition required hai ye ignore karna.
5. Optimized balanced check me height and bool together return na karna.
6. Level convention root level 0 vs 1 clear na rakhna.

## Interview questions

1. Mirror tree recursively kaise banate hain?
2. Identical trees check ka base case kya hai?
3. Sum of all nodes formula kya hai?
4. Height balanced tree definition kya hai?
5. Naive balanced check O(n²) kyun hai?
6. Same level k ka sum recursively kaise nikaaloge?
