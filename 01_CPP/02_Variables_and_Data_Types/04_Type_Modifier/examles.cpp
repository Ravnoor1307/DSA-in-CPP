#include <climits>
#include <iostream>
#include <limits>
using namespace std;
int main() {
    // 1. Signed integers
    signed int temperatureChange = -8;
    int scoreDifference = -15;

    cout << "=== Signed Integers ===\n";
    cout << "Temperature change: "
              << temperatureChange << '\n';
    cout << "Score difference: " << scoreDifference << "\n\n";

    // 2. Unsigned integers
    unsigned int itemCount = 50;
    unsigned short int smallCount = 120;

    cout << "=== Unsigned Integers ===\n";
    cout << "Item count: " << itemCount << '\n';
    cout << "Small count: " << smallCount << "\n\n";

    // 3. Short, long, and long long
    short int shortNumber = 120;
    long int longNumber = 1000000L;
    long long int largeNumber = 9000000000LL;

    cout << "=== Integer Type Modifiers ===\n";
    cout << "short int: " << shortNumber << '\n';
    cout << "long int: " << longNumber << '\n';
    cout << "long long int: " << largeNumber << "\n\n";

    // 4. Unsigned long and unsigned long long
    unsigned long int longCount = 200000UL;
    unsigned long long int veryLargeCount = 9000000000ULL;

    cout << "=== Unsigned Long Types ===\n";
    cout << "unsigned long: " << longCount << '\n';
    cout << "unsigned long long: "
              << veryLargeCount << "\n\n";

    // 5. Long double
    long double measurement = 123.456789L;

    cout << "=== Floating-Point Modifier ===\n";
    cout << "long double: " << measurement << "\n\n";

    // 6. Inspect sizes
    cout << "=== Type Sizes in C++ Bytes ===\n";
    cout << "sizeof(short): " << sizeof(short) << '\n';
    cout << "sizeof(int): " << sizeof(int) << '\n';
    cout << "sizeof(long): " << sizeof(long) << '\n';
    cout << "sizeof(long long): "
              << sizeof(long long) << '\n';
    cout << "sizeof(long double): "
              << sizeof(long double) << "\n\n";

    cout << "Bits per byte: " << CHAR_BIT << "\n\n";

    // 7. Inspect numeric limits
    cout << "=== Numeric Limits ===\n";
    cout << "Minimum int: "
              << numeric_limits<int>::min() << '\n';
    cout << "Maximum int: "
              << numeric_limits<int>::max() << '\n';
    cout << "Maximum unsigned int: "
              << numeric_limits<unsigned int>::max() << '\n';
    cout << "Maximum long long: "
              << numeric_limits<long long>::max() << '\n';
    cout << "Maximum unsigned long long: "
              << numeric_limits<unsigned long long>::max()
              << '\n';

    // 8. Demonstrate unsigned wraparound safely
    unsigned int value = 0;
    --value;

    cout << "\n=== Unsigned Wraparound ===\n";
    cout << "Maximum unsigned int after decrementing zero: "
              << value << '\n';

    return 0;
}
