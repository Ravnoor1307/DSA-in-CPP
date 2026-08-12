#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    // Declares an empty vector
    vector<int> v1;

    // Declares vector with given size
    // and fills it with a value
    vector<int> v2(3, 5);

    // Print items of v2
    for (int x : v2)
    {
        cout << x << " ";
    }

    cout << endl;

    // Initializes vector using
    // initializer list.
    vector<int> v3 = {1, 2, 3};

    // Print items of v3
    for (int x : v3)
    {
        cout << x << " ";
    }

    // Functions

    vector<char> vec = {'a', 'f', 'd'};

    // Inserting 'z' at the back
    vec.push_back('z');

    // Inserting 'c' at index 1
    vec.insert(vec.begin() + 1, 'c');

    for (char i : vec)
        cout << i << " ";

    // Accessing using operator[]
    cout << "Element at index 2 using []: " << vec[2] << endl;

    // Accessing using at()
    cout << "Element at index 3 using at(): " << vec.at(3) << endl;

    // Uncommenting the next line will throw an
    // out_of_range exception
    // cout v.at(10)<<endl;

    vector<int> v4 = {10, 20, 30};
    cout << "Original value at index 1: " << v4[1] << endl;

    // Updating the element at index i
    v4[1] = 50;

    cout << "Updated value at index 1: " << v4[1] << endl;

    vector<char> v5 = {'a', 'c', 'f', 'd', 'z'};

    // Finding size
    cout << v5.size();

    vector<char> v6 = {'a', 'c', 'f', 'd', 'z'};

    // Range-based loop
    for (char i : v6)
        cout << i << " ";

    // Deleting last element 'z'
    v6.pop_back();

    // Deleting element 'f'
    v6.erase(find(v6.begin(), v6.end(), 'f'));

    for (int i = 0; i < v6.size(); i++)
    {
        cout << v6[i] << " ";
    }

    vector<int> v7;

    // Check if the vector is empty
    if (v7.empty())
    {
        cout << "Vector is empty." << endl;
    }

    // Add an element
    v7.push_back(100);
    if (!v7.empty())
    {
        cout << "Vector is not empty. First element " << v7[0] << endl;
    }
    return 0;
}