# 11_Trees

## Module goal

Tree data structure hierarchy represent karta hai. Linear structures — array, linked list, stack, queue — mostly one-after-one relationship dikhate hain. But real life me hierarchy hoti hai: family tree, company org chart, file explorer, DOM, decision trees.

```text
Linear list:
[A] -> [B] -> [C] -> [D]

Tree hierarchy:
          A
        /   \
       B     C
      / \     \
     D   E     F
```

Tree module ka main focus hai: terminology, binary trees, traversals, properties, BST, easy problems, and medium interview patterns.

---

## Folder tree

```text
11_Trees/
├── README.md
├── 01_Tree_Intro/
│   ├── 01_why_trees_theory.cpp
│   ├── 02_tree_terminology_theory.cpp
│   ├── 03_binary_tree_theory.cpp
│   ├── 04_tree_node_structure.cpp
│   ├── 05_creating_first_tree.cpp
│   ├── README.md
│   └── task.cpp
├── 02_Tree_Traversals/
│   ├── 01_traversal_intro_theory.cpp
│   ├── 02_inorder_traversal.cpp
│   ├── 03_preorder_traversal.cpp
│   ├── 04_postorder_traversal.cpp
│   ├── 05_all_traversals_one_tree.cpp
│   ├── 06_level_order_approach1_height_loop.cpp
│   ├── 07_level_order_approach2_queue.cpp
│   ├── 08_traversals_without_recursion_idea.cpp
│   ├── README.md
│   └── task.cpp
├── 03_Tree_Properties/
│   ├── 01_height_of_tree.cpp
│   ├── 02_count_total_nodes.cpp
│   ├── 03_count_leaf_nodes.cpp
│   ├── 04_max_element_tree.cpp
│   ├── 05_search_in_tree.cpp
│   ├── 06_diameter_approach1_naive.cpp
│   ├── 07_diameter_approach2_optimized.cpp
│   ├── README.md
│   └── task.cpp
├── 04_Binary_Search_Tree_BST/
│   ├── 01_bst_property_theory.cpp
│   ├── 02_bst_insert.cpp
│   ├── 03_bst_search_approach1_recursive.cpp
│   ├── 04_bst_search_approach2_iterative.cpp
│   ├── 05_bst_min_max.cpp
│   ├── 06_bst_inorder_is_sorted.cpp
│   ├── 07_bst_delete_node.cpp
│   ├── 08_bst_validate_approach1_minmax.cpp
│   ├── 09_bst_kth_smallest.cpp
│   ├── README.md
│   └── task.cpp
├── 05_Tree_Problems_Easy/
│   ├── 01_mirror_tree.cpp
│   ├── 02_identical_trees_check.cpp
│   ├── 03_sum_of_all_nodes.cpp
│   ├── 04_height_balanced_check_approach1.cpp
│   ├── 05_height_balanced_check_approach2.cpp
│   ├── 06_same_level_sum_k.cpp
│   ├── README.md
│   └── task.cpp
└── 06_Tree_Problems_Medium/
    ├── 01_lowest_common_ancestor_bst.cpp
    ├── 02_lowest_common_ancestor_binary_tree.cpp
    ├── 03_top_view_of_tree.cpp
    ├── 04_left_view_of_tree.cpp
    ├── 05_zigzag_level_order.cpp
    ├── 06_max_path_sum.cpp
    ├── 07_serialize_deserialize_concept.cpp
    ├── README.md
    └── task.cpp
```

---

## Tree terminology cheat sheet

```text
          A  <- Root, depth 0, level 0/1 depending convention
        /   \
       B     C  <- B and C are siblings
      / \     \
     D   E     F  <- Leaves
```

| Term | Meaning | Real-world analogy |
|---|---|---|
| Root | top node, no parent | root folder / CEO / oldest ancestor |
| Parent | node directly above child | manager/parent folder |
| Child | node directly below parent | report/subfolder |
| Leaf | node with no children | employee with no reports / file |
| Sibling | same parent ke children | brothers/sisters |
| Ancestor | nodes above current node | parent, grandparent |
| Descendant | nodes below current node | child, grandchild |
| Edge | connection between two nodes | relation line |
| Level | layer from root | building floor |
| Depth | distance from root | how deep folder is |
| Height | longest downward path | deepest nested folder distance |
| Subtree | node with descendants | folder with all content |

---

## Binary tree basics

Binary tree rule:

```text
Every node has at most 2 children: left and right
```

Valid binary tree:

```text
        10
       /  \
      5    20
     /
    3
```

Invalid binary tree:

```text
        10
      /  |  \
     5   7   20   // 3 children not allowed
```

Node structure:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

Node visual:

```text
+-----------------------------+
| left ptr | data | right ptr |
+-----------------------------+
     |        10        |
     v                  v
 left child         right child
```

---

## Traversal cheat sheet

Same tree:

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

| Traversal | Rule | Root position | Output |
|---|---|---|---|
| Preorder | ROOT → LEFT → RIGHT | root first | `1 2 4 5 3 6 7` |
| Inorder | LEFT → ROOT → RIGHT | root middle | `4 2 5 1 6 3 7` |
| Postorder | LEFT → RIGHT → ROOT | root last | `4 5 2 6 7 3 1` |
| Level order | level by level | BFS | `1 2 3 4 5 6 7` |

Memory trick:

```text
PREorder  -> root comes PRE/first
INorder   -> root comes IN/middle
POSTorder -> root comes POST/last
```

### Level order queue visual

```text
start [1]
pop1, push2,3 -> [2,3]
pop2, push4,5 -> [3,4,5]
pop3, push6,7 -> [4,5,6,7]
pop4 -> [5,6,7]
pop5 -> [6,7]
pop6 -> [7]
pop7 -> []
```

Queue journey connect:

```text
Each node pushed once + popped once = 2n operations -> O(n)
```

---

## Tree property formula sheet

```text
height(root) = max(height(left), height(right)) + 1

countNodes(root) = countNodes(left) + countNodes(right) + 1

leafCount(root):
    if left == NULL && right == NULL -> 1
    else leafCount(left) + leafCount(right)

maxElement(root) = max(root->data, max(max(left), max(right)))

search normal tree:
    root match OR search(left) OR search(right)
```

Diameter measured in nodes:

```text
throughRoot = height(left) + height(right) + 1
diameter(root) = max(throughRoot, diameter(left), diameter(right))
```

Optimized diameter:

```text
Return both height and diameter in one recursion.
```

---

## BST cheat sheet

BST = ordered binary tree.

```text
For every node:
left subtree values < root->data < right subtree values
```

Example:

```text
              50
            /    \
          30      70
         /  \    /  \
       20   40  60   80
```

### BST operations

| Operation | Logic | Time | Space |
|---|---|---:|---:|
| Insert | compare and move left/right | O(h) | O(h) recursive |
| Search recursive | discard one subtree each step | O(h) | O(h) |
| Search iterative | pointer walk | O(h) | O(1) |
| Min | leftmost node | O(h) | O(1) |
| Max | rightmost node | O(h) | O(1) |
| Inorder | sorted output | O(n) | O(h) |
| Delete | search + 3 cases | O(h) | O(h) |
| Validate | min/max range | O(n) | O(h) |
| kth smallest | inorder count | O(n) worst | O(h) |

If tree balanced:

```text
h = log n
```

If tree skewed:

```text
h = n
```

### BST delete cases

```text
Case 1: Leaf node
delete node and return nullptr

Case 2: One child
return the child, child moves up

Case 3: Two children
find inorder successor = minimum in right subtree
copy successor value into current node
delete successor from right subtree
```

### BST golden property

```text
Inorder traversal of BST is sorted.
```

Use cases:

- kth smallest
- validate BST
- sorted listing
- convert BST to sorted array

---

## Medium patterns cheat sheet

### LCA in BST

```text
if p and q both smaller than root -> go left
if p and q both greater than root -> go right
else root is split point and LCA
```

Example:

```text
LCA(20,40)
50 -> both smaller -> 30
30 -> paths diverge -> LCA = 30
```

### LCA in binary tree

```text
left = lca(left subtree)
right = lca(right subtree)

if left and right both found -> current root is LCA
else return non-null side
```

### Top view

```text
root hd = 0
left child hd = hd - 1
right child hd = hd + 1
BFS order ensures first node at each hd is top visible
```

### Left view

```text
BFS level order
first node of every level goes into answer
```

### Zigzag level order

```text
level 1: left -> right
level 2: right -> left
level 3: left -> right
use queue + direction flag
```

### Max path sum

```text
leftGain = max(0, gain(left))
rightGain = max(0, gain(right))
throughCurrent = root->data + leftGain + rightGain
globalBest = max(globalBest, throughCurrent)
return root->data + max(leftGain, rightGain)
```

### Serialize / deserialize

```text
Preorder with null markers:
1 2 # # 3 # #

# markers are necessary to preserve structure.
```

---

## Master approach comparison table

| Topic | Best pattern | Real-world analogy | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Create tree | pointer links | file explorer folders | n allocations + n-1 links | O(n) | O(n) |
| DFS traversal | recursion | branch route | n node visits | O(n) | O(h) |
| Level order queue | BFS queue | floor-wise tour | n pushes + n pops = 2n | O(n) | O(width), worst O(n) |
| Height-loop level order | print each level from root | repeated floor scan | 1+2+...+n skewed | O(n²) worst | O(h) |
| Iterative inorder | explicit stack | manual call stack | n pushes + n pops | O(n) | O(h) |
| Height | max child + 1 | deepest folder | n nodes once | O(n) | O(h) |
| Count nodes | left+right+1 | total employees | n additions | O(n) | O(h) |
| Leaf count | no children check | employees no reports | n checks | O(n) | O(h) |
| Max in tree | check all nodes | highest age | n comparisons | O(n) | O(h) |
| Search normal tree | DFS | unsorted cabinet | n worst checks | O(n) | O(h) |
| Diameter naive | height at every node | repeated road measuring | n+(n-1)+...+1 skewed | O(n²) | O(h) |
| Diameter optimized | height+diameter pair | one combined report | n nodes once | O(n) | O(h) |
| BST insert/search | ordered path | dictionary tree | h comparisons | O(h) | O(h)/O(1) |
| BST validate | min/max range | allowed gate range | n nodes once | O(n) | O(h) |
| Mirror tree | swap children | mirror reflection | n swaps | O(n) | O(h) |
| Identical trees | two-tree recursion | compare two folders | n pair checks | O(n) | O(h) |
| Balanced naive | repeated height | repeated team audits | n² skewed | O(n²) | O(h) |
| Balanced optimized | height+bool pair | single team report | n nodes once | O(n) | O(h) |
| LCA BST | path split | diverging paths | h moves | O(h) | O(1) |
| LCA BT | left/right search | unsorted family tree | n nodes worst | O(n) | O(h) |
| Top view | BFS + HD map | drone view | n map operations | O(n log d) | O(n) |
| Left view | first node per level | left-side view | n queue ops | O(n) | O(n) |
| Zigzag | queue + direction | museum route | n nodes placed | O(n) | O(n) |
| Max path sum | postorder gain | max happiness path | n nodes once | O(n) | O(h) |
| Serialize | preorder + # | pack tree to string | 2n+1 tokens | O(n) | O(n) |

---

## Complexity derivations

### 1. Full tree traversal

```text
Each node visited once.
For n nodes: n visits.
Time = O(n)
```

DFS recursion also calls null children:

```text
real node calls = n
null child calls = n + 1
total calls = 2n + 1
Time = O(n)
```

### 2. Queue level order

```text
Each node pushed once.
Each node popped once.
Total queue operations = n + n = 2n.
Time = O(n)
```

### 3. Height-loop level order worst case

For skewed tree:

```text
level 1 scan cost = 1
level 2 scan cost = 2
level 3 scan cost = 3
...
level n scan cost = n
Total = 1 + 2 + ... + n = n(n+1)/2
Time = O(n²)
```

### 4. BST height

Balanced tree level growth:

```text
level 0 -> 1 node
level 1 -> 2 nodes
level 2 -> 4 nodes
level k -> 2^k nodes

n / 2^k = 1
n = 2^k
k = log₂n
```

Balanced BST operations follow height:

```text
Time = O(h) = O(log n)
```

Skewed BST:

```text
h = n
Time = O(n)
```

### 5. Naive diameter / naive balanced repeated height

```text
At root, height scans n nodes.
At next skewed node, height scans n-1 nodes.
Then n-2, ...
Total = n + (n-1) + ... + 1 = n(n+1)/2
Time = O(n²)
```

### 6. Optimized diameter / balanced

```text
Each node returns combined information once.
height + diameter OR height + balanced
Total node visits = n
Time = O(n)
```

### 7. Top view with map

```text
BFS visits n nodes.
Each map insert/check costs O(log d), d = horizontal distance count.
Time = O(n log d)
Space = O(n)
```

### 8. Serialization tokens

For binary tree with n real nodes:

```text
null links = n + 1
serialized tokens = n + (n+1) = 2n + 1
Time = O(n)
Space = O(n)
```

---

## Section-wise roadmap

### 01_Tree_Intro

- Why trees are needed for hierarchy.
- Family tree, org chart, file explorer, DOM examples.
- Full terminology: root, parent, child, leaf, sibling, ancestor, descendant, level, height, depth, subtree, edge.
- Binary tree theory.
- Node structure and manual tree creation.

### 02_Tree_Traversals

- Inorder, preorder, postorder DFS.
- One tree, three different outputs.
- Level order using height-loop and queue.
- Queue as real tree traversal tool.
- Traversals without recursion using stack idea.

### 03_Tree_Properties

- Height of tree.
- Count total nodes.
- Count leaf nodes.
- Max element.
- Search in normal binary tree.
- Diameter naive and optimized.

### 04_Binary_Search_Tree_BST

- BST property: left < root < right.
- Insert/search/min/max.
- Inorder sorted golden property.
- Delete node 3 cases.
- Validate BST by min/max range.
- kth smallest using inorder.

### 05_Tree_Problems_Easy

- Mirror tree.
- Identical trees check.
- Sum of all nodes.
- Height-balanced check naive and optimized.
- Same level k sum.

### 06_Tree_Problems_Medium

- LCA in BST and binary tree.
- Top view using map + level order.
- Left view.
- Zigzag level order.
- Max path sum.
- Serialize/deserialize concept.

---

## Common mistakes checklist

1. Tree and binary tree same assume karna.
2. Binary tree node ke 3 children allow karna.
3. Root, leaf, height, depth terms confuse karna.
4. DFS traversal order mix karna.
5. Preorder/inorder/postorder me root position yaad na rakhna.
6. Traversal base case `root==nullptr` miss karna.
7. Level order queue me children push order galat karna.
8. Height-loop level order ko O(n) bolna.
9. Normal binary tree search ko BST search samajhna.
10. Diameter through-root only consider karna.
11. Naive diameter/balanced repeated height cost ignore karna.
12. BST property full subtree par check na karna.
13. BST validation me min/max range use na karna.
14. BST delete two-children case me inorder successor delete na karna.
15. kth smallest me inorder sorted property skip karna.
16. Identical trees me one-null one-non-null case miss karna.
17. Balanced optimized approach me height+bool together return na karna.
18. BST LCA logic normal binary tree par apply karna.
19. Top view me first horizontal-distance node overwrite karna.
20. Max path sum me negative gain include karna.
21. Serialize tree without null markers karna.
22. Dynamic nodes ko delete/free na karna in practice code.

---

## Interview question bank

1. Tree data structure ki need kya hai?
2. Linear structures hierarchy represent kyun nahi kar paate?
3. Family tree/org chart/file explorer examples explain karo.
4. Tree terminology saare terms label karo.
5. Binary tree kya hota hai?
6. Skewed tree linked list jaisa kyun hota hai?
7. `struct Node { int data; Node* left; Node* right; }` explain karo.
8. Manual binary tree create karne ka code likho.
9. Inorder traversal rule kya hai?
10. Preorder traversal rule kya hai?
11. Postorder traversal rule kya hai?
12. Same tree ke teeno DFS outputs likho.
13. Inorder recursion call stack trace karo.
14. Preorder ka use tree copy me kyun hota hai?
15. Postorder tree delete ke liye useful kyun hai?
16. Level order height-loop approach O(n²) worst kyun?
17. Level order queue approach O(n) ka proof do.
18. Iterative inorder stack se kaise hota hai?
19. Height of tree formula kya hai?
20. Count nodes left+right+1 pattern explain karo.
21. Leaf node condition kya hai?
22. Normal tree me max element O(n) kyun?
23. Normal binary tree search O(n) kyun?
24. Diameter of tree kya hota hai?
25. Diameter through-root vs not-through-root cases explain karo.
26. Diameter optimized O(n) kaise hota hai?
27. BST property kya hai?
28. Insert 50,30,70,20,40 ka path diagram banao.
29. Recursive BST search and binary search connection explain karo.
30. Iterative BST search O(1) space kaise hota hai?
31. BST min/max kaise find karte hain?
32. BST inorder sorted kyun hota hai?
33. BST delete ke 3 cases explain karo.
34. Inorder successor kya hota hai?
35. Validate BST min/max range approach explain karo.
36. kth smallest in BST kaise find karoge?
37. Mirror tree recursively kaise banta hai?
38. Identical trees check ka algorithm kya hai?
39. Sum of all nodes ka recursion formula kya hai?
40. Height balanced tree definition kya hai?
41. Balanced check naive vs optimized compare karo.
42. Same level k sum ka recursive formula kya hai?
43. LCA in BST paths diverge kaise identify karte hain?
44. LCA in binary tree recursion magic explain karo.
45. Top view me horizontal distance ka role kya hai?
46. Left view first node each level se kaise aata hai?
47. Zigzag level order me direction flag ka use kya hai?
48. Max path sum me gain and global best difference kya hai?
49. Serialize/deserialize me `#` null markers kyun zaruri hain?
50. Tree problem solve karte time pehle kya identify karoge: DFS, BFS, BST property, or global answer?

---

## How to study this module

1. `01_Tree_Intro` me terminology tree manually draw karo.
2. `02_Tree_Traversals` me same tree ke inorder/preorder/postorder outputs yaad karo.
3. Level order queue state copy me draw karo.
4. `03_Tree_Properties` me height/count/leaves/max/search formulas practice karo.
5. Diameter naive vs optimized dry run zaroor karo.
6. `04_Binary_Search_Tree_BST` me insert/search/delete diagrams manually banao.
7. BST inorder sorted property ko kth smallest/validate use cases se connect karo.
8. `05_Tree_Problems_Easy` me mirror, identical, balanced optimized practice karo.
9. `06_Tree_Problems_Medium` me LCA, views, zigzag, max path, serialize patterns solve karo.
10. Har subfolder ka `task.cpp` pehle khud solve karo, phir lesson files se compare karo.
