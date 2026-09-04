/*
=======================================================================
 THEORY : Majority Element (Moore's Voting Algorithm)
=======================================================================
 1. WHAT PROBLEM DOES IT SOLVE?
    Given an array of size n, find the element that appears MORE THAN
    n/2 times (strictly greater than half).

    Example:
        arr = {2, 2, 1, 1, 1, 2, 2}   (n = 7)
        2 appears 4 times (> 7/2 = 3.5), so 2 is the majority element.
        Answer = 2.

    A majority element, if it exists, is UNIQUE:
    - Two different elements can NOT both appear more than n/2 times
      (their counts would sum to more than n).
    - n/2 times "strictly more" means count > n/2.
    - If n is even (n=8), majority needs count >= 5 (more than 4).
    - If n is odd (n=7), majority needs count >= 4 (more than 3.5).

 2. WHY IS THIS IMPORTANT?
    - Classic interview question (LeetCode 169 - Majority Element).
    - Demonstrates the Boyer-Moore Voting Algorithm, a brilliant
      O(n) time, O(1) space solution.
    - Teaches the trade-off: brute force -> hash map -> Moore's.

 3. APPROACH 1 -- BRUTE FORCE (O(n^2))
    For every element, count how many times it appears.
    If any count > n/2, that element is the majority.

        for i = 0 to n-1:
            count = 0
            for j = 0 to n-1:
                if arr[j] == arr[i]: count++
            if count > n/2: return arr[i]

    Pros:  Simple, no extra memory.
    Cons:  O(n^2) -- too slow for large n (10^5 -> 10^10 ops -> TLE).

 4. APPROACH 2 -- HASH MAP (O(n) time, O(n) space)
    Count frequencies using a hash map, then find the key with
    count > n/2.

        for each x in arr: freq[x]++
        for each (key, count) in freq:
            if count > n/2: return key

    Pros:  O(n) average time.
    Cons:  O(n) extra space for the map.

 5. APPROACH 3 -- SORTING (O(n log n))
    Sort the array. If a majority element exists (count > n/2),
    it MUST occupy the middle position n/2. Return arr[n/2].

    - After sorting, the majority (if any) lands in the middle.
    - Verify: count arr[n/2] to confirm it really is majority.
    - Time O(n log n) (sort), Space O(1) (in-place sort).

 6. APPROACH 4 -- MOORE'S VOTING ALGORITHM (O(n) time, O(1) space)
    THE optimal solution. Works in two passes:

    PASS 1 (candidate selection):
        candidate = arr[0], count = 1
        for i = 1 to n-1:
            if arr[i] == candidate: count++
            else: count--
            if count == 0:
                candidate = arr[i]
                count = 1

    PASS 2 (verification):
        Count how many times candidate appears.
        If count > n/2 -> candidate is majority, else no majority.

    WHY IT WORKS (key insight):
    - The algorithm CANCELLS equal pairs of different elements.
    - If a majority element M exists, M appears > n/2 times. Even after
      cancelling every M with a distinct element, at least one M is left.
    - So the final surviving candidate CAN be M.
    - BUT the algorithm does NOT guarantee the candidate is majority --
      it only guarantees that IF a majority exists, it is this candidate.
      Therefore an O(n) VERIFICATION pass is mandatory.

    TOTAL: O(n) time (two passes), O(1) space.

 7. WHY WE MUST VERIFY (crucial detail)
    Moore's algorithm finds a POSSIBLE majority, not a guaranteed one.
    Example: {1, 2, 3, 4, 5} -- no majority, but the algorithm returns
    some candidate. We MUST count it in a second pass to confirm
    count > n/2. Never skip the verification pass.

 8. EDGE CASES
    - No majority element -> return -1 / print "no majority".
    - n = 1 -> the single element is trivially the majority.
    - All same element -> it is the majority (appears n times > n/2).
    - n = 2 different -> neither appears more than once -> no majority.

 9. COMPLEXITY SUMMARY

    | Approach           | Time       | Space | Notes              |
    |--------------------|------------|-------|--------------------|
    | Brute force        | O(n^2)     | O(1)  | nested counting    |
    | Hash map           | O(n) avg   | O(n)  | extra memory       |
    | Sorting            | O(n log n) | O(1)  | sort + middle      |
    | Moore's voting     | O(n)       | O(1)  | BEST - 2 passes    |

 10. KEY TAKEAWAY
    For finding a majority element, Moore's Voting Algorithm is optimal:
    O(n) time and O(1) space. The survey is easily extended to related
    problems (e.g. "elements appearing more than n/3 times" needs two
    candidates; "more than n/4" needs three, etc.).

11. HOW TO CALCULATE THESE COMPLEXITIES (step by step)
    Step A - Input size n = array length.
    Step B - Brute force: outer i (n times), inner j counts occurrences
             (n times) -> n*n = O(n^2), O(1) space.
    Step C - Hash map: one n-loop doing O(1) average inserts, then an
             O(n) scan to find the key with count > n/2. Sequential,
             so ADD -> O(n) total. Up to n distinct keys -> O(n) space.
    Step D - Sorting: sort = O(n log n); the position-n/2 check is a
             single O(n) verification pass, sequential, keep largest
             -> O(n log n), O(1) space.
    Step E - Moore's: TWO loops, each O(n), sequential (ADD) -> O(n)
             time. Only one candidate + one count -> O(1) space.
    Step F - Decision: at n = 1,000,000, brute force = 10^12 ops (TLE);
             hash = 10^6 ops but needs extra memory; Moore's = 10^6 ops
             with ZERO extra memory -> Moore's is the BEST approach on
             BOTH time and space.
=======================================================================
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// ----------------------------------------------------------------
// APPROACH 1 : BRUTE FORCE - O(n^2)
// ----------------------------------------------------------------
// For each element count its occurrences. If count > n/2, it is majority.
// Uses raw array. Returns -1 if no majority.
int majorityBruteForceArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > n / 2)
            return arr[i];
    }
    return -1;
}

// Same logic using vector.
int majorityBruteForceVector(const vector<int> &v)
{
    int n = (int)v.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == v[i])
                count++;
        }
        if (count > n / 2)
            return v[i];
    }
    return -1;
}

// ----------------------------------------------------------------
// APPROACH 2 : HASH MAP - O(n) time, O(n) space
// ----------------------------------------------------------------
// Count frequencies with a map, then find the key with count > n/2.
int majorityHashMap(const vector<int> &v)
{
    int n = (int)v.size();
    map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[v[i]]++; // O(log n) per insert for map; O(1) avg for unordered_map

    for (auto &entry : freq)
    {
        if (entry.second > n / 2)
            return entry.first;
    }
    return -1;
}

// ----------------------------------------------------------------
// APPROACH 3 : SORTING - O(n log n)
// ----------------------------------------------------------------
// Sort, then the majority (if any) is arr[n/2]. Verify it.
int majoritySorting(vector<int> v) // pass by value -- we sort a copy
{
    int n = (int)v.size();
    sort(v.begin(), v.end());

    int candidate = v[n / 2];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == candidate)
            count++;
    }
    return (count > n / 2) ? candidate : -1;
}

// ----------------------------------------------------------------
// APPROACH 4 : MOORE'S VOTING ALGORITHM - O(n) time, O(1) space
// ----------------------------------------------------------------
// Pass 1 finds a candidate, Pass 2 verifies it.
int majorityMoores(const vector<int> &v)
{
    int n = (int)v.size();
    if (n == 0)
        return -1;

    // PASS 1 : Find candidate
    int candidate = v[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] == candidate)
            count++;
        else
            count--;

        if (count == 0)
        {
            candidate = v[i];
            count = 1;
        }
    }

    // PASS 2 : Verify candidate actually appears > n/2 times
    int verify = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == candidate)
            verify++;
    }

    return (verify > n / 2) ? candidate : -1;
}

// ----------------------------------------------------------------
// HELPER : Print result nicely
// ----------------------------------------------------------------
void printResult(const string &label, int value)
{
    cout << label;
    if (value == -1)
        cout << "no majority element" << endl;
    else
        cout << "majority element = " << value << endl;
}

// ----------------------------------------------------------------
// MAIN
// ----------------------------------------------------------------
int main()
{
    // ---- Demo 1 : Classic example (2 is the majority) ----
    vector<int> v1 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Array 1 : 2 2 1 1 1 2 2   (n=7, majority needs count>3)" << endl;
    cout << "--------------------------------------------" << endl;
    printResult("  Brute force   : ", majorityBruteForceArray(v1.data(), v1.size()));
    printResult("  Hash map      : ", majorityHashMap(v1));
    printResult("  Sorting       : ", majoritySorting(v1));
    printResult("  Moore's voting: ", majorityMoores(v1));
    cout << endl;

    // ---- Demo 2, 3, 4 : Same element appears in all three arrays ----
    int a2[] = {1, 1, 2, 1, 3, 5, 1};
    int a3[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int a4[] = {3, 3, 4, 2, 4, 4, 2, 4};

    cout << "Array 2 : 1 1 2 1 3 5 1       (majority = 1)" << endl;
    printResult("  Moore's voting: ", majorityMoores(vector<int>(a2, a2 + 7)));
    printResult("  Brute force   : ", majorityBruteForceArray(a2, 7));
    cout << endl;

    cout << "Array 3 : 3 3 4 2 4 4 2 4 4   (majority = 4)" << endl;
    printResult("  Moore's voting: ", majorityMoores(vector<int>(a3, a3 + 9)));
    cout << endl;

    cout << "Array 4 : 3 3 4 2 4 4 2 4     (NO majority)" << endl;
    printResult("  Moore's voting: ", majorityMoores(vector<int>(a4, a4 + 8)));
    cout << endl;

    // ---- Demo 5 : No majority ----
    vector<int> v5 = {1, 2, 3, 4, 5};
    cout << "Array 5 : 1 2 3 4 5           (NO majority)" << endl;
    printResult("  Brute force   : ", majorityBruteForceVector(v5));
    printResult("  Hash map      : ", majorityHashMap(v5));
    printResult("  Sorting       : ", majoritySorting(v5));
    printResult("  Moore's voting: ", majorityMoores(v5));
    cout << endl;

    // ---- Demo 6 : Single element ----
    vector<int> v6 = {7};
    cout << "Array 6 : 7                   (single, majority = 7)" << endl;
    printResult("  Moore's voting: ", majorityMoores(v6));
    cout << endl;

    return 0;
}
