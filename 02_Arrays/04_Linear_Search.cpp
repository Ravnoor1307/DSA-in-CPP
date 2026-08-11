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