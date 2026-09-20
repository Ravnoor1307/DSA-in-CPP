/*
REAL-WORLD SCENARIO:
Marks list ko ascending order me arrange karna hai using priority logic.

TASKS easy -> hard:
1. `heapifyDown` implement karo.
2. `buildMaxHeap` implement karo.
3. Root max ko last active index se swap karo.
4. Heap size reduce karke root heapify karo.
5. [4,10,3,5,1] dry run print karo.
6. Heap sort vs merge/quick comparison comments me likho.

HINTS:
- Build heap starts from n/2 - 1.
- Extraction loop: for end=n-1 to 1.
- Sorted zone array ke right side me grow hota hai.

STARTER CODE:
void heapSort(vector<int>& a) { // write build + extract loop }

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& a) {
    for (int x : a) cout << x << ' ';
    cout << "\n";
}

void heapifyDown(vector<int>& a, int n, int i) {
    while (true) {
        int l = 2*i+1, r = 2*i+2, largest = i;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--) heapifyDown(a, n, i); // Bottom-up build heap.
    for (int end = n - 1; end > 0; end--) {
        swap(a[0], a[end]);       // Current max final sorted position me.
        heapifyDown(a, end, 0);   // Sorted zone exclude karke heap repair.
    }
}

int main() {
    vector<int> a = {4, 10, 3, 5, 1};
    heapSort(a);
    print(a);
    return 0;
}

/*
OUTPUT:
1 3 4 5 10
*/
