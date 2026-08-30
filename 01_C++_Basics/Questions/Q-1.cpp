/*
=======================================================================
 THEORY : Q-1 - Digital Lock Security System (Hard)
=======================================================================
 This problem is a classic example of DIGIT EXTRACTION + CONDITIONAL
 validation. It combines all the basics into one realistic system.

  GOAL: Validate an 8-digit password against 5 rules:
    1) must be a POSITIVE integer
    2) must contain EXACTLY 8 digits
    3) sum of digits must be divisible by 7
    4) product of all NON-ZERO digits must be divisible by 9
    5) FIRST digit > LAST digit
    6) no two CONSECUTIVE digits may be equal

  DIGIT EXTRACTION TECHNIQUE (very important for DSA):
    while (temp != 0) {
        digit  = temp % 10;   // pull out the LAST digit
        temp  /= 10;          // drop that digit
    }
    This visits the digits from right to left.

  How each rule is checked while looping from RIGHT to LEFT:
    - digits_in_password            : count the loop iterations
    - sum_of_digits_of_password     : digit += every extracted digit
    - product_of_all_non_zero_digits: multiply if digit != 0
    - last_digit                    : the FIRST digit extracted
                                       (rightmost / units place)
    - first_digit                   : AFTER the whole loop, the last
                                       digit extracted (the leftmost)
    - consecutive-dup check         : compare each new digit with the
                                       `previous` digit; if equal, set
                                       flag and break.

  FALL-THROUGH VALIDATION (clean design pattern):
    Multiple independent rules are checked one by one; the moment a
    rule fails, the program prints "Invalid Password!" and returns
    early. Only if ALL checks pass do we print the success message.

  COMPLEXITY:
    Time  : O(d) where d = number of digits (d = 8 here) -> O(1)
    Space : O(1) (no extra arrays used)

  NOTE: Since digits are extracted right-to-left:
        first_digit (leftmost) is compared with last_digit
        (rightmost), exactly as the problem demands.
=======================================================================
*/

/*
# Question 1: Digital Lock Security System (Hard)

A digital lock accepts only passwords satisfying all these conditions:

* Password is a positive integer.
* It contains exactly **8 digits**.
* Sum of digits is divisible by **7**.
* Product of all non-zero digits is divisible by **9**.
* First digit must be greater than last digit.
* No two consecutive digits should be the same.

*/

#include <iostream>
using namespace std;
int main()
{

    long long password;
    cout << "Enter Password : ";
    cin >> password;

    // Calculating Digits of Password
    int digits_in_password = 0;
    long long temp_password = password;
    int sum_of_digits_of_password = 0;
    long long product_of_all_non_zero_digits = 1;
    bool two_same_consecutive_digits = false;
    int first_digit;
    int last_digit;
    int previous = -1;

    if (password <= 0)
    {
        cout << endl
             << "Invalid Password!" << endl;
        return 0;
    }
    else
    {

        while (temp_password != 0)
        {
            // Calculating Digits in Password
            int current_digit = temp_password % 10;
            digits_in_password += 1;

            // Calculating Sum of Digits
            sum_of_digits_of_password += current_digit;

            // Calculating Product of all Non-zero Digits
            if (current_digit != 0)
            {
                product_of_all_non_zero_digits *= current_digit;
            }

            // First Digit Must Be Grater Than Last Digit

            if (digits_in_password == 1)
            {
                last_digit = current_digit;
            }
            first_digit = current_digit;

            // Finding that no two consecutive digits should be same
            if (current_digit == previous)
            {
                two_same_consecutive_digits = true;
                break;
            }
            previous = current_digit;

            temp_password /= 10;
        }
    }

    // Main Condition
    if (digits_in_password != 8)
    {
        cout << "Invalid Password!";
        return 0;
    }

    if (sum_of_digits_of_password % 7 != 0)
    {
        cout << "Invalid Password!";
        return 0;
    }

    if (product_of_all_non_zero_digits % 9 != 0)
    {
        cout << "Invalid Password!";
        return 0;
    }

    if (first_digit <= last_digit)
    {
        cout << "Invalid Password!";
        return 0;
    }

    if (two_same_consecutive_digits)
    {
        cout << "Invalid Password!";
        return 0;
    }

    cout << "Congratulations! You have Entered a Correct Password!";

    return 0;
}