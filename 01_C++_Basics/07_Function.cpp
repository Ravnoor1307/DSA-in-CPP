#include <iostream>
#include <cmath>
using namespace std;

// Function Defination
int printHello()
{
    cout << "Hello" << endl;
    return 3;
}

// Sum of two numbers
double sum(double a, double b)
{
    return a + b;
}

// min of two numbers
int min(int a, int b)
{
    int min;
    if (a < b)
    {
        min = a;
    }
    else
    {
        min = b;
    }
    return min;
}

// sum of numbers from 1 to n
int sum_1_to_n(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

// factorial of nth number
int fact(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Pass by value
void changeX(int x)
{
    x = x * 2;
    cout << "X : " << x << endl;
}

// Sum of digit of numbers
int sum_of_digit_of_numbers(int num)
{
    int sum = 0;
    while (num != 0)
    {
        int remainder = num % 10;
        sum += remainder;
        num /= 10;
    }
    return sum;
}

// nCr binomial coffecients
int nCr(int n, int r)
{
    // nCr = n! /(r! * (n-r)!)
    int result = (fact(n)) / (fact(r) * fact(n - r));
}

// func for checking prime number
bool isPrime(int n)
{
    // Handle edge cases
    if (n <= 1)
        return false; // 0, 1, and negatives are not prime
    if (n == 2)
        return true; // 2 is prime
    if (n % 2 == 0)
        return false; // Even numbers > 2 are not prime

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// all prime numbers from 2 to n
void allPrimeNumbers(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
}



int main()
{

    // Function Call
    int value = printHello();
    cout << "Value : " << value << endl
         << endl;

    cout << printHello() << endl;

    // Sum of two numbers

    cout << endl
         << sum(34.7646, 564.674) << endl;

    // min of two numbers
    cout << endl
         << min(34, 65) << endl;

    // sum of numbers from 1 to n
    cout << endl
         << "Sum : " << sum_1_to_n(50) << endl;

    // factorial of nth number
    cout << endl
         << "Factorial : " << fact(5) << endl
         << endl;

    // Pass by  value
    int x = 5;
    changeX(x);
    cout << endl
         << "X : " << x << endl;

    // Sum of digit of numbers
    cout << endl
         << "Sum of digits of a number : " << sum_of_digit_of_numbers(12345) << endl;

    // nCr binomial coffecients
    cout << endl
         << "nCr binnomial coffecients of 5C2 is : " << nCr(5, 2) << endl;

    // func for checking prime number
    int num;
    cout <<endl<<endl<< "Enter number : ";
    cin >> num;

    if (isPrime(num))
    {
        cout << endl
             << num << " is a prime number.\n";
    }
    else
    {
        cout << endl
             << num << " is not a prime number.\n";
    }

    // all prime numbers from 2 to n
    cout<<endl<<endl<<"Prime Numbers between 1 to 50 are : "<<endl;
    allPrimeNumbers(50);
    
    return 0;
}