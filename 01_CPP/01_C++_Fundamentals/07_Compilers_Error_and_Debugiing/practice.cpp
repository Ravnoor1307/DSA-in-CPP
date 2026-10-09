#include <cassert>
#include <iostream>
#include <string>
using namespace std;
// Exercise 1:
// Fix the compilation error in this function.
int calculateSum(int first, int second)
{
    int sum = first + second;
    return sum;
}

// Exercise 2:
// Fix the logical error in this function.
// It should calculate the area of a rectangle.
int calculateArea(int length, int width)
{
    return length * width;
}

// Exercise 3:
// Fix the average calculation so it preserves decimal values.
double calculateAverage(int total, int count)
{
    return double(total) / count;
}

// Exercise 4:
// Add a guard against count being zero.
// Decide how the function should handle invalid input.
bool tryCalculateAverage(int total, int count, double &average)
{
    // TODO: Return false if count is zero.
    if (count != 0)
    {
        average = total / count;
        return true;
    }
    // TODO: Otherwise calculate the average and return true.
    return false;
}

// Exercise 5:
// Add assertions to verify the expected results.
void testFunctions()
{
    // Uncomment and complete these checks after fixing the functions.
    assert(calculateSum(10, 20) == 30);
    assert(calculateArea(5, 3) == 15);
    assert(calculateAverage(241, 3) > 80.3);
    assert(calculateAverage(241, 3) < 80.4);
}

// Exercise 6:
// Complete the TODOs in main() and test your fixes.
int main()
{
    cout << "=== Debugging Practice ===\n";

    // TODO: Print the sum of 10 and 20.
    calculateSum(10, 20);
    // TODO: Print the area of a rectangle with length 5 and width 3.
    calculateArea(5, 3);
    // TODO: Print the average of 241 and 3.
    calculateAverage(241, 3);
    // TODO: Test tryCalculateAverage() with a valid count.
    double avg;
    tryCalculateAverage(241, 3,avg);
    // TODO: Test tryCalculateAverage() with count = 0.
    tryCalculateAverage(241, 0,avg);

    // TODO: Call testFunctions() after enabling the assertions.
    testFunctions();
    return 0;
}