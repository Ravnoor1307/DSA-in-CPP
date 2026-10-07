/*
Topic: C++ for Competitive Programming
File: 04_practice_problems.cpp

Practice:
1. Constraint-safe sum
2. Sort and deduplicate
3. Frequency array
4. Count occurrences using binary-search bounds
5. Maximum pair product without int overflow

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
./practice
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using ll = long long;

// ========== PROBLEM 1: SAFE SUM ==========
//
// Values may each be as large as 1e9.
// Use a long long accumulator.
//
// Time: O(n)
// Extra space: O(1)

ll safeSum(
    const std::vector<int>& values
) {
    return std::accumulate(
        values.begin(),
        values.end(),
        0LL
    );
}

// ========== PROBLEM 2: SORT AND DEDUPLICATE ==========
//
// Time: O(n log n)
// Extra algorithmic space: depends on std::sort implementation.

void deduplicate(
    std::vector<int>& values
) {
    std::sort(
        values.begin(),
        values.end()
    );

    values.erase(
        std::unique(
            values.begin(),
            values.end()
        ),
        values.end()
    );
}

// ========== PROBLEM 3: FREQUENCY ARRAY ==========
//
// Constraint:
// 0 <= value <= 5
//
// This avoids hashing because the key range is tiny.
//
// Time: O(n)
// Extra space: O(1) because range is fixed.

std::vector<int> frequencies(
    const std::vector<int>& values
) {
    std::vector<int> frequency(6, 0);

    for (int value : values) {
        ++frequency[value];
    }

    return frequency;
}

// ========== PROBLEM 4: COUNT OCCURRENCES ==========
//
// Input vector must be sorted.
//
// Time: O(log n) comparisons on vector iterators.

int occurrenceCount(
    const std::vector<int>& sorted,
    int target
) {
    auto first = std::lower_bound(
        sorted.begin(),
        sorted.end(),
        target
    );

    auto afterLast = std::upper_bound(
        sorted.begin(),
        sorted.end(),
        target
    );

    return static_cast<int>(
        afterLast - first
    );
}

// ========== PROBLEM 5: MAXIMUM PRODUCT OF TWO VALUES ==========
//
// Sorting makes it easy to handle negative values too.
//
// Maximum product can come from:
// - two largest values
// - two most negative values
//
// We widen before multiplication.
//
// Time: O(n log n)

ll maximumPairProduct(
    std::vector<int> values
) {
    std::sort(
        values.begin(),
        values.end()
    );

    int n =
        static_cast<int>(values.size());

    ll largestPair =
        1LL
        * values[n - 1]
        * values[n - 2];

    ll smallestPair =
        1LL
        * values[0]
        * values[1];

    return std::max(
        largestPair,
        smallestPair
    );
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << "=== PROBLEM 1: SAFE SUM ===\n";

    std::vector<int> large{
        1'000'000'000,
        1'000'000'000,
        1'000'000'000
    };

    std::cout << "Sum = "
              << safeSum(large)
              << '\n';

    std::cout << "\n=== PROBLEM 2: DEDUPLICATE ===\n";

    std::vector<int> values{
        5, 1, 3, 1, 5, 2, 3
    };

    deduplicate(values);

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== PROBLEM 3: FREQUENCY ARRAY ===\n";

    std::vector<int> small{
        1, 2, 2, 3, 3, 3, 5
    };

    auto frequency =
        frequencies(small);

    for (
        int value = 0;
        value <= 5;
        ++value
    ) {
        if (frequency[value] > 0) {
            std::cout << value
                      << " -> "
                      << frequency[value]
                      << '\n';
        }
    }

    std::cout << "\n=== PROBLEM 4: OCCURRENCE COUNT ===\n";

    std::vector<int> sorted{
        1, 2, 2, 2, 4, 5, 5
    };

    std::cout << "2 occurs "
              << occurrenceCount(
                     sorted,
                     2
                 )
              << " times\n";

    std::cout << "3 occurs "
              << occurrenceCount(
                     sorted,
                     3
                 )
              << " times\n";

    std::cout << "\n=== PROBLEM 5: MAXIMUM PAIR PRODUCT ===\n";

    std::vector<int> mixed{
        -100000,
        -90000,
        2,
        3,
        100000
    };

    std::cout << "Maximum product = "
              << maximumPairProduct(mixed)
              << '\n';

    std::cout
        << "\nNext: "
        << "02_INTRO_TO_DATA_STRUCTURES__/"
        << "01_WHAT_ARE_DATA_STRUCTURES/\n";

    return 0;
}

/*
Expected output:

=== PROBLEM 1: SAFE SUM ===
Sum = 3000000000

=== PROBLEM 2: DEDUPLICATE ===
1 2 3 5

=== PROBLEM 3: FREQUENCY ARRAY ===
1 -> 1
2 -> 2
3 -> 3
5 -> 1

=== PROBLEM 4: OCCURRENCE COUNT ===
2 occurs 3 times
3 occurs 0 times

=== PROBLEM 5: MAXIMUM PAIR PRODUCT ===
Maximum product = 9000000000

Next: 02_INTRO_TO_DATA_STRUCTURES__/01_WHAT_ARE_DATA_STRUCTURES/
*/
