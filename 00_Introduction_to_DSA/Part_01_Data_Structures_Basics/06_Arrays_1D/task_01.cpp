#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

// ---------------- TASK 1: traverse ----------------
void sol_task1() {
    int arr[] = {4, 8, 15, 16, 23, 42};
    int n = 6;
    cout << "   Original array: ";
    printArr(arr, n);
}



int main() {
    cout << "TASK 1:\n"; sol_task1();
    return 0;
}