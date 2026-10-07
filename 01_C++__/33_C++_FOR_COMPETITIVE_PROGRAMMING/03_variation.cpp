/*
Topic: C++ for Competitive Programming
File: 03_variation.cpp

Purpose:
Explore common contest traps:
- overflowing before conversion
- accumulate initial type
- off-by-one handling
- lower_bound
- map lookup
- avoiding large copies

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using ll = long long;

// ========== SECTION 1: READ-ONLY LARGE PARAMETER ==========

ll sumValues(
    const std::vector<int>& values
) {
    return std::accumulate(
        values.begin(),
        values.end(),
        0LL
    );
}

// ========== SECTION 2: EXACT LOOKUP WITH LOWER_BOUND ==========

int findSorted(
    const std::vector<int>& values,
    int target
) {
    auto iterator = std::lower_bound(
        values.begin(),
        values.end(),
        target
    );

    if (
        iterator == values.end()
        || *iterator != target
    ) {
        return -1;
    }

    return static_cast<int>(
        iterator - values.begin()
    );
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::boolalpha;

    std::cout << "=== VARIATION 1: PROMOTE BEFORE MULTIPLY ===\n";

    int a = 1'000'000'000;
    int b = 2;

    ll safe =
        1LL * a * b;

    std::cout << "Safe result = "
              << safe << '\n';

    std::cout << "\n=== VARIATION 2: ACCUMULATOR TYPE ===\n";

    std::vector<int> billionValues{
        1'000'000'000,
        1'000'000'000,
        1'000'000'000
    };

    ll sum = std::accumulate(
        billionValues.begin(),
        billionValues.end(),
        0LL
    );

    std::cout << "Sum = "
              << sum << '\n';

    std::cout << "\n=== VARIATION 3: HALF-OPEN INDEX LOOP ===\n";

    std::vector<int> values{
        10, 20, 30, 40
    };

    for (
        int i = 0;
        i < static_cast<int>(values.size());
        ++i
    ) {
        std::cout << i
                  << ":"
                  << values[i]
                  << ' ';
    }

    std::cout << '\n';

    std::cout << "\n=== VARIATION 4: LOWER_BOUND SEARCH ===\n";

    std::vector<int> sorted{
        1, 3, 5, 7, 9
    };

    std::cout << "7 at "
              << findSorted(sorted, 7)
              << '\n';

    std::cout << "8 at "
              << findSorted(sorted, 8)
              << '\n';

    std::cout << "\n=== VARIATION 5: MAP find VS [] ===\n";

    std::map<std::string, int> marks{
        {"Asha", 95}
    };

    auto found =
        marks.find("Ravi");

    std::cout << "Ravi exists? "
              << (found != marks.end())
              << '\n';

    std::cout << "Size before [] = "
              << marks.size()
              << '\n';

    int insertedDefault =
        marks["Ravi"];

    std::cout << "Default value = "
              << insertedDefault
              << '\n';

    std::cout << "Size after [] = "
              << marks.size()
              << '\n';

    std::cout << "\n=== VARIATION 6: CONST REFERENCE PARAMETER ===\n";

    std::cout << "Sum without vector copy = "
              << sumValues(values)
              << '\n';

    std::cout
        << "\nNext: "
        << "02_INTRO_TO_DATA_STRUCTURES__/"
        << "01_WHAT_ARE_DATA_STRUCTURES/\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: PROMOTE BEFORE MULTIPLY ===
Safe result = 2000000000

=== VARIATION 2: ACCUMULATOR TYPE ===
Sum = 3000000000

=== VARIATION 3: HALF-OPEN INDEX LOOP ===
0:10 1:20 2:30 3:40

=== VARIATION 4: LOWER_BOUND SEARCH ===
7 at 3
8 at -1

=== VARIATION 5: MAP find VS [] ===
Ravi exists? false
Size before [] = 1
Default value = 0
Size after [] = 2

=== VARIATION 6: CONST REFERENCE PARAMETER ===
Sum without vector copy = 100

Next: 02_INTRO_TO_DATA_STRUCTURES__/01_WHAT_ARE_DATA_STRUCTURES/
*/
