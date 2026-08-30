/*
=======================================================================
 THEORY : Type Casting (Type Conversion) and User Input
=======================================================================
 1. TYPE CASTING is converting a value from one data type to another.
    Two kinds:

 2. IMPLICIT (Automatic) Conversion
    - Done automatically by the compiler when mixing types.
    - Smaller type is promoted to the larger type to avoid data loss.
        int a = 34;
        int sum = a + 45.45753;
      Here `a` is promoted to double, the sum is 79.45753, but since
      it is stored into an `int`, the fractional part is TRUNCATED
      and sum becomes 79.
    - Danger: implicit conversion may silently lose precision.

 3. EXPLICIT (Manual / Casting) Conversion
    - The programmer decides the target type using a cast.
        float b = 45.25455;
        int prod = a * (int)b;     // (int)b truncates 45.25455 -> 45
      So prod = 34 * 45 = 1530.
    - C-style cast:  (type)variable
    - C++ casts also include: static_cast<type>(x), dynamic_cast,
      const_cast, reinterpret_cast.

 4. USER INPUT with cin
    - cin (console input) reads data typed by the user.
        int age;
        cin >> age;
    - >> is the extraction operator.
    - Input is read from the keyboard and stored in the variable.

 EXPECTED OUTPUT (if user enters 20):
     Enter your age : 20
     Your age is : 20
=======================================================================
*/
#include <iostream>
using namespace std;
int main()
{

    // Implicit TypeConversion
    int a = 34;
    int sum = a + 45.45753;

    cout << sum << endl;

    // Explicite TypeConversion
    float b = 45.25455;
    int prod = a * (int)b;
    cout << prod << endl;

    // Taking Input

    int age;
    cout << "Enter your age : ";
    cin >> age;

    cout << "Your age is : " << age << endl;
    
    return 0;
}