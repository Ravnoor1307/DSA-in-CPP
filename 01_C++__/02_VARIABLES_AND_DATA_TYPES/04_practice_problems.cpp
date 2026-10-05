/*
TOPIC: Variables and Data Types
FILE: 04_practice_problems.cpp

These are deliberately small exercises because input, operators,
conditions, and loops occur later in the roadmap.

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>

using namespace std;

int main() {

    // ========================================================
    // PROBLEM 1: STUDENT PROFILE
    // ========================================================
    //
    // Create variables representing:
    //
    // age       -> int
    // grade     -> char
    // percentage -> double
    // passed    -> bool
    //
    // Then display them.

    int age = 18;
    char grade = 'A';
    double percentage = 92.5;
    bool passed = true;

    cout << "=== PROBLEM 1: Student Profile ===\n";

    cout << "Age: " << age << '\n';
    cout << "Grade: " << grade << '\n';
    cout << "Percentage: " << percentage << '\n';

    cout << boolalpha;
    cout << "Passed: " << passed << '\n';
    cout << noboolalpha;

    cout << '\n';


    // ========================================================
    // PROBLEM 2: UPDATE A SCORE
    // ========================================================
    //
    // Start:
    //
    // score = 40
    //
    // Print it, change it to 85, and print it again.
    //
    // Dry run:
    //
    // score = 40
    // print 40
    //
    // score = 85
    // print 85

    int score = 40;

    cout << "=== PROBLEM 2: Update Score ===\n";

    cout << "Before: " << score << '\n';

    score = 85;

    cout << "After: " << score << "\n\n";


    // ========================================================
    // PROBLEM 3: VALUE COPYING
    // ========================================================
    //
    // Start:
    //
    // first = 10
    // second = first
    //
    // Then modify first.
    //
    // second must remain unchanged because it received a copy.

    int first = 10;
    int second = first;

    first = 50;

    cout << "=== PROBLEM 3: Value Copy ===\n";

    cout << "first = " << first << '\n';
    cout << "second = " << second << "\n\n";


    // ========================================================
    // PROBLEM 4: LARGE PRODUCT
    // ========================================================
    //
    // width and height are ints.
    //
    // Their mathematical product is:
    //
    // 100000 * 100000
    // = 10000000000
    //
    // This may not fit into a normal 32-bit int.
    //
    // Use 1LL so the multiplication happens as long long.

    int width = 100'000;
    int height = 100'000;

    long long area = 1LL * width * height;

    cout << "=== PROBLEM 4: Large Product ===\n";

    cout << "Area = " << area << "\n\n";


    // ========================================================
    // PROBLEM 5: CONSTANT
    // ========================================================
    //
    // DAYS_IN_WEEK should never change.
    //
    // Represent it with const.

    const int DAYS_IN_WEEK = 7;

    cout << "=== PROBLEM 5: Constant ===\n";

    cout << "Days in week = "
         << DAYS_IN_WEEK << "\n\n";


    // ========================================================
    // BONUS: PREDICT THE STATE
    // ========================================================
    //
    // Dry run:
    //
    // x = 5
    // y = x     -> y becomes 5
    // x = 9     -> only x changes
    // z = y     -> z becomes 5
    //
    // Final:
    //
    // x = 9
    // y = 5
    // z = 5

    int x = 5;
    int y = x;

    x = 9;

    int z = y;

    cout << "=== BONUS: Final State ===\n";

    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
    cout << "z = " << z << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Student Profile ===
Age: 18
Grade: A
Percentage: 92.5
Passed: true

=== PROBLEM 2: Update Score ===
Before: 40
After: 85

=== PROBLEM 3: Value Copy ===
first = 50
second = 10

=== PROBLEM 4: Large Product ===
Area = 10000000000

=== PROBLEM 5: Constant ===
Days in week = 7

=== BONUS: Final State ===
x = 9
y = 5
z = 5

PRACTICE LINKS

1. HackerRank:
https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

2. GFG:
https://www.geeksforgeeks.org/cpp-data-types/

3. LeetCode 2235:
https://leetcode.com/problems/add-two-integers/

4. LeetCode 2469:
https://leetcode.com/problems/convert-the-temperature/

5. GFG Variables:
https://www.geeksforgeeks.org/cpp-variables/

WHAT'S NEXT:
01_C++__/03_TYPE_CONVERSION_AND_CASTING/
*/
