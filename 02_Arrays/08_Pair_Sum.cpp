/*
=======================================================================
 THEORY : Pair Sum -- Finding Two Elements That Add to a Target
=======================================================================
 1. WHAT PROBLEM DOES IT SOLVE?
    Given an array and a target sum, find ALL pairs of elements
    (two distinct indices i, j where i < j) whose values add up
    to the target.

    Example:
        arr = {2, 7, 11, 15, 1, 8}, target = 9
        Pairs: (2,7) and (1,8) -> indices (0,1) and (4,5)

 2. WHY IS THIS IMPORTANT?
    - Classic interview warm-up (LeetCode 1 -- Two Sum variant).
    - Builds the foundation for Three Sum, Four Sum, and subarray
      problems.
    - Teaches the trade-off between brute force and optimal.

 3. APPROACH 1 -- BRUTE FORCE (O(n^2))
    Check EVERY possible pair (i, j) where i < j:
        for i = 0 to n-1:
            for j = i+1 to n-1:
                if arr[i] + arr[j] == target -> print pair

    Pros:  Works on UNSORTED arrays. No extra memory.
    Cons:  Slow for large n (10^5 elements -> 10^10 ops -> TLE).

 4. APPROACH 2 -- SORTING + TWO POINTERS (O(n log n))
    ONLY works on SORTED arrays:
        1. Sort the array first (if not already sorted).
        2. Place one pointer at the start (left = 0) and one at
           the end (right = n-1).
        3. While left < right:
               sum = arr[left] + arr[right]
               if sum == target -> found pair, move both inward
               if sum < target  -> need larger sum, move left++
               if sum > target  -> need smaller sum, move right--
        4. When left meets right, stop.

    Why it works:
        - Moving left++ INCREASES the sum (larger left value).
        - Moving right-- DECREASES the sum (smaller right value).
        - Each element is visited at most once -> O(n) after sort.

    Total: O(n log n) sort + O(n) scan = O(n log n).

 5. APPROACH 3 -- HASHING (O(n) average, unsorted arrays)
    For UNSORTED arrays, use a hash set:
        for each element x:
            if (target - x) is in the set -> found pair
            else add x to the set

    Pros:  O(n) time. Works on unsorted data.
    Cons:  O(n) extra space. Worst case O(n^2) with hash collisions.

 6. ARRAYS vs VECTORS
    - Arrays: fixed size, stack-allocated, pass size separately.
    - Vectors: dynamic size, heap-allocated, know their own size.
    - The two-pointer logic is IDENTICAL; only the container
      interface differs (v.size() vs n, v[i] vs arr[i]).

 7. PRINTING ALL PAIRS (no target, just enumerate)
    Useful for understanding the brute force pattern:
        for i = 0 to n-1:
            for j = i+1 to n-1:
                print (arr[i], arr[j])

    Total pairs = n*(n-1)/2. Time O(n^2), Space O(1).

 8. EDGE CASES
    - No pair sums to target -> print "no pair found".
    - Multiple pairs with same value -> print all (no early exit).
    - Duplicate elements -> depends on problem statement:
        * "indices must differ" -> (2,2) at different indices is OK.
        * "distinct values" -> skip pairs where arr[i] == arr[j].
    - Array size < 2 -> no pairs possible.

 9. COMPLEXITY SUMMARY

    | Approach               | Time       | Space | Sorted needed? |
    |------------------------|------------|-------|----------------|
    | Brute force            | O(n^2)     | O(1)  | No             |
    | Sort + two pointers    | O(n log n) | O(1)  | Yes (or sort)  |
    | Hash set               | O(n) avg   | O(n)  | No             |

 10. KEY TAKEAWAY
    If the array is ALREADY SORTED, two pointers is the best
    choice: O(n) scan, O(1) space. If unsorted, decide between
    sorting first (O(n log n)) or hashing (O(n) but O(n) space).

 11. HOW TO CALCULATE THESE COMPLEXITIES (step by step)
    Step A - Input size n = array length.
    Step B - Brute force: outer i (n times), inner j (i+1..n-1).
             Count = n(n-1)/2 (triangular) -> O(n^2), O(1) space.
    Step C - Sort + two pointers: two SEQUENTIAL parts.
             Sort = O(n log n). The scan moves left/right each at most
             n times total -> O(n). Sequential blocks ADD, so we keep
             the larger -> O(n log n). O(1) space.
    Step D - Hash set: one n-loop doing O(1) average hashing -> O(n)
             time; the set can hold up to n keys -> O(n) space.
    Step E - Decision: at n = 100,000, brute force = ~10^10 ops (TLE).
             Both O(n log n) and O(n) fit the ~10^8 budget. If memory
             is limited choose sort+two-pointers (O(1) space); if time
             is the only concern hash set is fastest. The "best" = the
             simplest approach that FITS the constraints.
=======================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ----------------------------------------------------------------
// 1) PRINT ALL PAIRS -- O(n^2) brute force enumeration
// ----------------------------------------------------------------
// Prints every unique pair (i, j) where i < j.
// Uses raw arrays.
void printAllPairsArray(int arr[], int n)
{
    cout << "All pairs (array):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "  (" << arr[i] << ", " << arr[j] << ")" << endl;
        }
    }
}

// Same logic using vectors.
void printAllPairsVector(const vector<int> &v)
{
    cout << "All pairs (vector):" << endl;
    for (int i = 0; i < (int)v.size(); i++)
    {
        for (int j = i + 1; j < (int)v.size(); j++)
        {
            cout << "  (" << v[i] << ", " << v[j] << ")" << endl;
        }
    }
}

// ----------------------------------------------------------------
// 2) BRUTE FORCE PAIR SUM -- O(n^2)
// ----------------------------------------------------------------
// Finds and prints every pair whose sum equals target.
// Works on UNSORTED arrays. Uses raw arrays.
void pairSumBruteForceArray(int arr[], int n, int target)
{
    cout << "Brute force pair sum = " << target << " (array):" << endl;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << "  (" << arr[i] << ", " << arr[j]
                     << ") at indices (" << i << ", " << j << ")" << endl;
                found = true;
            }
        }
    }
    if (!found)
        cout << "  no pair found" << endl;
}

// Same logic using vectors.
void pairSumBruteForceVector(const vector<int> &v, int target)
{
    cout << "Brute force pair sum = " << target << " (vector):" << endl;
    bool found = false;
    for (int i = 0; i < (int)v.size(); i++)
    {
        for (int j = i + 1; j < (int)v.size(); j++)
        {
            if (v[i] + v[j] == target)
            {
                cout << "  (" << v[i] << ", " << v[j]
                     << ") at indices (" << i << ", " << j << ")" << endl;
                found = true;
            }
        }
    }
    if (!found)
        cout << "  no pair found" << endl;
}

// ----------------------------------------------------------------
// 3) TWO-POINTERS PAIR SUM -- O(n) on SORTED array
// ----------------------------------------------------------------
// Requires the array to be SORTED in ascending order.
// Uses raw arrays.
void pairSumTwoPointersArray(int arr[], int n, int target)
{
    cout << "Two-pointer pair sum = " << target << " (array):" << endl;
    int left = 0, right = n - 1;
    bool found = false;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            cout << "  (" << arr[left] << ", " << arr[right]
                 << ") at indices (" << left << ", " << right << ")" << endl;
            found = true;
            left++;
            right--;
        }
        else if (sum < target)
        {
            left++; // need a larger sum
        }
        else
        {
            right--; // need a smaller sum
        }
    }
    if (!found)
        cout << "  no pair found" << endl;
}

// Same logic using vectors.
void pairSumTwoPointersVector(const vector<int> &v, int target)
{
    cout << "Two-pointer pair sum = " << target << " (vector):" << endl;
    int left = 0, right = (int)v.size() - 1;
    bool found = false;
    while (left < right)
    {
        int sum = v[left] + v[right];
        if (sum == target)
        {
            cout << "  (" << v[left] << ", " << v[right]
                 << ") at indices (" << left << ", " << right << ")" << endl;
            found = true;
            left++;
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    if (!found)
        cout << "  no pair found" << endl;
}

// ----------------------------------------------------------------
// MAIN
// ----------------------------------------------------------------
int main()
{
    // --- Demo 1: Print all pairs (small array) ---
    int small[] = {1, 2, 3};
    int sn = sizeof(small) / sizeof(small[0]);
    cout << "========== PRINT ALL PAIRS ==========" << endl;
    printAllPairsArray(small, sn);
    cout << endl;

    vector<int> sv = {1, 2, 3};
    printAllPairsVector(sv);
    cout << endl;

    // --- Demo 2: Brute force pair sum (unsorted) ---
    int arr1[] = {8, 7, 2, 5, 3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "========== BRUTE FORCE (unsorted) ==========" << endl;
    pairSumBruteForceArray(arr1, n1, 10);
    cout << endl;

    vector<int> v1 = {8, 7, 2, 5, 3, 1};
    pairSumBruteForceVector(v1, 10);
    cout << endl;

    // --- Demo 3: Two-pointer pair sum (sorted) ---
    // Same data but sorted for two-pointer approach.
    int arr2[] = {1, 2, 3, 5, 7, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "========== TWO-POINTER (sorted) ==========" << endl;
    pairSumTwoPointersArray(arr2, n2, 10);
    cout << endl;

    vector<int> v2 = {1, 2, 3, 5, 7, 8};
    pairSumTwoPointersVector(v2, 10);
    cout << endl;

    // --- Demo 4: Edge cases ---
    cout << "========== EDGE CASES ==========" << endl;
    pairSumBruteForceArray(arr1, n1, 100);
    cout << endl;

    int single[] = {5};
    pairSumBruteForceArray(single, 1, 10);
    cout << endl;

    return 0;
}
