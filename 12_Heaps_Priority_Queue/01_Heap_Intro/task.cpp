/*
REAL-WORLD SCENARIO:
Emergency room triage system build karna hai jahan highest priority patient immediately accessible ho.

TASKS easy -> hard:
1. Max heap and min heap definition comments me likho.
2. Given index i, parent/left/right calculate karo.
3. Check karo vector max-heap property follow karta hai ya nahi.
4. Heap and BST difference table comments me likho.
5. Complete binary tree array mapping draw karo.
6. For i=4, parent/left/right dry run print karo.

HINTS:
- parent(i) = (i-1)/2
- left(i) = 2i+1
- right(i) = 2i+2
- parent >= children for max heap

STARTER CODE:
int parent(int i) { return ?; }
bool isMaxHeap(vector<int>& a) { ... }

SOLUTIONS are placed after this comment so pehle khud try karo.
*/

#include <iostream>
#include <vector>
using namespace std;

int parentIndex(int i) { return (i - 1) / 2; }
int leftIndex(int i) { return 2 * i + 1; }
int rightIndex(int i) { return 2 * i + 2; }

bool isMaxHeap(const vector<int>& a) {
    for (int i = 0; i < (int)a.size(); i++) {
        int l = leftIndex(i), r = rightIndex(i);
        if (l < (int)a.size() && a[i] < a[l]) return false; // parent chhota hua to rule break
        if (r < (int)a.size() && a[i] < a[r]) return false;
    }
    return true;
}

int main() {
    vector<int> heap = {90, 70, 80, 20, 30, 60};
    int i = 4;
    cout << "Index " << i << " parent=" << parentIndex(i)
         << " left=" << leftIndex(i) << " right=" << rightIndex(i) << "\n";
    cout << "Is max heap? " << (isMaxHeap(heap) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Index 4 parent=1 left=9 right=10
Is max heap? YES
*/
