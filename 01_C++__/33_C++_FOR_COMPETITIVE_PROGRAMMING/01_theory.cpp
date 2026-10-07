/*
Topic: C++ for Competitive Programming

Covers:
- fast I/O
- test-case structure
- integer overflow
- safe long long arithmetic
- floating-point output
- aliases
- STL contest patterns
- complexity from constraints
- reserve vs resize
- debugging habits
- implementation discipline

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
./theory

This is a deterministic lecture program. It demonstrates contest
patterns without requiring interactive input.
*/

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// ========== SECTION 1: TYPE ALIAS ==========

using ll = long long;

// ========== SECTION 2: CONSTRAINT-AWARE SUM ==========

ll safeSum(const std::vector<int>& values) {
    // 0LL makes the accumulator a long long.
    return std::accumulate(
        values.begin(),
        values.end(),
        0LL
    );
}

// ========== SECTION 3: SAFE WIDENING BEFORE MULTIPLICATION ==========

ll safeProduct(int a, int b) {
    return 1LL * a * b;
}

// ========== SECTION 4: FREQUENCY ARRAY ==========

std::vector<int> buildFrequency(
    const std::vector<int>& values,
    int maximumValue
) {
    std::vector<int> frequency(
        maximumValue + 1,
        0
    );

    for (int value : values) {
        if (value >= 0 && value <= maximumValue) {
            ++frequency[value];
        }
    }

    return frequency;
}

// ========== SECTION 5: SORT + UNIQUE ==========

void removeDuplicates(
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

// ========== SECTION 6: BINARY SEARCH HELPER ==========

int firstAtLeast(
    const std::vector<int>& values,
    int target
) {
    auto iterator = std::lower_bound(
        values.begin(),
        values.end(),
        target
    );

    if (iterator == values.end()) {
        return -1;
    }

    return static_cast<int>(
        iterator - values.begin()
    );
}

// ========== SECTION 7: SOLVE-STYLE FUNCTION ==========

int solveOneCase(
    const std::vector<int>& values
) {
    int maximum = values[0];

    for (int value : values) {
        maximum = std::max(
            maximum,
            value
        );
    }

    return maximum;
}

int main() {
    // In a real submission, place these at the start of main:
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::boolalpha;

    // ========== SECTION 8: FAST I/O CONFIGURATION ==========

    std::cout << "=== DEMO 1: FAST I/O SETUP ===\n";

    std::cout
        << "ios::sync_with_stdio(false);\n"
        << "cin.tie(nullptr);\n"
        << "Prefer '\\n' for batch output.\n";

    // ========== SECTION 9: LONG LONG SUM ==========

    std::cout << "\n=== DEMO 2: SAFE SUM ===\n";

    std::vector<int> largeValues{
        1'000'000'000,
        1'000'000'000,
        1'000'000'000
    };

    std::cout << "Sum = "
              << safeSum(largeValues)
              << '\n';

    // ========== SECTION 10: MULTIPLICATION ==========

    std::cout << "\n=== DEMO 3: SAFE MULTIPLICATION ===\n";

    int a = 1'000'000'000;
    int b = 1'000'000'000;

    std::cout << "Product = "
              << safeProduct(a, b)
              << '\n';

    // ========== SECTION 11: FLOAT PRECISION ==========

    std::cout << "\n=== DEMO 4: FLOATING OUTPUT ===\n";

    double pi = 3.141592653589793;

    std::cout << std::fixed
              << std::setprecision(6)
              << pi
              << '\n';

    // Restore default floating format for later output.
    std::cout.unsetf(
        std::ios::floatfield
    );

    // ========== SECTION 12: SORTING ==========

    std::cout << "\n=== DEMO 5: SORT ===\n";

    std::vector<int> values{
        5, 1, 5, 3, 2, 3
    };

    std::sort(
        values.begin(),
        values.end()
    );

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // ========== SECTION 13: UNIQUE ==========

    std::cout << "\n=== DEMO 6: SORT + UNIQUE ===\n";

    removeDuplicates(values);

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // ========== SECTION 14: LOWER_BOUND ==========

    std::cout << "\n=== DEMO 7: LOWER_BOUND ===\n";

    std::cout << "First value >= 3 at index "
              << firstAtLeast(values, 3)
              << '\n';

    std::cout << "First value >= 10 at index "
              << firstAtLeast(values, 10)
              << '\n';

    // ========== SECTION 15: FREQUENCY ARRAY ==========

    std::cout << "\n=== DEMO 8: FREQUENCY ARRAY ===\n";

    std::vector<int> smallValues{
        1, 2, 2, 3, 3, 3
    };

    auto frequency =
        buildFrequency(
            smallValues,
            3
        );

    for (int value = 1; value <= 3; ++value) {
        std::cout << value
                  << " -> "
                  << frequency[value]
                  << '\n';
    }

    // ========== SECTION 16: HASH FREQUENCY ==========

    std::cout << "\n=== DEMO 9: HASH FREQUENCY ===\n";

    std::string word = "banana";

    std::unordered_map<char, int> counts;

    for (char character : word) {
        ++counts[character];
    }

    std::cout << "a = "
              << counts['a'] << '\n';

    std::cout << "b = "
              << counts['b'] << '\n';

    std::cout << "n = "
              << counts['n'] << '\n';

    // ========== SECTION 17: RESERVE VS RESIZE ==========

    std::cout << "\n=== DEMO 10: reserve VS resize ===\n";

    std::vector<int> reserved;

    reserved.reserve(10);

    std::cout << "After reserve, size = "
              << reserved.size()
              << '\n';

    std::cout << "Capacity >= 10? "
              << (reserved.capacity() >= 10)
              << '\n';

    reserved.resize(3);

    std::cout << "After resize(3), size = "
              << reserved.size()
              << '\n';

    // ========== SECTION 18: TEST CASE ISOLATION ==========

    std::cout << "\n=== DEMO 11: solve()-STYLE CASES ===\n";

    std::vector<std::vector<int>> testCases{
        {1, 9, 3},
        {-5, -1, -8},
        {42}
    };

    for (const auto& testCase : testCases) {
        std::cout << solveOneCase(testCase)
                  << '\n';
    }

    // ========== SECTION 19: ASSERTIONS ==========

    std::cout << "\n=== DEMO 12: ASSERTIONS ===\n";

    int index = 2;
    int size = 5;

    assert(index >= 0);
    assert(index < size);

    std::cout << "Index assumptions verified\n";

    // ========== SECTION 20: CONSTRAINT THINKING ==========

    std::cout << "\n=== DEMO 13: CONSTRAINT THINKING ===\n";

    std::cout
        << "n = 200000 -> avoid full O(n^2) scans\n"
        << "Check total constraints across test cases\n"
        << "Estimate numeric ranges before selecting int/long long\n";

    std::cout
        << "\nNext: "
        << "02_INTRO_TO_DATA_STRUCTURES__/"
        << "01_WHAT_ARE_DATA_STRUCTURES/\n";

    return 0;
}

/*
Expected output:

=== DEMO 1: FAST I/O SETUP ===
ios::sync_with_stdio(false);
cin.tie(nullptr);
Prefer '\n' for batch output.

=== DEMO 2: SAFE SUM ===
Sum = 3000000000

=== DEMO 3: SAFE MULTIPLICATION ===
Product = 1000000000000000000

=== DEMO 4: FLOATING OUTPUT ===
3.141593

=== DEMO 5: SORT ===
1 2 3 3 5 5

=== DEMO 6: SORT + UNIQUE ===
1 2 3 5

=== DEMO 7: LOWER_BOUND ===
First value >= 3 at index 2
First value >= 10 at index -1

=== DEMO 8: FREQUENCY ARRAY ===
1 -> 1
2 -> 2
3 -> 3

=== DEMO 9: HASH FREQUENCY ===
a = 3
b = 1
n = 2

=== DEMO 10: reserve VS resize ===
After reserve, size = 0
Capacity >= 10? true
After resize(3), size = 3

=== DEMO 11: solve()-STYLE CASES ===
9
-1
42

=== DEMO 12: ASSERTIONS ===
Index assumptions verified

=== DEMO 13: CONSTRAINT THINKING ===
n = 200000 -> avoid full O(n^2) scans
Check total constraints across test cases
Estimate numeric ranges before selecting int/long long

Next: 02_INTRO_TO_DATA_STRUCTURES__/01_WHAT_ARE_DATA_STRUCTURES/
*/
