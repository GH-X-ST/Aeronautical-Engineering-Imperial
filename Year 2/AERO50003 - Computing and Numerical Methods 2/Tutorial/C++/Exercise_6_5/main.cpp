// Using recursion to computes the first 15 Fibonacci numbers

#include <iostream>
#include <string>
using namespace std;

// Declaration
long Fibonacci(long n);

int main()
{
    try
    {
        int n;
        string N;
        
        // Ask user for input
        cout << "Please input the order of the Fibonacci numbers: ";
        getline(cin, N);
        n = stoi(N);
        
        // Output result
        cout << Fibonacci(n) << endl;
        
        return 0;
    }
    
    catch (const logic_error& e)
    {
        cout << "An error occured: " << e.what() << endl;
    }
    
}

// Defination
long Fibonacci(long n)
{
    long x;
    
    if (n < 0)
    {
        throw logic_error("n should be larger than 0");
    }
    
    else if (n == 0)
    {
        return 1;
    }
    
    else if (n == 1)
    {
        return 1;
    }
    
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}
