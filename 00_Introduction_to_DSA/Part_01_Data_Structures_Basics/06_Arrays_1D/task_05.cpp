#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

// ---------------- TASK 5: linear search ----------------
void sol_task5() {
    int arr[] = {4, 8, 15, 16, 23, 42};
    int n = 6, x = 23, pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            pos = i;                      // mil gaya
            break;                        // aage waste me loop mat chalao
        }
    }
    cout << "   " << x << " mila index " << pos << " par\n";
}

int main() {
    cout << "TASK 5:\n"; sol_task5();
    return 0;
}