/*
=======================================================================
 THEORY : Introduction to C++
=======================================================================
 1. C++ is a general-purpose, high-level programming language.
    It extends the C language by adding Object-Oriented Programming
    (classes, objects, inheritance, polymorphism) features.

 2. #include <iostream>
    - A preprocessor directive that tells the compiler to include the
      iostream (input/output stream) header file.
    - iostream provides the objects `cin` (input) and `cout` (output).

 3. using namespace std;
    - Says "use the standard namespace".
    - Allows us to write `cout` and `cin` directly instead of
      `std::cout` and `std::cin`.

 4. int main()
    - main() is the entry point of every C++ program. Program
      execution always starts from this function.
    - The `int` before main means the function returns an integer
      (an exit status code) to the operating system.

 5. cout << "Hello World" << endl;
    - cout  -> console output (prints on screen).
    - <<    -> insertion operator (pushes data into cout).
    - endl  -> end line; inserts a newline and flushes the buffer.
    - \n    -> alternative (faster) way to add a newline.

 6. return 0;
    - Returns 0 from main, which indicates successful execution
      of the program to the operating system.
    - Non-zero return values indicate an error/abnormal termination.

 EXPECTED OUTPUT:
     Hello World
=======================================================================
*/
#include<iostream>
using namespace std;
int main(){

    cout<<"Hello World"<<endl;

return 0;
}