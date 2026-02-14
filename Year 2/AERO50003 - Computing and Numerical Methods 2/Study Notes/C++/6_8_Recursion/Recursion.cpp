// Recursion is a function that calls itself

// Example using recursion to find a factorial of a parameter

#include <iostream>
using namespace std;

long factorial(int n);

int main()
{
    int n;
    cout << "Please enter a number to find its factorial: " << endl;
    cin >> n;
    
    try
    {
        cout << "The factorial of " << n << " is " << factorial(n);
    }
    
    catch (const logic_error& e)
    {
        cout << "An error occured: " << e.what() << endl;
    }
    
	return 0;
}

long factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        throw logic_error("N must be >=c  0. ");
    }
}