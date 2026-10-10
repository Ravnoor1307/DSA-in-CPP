#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
int main() {
    // 1. Integer types
    short smallCount = 120;
    int age = 20;
    long populationEstimate = 1000000L;
    long long largeTotal = 9000000000LL;

    cout << "=== Integer Types ===\n";
    cout << "short: " << smallCount << '\n';
    cout << "int: " << age << '\n';
    cout << "long: " << populationEstimate << '\n';
    cout << "long long: " << largeTotal << "\n\n";

    // 2. Floating-point types
    float height = 1.75f;
    double percentage = 87.65;
    long double measurement = 123.456789L;

    cout << "=== Floating-Point Types ===\n";
    cout << std::fixed << std::setprecision(2);
    cout << "float height: " << height << '\n';
    cout << "double percentage: " << percentage << '\n';
    cout << "long double measurement: "
              << measurement << "\n\n";

    // 3. Character type
    char grade = 'A';
    char initial = 'R';

    cout << "=== Character Type ===\n";
    cout << "Grade: " << grade << '\n';
    cout << "Initial: " << initial << "\n\n";

    // 4. Boolean type
    int score = 85;
    bool passed = score >= 40;

    cout << "=== Boolean Type ===\n";
    cout << std::boolalpha;
    cout << "Passed: " << passed << "\n\n";

    // 5. String type
    string firstName = "Alex";
    string lastName = "Sharma";
    string fullName = firstName + " " + lastName;

    cout << "=== String Type ===\n";
    cout << "Full name: " << fullName << "\n\n";

    // 6. Signed and unsigned integers
    int temperatureChange = -8;
    unsigned int numberOfItems = 50;

    cout << "=== Signed and Unsigned ===\n";
    cout << "Temperature change: "
              << temperatureChange << '\n';
    cout << "Number of items: "
              << numberOfItems << "\n\n";

    // 7. Inspect sizes and limits
    cout << "=== Type Sizes (bytes) ===\n";
    cout << "sizeof(char): " << sizeof(char) << '\n';
    cout << "sizeof(short): " << sizeof(short) << '\n';
    cout << "sizeof(int): " << sizeof(int) << '\n';
    cout << "sizeof(long): " << sizeof(long) << '\n';
    cout << "sizeof(long long): "
              << sizeof(long long) << '\n';
    cout << "sizeof(float): " << sizeof(float) << '\n';
    cout << "sizeof(double): " << sizeof(double) << '\n';
    cout << "sizeof(long double): "
              << sizeof(long double) << "\n\n";

    cout << "Bits per byte: " << CHAR_BIT << '\n';
    cout << "Maximum int: "
              << numeric_limits<int>::max() << '\n';
    cout << "Minimum int: "
              << numeric_limits<int>::min() << '\n';
    cout << "Maximum unsigned int: "
              << numeric_limits<unsigned int>::max()
              << '\n';
    cout << "Lowest finite double: "
              << numeric_limits<double>::lowest() << '\n';
    cout << "Maximum finite double: "
              << numeric_limits<double>::max() << '\n';

    return 0;
}
