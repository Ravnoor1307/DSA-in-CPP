
#include <iostream>
#include <string>
using namespace std;
int main() {
    // 1. Declaration followed by assignment
    int score;
    score = 85;

    cout << "=== Declaration and Assignment ===\n";
    cout << "Score: " << score << '\n';

    // 2. Copy initialization
    int age = 20;

    // 3. Direct initialization
    double price(99.50);

    // 4. Direct-list initialization
    int quantity{3};

    // 5. Copy-list initialization
    char grade = {'A'};

    cout << "\n=== Initialization Forms ===\n";
    cout << "Age: " << age << '\n';
    cout << "Price: " << price << '\n';
    cout << "Quantity: " << quantity << '\n';
    cout << "Grade: " << grade << '\n';

    // 6. Value initialization
    int counter{};
    double balance{};
    bool isActive{};

    cout << "\n=== Value Initialization ===\n";
    cout << "Counter: " << counter << '\n';
    cout << "Balance: " << balance << '\n';
    cout << boolalpha;
    cout << "Is active: " << isActive << '\n';

    // 7. Reassignment
    counter = 5;
    counter = counter + 2;

    cout << "\n=== Assignment ===\n";
    cout << "Updated counter: " << counter << '\n';

    // 8. Constants
    const int maximumAttempts{3};

    cout << "\n=== Constant ===\n";
    cout << "Maximum attempts: "
              << maximumAttempts << '\n';

    // 9. String initialization
    string studentName{"Aman"};
    string emptyName{};

    cout << "\n=== String Initialization ===\n";
    cout << "Student name: " << studentName << '\n';
    cout << "Empty name length: "
              << emptyName.size() << '\n';

    // 10. Demonstrating that only initialized values
    // should be read.
    int result{};
    result = 10 + 20;

    cout << "\n=== Safe Calculation ===\n";
    cout << "Result: " << result << '\n';

    return 0;
}
