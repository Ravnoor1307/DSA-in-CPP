#include <iostream>
#include <limits>
using namespace std;

// TYPE MODIFIERS — PRACTICE WORKBOOK
//
// Instructions:
// 1. Attempt each task before reading the reference solution.
// 2. Explain why you chose each type.
// 3. Compile using C++17.
// 4. Test boundary cases whenever appropriate.

int main() {
    // --------------------------------------------------------
    // Exercise 1: Signed Integers
    // --------------------------------------------------------
    // Task:
    // Store a temperature change of -12 and a score difference
    // of 25 using appropriate signed integer variables.
    //
    // Reference solution:

    signed int temperatureChange = -12;
    int scoreDifference = 25;

    cout << "=== Exercise 1 ===\n";
    cout << "Temperature change: "
              << temperatureChange << '\n';
    cout << "Score difference: "
              << scoreDifference << "\n\n";

    // --------------------------------------------------------
    // Exercise 2: Unsigned Integers
    // --------------------------------------------------------
    // Task:
    // Store the number of books in a library.
    // Explain why an unsigned type can represent this count,
    // and why it may still be inappropriate in some programs.
    //
    // Reference solution:

    unsigned int bookCount = 500;

    cout << "=== Exercise 2 ===\n";
    cout << "Book count: " << bookCount << "\n\n";

    // --------------------------------------------------------
    // Exercise 3: Large Integer Values
    // --------------------------------------------------------
    // Task:
    // Store a value greater than 2,147,483,647 using a suitable
    // integer type when that value exceeds the range of int.
    //
    // Reference solution:

    long long largeValue = 5000000000LL;

    cout << "=== Exercise 3 ===\n";
    cout << "Large value: " << largeValue << "\n\n";

    // --------------------------------------------------------
    // Exercise 4: Inspect Type Limits
    // --------------------------------------------------------
    // Task:
    // Print the minimum and maximum values of short, int,
    // and long long.
    //
    // Reference solution:

    cout << "=== Exercise 4 ===\n";

    cout << "short minimum: "
              << numeric_limits<short>::min() << '\n';
    cout << "short maximum: "
              << numeric_limits<short>::max() << '\n';

    cout << "int minimum: "
              << numeric_limits<int>::min() << '\n';
    cout << "int maximum: "
              << numeric_limits<int>::max() << '\n';

    cout << "long long minimum: "
              << numeric_limits<long long>::min() << '\n';
    cout << "long long maximum: "
              << numeric_limits<long long>::max()
              << "\n\n";

    // --------------------------------------------------------
    // Exercise 5: Inspect Type Sizes
    // --------------------------------------------------------
    // Task:
    // Print the sizes of short, int, long, long long,
    // and long double.
    //
    // Reference solution:

    cout << "=== Exercise 5 ===\n";
    cout << "short: " << sizeof(short) << " byte(s)\n";
    cout << "int: " << sizeof(int) << " byte(s)\n";
    cout << "long: " << sizeof(long) << " byte(s)\n";
    cout << "long long: "
              << sizeof(long long) << " byte(s)\n";
    cout << "long double: "
              << sizeof(long double) << " byte(s)\n\n";

    // --------------------------------------------------------
    // Exercise 6: Find the Bug
    // --------------------------------------------------------
    // Task:
    // Explain why using unsigned int for a countdown can be
    // dangerous when the loop condition is i >= 0.
    //
    // Reference solution:
    //
    // An unsigned integer cannot become negative. Therefore,
    // i >= 0 is always true. Decrementing zero wraps around.
    //
    // Safer countdown when processing positive values:

    cout << "=== Exercise 6 ===\n";

    for (unsigned int i = 3; i > 0; --i) {
        cout << i << '\n';
    }

    cout << '\n';

    // --------------------------------------------------------
    // Exercise 7: Choose the Type
    // --------------------------------------------------------
    // Task:
    // Choose an appropriate type for each:
    // a. A temperature difference that can be negative
    // b. A large integer total
    // c. A measurement requiring floating-point values
    // d. A nonnegative item count
    //
    // Reference solution:

    int temperatureDifference = -5;
    long long total = 8000000000LL;
    long double measurement = 45.6789L;
    unsigned int itemCount = 250;

    cout << "=== Exercise 7 ===\n";
    cout << "Temperature difference: "
              << temperatureDifference << '\n';
    cout << "Total: " << total << '\n';
    cout << "Measurement: " << measurement << '\n';
    cout << "Item count: " << itemCount << '\n';

    return 0;
}
