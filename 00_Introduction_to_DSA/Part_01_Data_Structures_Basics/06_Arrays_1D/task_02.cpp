#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

// ---------------- TASK 2: sum ----------------
void sol_task2() {
    int arr[] = {4, 8, 15, 16, 23, 42};
    int n = 6, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];            // har element ko sum me jodo
    }
    cout << "   Sum = " << sum << "\n";
}

int main() {
    cout << "TASK 2:\n"; sol_task2();
    return 0;
}