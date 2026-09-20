#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}



// ---------------- TASK 7: delete at position ----------------
void sol_task7() {
    int arr[] = {4, 8, 15, 16, 23, 42};
    int n = 6, p = 1;                     // index 1 ki value 8 hatani hai
    for (int i = p; i < n - 1; i++) {
        arr[i] = arr[i + 1];              // left shift — har value ek ghar aage
    }
    n--;                                  // size ghati (8 xuda gayi)
    cout << "   After delete pos 1: ";
    printArr(arr, n);
}

int main() {
    cout << "TASK 7:\n"; sol_task7();
    return 0;
}