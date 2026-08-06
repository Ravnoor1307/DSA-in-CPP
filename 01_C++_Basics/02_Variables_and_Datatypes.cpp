#include <iostream>
using namespace std;

// Using #define to create a macro
#define Side 5

// Declaring gloabal variable

// Global variable
int x = 5;

void display()
{
    cout << x << endl;
}

// # Void Datatype
void display1()
{
    cout << "Hello";
}

// # Function Datatype
int add(int a, int b)
{
    return a + b;
}

// # Structure Datatype
struct Student
{
    string name;
    int age;
};

// # Class Datatype

class Student1
{

public:
    string name;
    int age;
};

// Union Datatype
union Data
{
    int i;
    float f;
};

int main()
{

    // Creating a variable to store integer
    int var = 10;

    cout << var;

    // Character variable
    char d = 'A';
    cout << d;

    // Creating a boolean variable
    bool isTrue = true;

    cout << isTrue;

    float f = 36.5f;

    double pi = 3.1415926535;

    // Array
    int arr[5] = {1, 2, 3, 4, 5};

    // Pointer
    int *ptr = &x;

    // Reference
    int &ref = x;

    // Declaring and defining a constant variable
    const int c = 24;
    cout << c << endl;

    // Trying to change the value constant c
    // c = 0;    // Displays an error
    // cout << c<<endl;

    // Accessing and Updating
    int num = 3;
    cout << endl
         << num << endl;
    // Updating Variable
    num = 5;
    cout << endl
         << num << endl;

    // Assigning num1's value to num2
    int num1 = 4, num2;
    num2 = num1;
    cout << num1 << " " << num2 << endl;

    // Using constant
    double area = Side * Side;
    cout << area << endl;

    // Declaring Local variable
    int y = 30;

    // Accessing x and y variables in their scope
    cout << x << " " << y << endl
         << endl;

    display();

    // Changing value of global from main function before calling display()
    x = 10;
    display();

    // sizeof

    int size_of_integer = sizeof(int);
    cout<<"Size of Integer : "<<size_of_integer<<endl;

    return 0;
}