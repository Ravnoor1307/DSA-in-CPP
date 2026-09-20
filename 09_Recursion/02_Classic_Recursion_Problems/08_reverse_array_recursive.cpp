/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 08_reverse_array_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Bookshelf reverse karne ke liye leftmost aur rightmost books swap karo, phir andar ki smaller shelf reverse karo. Ye two-pointer recursion hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Function reverseArray(arr,left,right).
│ 2. Base case: left >= right.
│ 3. Swap arr[left] and arr[right].
│ 4. Recursive call for inner subarray: left+1, right-1.
│ 5. Arrays wale two-pointer pattern ka recursive version hai.
│
│ ASCII VISUAL / RECURSION STATE:
│ arr = [1,2,3,4,5]
│
│ L             R  swap 1,5 -> [5,2,3,4,1]
│    L       R     swap 2,4 -> [5,4,3,2,1]
│       L          stop
│
│ Recursive calls:
│ rev(0,4) -> rev(1,3) -> rev(2,2) base
│
│ DRY RUN:
│ rev(0,4): swap 1 and 5
│ rev(1,3): swap 2 and 4
│ rev(2,2): base stop
│ final [5,4,3,2,1]
│
│ FLOW OF EXECUTION:
│ main -> choose classic formula -> recursive/iterative calls -> return/print answer
│
│ COMPLEXITY CALCULATION:
│ - Each call swaps one pair.
│ - Number of pairs = floor(n/2).
│ - Each call constant work.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion depth floor(n/2)+1.
│ -> Space Complexity = O(n) call stack.
│ APPROACH COMPARISON TABLE:
│ Iterative two-pointer = two hands swap books, O(n) time/O(1) space.
│ Recursive two-pointer = swap outer books then ask smaller shelf, O(n) time/O(n) stack.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseArrayRecursive(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    swap(arr[left], arr[right]);
    reverseArrayRecursive(arr, left + 1, right - 1); // andar ka smaller array
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    reverseArrayRecursive(arr, 0, (int)arr.size() - 1);
    cout << "Reversed array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Reversed array: 5 4 3 2 1
*/

