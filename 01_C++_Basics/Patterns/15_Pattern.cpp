/*
=======================================================================
 THEORY : Pattern Printing - Hollow Diamond
=======================================================================
 To print a HOLLOW shape, print a star only at the first and the last
 column of every row; use spaces in between (the "hole").
    - if (i == 0) there is only ONE star (top tip)
    - inner loop prints (2*i - 1) spaces between the two stars

 PATTERN 15 (Hollow diamond):
    TOP HALF  : i = 0..n-1
        print (n-i-1) spaces, '*', middle (2i-1) spaces, '*'
    BOTTOM HALF: i = 0..n-2  (mirror of the top half)

 EXPECTED OUTPUT (n = 4):
       *
      * *
     *   *
    *     *
     *   *
      * *
       *
=======================================================================
*/
#include<iostream>
using namespace std;
int main(){

    int n = 4;


    for(int i = 0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<"*";

        if(i != 0){
            for(int j=0;j<2*i -1;j++){
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=0;i<n-1;i++){
        for(int j = 0;j<i+1;j++){
            cout<<" ";
        }
        
        cout<<"*";

        if(i != n-2){
            for(int j = 0;j<2*(n-i)-5;j++){
                cout<<" ";
            }cout<<"*";
        }
        cout<<endl;
    }
 
return 0;
}