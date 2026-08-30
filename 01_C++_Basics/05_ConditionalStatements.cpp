/*
=======================================================================
 THEORY : Conditional Statements (Decision Making)
=======================================================================
 Conditional statements execute a block of code only when a certain
 condition is true. They control the flow of a program.

 1. if statement
        if (condition) {  // body executed only if condition is true }
    - For a single-line body braces can be omitted.

 2. if-else
        if (condition) { ... } else { ... }
    - else block runs when the condition is false.

 3. if-else if-else  (ladder)
        if (c1) { ... }
        else if (c2) { ... }
        else { ... }
    - Checks conditions from top to bottom; the FIRST true block runs
      and the remaining conditions are skipped.

 4. switch statement
        switch(expr){ case val: ... break; default: ... }
    - More readable replacement for many if-else-if when testing one
      variable against fixed values.
    - `break` stops fall-through to the next case.
    - `default` executes when no case matches (optional).

 5. TERNARY (conditional) OPERATOR
        variable = (condition) ? value_if_true : value_if_false;
    - A shorthand for the if-else that returns a value.
        max = (num1 > num2) ? num1 : num2;
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    int age = 19;

    // Check if age is greater than 18 fo
    // vote eligiblity
    if (age > 18)
    {
        cout << "allowed to vote" << endl;
    }

    // One line Code can also be Written as
    if (age > 18)
        cout << "allowed to vote" << endl;

    int n = 5;
    // Using if-else to determine if the number is positive
    // or non positive
    if (n > 0)
    {
        cout << "number is positive." << endl;
    }
    else
    {
        cout << "number is non-positive." << endl;
    }

    // Using if-elseif-else statement

    // if this condition is true child is printed
    if (age < 13)
    {
        cout << "child" << endl;
    }

    // if above if statement is not true then we check
    // this else if condition if it evaluates to true print
    // growing age
    else if (age >= 1 and age <= 18)
    {
        cout << "Growing stage" << endl;
    }

    // if none of above condition is true print adult
    else
    {
        cout << "adult" << endl;
    }

    // Switch Case

    char c = 'B';
    switch (c)
    {

    // if the input character is A then print GFG
    case 'A':
        cout << "HTML" << endl;
        break;

    // if the input character is B then print
    // GeeksforGeeks
    case 'B':
        cout << "Hyper Text Markup Language" << endl;
        break;
    default:

        // if the input character is invalid then print
        // invalid input
        cout << "invalid input";
    }

    // Ternary Operator

    int num1 = 10, num2 = 40;
    int max;

    // if the condition is true then num1 will be printed
    // else num2 will be printed
    max = (num1 > num2) ? num1 : num2;
    cout << max;

    return 0;
}