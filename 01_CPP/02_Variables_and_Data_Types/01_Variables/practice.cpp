
#include <iostream>
using namespace std;
int main() {
    // =====================================================
    // EXERCISE 1: Declare and initialize variables
    // =====================================================
    // TODO:
    // 1. Create an integer variable named studentAge.
    // 2. Initialize it with your chosen age.
    // 3. Create a double named percentage and initialize it.
    // 4. Display both values.

    int studentAge{18};
    double percentage{75.5};

    cout << "=== Exercise 1 ===\n";
    cout << "Student age: " << studentAge << '\n';
    cout << "Percentage: " << percentage << '\n';


    // =====================================================
    // EXERCISE 2: Assignment
    // =====================================================
    // TODO:
    // 1. Start with a score of 0.
    // 2. Add 10 to the score.
    // 3. Add another 20.
    // 4. Display the final score.
    //
    // Expected final score: 30

    int score{0};

    // Write your assignments here.
    score = score + 10;
    score = score + 20;

    cout << "\n=== Exercise 2 ===\n";
    cout << "Final score: " << score << '\n';


    // =====================================================
    // EXERCISE 3: Arithmetic using variables
    // =====================================================
    // TODO:
    // Calculate the total price of 4 items costing
    // 25.50 each.
    //
    // Formula:
    // totalPrice = pricePerItem * quantity
    //
    // Expected result: 102

    double pricePerItem{25.50};
    int quantity{4};

    double totalPrice{0.0};

    // Replace this line with your calculation.
    totalPrice = pricePerItem * quantity;

    cout << "\n=== Exercise 3 ===\n";
    cout << "Total price: " << totalPrice << '\n';


    // =====================================================
    // EXERCISE 4: Naming practice
    // =====================================================
    // TODO:
    // Declare suitable variables for:
    // 1. The number of books.
    // 2. The average marks of a student.
    // 3. Whether a student is enrolled.
    //
    // Use meaningful names and appropriate types.

    int numberOfBooks{5};
    double averageMarks{82.5};
    bool isEnrolled{true};

    cout << "\n=== Exercise 4 ===\n";
    cout << "Books: " << numberOfBooks << '\n';
    cout << "Average marks: " << averageMarks << '\n';
    cout << "Enrolled: " << std::boolalpha
              << isEnrolled << '\n';


    // =====================================================
    // EXERCISE 5: Update a variable
    // =====================================================
    // TODO:
    // A player starts with 100 points.
    // The player earns 25 points and then loses 15.
    // Update the same variable after each operation.
    //
    // Expected final points: 110

    int playerPoints{100};

    // Write the two assignments here.
    playerPoints = playerPoints + 25;
    playerPoints = playerPoints - 15;

    cout << "\n=== Exercise 5 ===\n";
    cout << "Player points: " << playerPoints << '\n';


    // =====================================================
    // EXERCISE 6: Integer versus decimal division
    // =====================================================
    // TODO:
    // Store the result of 9 / 2 in an int.
    // Store the result of 9.0 / 2.0 in a double.
    // Display both results and explain the difference
    // in your own words in notes.md.

    int integerDivision{9 / 2};
    double decimalDivision{9.0 / 2.0};

    cout << "\n=== Exercise 6 ===\n";
    cout << "Integer division: " << integerDivision << '\n';
    cout << "Decimal division: " << decimalDivision << '\n';


    // =====================================================
    // CHALLENGE: Simple student report
    // =====================================================
    // TODO:
    // 1. Create variables for a student's age and marks.
    // 2. Store marks for three subjects.
    // 3. Calculate the total marks.
    // 4. Calculate the average using floating-point division.
    // 5. Display all values with meaningful labels.
    //
    // Suggested subject marks: 80, 90, and 85
    // Expected total: 255
    // Expected average: 85

    int studentMaths{80};
    int studentScience{90};
    int studentEnglish{85};

    int totalMarks{
        studentMaths + studentScience + studentEnglish
    };

    double average{
        totalMarks / 3.0
    };

    cout << "\n=== Student Report Challenge ===\n";
    cout << "Total marks: " << totalMarks << '\n';
    cout << "Average marks: " << average << '\n';

    return 0;
}
