/*
TOPIC: Pointer Arithmetic

Covers:
- Pointer + integer
- Pointer - integer
- Increment/decrement
- a[i] == *(a+i)
- One-past-end pointers
- Pointer subtraction
- ptrdiff_t
- Pointer range traversal
- Reverse traversal
- Pointer-to-array arithmetic
- 2D array pointer interpretation
- C-string traversal
- Safety rules

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>
#include <cstddef>

using namespace std;


// ========== SECTION 1: POINTER + OFFSET ==========
//
// Given:
//
//     int a[4];
//     int* p = a;
//
// p + 1 points to a[1].
// p + 2 points to a[2].
//
// Movement is measured in elements.


// ========== SECTION 2: INDEXING IDENTITY ==========
//
//     a[i]
//
// is defined using:
//
//     *(a + i)
//
// Pointer indexing:
//
//     p[i]
//
// similarly means:
//
//     *(p + i)


// ========== SECTION 3: POINTER INCREMENT ==========
//
//     ++p
//
// advances p by one element.
//
// It does NOT change the array.


// ========== SECTION 4: POINTER VS POINTEE INCREMENT ==========
//
//     ++p
//
// moves pointer.
//
//     ++(*p)
//
// increments pointed value.


// ========== SECTION 5: POSTFIX PRECEDENCE ==========
//
//     *p++
//
// parses as:
//
//     *(p++)
//
// while:
//
//     (*p)++
//
// increments the pointed object.


// ========== SECTION 6: ONE-PAST-END ==========
//
// For n elements:
//
//     a + n
//
// is a valid one-past boundary pointer.
//
// It may be formed and compared.
//
// It must NOT be dereferenced.


// ========== SECTION 7: POINTER DIFFERENCE ==========
//
// If p and q point into the same array:
//
//     q - p
//
// reports distance in ELEMENTS.
//
// Result type:
//
//     ptrdiff_t


// ========== SECTION 8: HALF-OPEN RANGE ==========
//
//     [begin, end)
//
// begin points to first element.
//
// end points one past the last.
//
// This model is fundamental to STL iterators.


// ========== SECTION 9: POINTER SAFETY ==========
//
// Do not:
//
// - move outside a valid array range
// - dereference one-past
// - subtract unrelated pointers
// - perform arithmetic on nullptr
// - use void* arithmetic in standard C++


// ========== SECTION 10: 2D ARRAYS ==========
//
// For:
//
//     int matrix[2][3];
//
// matrix converts to:
//
//     pointer to array of 3 int
//
// Therefore:
//
//     matrix + 1
//
// moves by one entire row.


// ========== SECTION 11: 2D INDEX IDENTITY ==========
//
//     matrix[row][col]
//
// corresponds conceptually to:
//
//     *(*(matrix + row) + col)


// ========== SECTION 12: C-STRINGS ==========
//
// Character pointers can traverse until:
//
//     '\0'
//
// Do not move blindly past the terminator.


void printWithPointers(
    const int* begin,
    const int* end
);

long long sumWithPointers(
    const int* begin,
    const int* end
);


int main() {

    cout << boolalpha;


    cout << "=== DEMO 1: Pointer Offsets ===\n";

    int values[5] = {
        10, 20, 30, 40, 50
    };

    int* ptr = values;

    cout << "*ptr = "
         << *ptr << '\n';

    cout << "*(ptr + 1) = "
         << *(ptr + 1) << '\n';

    cout << "*(ptr + 4) = "
         << *(ptr + 4) << "\n\n";


    cout << "=== DEMO 2: Index Equivalence ===\n";

    cout << "values[2] = "
         << values[2] << '\n';

    cout << "*(values + 2) = "
         << *(values + 2) << '\n';

    cout << "ptr[2] = "
         << ptr[2] << "\n\n";


    cout << "=== DEMO 3: Pointer Increment ===\n";

    ptr = values;

    cout << *ptr << ' ';

    ++ptr;
    cout << *ptr << ' ';

    ++ptr;
    cout << *ptr << '\n';

    cout << '\n';


    cout << "=== DEMO 4: Pointer vs Pointee Increment ===\n";

    int demo[3] = {
        1, 2, 3
    };

    int* demoPtr = demo;

    ++(*demoPtr);

    cout << "after ++(*ptr): "
         << demo[0] << ' '
         << demo[1] << ' '
         << demo[2] << '\n';

    ++demoPtr;

    ++(*demoPtr);

    cout << "after moving and modifying: "
         << demo[0] << ' '
         << demo[1] << ' '
         << demo[2]
         << "\n\n";


    cout << "=== DEMO 5: Half-Open Range ===\n";

    const int* begin = values;
    const int* end = values + 5;

    printWithPointers(
        begin,
        end
    );

    cout << '\n';


    cout << "=== DEMO 6: Pointer Difference ===\n";

    ptrdiff_t distance =
        end - begin;

    cout << "distance = "
         << distance
         << "\n\n";


    cout << "=== DEMO 7: Sum With Pointers ===\n";

    cout << "sum = "
         << sumWithPointers(
                begin,
                end
            )
         << "\n\n";


    cout << "=== DEMO 8: Reverse Pointer Traversal ===\n";

    const int* reversePtr =
        end;

    while (reversePtr != begin) {

        --reversePtr;

        cout << *reversePtr
             << ' ';
    }

    cout << "\n\n";


    cout << "=== DEMO 9: Two Pointers ===\n";

    int* left =
        values;

    int* right =
        values + 4;

    cout << "left value = "
         << *left << '\n';

    cout << "right value = "
         << *right << '\n';

    cout << "element distance = "
         << right - left
         << "\n\n";


    cout << "=== DEMO 10: 2D Pointer Arithmetic ===\n";

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "matrix[1][2] = "
         << matrix[1][2]
         << '\n';

    cout << "pointer form = "
         << *(*(matrix + 1) + 2)
         << '\n';

    cout << "first item next row = "
         << **(matrix + 1)
         << "\n\n";


    cout << "=== DEMO 11: C-String Pointer Walk ===\n";

    const char text[] =
        "DSA";

    const char* charPtr =
        text;

    while (*charPtr != '\0') {

        cout << *charPtr
             << ' ';

        ++charPtr;
    }

    cout << '\n';

    return 0;
}


void printWithPointers(
    const int* begin,
    const int* end
) {
    for (const int* ptr = begin;
         ptr != end;
         ++ptr) {

        cout << *ptr << ' ';
    }

    cout << '\n';
}


long long sumWithPointers(
    const int* begin,
    const int* end
) {
    long long sum = 0;

    while (begin != end) {

        sum += *begin;

        ++begin;
    }

    return sum;
}


/*
EXPECTED OUTPUT

=== DEMO 1: Pointer Offsets ===
*ptr = 10
*(ptr + 1) = 20
*(ptr + 4) = 50

=== DEMO 2: Index Equivalence ===
values[2] = 30
*(values + 2) = 30
ptr[2] = 30

=== DEMO 3: Pointer Increment ===
10 20 30

=== DEMO 4: Pointer vs Pointee Increment ===
after ++(*ptr): 2 2 3
after moving and modifying: 2 3 3

=== DEMO 5: Half-Open Range ===
10 20 30 40 50

=== DEMO 6: Pointer Difference ===
distance = 5

=== DEMO 7: Sum With Pointers ===
sum = 150

=== DEMO 8: Reverse Pointer Traversal ===
50 40 30 20 10

=== DEMO 9: Two Pointers ===
left value = 10
right value = 50
element distance = 4

=== DEMO 10: 2D Pointer Arithmetic ===
matrix[1][2] = 6
pointer form = 6
first item next row = 4

=== DEMO 11: C-String Pointer Walk ===
D S A

WHAT'S NEXT:
01_C++__/16_DYNAMIC_MEMORY/
*/
