/*
=======================================================================
 THEORY : Binary Search
=======================================================================
 1. WHAT IT DOES
    - Finds the index of a target in a SORTED array in O(log n) time
      by repeatedly HALVING the search space.
    - Requirement: the array MUST be sorted. On unsorted data the
      answer is meaningless.

 2. ALGORITHM (iterative)
      1) low = 0, high = n-1
      2) while low <= high:
            mid = low + (high - low)/2     // avoids overflow
            if  arr[mid] == target -> return mid
            else if arr[mid] <  target -> low  = mid + 1  (ignore left)
            else                     -> high = mid - 1  (ignore right)
      3) return -1  (not found)

 3. WHY O(log n)?
    - Every step halves the search interval:
        n -> n/2 -> n/4 -> ... -> 1   takes log2(n) steps.
    - For n = 1e9, binary search needs only ~30 comparisons,
      while linear search could need a billion.

 4. IMPORTANT WORKSECTS
    - mid formula:  low + (high - low)/2  is BETTER than (low+high)/2
      because (low+high) can overflow for very large arrays.
    - The boundary updates (low = mid+1 / high = mid-1) guarantee the
      loop terminates and mid is never checked twice.

 5. WHEN TO USE
    - Search in sorted data, lower/upper bound queries, "answer
      binary search" used widely in competitive programming.

    Pseudo-code (reference - code will be added soon):

        int binary_search(int arr[], int n, int target) {
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target) return mid;
                arr[mid] < target ? low = mid + 1 : high = mid - 1;
            }
            return -1;
        }

 COMPLEXITY:
    Time  : O(log n) worst and average, O(1) best (mid hit at once)
    Space : O(1) (iterative version; recursive uses O(log n) stack)
=======================================================================
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int targets[] = {70, 10, 100, 55};
    for (int t = 0; t < 4; t++)
    {
        int target = targets[t];
        int result = binarySearch(arr, n, target);
        if (result != -1)
            cout << "Binary search for " << target << " -> found at index " << result << endl;
        else
            cout << "Binary search for " << target << " -> not found" << endl;
    }

    cout << "\nStep-by-step trace for target = 70:" << endl;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << "  low=" << low << " high=" << high << " mid=" << mid
             << " arr[mid]=" << arr[mid];
        if (arr[mid] == 70)
        {
            cout << " -> FOUND!" << endl;
            break;
        }
        else if (arr[mid] < 70)
        {
            cout << " -> low = mid+1" << endl;
            low = mid + 1;
        }
        else
        {
            cout << " -> high = mid-1" << endl;
            high = mid - 1;
        }
    }

    return 0;
}