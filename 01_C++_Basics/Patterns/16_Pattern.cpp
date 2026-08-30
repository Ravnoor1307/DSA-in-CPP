/*
=======================================================================
 THEORY : Pattern Printing - Butterfly / Diamond of Stars
=======================================================================
 Complex shapes = simple triangles combined:
    TOP HALF (i = 0..n-1):
        print (i+1) stars, (2*(n-i) - 2) spaces, (i+1) stars
    BOTTOM HALF (i = 0..n-1, mirror):
        print (n-i) stars, (2*i) spaces, (n-i) stars
    Together they make a diamond / butterfly of stars.

 EXPECTED OUTPUT (n = 4):
     *  *  *  *
     *  *  *  *  *  *  *  *
     *  *  *  *  *  *  *  *  *  *  *  *
     *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
     *  *  *  *  *  *  *  *
     *  *  *  *  *  *
     *  *  *  *
     *  *
 (shown with spaces for the middle gap, fine to visualise as:
    *                *
    * *            * *
    * * *        * * *
    * * * *    * * * *
    * * * *    * * * *   <- (this file repeats stars only)
    ...)
 The pattern simply grows to full width then shrinks back.
=======================================================================
*/
#include<iostream>
using namespace std;
int main(){

    int n=4;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<i+1;j++){
            cout<<" * ";
        }
        for(int k = 0;k< 2*(n-i) - 2;k++){
            cout<<"   ";
        }
        for(int l=0;l<i+1;l++){
            cout<<" * ";
        }
        cout<<endl;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i;j++){
            cout<<" * ";
        }
        for(int k=0;k<i*2;k++){
            cout<<"   ";
        }
        for(int l=0;l<n-i;l++){
            cout<<" * "; 
        }
        cout<<endl;
    }
 
return 0;
}