/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_search_in_matrix_approach2_rowwise_bs.cpp
│
│ REAL-WORLD SCENARIO:
│ Library me har shelf sorted hai. Har shelf par binary search karoge, to linear shelf scan se fast ho jayega.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Condition: each row sorted honi chahiye.
│ 2. Har row ke liye binary search apply karo.
│ 3. Binary search mid compare karta hai.
│ 4. Target chhota ho to right half discard.
│ 5. Target bada ho to left half discard.
│ 6. Rows unsorted overall ho sakti hain, but each row sorted enough for this approach.
│
│ ASCII VISUAL / PATH DIAGRAM:
│ Matrix rows sorted:
│ 1  3  5  7
│ 10 11 16 20
│ 23 30 34 60
│ target=16
│
│ Row 0 BS -> not found
│ Row 1 BS -> mid values lead to 16 FOUND
│
│ DRY RUN:
│ Row1 [10,11,16,20]
│ low=0, high=3, mid=1 -> 11 < 16, low=2
│ low=2, high=3, mid=2 -> 16 found
│
│ FLOW OF EXECUTION:
│ matrix setup -> choose traversal/search pattern -> update pointers/bounds -> output
│
│ COMPLEXITY CALCULATION:
│ - There are R rows.
│ - Binary search on one row of C elements halves search space each step.
│ - C/2^k = 1 -> C = 2^k -> k = log₂C.
│ - Total = R * log₂C.
│ -> Time Complexity = O(R log C).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Binary search iterative variables low/high/mid only.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool binarySearchRow(const vector<int>& row, int target) {
    int low = 0, high = (int)row.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << "mid value " << row[mid] << "\n";
        if (row[mid] == target) return true;
        if (row[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> A = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 16;
    bool found = false;
    for (int r = 0; r < (int)A.size(); r++) {
        cout << "Search row " << r << "\n";
        if (binarySearchRow(A[r], target)) {
            found = true;
            break;
        }
    }
    cout << "Found? " << (found ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Search row 0
mid value 3
mid value 5
mid value 7
Search row 1
mid value 11
mid value 16
Found? YES
*/

