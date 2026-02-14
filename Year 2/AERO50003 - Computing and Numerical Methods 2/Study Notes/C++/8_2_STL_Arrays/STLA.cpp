// array // a container which emulates a "C"-style fixed-size array

// array<datatype, length> identifier;

#include <iostream>
#include <array> // For STL std::array
using namespace std;

// Declare a function to print array
void printA(int a[], int l);
void printB(array<int, 5> a, int l);

int main()
{
    // Define array x
    int x[5] = {1, 2, 3, 4, 5};
    
    // Define same array by std:array
    array<int, 5> y = {1, 2, 3, 4, 5};
    
    // Arrays can be directly initialsed by std::array
    array<int, 5> z;
    z = y;    
    
    // Find size of array
    unsigned int n = size(y);
    
    // Compare array become easy
    if (z == y)
    {
        cout << "Array y equal to array z" << endl;
    }
    
    // Print the results
    cout << "Print Array x" << endl;
    printA(x, 5);
    
    cout << "Print Array y with size " << n << endl;
    printB(y, 5);

    cout << "Print Array z" << endl;
    printB(z, 5); 
    
	return 0;
}

// Defination
void printA(int a[], int l)
{
    for(int i = 0; i < l; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printB(array<int, 5> a, int l)
{
    for(int i = 0; i < l; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}