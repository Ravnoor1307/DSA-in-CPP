#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    // Feature 1: Procedural programming
    int a = 10;
    int b = 20;

    cout << "=== Procedural Programming ===\n";
    cout << "Sum: " << a + b << "\n\n";

    // Feature 2: Strongly expressed data types
    cout << "=== Data Types ===\n";

    int age = 20;
    double price = 49.99;
    char grade = 'A';
    bool isLearning = true;

    cout << "Age: " << age << '\n';
    cout << "Price: " << price << '\n';
    cout << "Grade: " << grade << '\n';
    cout << "Learning C++: " << std::boolalpha
              << isLearning << "\n\n";

    // Feature 3: Standard library strings
    cout << "=== Strings ===\n";

    string language = "C++";
    cout << "Learning " << language << "\n\n";

    // Feature 4: Standard library containers and algorithms
    cout << "=== Generic Programming and STL ===\n";

    vector<int> numbers = {5, 2, 8, 1, 3};

    sort(numbers.begin(), numbers.end());

    cout << "Sorted numbers: ";

    for (int number : numbers) {
        cout << number << ' ';
    }

    cout << '\n';

    return 0;
}