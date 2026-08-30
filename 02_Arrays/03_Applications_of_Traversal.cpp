/*
=======================================================================
 THEORY : Applications of Array Traversal
=======================================================================
 Traversal is not just for printing - it is the engine behind many
 everyday operations on arrays. Two applications are shown here.

 1. SEARCHING AN ELEMENT
    - Walk the array comparing each element with the TARGET.
    - Use a bool flag `found` starting as false.
    - If arr[i] == target: set found = true and BREAK (we already
      found it - no need to continue).
    - After the loop, test the flag.
      This is nothing but LINEAR SEARCH.

 2. MODIFYING ELEMENTS (in-place update)
    - Visit every element and assign it a new value.
        price[i] += 15;    // increase every price by 15
    - In-place changes affect the ORIGINAL array (arrays are passed
      by reference in C when used directly).

 3. KEY POINTS
    - Search: best/still O(n) worst-case time (early break can stop
      sooner in the best case, e.g. target at index 0 -> O(1)).
    - Update: every element is touched -> O(n).

 COMPLEXITY:  both loops are O(n) time, O(1) space.
=======================================================================
*/
#include<iostream>
using namespace std;
int main(){

    // Searching Elements
    int marks[5] = {98, 90, 78, 79, 89};
    int size_of_marks = sizeof(marks) / sizeof(marks[0]);
    bool found = false;
    int target = 78;
    for(int i = 0;i < size_of_marks ; i++){
        if (marks[i] == target){
            found = true;
            break;
        }
    }
    if(found){
        cout<<"Element Found!"<<endl;
    }else{
        cout<<"Element Not Found!"<<endl;
    }

    cout << endl;


    // Modifying Elements
    double price[] = {35,60,50,40,100};
    int size_of_price = sizeof(price) / sizeof(price[0]);
    for(int i = 0; i < size_of_price ; i++){
        price[i] += 15;
    }
    cout << "Modified array: ";
    for(int i = 0; i < size_of_price; i++) {
        cout << price[i] << " ";
    }
    cout << endl;
return 0;
}