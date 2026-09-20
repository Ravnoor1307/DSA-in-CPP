# 04_Binary_Search_Tree_BST

## Real-world analogy summary

BST sorted dictionary ki tree form hai. Har node par rule: left subtree ke values smaller, right subtree ke values greater. Is property se search binary-search-like path follow karta hai.

## BST property

```text
For every node:
all values in left subtree < root->data < all values in right subtree
```

Example:

```text
              50
            /    \
          30      70
         /  \    /  \
       20   40  60   80
```

## Golden property

```text
BST inorder traversal gives sorted order.
20 30 40 50 60 70 80
```

## Approach comparison table

| Operation | Core idea | Calculation | Time | Space |
|---|---|---:|---:|---:|
| Insert | compare and go left/right | one level per comparison = h | O(h) | O(h) recursive |
| Search recursive | discard one subtree each step | path height h | O(h) | O(h) |
| Search iterative | pointer walk | path height h | O(h) | O(1) |
| Min | leftmost walk | h moves | O(h) | O(1) |
| Max | rightmost walk | h moves | O(h) | O(1) |
| Inorder sorted | L Root R | n visits | O(n) | O(h) |
| Delete | search + case handling | h search + h successor | O(h) | O(h) |
| Validate min/max | range passing | n nodes once | O(n) | O(h) |
| kth smallest | inorder count | up to n visits | O(n) worst | O(h) |

Balanced BST: h=log n. Skewed BST: h=n.

## Delete cases

```text
Case 1: leaf        -> delete and return nullptr
Case 2: one child   -> child moves up
Case 3: two child   -> replace with inorder successor, then delete successor
```

## Common mistakes

1. BST property sirf direct child par check karna, full subtree range ignore karna.
2. Search recursive me wrong side jaana.
3. Iterative search me current pointer update bhoolna.
4. Inorder successor = right subtree ka minimum, ye confuse karna.
5. Delete two-child case me successor node delete na karna.
6. kth smallest me inorder sorted property use na karna.

## Interview questions

1. BST property explain karo.
2. Insert 50,30,70,20,40 ka diagram banao.
3. Recursive and iterative search compare karo.
4. BST min/max kaise find karte hain?
5. Inorder sorted kyun hota hai?
6. BST delete ke 3 cases explain karo.
7. Validate BST min/max range approach explain karo.
8. kth smallest in BST kaise find karoge?
