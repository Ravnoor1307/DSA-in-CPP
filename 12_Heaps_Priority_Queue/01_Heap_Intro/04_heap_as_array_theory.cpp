/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_heap_as_array_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Apartment building ke flats level-wise numbered hain. Flat number se parent floor aur child flats calculate ho jaate hain. Heap array formulas bhi exactly yehi mapping use karte hain.
│
│ VISUAL NOTES:
│ Tree + array side by side:
│
│              90(index0)
│            /            \
│      70(index1)       80(index2)
│       /      \          /
│ 20(index3) 30(index4) 60(index5)
│
│ Array:
│ index:  0   1   2   3   4   5
│ value: [90, 70, 80, 20, 30, 60]
│
│ FORMULAS (0-based):
│ parent(i) = (i - 1) / 2
│ left(i)   = 2*i + 1
│ right(i)  = 2*i + 2
│
│ Proof idea:
│ Level-order numbering me node i ke baad children slots pair me aate hain.
│ index0 children: 1,2 -> 2*0+1, 2*0+2
│ index1 children: 3,4 -> 2*1+1, 2*1+2
│ index2 children: 5,6 -> 2*2+1, 2*2+2
│
│ Dry run index 4:
│ value = 30
│ parent = (4-1)/2 = 3/2 = 1 -> value 70
│ left = 2*4+1 = 9 -> out of range
│ right = 2*4+2 = 10 -> out of range

│
│ DRY RUN / FLOW:
│ Real-world input -> identify priority -> maintain heap property -> answer fast.
│
│ COMPLEXITY CALCULATION:
│ parent/left/right calculation uses arithmetic only.
│ Fixed number of operations:
│ parent: subtract + divide = 2 constant ops.
│ left: multiply + add = 2 constant ops.
│ right: multiply + add = 2 constant ops.
│ Time = O(1).
│
│ Array of n heap elements -> O(n) storage.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

int main() {
    vector<int> heap = {90, 70, 80, 20, 30, 60};
    int i = 4;
    cout << "heap[index " << i << "] = " << heap[i] << "\n";
    int p = parent(i), l = leftChild(i), r = rightChild(i);
    cout << "parent index = (4-1)/2 = " << p << ", value = " << heap[p] << "\n";
    cout << "left child index = 2*4+1 = " << l << " -> " << (l < (int)heap.size() ? "exists" : "out of range") << "\n";
    cout << "right child index = 2*4+2 = " << r << " -> " << (r < (int)heap.size() ? "exists" : "out of range") << "\n";
    return 0;
}

/*
OUTPUT:
heap[index 4] = 30
parent index = (4-1)/2 = 1, value = 70
left child index = 2*4+1 = 9 -> out of range
right child index = 2*4+2 = 10 -> out of range
*/

