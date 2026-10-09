#include <iostream>
#include <string>
using namespace std;
int main()
{
    // Exercise 1:
    // Declare an integer variable named score and initialize it to 95.
    // TODO: Write your code here.
    int score = 95;

    // Exercise 2:
    // Declare a string named studentName and initialize it with your name.
    // TODO: Write your code here.
    string studentName = "Ravnoor Singh";

    // Exercise 3:
    // Declare two integers, first and second, with values 12 and 8.
    // Calculate their sum in a variable named total.
    // TODO: Write your code here.
    int first = 12;
    int second = 8;
    int total = first + second;

    // Exercise 4:
    // Print score, studentName, and total.
    // TODO: Write your code here.
    cout << "Score : " << score << endl
         << "Student Name : " << studentName << endl
         << "Total : " << total << endl;

    // Exercise 5:
    // Create a block with braces and declare an integer named localValue
    // inside it. Print localValue inside the block.
    // TODO: Write your code here.
    {
        int localValue = 10;
        cout << "Local Value : " << localValue << endl;
    }

    // Exercise 6:
    // Declare a double named rectangleLength with value 5.0.
    // Declare a double named rectangleWidth with value 3.0.
    // Calculate and print the rectangle's area.
    // TODO: Write your code here.
    double rectangleLength = 5.0;
    double rectangleWidth = 3.0;
    double area = rectangleLength * rectangleWidth;
    cout << "Area of Rectangle : " << area << endl;

    // Exercise 7:
    // Add a comment explaining what the program does.
    // TODO: Write your comment here.
    /*
    The above programm performs the calculation of area
    first the length and breadth both are intialized and then the area is calculated and then printed */

    return 0;
}