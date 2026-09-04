/*
=======================================================================
 THEORY : Kadane's Algorithm (Maximum Subarray Sum)
=======================================================================
 1. WHAT PROBLEM DOES IT SOLVE?
    Given an array of integers (which may contain NEGATIVE numbers),
    find the CONTIGUOUS subarray with the LARGEST sum, and output
    that maximum sum.

    Example:
        arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }
        The max subarray is {4, -1, 2, 1} whose sum = 6.
        Answer = 6.

 2. KEY CONCEPT
    Instead of checking every subarray (O(n^2) / O(n^3)), we keep a
    running sum while scanning the array ONCE (single pass):

        current_sum = max(current element alone,
                          current element + previous running sum)

    In other words:
        current_sum = max(arr[i], current_sum + arr[i])

    - If the running sum so far becomes NEGATIVE, it is NEVER useful
      to keep it — starting fresh from the current element is better.
    - We track the best (maximum) of all current sums seen so far.

    This is a textbook application of the principle:
        "don't carry forward a burden that only makes the answer worse."

 3. THE ALGORITHM (steps)
    1) initialise:
          current_sum = 0  (running total for the subarray we build)
          best_sum    = arr[0]  (best answer seen so far)
    2) for each element a[i] (i starting from 0):
          current_sum = max(a[i], current_sum + a[i])
          best_sum    = max(best_sum, current_sum)
    3) after the loop, best_sum holds the maximum subarray sum.

 4. WHY "max(a[i], current_sum + a[i])" WORKS
    - current_sum + a[i]  : extend the current subarray.
    - a[i]                : start a NEW subarray at i.
    - If current_sum is negative, current_sum + a[i] < a[i], so we
      start fresh. A negative prefix can never help maximise a sum.

 5. FDGE CASES (very important for interviews)
    - All negative numbers:
         For {-3, -1, -2}, the answer is -1 (the LEAST negative one).
         We must initialise best_sum = arr[0] (NOT 0), and use the
         "start new subarray" rule, otherwise empty subarray (sum 0)
         would wrongly win. With our form it correctly gives -1.
    - All positive numbers: the whole array is the answer.
    - Empty / size-0 array: handle separately (return 0 / handle in
      caller). We keep a non-empty array for the demo.

 6. COMPLEXITY (this is THE whole point of Kadane)
        Time  : O(n)   — single pass through the array. Best possible
                 (we must at least look at every element).
        Space : O(1)   — only two integer variables, no extra array.

 6b. HOW TO CALCULATE THE COMPLEXITY (step by step)
    Step A - Input size n = array length.
    Step B - Dominant operation = one pass, visiting each element once.
    Step C - Print-all-subarrays uses 3 nested loops -> n(n+1)/2 subarrays
             each printed in O(n) -> O(n^3).
             Brute-force max sum uses 2 nested loops -> n(n+1)/2 starts
             without printing -> O(n^2). Kadane uses a SINGLE loop.
    Step D - Kadane: exactly n iterations, O(1) work each -> O(n); two
             integer variables -> O(1) space.
    Step E - Decision: at n = 100,000, O(n^2) = 10^10 ops (TLE vs the
             ~10^8 budget) while Kadane = 10^5 ops (instant) ->
             Kadane is the best approach, and O(n) is optimal (we must
             look at every element).

 7. COMPARISON WITH OTHER APPROACHES (shown in this file)
        Brute force (3 nested loops)  : O(n^3)
        Brute force (2 nested loops)   : O(n^2)   -- used below
        Kadane's algorithm             : O(n)
    For n = 100,000: O(n^2) is ~10^10 ops (too slow), Kadane is
    ~10^5 ops (instant). This contrast is why Kadane matters.

 8. RECONSTRUCTING THE ACTUAL SUBARRAY (bonus)
    To also print WHICH elements form the max subarray, track where
    the best subarray starts and ends:
      - when current_sum resets to arr[i]  -> new start = i
      - when best_sum updates              -> record start & end = i
    We include a variant below that prints the subarray itself too.

 9. COMMON INTERVIEW VARIANTS
    - Return the max sum only.  (simplest)
    - Return the start & end indices of the best subarray.
    - 2-D variants (max sum rectangle) build on the 1-D idea.
    - Circular array variant (two Kadane passes).
=======================================================================
*/

#include <iostream>
using namespace std;

// --------------------------------------------------------------------
// PART 1 : Print ALL possible subarrays (every contiguous segment)
// --------------------------------------------------------------------
// A subarray is any contiguous slice a[l..r] (0 <= l <= r < n).
// Fix the LEFT index l with an outer loop and the RIGHT index r with
// an inner loop; a third loop prints elements from l to r.
// Number of subarrays = n*(n+1)/2.
// Time: O(n^3) here (printing itself costs O(n) per subarray).
void printAllSubarrays(int arr[], int n)
{
    cout << "ALL SUBARRAYS of the array:" << endl;
    int count = 0;
    for (int l = 0; l < n; l++) // start index
    {
        for (int r = l; r < n; r++) // end index  (r >= l)
        {
            cout << "[ ";
            for (int k = l; k <= r; k++) // print elements from l..r
            {
                cout << arr[k] << " ";
            }
            cout << "]  ";
            count++;
        }
        cout << endl; // new line after finishing one start index
    }
    cout << "Total number of subarrays = " << count << "  (n*(n+1)/2)"
         << endl
         << endl;
}

// --------------------------------------------------------------------
// PART 2 : BRUTE FORCE - Maximum subarray sum (O(n^2), no extra memory)
// --------------------------------------------------------------------
// Fix every possible start l and every possible end r, compute the
// sum of that slice by ACCUMULATING as r grows (avoids the inner
// printing loop -> O(n^2) instead of O(n^3)).
// Time O(n^2), Space O(1).
int bruteForceMaxSum(int arr[], int n)
{
    int maxSum = arr[0]; // handle all-negative later
    for (int l = 0; l < n; l++)
    {
        int currentSum = 0; // sum of a[l..r]
        for (int r = l; r < n; r++)
        {
            currentSum += arr[r]; // extend slice by one
            if (currentSum > maxSum)
                maxSum = currentSum;
        }
    }
    return maxSum;
}

// --------------------------------------------------------------------
// PART 3 : KADANE'S ALGORITHM - O(n) single pass
// --------------------------------------------------------------------
// Maintain a running sum; if it turns negative, discard it (start a
// new subarray from the current element). Track the best seen.
int kadaneMaxSum(int arr[], int n)
{
    int currentSum = 0;
    int bestSum = arr[0]; // so all-negative arrays still work
    for (int i = 0; i < n; i++)
    {
        currentSum = max(arr[i], currentSum + arr[i]); // extend or reset
        bestSum = max(bestSum, currentSum);
    }
    return bestSum;
}

// --------------------------------------------------------------------
// PART 4 : KADANE'S that also RECONSTRUCTS the best subarray itself
// --------------------------------------------------------------------
void kadaneWithSubarray(int arr[], int n)
{
    int currentSum = 0;
    int bestSum = arr[0];
    int start = 0, end = 0; // current window [start..i]
    int bestStart = 0, bestEnd = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > currentSum + arr[i])
        {
            // starting a NEW subarray at i is better than extending
            currentSum = arr[i];
            start = i;
        }
        else
        {
            currentSum = currentSum + arr[i]; // extend existing
        }

        if (currentSum > bestSum)
        {
            bestSum = currentSum;
            bestStart = start;
            bestEnd = i;
        }
    }

    cout << "Kadane + reconstruction : max sum = " << bestSum
         << "  ->  subarray = [ ";
    for (int k = bestStart; k <= bestEnd; k++)
        cout << arr[k] << " ";
    cout << "]" << endl
         << endl;
}

int main()
{
    int array[10] = {1, 2, 4, 5, 3, 7, 2, 8, 16, 19};
    int n = sizeof(array) / sizeof(array[0]);

    // Print the array first
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl
         << endl;

    // 1) All possible subarrays
    printAllSubarrays(array, n);

    // 2) Brute-force maximum subarray sum
    cout << "Brute force max subarray sum : " << bruteForceMaxSum(array, n) << endl;

    // 3) Kadane's algorithm (O(n))
    cout << "Kadane max subarray sum       : " << kadaneMaxSum(array, n) << endl;

    // 4) Kadane + the actual subarray
    kadaneWithSubarray(array, n);

    // ----------------------------------------------------------------
    // DEMONSTRATION with NEGATIVE numbers (why initialise best=arr[0])
    // ----------------------------------------------------------------
    int mixed[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int m = sizeof(mixed) / sizeof(mixed[0]);

    cout << "Demo array with negatives: ";
    for (int i = 0; i < m; i++)
        cout << mixed[i] << " ";
    cout << endl;
    cout << "Brute force max sum : " << bruteForceMaxSum(mixed, m) << endl;
    cout << "Kadane max sum      : " << kadaneMaxSum(mixed, m) << endl;
    kadaneWithSubarray(mixed, m);

    // All-negative edge case
    int neg[] = {-3, -1, -2};
    int N = sizeof(neg) / sizeof(neg[0]);
    cout << "All-negative array {-3,-1,-2} -> Kadane max sum = "
         << kadaneMaxSum(neg, N) << " (the least negative, -1)" << endl;

    return 0;
}