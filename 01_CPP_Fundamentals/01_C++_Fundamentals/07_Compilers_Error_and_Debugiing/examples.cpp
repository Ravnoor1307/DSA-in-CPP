#include <iostream>
using namespace std;
// Calculates the average of three marks.
double calculateAverage(int firstMark, int secondMark, int thirdMark) {
    int total = firstMark + secondMark + thirdMark;

    // Divide by 3.0 to preserve fractional results.
    double average = total / 3.0;

    return average;
}

int main() {
    const int firstMark = 80;
    const int secondMark = 90;
    const int thirdMark = 71;

    const int total = firstMark + secondMark + thirdMark;
    const double average =
        calculateAverage(firstMark, secondMark, thirdMark);

    // Diagnostic output helps verify intermediate values.
    cout << "[DEBUG] First mark: " << firstMark << '\n';
    cout << "[DEBUG] Second mark: " << secondMark << '\n';
    cout << "[DEBUG] Third mark: " << thirdMark << '\n';
    cout << "[DEBUG] Total: " << total << '\n';

    cout << "\n=== Result ===\n";
    cout << "Total marks: " << total << '\n';
    cout << "Average marks: " << average << '\n';

    return 0;
}