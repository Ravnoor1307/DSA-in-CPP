/*
TOPIC: Arrays 1D and 2D
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>

using namespace std;


// ============================================================
// PROBLEM 1: LINEAR SEARCH
// ============================================================

int linearSearch(
    const int values[],
    int n,
    int target
) {
    for (int i = 0; i < n; ++i) {

        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}


// ============================================================
// PROBLEM 2: SUM
// ============================================================

long long sumArray(
    const int values[],
    int n
) {
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += values[i];
    }

    return sum;
}


// ============================================================
// PROBLEM 3: REVERSE IN PLACE
// ============================================================

void reverseArray(
    int values[],
    int n
) {
    int left = 0;
    int right = n - 1;

    while (left < right) {

        int temp =
            values[left];

        values[left] =
            values[right];

        values[right] =
            temp;

        ++left;
        --right;
    }
}


// ============================================================
// PROBLEM 4: COUNT OCCURRENCES
// ============================================================

int countOccurrences(
    const int values[],
    int n,
    int target
) {
    int count = 0;

    for (int i = 0; i < n; ++i) {

        if (values[i] == target) {
            ++count;
        }
    }

    return count;
}


// ============================================================
// UTILITY
// ============================================================

void printArray(
    const int values[],
    int n
) {
    for (int i = 0; i < n; ++i) {

        cout << values[i];

        if (i + 1 < n) {
            cout << ' ';
        }
    }

    cout << '\n';
}


int main() {

    int values[7] = {
        4, 2, 7, 2, 9, 2, 5
    };

    constexpr int N = 7;


    // ========================================================
    // TEST 1
    // ========================================================

    cout << "=== PROBLEM 1: Linear Search ===\n";

    cout << "index of 9 = "
         << linearSearch(
                values,
                N,
                9
            )
         << "\n\n";


    // ========================================================
    // TEST 2
    // ========================================================

    cout << "=== PROBLEM 2: Sum ===\n";

    cout << "sum = "
         << sumArray(values, N)
         << "\n\n";


    // ========================================================
    // TEST 3
    // ========================================================

    cout << "=== PROBLEM 3: Reverse ===\n";

    reverseArray(values, N);

    printArray(values, N);

    cout << '\n';


    // ========================================================
    // TEST 4
    // ========================================================

    cout << "=== PROBLEM 4: Count Occurrences ===\n";

    cout << "count of 2 = "
         << countOccurrences(
                values,
                N,
                2
            )
         << "\n\n";


    // ========================================================
    // PROBLEM 5: MATRIX TOTAL
    // ========================================================

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int total = 0;

    for (int row = 0; row < 2; ++row) {

        for (int col = 0; col < 3; ++col) {
            total += matrix[row][col];
        }
    }

    cout << "=== PROBLEM 5: Matrix Total ===\n";

    cout << "total = "
         << total
         << "\n\n";


    // ========================================================
    // BONUS: MAIN DIAGONAL SUM
    // ========================================================

    int square[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int diagonalSum = 0;

    for (int i = 0; i < 3; ++i) {
        diagonalSum += square[i][i];
    }

    cout << "=== BONUS: Diagonal Sum ===\n";

    cout << diagonalSum << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Linear Search ===
index of 9 = 4

=== PROBLEM 2: Sum ===
sum = 31

=== PROBLEM 3: Reverse ===
5 2 9 2 7 2 4

=== PROBLEM 4: Count Occurrences ===
count of 2 = 3

=== PROBLEM 5: Matrix Total ===
total = 21

=== BONUS: Diagonal Sum ===
15


PRACTICE LINKS

1. LeetCode 1480
https://leetcode.com/problems/running-sum-of-1d-array/

2. LeetCode 1929
https://leetcode.com/problems/concatenation-of-array/

3. LeetCode 1672
https://leetcode.com/problems/richest-customer-wealth/

4. GFG Arrays
https://www.geeksforgeeks.org/cpp-arrays/

5. GFG Multidimensional Arrays
https://www.geeksforgeeks.org/multidimensional-arrays-in-cpp/


WHAT'S NEXT:
01_C++__/13_STRINGS_AND_C_STRINGS/
*/
