#include <iostream>
using namespace std;

int main() {
    int n = 4; // Number of rows

    for (int i = n; i >= 1; i--) {
        // Print leading spaces
        for (int j = 0; j < n - i; j++) {
            cout << "  "; // Two spaces for alignment
        }

        // Increasing numbers from 1 to i
        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }

        // Increasing numbers from 1 to i-1 again
        for (int k = 1; k <= i - 1; k++) {
            cout << k << " ";
        }

        cout << endl;
    }

    return 0;
}
