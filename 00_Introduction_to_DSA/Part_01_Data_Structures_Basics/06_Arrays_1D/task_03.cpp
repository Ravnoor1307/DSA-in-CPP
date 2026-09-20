#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

// ---------------- TASK 3: max + index ----------------
void sol_task3() {
    int arr[] = {4, 8, 15, 16, 23, 42};
    int n = 6;
    int maxVal = arr[0], maxIdx = 0;      // pehle element ko maan lo max
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIdx = i;                   // naya record holder ke saath uska index
        }
    }
    cout << "   Max = " << maxVal << " at index " << maxIdx << "\n";
}


int main() {
    cout << "TASK 3:\n"; sol_task3();
    return 0;
}