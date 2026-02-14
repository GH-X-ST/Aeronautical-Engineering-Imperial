#include <iostream>
using namespace std;

// Declaration
int MyFunction (double x, double y);

// Main program
int main()
{
    int a = MyFunction (1.2, 5.3);

	return 0;
}

// Defination
int MyFunction (double x, double y)
{
    double A = x + y;
    
    cout << A << endl;
    
    return A;
}