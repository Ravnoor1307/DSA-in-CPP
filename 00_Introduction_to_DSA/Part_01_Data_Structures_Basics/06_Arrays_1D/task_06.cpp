#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}


// ---------------- TASK 6: insert at position ----------------
void sol_task6() {
    int arr[10] = {4, 8, 15, 16, 23, 42}; // kapacity 10, filled 6
    int n = 6, p = 2, val = 99;
    for (int i = n; i > p; i--) {
        arr[i] = arr[i - 1];              // right shift — peeche se shuru karo
    }
    arr[p] = val;                         // khali slot par nayi value
    n++;
    cout << "   After insert 99 @ pos 2: ";
    printArr(arr, n);
}



int main() {
    cout << "TASK 6:\n"; sol_task6();
    return 0;
}