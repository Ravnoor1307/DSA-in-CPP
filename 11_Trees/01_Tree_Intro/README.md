# 01_Tree_Intro

## Real-world analogy summary

Tree hierarchy ko represent karta hai: family tree, company org chart, file explorer, DOM. Linear list me sirf one-after-one relation hota hai; tree me parent ke multiple children ho sakte hain.

## Linear vs tree visual

```text
Linear:
[CEO] -> [Manager] -> [Employee]

Tree:
          CEO
       /   |   \
      HR  Tech Sales
          /  \
       Dev1  Dev2
```

## Terminology cheat sheet

| Term | Meaning | Real-life analogy |
|---|---|---|
| Root | top node, no parent | family ancestor / root folder |
| Parent | node above child | father/mother/manager |
| Child | node below parent | child/report/subfolder |
| Leaf | no children | employee with no report/file |
| Sibling | same parent | brothers/sisters |
| Ancestor | nodes above | parent, grandparent |
| Descendant | nodes below | children, grandchildren |
| Edge | connection | relationship line |
| Level/Depth | distance from root | floor from top |
| Height | longest downward path | depth of deepest folder |
| Subtree | node and descendants | folder with all inside content |

## Binary tree

```text
Every node has at most 2 children: left and right.
```

Valid:

```text
    10
   /  \
  5   20
```

Invalid:

```text
    10
  / |  \
 5  7  20   // 3 children not binary
```

## Node structure

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

## Complexity table

| Operation | Calculation | Time | Space |
|---|---:|---:|---:|
| Create one node | fixed assignments | O(1) | O(1) |
| Create n-node tree | n allocations + n-1 links | O(n) | O(n) |
| Traverse n nodes | visit each node once | O(n) | O(h) stack |
| Skewed tree height | h=n | traversal stack O(n) | O(n) |
| Perfect tree height | levels grow 1,2,4... | O(log n) height | O(log n) stack |

## Common mistakes

1. Tree ko linked list jaisa one-direction assume karna.
2. Binary tree me 3 children allow samajhna.
3. Root and leaf terms confuse karna.
4. Depth and height confuse karna.
5. Leaf node ke left/right nullptr set na karna.

## Interview questions

1. Tree data structure ki need kya hai?
2. Linear structure hierarchy represent kyun nahi kar pata?
3. Tree terminology explain karo.
4. Binary tree kya hota hai?
5. Skewed tree linked list jaisa kyun hota hai?
6. Node structure draw karo.
