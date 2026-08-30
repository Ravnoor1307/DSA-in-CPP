/*
=======================================================================
 THEORY : Linear Search
=======================================================================
 1. WHAT IT DOES
    - Finds the position (index) of a target value by checking each
      element one by one from index 0 to n-1.

 2. ALGORITHM
      1) Start at index 0.
      2) If arr[index] == target -> return index (found).
      3) Else move to the next index.
      4) If we reach the end without a match -> return -1 (not found).

 3. WHEN TO USE IT
    - When the array is SMALL or UNSORTED.
    - Binary search needs a sorted array; linear does not.

 4. FUNCTION STRUCTURE REMINDER
    - Arrays passed to a function decay into a pointer, so we MUST
      pass the size separately:
        int linear_search(int size, int target, int arr[])

 COMPLEXITY:
    Best case   : target at index 0 -> O(1)
    Worst case  : target missing or at last index -> O(n)
    Average case: O(n)
    Space       : O(1) extra

    n = 8, target = 30
    arr = {10, 50, 30, 70, 80, 20, 90, 40}
    Expected output: Target Found at Index : 2
=======================================================================
*/
#include <iostream>
using namespace std;

int linear_search(int size, int target, int arr[])
{
    for (int index = 0; index < size; index++)
    {
        if (arr[index] == target)
        {
            return index;
        }
    }
    return -1;
}
int main()
{

    // Linear Search
    int arr[] = {10, 50, 30, 70, 80, 20, 90, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    int index = linear_search(size, target, arr);
    if ((index >= 0) && (index < size))
    {
        cout << "Target Found at Index : " << index << endl;
    }
    else
    {
        cout << "Target Not Found !" << endl;
    }

    return 0;
}