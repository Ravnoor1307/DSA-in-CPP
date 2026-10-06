/*
TOPIC: Arrays 1D and 2D

Covers:
- Raw built-in arrays
- Initialization
- Indexing
- Traversal
- Bounds
- Contiguous storage
- sizeof arrays
- Passing arrays to functions
- Array-to-pointer adjustment
- Mutation through parameters
- Range-based loops
- Linear search
- Aggregation
- Reversal
- 2D arrays
- Matrix traversal
- Row/column/diagonal operations

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>

using namespace std;


// ========== SECTION 1: RAW ARRAYS ==========
//
//     int values[5];
//
// creates five contiguous int elements.
//
// Valid indexes:
//
//     0 1 2 3 4


// ========== SECTION 2: INITIALIZATION ==========
//
// Full:
//
//     int a[3] = {10, 20, 30};
//
// Deduction:
//
//     int a[] = {10, 20, 30};
//
// Zero:
//
//     int a[3]{};
//
// Partial:
//
//     int a[5] = {10, 20};
//
// becomes:
//
//     10 20 0 0 0


// ========== SECTION 3: INDEXING ==========
//
//     a[i]
//
// accesses element i.
//
// For n elements:
//
//     0 <= i < n
//
// Raw arrays do not perform automatic bounds checking.


// ========== SECTION 4: TRAVERSAL ==========
//
//     for (int i = 0; i < n; ++i) {
//         cout << a[i];
//     }


// ========== SECTION 5: CONTIGUOUS STORAGE ==========
//
// Elements are stored consecutively.
//
// This enables constant-time indexed access and efficient
// sequential traversal.


// ========== SECTION 6: SIZEOF ==========
//
// For an actual array object:
//
//     sizeof(a)
//
// gives total array storage.
//
// Element count can be obtained locally with:
//
//     sizeof(a) / sizeof(a[0])
//
// But this does NOT work the same way in pointer-style
// function parameters.


// ========== SECTION 7: ARRAY FUNCTION PARAMETERS ==========
//
//     void f(int a[], int n)
//
// parameter a is adjusted to:
//
//     int* a
//
// Therefore the size n is commonly supplied separately.


// ========== SECTION 8: CONST ARRAY PARAMETER ==========
//
//     void print(const int a[], int n)
//
// is effectively:
//
//     void print(const int* a, int n)
//
// The function cannot modify elements through that pointer.


// ========== SECTION 9: RANGE-BASED LOOP ==========
//
// For an actual array:
//
//     for (int value : a)
//
// copies each element.
//
//     for (int& value : a)
//
// refers to each actual element.


// ========== SECTION 10: 2D ARRAY ==========
//
//     int matrix[2][3];
//
// means:
//
//     array of 2 rows
//
// each row:
//
//     array of 3 int
//
// Access:
//
//     matrix[row][col]


// ========== SECTION 11: ROW-MAJOR STORAGE ==========
//
// For:
//
//     1 2 3
//     4 5 6
//
// memory element order is:
//
//     1 2 3 4 5 6


// ========== SECTION 12: MATRIX COMPLEXITY ==========
//
// R rows and C columns:
//
//     total elements = R*C
//
// full traversal:
//
//     O(R*C)


void printArray(
    const int values[],
    int n
);

int linearSearch(
    const int values[],
    int n,
    int target
);

long long sumArray(
    const int values[],
    int n
);

void changeFirst(
    int values[],
    int n
);

void printMatrix(
    const int matrix[][3],
    int rows
);


int main() {

    cout << "=== DEMO 1: Initialization ===\n";

    int values[5] = {
        10, 20, 30, 40, 50
    };

    printArray(values, 5);

    cout << '\n';


    cout << "=== DEMO 2: Indexing and Modification ===\n";

    cout << "values[2] before = "
         << values[2] << '\n';

    values[2] = 99;

    cout << "values[2] after = "
         << values[2] << '\n';

    cout << "array: ";
    printArray(values, 5);

    cout << '\n';


    cout << "=== DEMO 3: sizeof Actual Array ===\n";

    cout << "total bytes = "
         << sizeof(values)
         << '\n';

    cout << "element bytes = "
         << sizeof(values[0])
         << '\n';

    cout << "element count = "
         << sizeof(values) / sizeof(values[0])
         << "\n\n";


    cout << "=== DEMO 4: Linear Search ===\n";

    int index =
        linearSearch(
            values,
            5,
            40
        );

    cout << "40 found at index = "
         << index
         << "\n\n";


    cout << "=== DEMO 5: Sum ===\n";

    cout << "sum = "
         << sumArray(values, 5)
         << "\n\n";


    cout << "=== DEMO 6: Function Mutates Array ===\n";

    changeFirst(values, 5);

    printArray(values, 5);

    cout << '\n';


    cout << "=== DEMO 7: Range-Based Loop ===\n";

    int numbers[4] = {
        1, 2, 3, 4
    };

    for (int number : numbers) {
        cout << number << ' ';
    }

    cout << "\n\n";


    cout << "=== DEMO 8: Reference Range Loop ===\n";

    for (int& number : numbers) {
        number *= 2;
    }

    for (int number : numbers) {
        cout << number << ' ';
    }

    cout << "\n\n";


    cout << "=== DEMO 9: Reverse In Place ===\n";

    int reverseValues[5] = {
        1, 2, 3, 4, 5
    };

    int left = 0;
    int right = 4;

    while (left < right) {

        int temp =
            reverseValues[left];

        reverseValues[left] =
            reverseValues[right];

        reverseValues[right] =
            temp;

        ++left;
        --right;
    }

    printArray(reverseValues, 5);

    cout << '\n';


    cout << "=== DEMO 10: 2D Array ===\n";

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printMatrix(matrix, 2);

    cout << '\n';


    cout << "=== DEMO 11: Row Sums ===\n";

    for (int row = 0; row < 2; ++row) {

        int rowSum = 0;

        for (int col = 0; col < 3; ++col) {
            rowSum += matrix[row][col];
        }

        cout << "row "
             << row
             << " sum = "
             << rowSum
             << '\n';
    }

    cout << '\n';


    cout << "=== DEMO 12: Diagonal ===\n";

    int square[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; ++i) {
        cout << square[i][i] << ' ';
    }

    cout << '\n';

    return 0;
}


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


void changeFirst(
    int values[],
    int n
) {
    if (n > 0) {
        values[0] = 500;
    }
}


void printMatrix(
    const int matrix[][3],
    int rows
) {
    for (int row = 0; row < rows; ++row) {

        for (int col = 0; col < 3; ++col) {

            cout << matrix[row][col];

            if (col + 1 < 3) {
                cout << ' ';
            }
        }

        cout << '\n';
    }
}


/*
EXPECTED OUTPUT ON A COMMON PLATFORM WHERE sizeof(int) == 4

=== DEMO 1: Initialization ===
10 20 30 40 50

=== DEMO 2: Indexing and Modification ===
values[2] before = 30
values[2] after = 99
array: 10 20 99 40 50

=== DEMO 3: sizeof Actual Array ===
total bytes = 20
element bytes = 4
element count = 5

=== DEMO 4: Linear Search ===
40 found at index = 3

=== DEMO 5: Sum ===
sum = 219

=== DEMO 6: Function Mutates Array ===
500 20 99 40 50

=== DEMO 7: Range-Based Loop ===
1 2 3 4

=== DEMO 8: Reference Range Loop ===
2 4 6 8

=== DEMO 9: Reverse In Place ===
5 4 3 2 1

=== DEMO 10: 2D Array ===
1 2 3
4 5 6

=== DEMO 11: Row Sums ===
row 0 sum = 6
row 1 sum = 15

=== DEMO 12: Diagonal ===
1 5 9

sizeof output may differ on a conforming implementation with a
different sizeof(int).

WHAT'S NEXT:
01_C++__/13_STRINGS_AND_C_STRINGS/
*/
