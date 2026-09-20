/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_recursive_binary_search.cpp
│
│ REAL-WORLD SCENARIO:
│ Sorted dictionary me middle page check karke half pages discard karte ho. Recursive binary search bhi sorted array ko half problem me reduce karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Array sorted hona chahiye.
│ 2. Base case: low > high, target absent.
│ 3. mid = low + (high-low)/2.
│ 4. If arr[mid]==target, found.
│ 5. If target smaller, recurse left half.
│ 6. If target bigger, recurse right half.
│
│ ASCII VISUAL / RECURSION TREE STATE:
│ arr = [2,4,6,8,10,12], target=10
│ low=0 high=5 mid=2 value6
│ 10 > 6 -> search right half [8,10,12]
│ low=3 high=5 mid=4 value10 FOUND
│
│ Half reduction visual:
│ n -> n/2 -> n/4 -> ... -> 1
│
│ DRY RUN:
│ call(0,5): mid2 val6, right
│ call(3,5): mid4 val10, found index4
│
│ FLOW OF EXECUTION:
│ input/problem state -> recursive choices -> base cases -> undo/unwind/output
│
│ COMPLEXITY CALCULATION:
│ - Each call halves the search range.
│ - After k calls, size = n/2^k.
│ - Stop when n/2^k = 1.
│ - n = 2^k -> k = log₂n.
│ -> Time Complexity = O(log n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion depth log₂n.
│ -> Space Complexity = O(log n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int binarySearchRec(const vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    cout << "search low=" << low << " high=" << high << " mid=" << mid << " value=" << arr[mid] << "\n";
    if (arr[mid] == target) return mid;
    if (target < arr[mid]) return binarySearchRec(arr, low, mid - 1, target);
    return binarySearchRec(arr, mid + 1, high, target);
}

int main() {
    vector<int> arr = {2,4,6,8,10,12};
    cout << "Found index = " << binarySearchRec(arr, 0, (int)arr.size()-1, 10) << "\n";
    return 0;
}

/*
OUTPUT:
Found index = search low=0 high=5 mid=2 value=6
search low=3 high=5 mid=4 value=10
4
*/

