/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_why_trees_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Family tree, company org chart, file explorer, and DOM me hierarchy hoti hai. Linear array/linked list sirf next-next relation dikha sakte hain; parent-child hierarchy ke liye tree natural hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Linear structures me elements one after another hote hain.
│ 2. Hierarchical data me ek parent ke multiple children ho sakte hain.
│ 3. Tree root se start hota hai and branches children tak jaati hain.
│ 4. File explorer: folder ke andar folder, phir file.
│ 5. DOM: HTML element ke andar nested elements.
│ 6. Tree traversal/search hierarchical relationships follow karta hai.
│
│ ASCII VISUAL / TREE STATE:
│ Linear list:
│ [CEO] -> [Manager] -> [Employee] -> [Intern]
│ Problem: CEO ke multiple managers ka relation clear nahi.
│
│ Tree / org chart:
│                 CEO
│              /   |   \
│          HR     Tech   Sales
│                /    \
│             Dev1    Dev2
│
│ File explorer:
│ root/
│ ├── docs/
│ │   └── notes.txt
│ └── images/
│     └── logo.png
│
│ DRY RUN:
│ Need represent company:
│ CEO has HR, Tech, Sales.
│ Tech has Dev1 and Dev2.
│ A linked list would force one chain, but tree keeps real hierarchy.
│
│ FLOW OF EXECUTION:
│ main -> create/describe tree -> pointer/term logic -> output
│
│ COMPLEXITY CALCULATION:
│ - Theory demo prints fixed lines only.
│ - If a tree with n nodes is traversed, each node visited once.
│ -> Traversal Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - A tree stores n nodes and n-1 edges.
│ -> Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    cout << "Linear: CEO -> Manager -> Employee cannot show many branches clearly.\n";
    cout << "Tree: one root with parent-child hierarchy.\n";
    cout << "Examples: family tree, org chart, file explorer, DOM.\n";
    return 0;
}

/*
OUTPUT:
Linear: CEO -> Manager -> Employee cannot show many branches clearly.
Tree: one root with parent-child hierarchy.
Examples: family tree, org chart, file explorer, DOM.
*/

