/*
Topic: auto and Range-Based Loops
File: 04_practice_problems.cpp

Practice:
1. Sum an array with a range loop
2. Modify values by reference
3. Count vowels in a string
4. Traverse a matrix
5. Structured bindings

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

// ========== PROBLEM 1: ARRAY SUM ==========
//
// Traverse all elements without manually managing an index.
//
// Time:  O(n)
// Space: O(1)

int sumArray(const int (&values)[5]) {
    int total = 0;

    for (auto value : values) {
        total += value;
    }

    return total;
}

// ========== PROBLEM 2: DOUBLE IN PLACE ==========
//
// References are necessary because the original elements
// must change.
//
// Time:  O(n)
// Space: O(1)

void doubleValues(int (&values)[5]) {
    for (auto& value : values) {
        value *= 2;
    }
}

// ========== PROBLEM 3: COUNT VOWELS ==========
//
// std::string is iterable.
//
// Time:  O(n)
// Space: O(1)

int countVowels(const std::string& text) {
    int count = 0;

    for (auto character : text) {
        if (
            character == 'a'
            || character == 'e'
            || character == 'i'
            || character == 'o'
            || character == 'u'
            || character == 'A'
            || character == 'E'
            || character == 'I'
            || character == 'O'
            || character == 'U'
        ) {
            ++count;
        }
    }

    return count;
}

// ========== PROBLEM 4: MATRIX SUM ==========
//
// Range references preserve each row array.
//
// Time:  O(rows * columns)
// Space: O(1)

int matrixSum(const int (&matrix)[2][3]) {
    int total = 0;

    for (const auto& row : matrix) {
        for (auto value : row) {
            total += value;
        }
    }

    return total;
}

// ========== PROBLEM 5: STRUCTURED BINDINGS ==========

void printStudent(
    const std::pair<std::string, int>& student
) {
    const auto& [name, marks] = student;

    std::cout << name
              << " -> "
              << marks
              << '\n';
}

int main() {
    std::cout << "=== PROBLEM 1: ARRAY SUM ===\n";

    int values[5] = {
        1, 2, 3, 4, 5
    };

    std::cout << "Sum = "
              << sumArray(values)
              << '\n';

    std::cout << "\n=== PROBLEM 2: MODIFY BY REFERENCE ===\n";

    doubleValues(values);

    for (const auto& value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== PROBLEM 3: COUNT VOWELS ===\n";

    std::string text = "Data Structures";

    std::cout << "Vowels = "
              << countVowels(text)
              << '\n';

    std::cout << "\n=== PROBLEM 4: MATRIX ===\n";

    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::cout << "Matrix sum = "
              << matrixSum(matrix)
              << '\n';

    std::cout << "\n=== PROBLEM 5: STRUCTURED BINDINGS ===\n";

    std::pair<std::string, int> student{
        "Asha",
        95
    };

    printStudent(student);

    auto& [name, marks] = student;

    marks = 100;

    std::cout << "After reference update:\n";
    printStudent(student);

    std::cout << "\n=== EXTRA: VECTOR READ-ONLY LOOP ===\n";

    std::vector<std::string> topics = {
        "arrays",
        "strings",
        "pointers"
    };

    for (const auto& topic : topics) {
        std::cout << topic << '\n';
    }

    std::cout << "\nNext: 29_LAMBDAS\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: ARRAY SUM ===
Sum = 15

=== PROBLEM 2: MODIFY BY REFERENCE ===
2 4 6 8 10

=== PROBLEM 3: COUNT VOWELS ===
Vowels = 5

=== PROBLEM 4: MATRIX ===
Matrix sum = 21

=== PROBLEM 5: STRUCTURED BINDINGS ===
Asha -> 95
After reference update:
Asha -> 100

=== EXTRA: VECTOR READ-ONLY LOOP ===
arrays
strings
pointers

Next: 29_LAMBDAS
*/
