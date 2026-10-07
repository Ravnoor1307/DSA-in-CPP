/*
Topic: C++ for Competitive Programming
File: 02_basics.cpp

Purpose:
Practice:
- contest-style solve structure
- safe arithmetic
- STL shortcuts
- range handling
- test-case isolation

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using ll = long long;

// ========== SECTION 1: CASE SOLVER ==========

void solveCase(
    const std::vector<int>& values
) {
    ll sum = std::accumulate(
        values.begin(),
        values.end(),
        0LL
    );

    auto minimum = std::min_element(
        values.begin(),
        values.end()
    );

    auto maximum = std::max_element(
        values.begin(),
        values.end()
    );

    std::cout << "sum="
              << sum
              << ", min="
              << *minimum
              << ", max="
              << *maximum
              << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::boolalpha;

    std::cout << "=== BASIC 1: MULTIPLE CASE STYLE ===\n";

    std::vector<std::vector<int>> cases{
        {1, 2, 3},
        {10, 20, 30},
        {-5, -1, -10}
    };

    for (const auto& testCase : cases) {
        solveCase(testCase);
    }

    std::cout << "\n=== BASIC 2: SAFE PRODUCT ===\n";

    int a = 100000;
    int b = 100000;

    ll product =
        1LL * a * b;

    std::cout << "Product = "
              << product << '\n';

    std::cout << "\n=== BASIC 3: SORT DESCENDING ===\n";

    std::vector<int> values{
        5, 1, 8, 3
    };

    std::sort(
        values.begin(),
        values.end(),
        [](int left, int right) {
            return left > right;
        }
    );

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== BASIC 4: FREQUENCY ===\n";

    std::unordered_map<int, int> frequency;

    for (int value : {1, 2, 2, 3, 3, 3}) {
        ++frequency[value];
    }

    // Deterministic output order.
    for (int key = 1; key <= 3; ++key) {
        std::cout << key
                  << " -> "
                  << frequency[key]
                  << '\n';
    }

    std::cout << "\n=== BASIC 5: BINARY SEARCH ===\n";

    std::vector<int> sorted{
        1, 3, 5, 7, 9
    };

    std::cout << "Has 7? "
              << std::binary_search(
                     sorted.begin(),
                     sorted.end(),
                     7
                 )
              << '\n';

    std::cout << "Has 8? "
              << std::binary_search(
                     sorted.begin(),
                     sorted.end(),
                     8
                 )
              << '\n';

    std::cout << "\n=== BASIC 6: reserve / resize ===\n";

    std::vector<int> reserved;

    reserved.reserve(100);

    std::cout << "size after reserve = "
              << reserved.size()
              << '\n';

    reserved.resize(3, 7);

    std::cout << "after resize: ";

    for (int value : reserved) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    std::cout
        << "\nNext: "
        << "02_INTRO_TO_DATA_STRUCTURES__/"
        << "01_WHAT_ARE_DATA_STRUCTURES/\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: MULTIPLE CASE STYLE ===
sum=6, min=1, max=3
sum=60, min=10, max=30
sum=-16, min=-10, max=-1

=== BASIC 2: SAFE PRODUCT ===
Product = 10000000000

=== BASIC 3: SORT DESCENDING ===
8 5 3 1

=== BASIC 4: FREQUENCY ===
1 -> 1
2 -> 2
3 -> 3

=== BASIC 5: BINARY SEARCH ===
Has 7? true
Has 8? false

=== BASIC 6: reserve / resize ===
size after reserve = 0
after resize: 7 7 7

Next: 02_INTRO_TO_DATA_STRUCTURES__/01_WHAT_ARE_DATA_STRUCTURES/
*/
