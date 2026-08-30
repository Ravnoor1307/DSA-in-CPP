/*
=======================================================================
 THEORY : Pattern Printing - Inverted Number Pyramid
=======================================================================
 Same pyramid idea but iterated from LARGE row to SMALL row:
    for i from n down to 1
        print (n - i) leading spaces
        print numbers 1 .. i        (increasing)
        print numbers 1 .. i-1      (increasing again)
    This builds an inverted (upside-down) symmetric number triangle.

 EXPECTED OUTPUT (n = 4):
    1 2 3 4 1 2 3
      1 2 3 1 2
        1 2 1
          1

 Compare with file 13 (which builds the normal upright pyramid).
=======================================================================
*/
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
