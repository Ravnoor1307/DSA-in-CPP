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