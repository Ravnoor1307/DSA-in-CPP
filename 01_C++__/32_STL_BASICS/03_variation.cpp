/*
Topic: STL Basics
File: 03_variation.cpp

Purpose:
Explore:
- custom sorting
- lower_bound / upper_bound
- unordered maps
- min-priority queues
- iterator positions
- safe map lookup

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

struct Student {
    std::string name;
    int marks;
};

int main() {
    std::cout << std::boolalpha;

    // ========== SECTION 1: CUSTOM SORT ==========

    std::cout << "=== VARIATION 1: custom sort ===\n";

    std::vector<Student> students{
        {"Ravi", 80},
        {"Asha", 95},
        {"Mina", 80},
        {"John", 90}
    };

    std::sort(
        students.begin(),
        students.end(),
        [](const Student& a, const Student& b) {
            if (a.marks != b.marks) {
                return a.marks > b.marks;
            }

            return a.name < b.name;
        }
    );

    for (const auto& student : students) {
        std::cout << student.name
                  << " "
                  << student.marks
                  << '\n';
    }

    // ========== SECTION 2: LOWER / UPPER BOUND ==========

    std::cout << "\n=== VARIATION 2: bounds ===\n";

    std::vector<int> sorted{
        1, 2, 2, 2, 4, 7
    };

    auto lower = std::lower_bound(
        sorted.begin(),
        sorted.end(),
        2
    );

    auto upper = std::upper_bound(
        sorted.begin(),
        sorted.end(),
        2
    );

    std::cout << "First 2 index = "
              << (lower - sorted.begin())
              << '\n';

    std::cout << "First >2 index = "
              << (upper - sorted.begin())
              << '\n';

    std::cout << "Frequency of 2 = "
              << (upper - lower)
              << '\n';

    // ========== SECTION 3: UNORDERED MAP ==========

    std::cout << "\n=== VARIATION 3: unordered_map ===\n";

    std::string word = "mississippi";

    std::unordered_map<char, int> frequency;

    for (char character : word) {
        ++frequency[character];
    }

    // Explicit key access keeps expected output deterministic.
    std::cout << "m -> "
              << frequency['m'] << '\n';

    std::cout << "i -> "
              << frequency['i'] << '\n';

    std::cout << "s -> "
              << frequency['s'] << '\n';

    std::cout << "p -> "
              << frequency['p'] << '\n';

    // ========== SECTION 4: MIN PRIORITY QUEUE ==========

    std::cout << "\n=== VARIATION 4: min priority_queue ===\n";

    std::priority_queue<
        int,
        std::vector<int>,
        std::greater<int>
    > minHeap;

    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(20);

    while (!minHeap.empty()) {
        std::cout << minHeap.top()
                  << ' ';

        minHeap.pop();
    }

    std::cout << '\n';

    // ========== SECTION 5: ITERATOR INDEX ==========

    std::cout << "\n=== VARIATION 5: iterator position ===\n";

    std::vector<int> numbers{
        10, 20, 30, 40
    };

    auto found = std::find(
        numbers.begin(),
        numbers.end(),
        30
    );

    if (found != numbers.end()) {
        std::cout << "30 at index "
                  << (found - numbers.begin())
                  << '\n';
    }

    // ========== SECTION 6: MAP LOOKUP WITHOUT INSERT ==========

    std::cout << "\n=== VARIATION 6: map lookup ===\n";

    std::map<std::string, int> ages{
        {"Asha", 20},
        {"Ravi", 21}
    };

    auto person = ages.find("Mina");

    std::cout << "Mina exists? "
              << (person != ages.end())
              << '\n';

    // ages["Mina"] would insert a default int value if absent.
    std::cout << "Map size remains = "
              << ages.size()
              << '\n';

    std::cout << "\nNext: 33_C++_FOR_COMPETITIVE_PROGRAMMING\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: custom sort ===
Asha 95
John 90
Mina 80
Ravi 80

=== VARIATION 2: bounds ===
First 2 index = 1
First >2 index = 4
Frequency of 2 = 3

=== VARIATION 3: unordered_map ===
m -> 1
i -> 4
s -> 4
p -> 2

=== VARIATION 4: min priority_queue ===
10 20 30

=== VARIATION 5: iterator position ===
30 at index 2

=== VARIATION 6: map lookup ===
Mina exists? false
Map size remains = 2

Next: 33_C++_FOR_COMPETITIVE_PROGRAMMING
*/
