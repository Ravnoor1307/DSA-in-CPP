/*
=======================================================================
 THEORY : Variables, Data Types and Storage Classes
=======================================================================
 1. VARIABLE
    - A variable is a named memory location used to store data.
    - Its value can be changed while the program runs.
    - Syntax:  data_type variable_name = value;

 2. DATA TYPES used in this file
    - int      : whole numbers            (e.g. 10, -3)      ~4 bytes
    - char     : single character         (e.g. 'A')         ~1 byte
    - bool     : true (1) or false (0)                        ~1 byte
    - float    : decimal number           (e.g. 36.5)        ~4 bytes
    - double   : decimal number, more precision               ~8 bytes
    - array    : collection of same type elements
    - pointer  : stores the memory ADDRESS of a variable
    - reference: an alias (another name) for an existing variable
    - void     : no return value / no data
    - string   : sequence of characters (needs <string>)

 3. #define Side 5
    - Creates a MACRO. The preprocessor replaces every occurrence
      of `Side` with the literal 5 before compilation.
    - Macros do not consume memory at run time.

 4. GLOBAL vs LOCAL variables
    - Global : declared OUTSIDE all functions; accessible everywhere.
                  int x = 5;
    - Local  : declared INSIDE a function/block; scope limited to
               that block only.  e.g. int y = 30;

 5. SCOPE LOSOSTE of variables
    - Local variable shadows a global variable with the same name.

 6. const
    - A constant variable whose value CANNOT be modified after
      initialisation. Trying to modify it gives a compile error.
        const int c = 24;  c = 0;  // ERROR

 7. STRUCT / CLASS / UNION
    - struct  : user-defined type; by default all members are public.
    - class   : user-defined type; by default members are private,
                here we made them public explicitly.
    - union   : all members SHARE the same memory location; only one
                member holds a value at a time.

 8. sizeof()
    - Operator that returns the number of bytes a type/variable uses.
        sizeof(int)   -> typically 4
        sizeof(double) -> typically 8

 9. ASSIGNMENT
    - int num1 = 4, num2;  num2 = num1;   // copies value of num1
=======================================================================
*/
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