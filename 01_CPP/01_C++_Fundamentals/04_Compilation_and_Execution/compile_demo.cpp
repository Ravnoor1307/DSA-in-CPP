#include <iostream>
#include <string>
using namespace std;
int main() {
    std::string name = "C++ Learner";
    int firstNumber = 10;
    int secondNumber = 20;

    int sum = firstNumber + secondNumber;

    std::cout << "=== Compilation and Execution Demo ===\n";
    std::cout << "Program started successfully.\n\n";

    std::cout << "Name: " << name << '\n';
    std::cout << "First number: " << firstNumber << '\n';
    std::cout << "Second number: " << secondNumber << '\n';
    std::cout << "Sum: " << sum << '\n';

    std::cout << "\nProgram completed successfully.\n";

    return 0;
}