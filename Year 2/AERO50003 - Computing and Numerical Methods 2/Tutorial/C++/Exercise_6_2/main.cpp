// This program is aim to sort the input in increasing order

#include <iostream>
#include <string>
using namespace std;

// Declaration
void swap(int &a, int &b);

int main()
{
    // Ask user for input
    int a, b, c;
    string A, B, C;
    
    cout << "Please input three integers below..." << endl;
    
    cout << "interger 1: ";
    getline(cin, A);
    a = stoi(A);
    
    cout << "interger 2: ";
    getline(cin, B);
    b = stoi(B);   
    
    cout << "interger 3: ";
    getline(cin, C);
    c = stoi(C); 
    
    // Sort the input
    if (a > b)
    {
        swap(a, b);
    }
    
    if (a > c)
    {
        swap(a, c);
    }
    
    if (b > c)
    {
        swap(b, c);
    }
    
    // Output the result
    cout << "Sorted : " << a << ", " << b << ", " << c << endl;
	return 0;
}

// Defination
void swap(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}
