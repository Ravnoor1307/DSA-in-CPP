#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}


// ---------------- TASK 4: reverse in place ----------------
void sol_task4() {
    int arr[] = {4, 8, 15, 16, 23, 42};
    int n = 6;
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];               // teen variable swap pattern
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    cout << "   Reversed: ";
    printArr(arr, n);
}

int main() {
    cout << "TASK 4:\n"; sol_task4();
    return 0;
}