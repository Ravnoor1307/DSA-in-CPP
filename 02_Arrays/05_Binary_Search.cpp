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

 NOTE: This file currently contains NO runnable code.
       A complete working implementation lives inside the notes file
       (DSA_Complete_Notes.ipynb) as well as the topic file
       01_C++_Basics/00_Complexity_Analysis.cpp.
=======================================================================
*/