/*
TOPIC: Pointer Arithmetic
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>
#include <cstddef>

using namespace std;


// ============================================================
// PROBLEM 1: SUM POINTER RANGE
// ============================================================

long long sumRange(
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


// ============================================================
// PROBLEM 2: FIND TARGET
// ============================================================

const int* findValue(
    const int* begin,
    const int* end,
    int target
) {
    while (begin != end) {

        if (*begin == target) {
            return begin;
        }

        ++begin;
    }

    // Using end as the "not found" sentinel mirrors
    // standard iterator algorithms.
    return end;
}


// ============================================================
// PROBLEM 3: REVERSE POINTER RANGE
// ============================================================

void reverseRange(
    int* begin,
    int* end
) {
    // Range:
    // [begin, end)
    //
    // end is one-past-last.

    while (begin != end) {

        --end;

        if (begin >= end) {
            break;
        }

        int temp = *begin;

        *begin = *end;
        *end = temp;

        ++begin;
    }
}


// ============================================================
// PROBLEM 4: COUNT C-STRING CHARACTERS
// ============================================================

int countCharacter(
    const char* text,
    char target
) {
    int count = 0;

    while (*text != '\0') {

        if (*text == target) {
            ++count;
        }

        ++text;
    }

    return count;
}


// ============================================================
// PROBLEM 5: MATRIX TOTAL
// ============================================================

int matrixTotal(
    const int (*matrix)[3],
    int rows
) {
    int total = 0;

    const int (*row)[3] =
        matrix;

    const int (*end)[3] =
        matrix + rows;

    while (row != end) {

        const int* element =
            *row;

        const int* rowEnd =
            *row + 3;

        while (element != rowEnd) {

            total += *element;

            ++element;
        }

        ++row;
    }

    return total;
}


int main() {

    int values[6] = {
        5, 10, 15, 20, 25, 30
    };

    int* begin =
        values;

    int* end =
        values + 6;


    // ========================================================
    // TEST 1
    // ========================================================

    cout << "=== PROBLEM 1: Sum ===\n";

    cout << sumRange(begin, end)
         << "\n\n";


    // ========================================================
    // TEST 2
    // ========================================================

    cout << "=== PROBLEM 2: Find ===\n";

    const int* found =
        findValue(
            begin,
            end,
            20
        );

    if (found != end) {

        cout << "value = "
             << *found << '\n';

        cout << "index = "
             << found - begin
             << '\n';
    }

    cout << '\n';


    // ========================================================
    // TEST 3
    // ========================================================

    cout << "=== PROBLEM 3: Reverse ===\n";

    reverseRange(
        begin,
        end
    );

    for (int value : values) {
        cout << value << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // TEST 4
    // ========================================================

    const char text[] =
        "banana";

    cout << "=== PROBLEM 4: Character Count ===\n";

    cout << countCharacter(
                text,
                'a'
            )
         << "\n\n";


    // ========================================================
    // TEST 5
    // ========================================================

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "=== PROBLEM 5: Matrix Total ===\n";

    cout << matrixTotal(
                matrix,
                2
            )
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Sum ===
105

=== PROBLEM 2: Find ===
value = 20
index = 3

=== PROBLEM 3: Reverse ===
30 25 20 15 10 5

=== PROBLEM 4: Character Count ===
3

=== PROBLEM 5: Matrix Total ===
21


PRACTICE LINKS

1. GFG Pointer Arithmetic
https://www.geeksforgeeks.org/cpp-pointer-arithmetic/

2. GFG Pointers and Arrays
https://www.geeksforgeeks.org/cpp-pointers-and-arrays/

3. HackerRank Pointer
https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

4. LeetCode 344
https://leetcode.com/problems/reverse-string/

5. LeetCode 283
https://leetcode.com/problems/move-zeroes/


WHAT'S NEXT:
01_C++__/16_DYNAMIC_MEMORY/
*/
