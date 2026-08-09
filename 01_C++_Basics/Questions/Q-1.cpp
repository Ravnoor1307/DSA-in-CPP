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