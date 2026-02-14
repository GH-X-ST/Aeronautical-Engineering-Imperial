// This function will compute a Pascal's triangle

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Declaration
long Pas(int m, int n);
long Fibonacci(int n);

int main()
{
    // Using try block catch exceptions
    try
    {
        // Ask user to input n
        int n;
        string N;
        
        cout << "Please enter the row you want to choose: " << endl;
        getline(cin, N);
        n = stoi(N);

        // Prints out nth row of Pascal's triangle
        cout << n << "th row of Pascal's triangle is:" << endl;
        for (int m = 1; m <= n + 1; m++)
        {
            cout << setw(5) << Pas(m, n);
        }
        cout << endl;
        
        // Prints out the sum of the nth row
        long sum = 0;
        for (int m = 1; m <= n + 1; m++)
        { 
            sum += Pas(m, n);
        }
        cout << "Sum of the " << n << "th row of Pascal's triangle is:" << endl;
        cout << sum << endl;
        
        // Calculate Fibbinacci sequence
        cout << "Please enter the nth Fibbinacci sequence you want to calculate" << endl;
        getline(cin, N);
        n = stoi(N);
        
        cout << n << "th Fibonacci sequence is: " << Fibonacci(n) << endl;
    }
    
    // Using catch block to display the exceptions
    catch (const logic_error& e)
    {
        cout << "An error occured: " << e.what() << endl;
    }    
}

// Defination
long Pas(int m, int n)
{
    if (n < 0)
    {
        throw logic_error("n should be equal or larger than 0");
    }
    
    else if (m < 1)
    {
        throw logic_error("m should be larger than 0");
    }
    
    else if (m > n + 1)
    {
        throw logic_error("m out of range");
    }
    
    else if (m == n + 1)
    {
        return 1;
    }
    
    else if (m == 1)
    {
        return 1;
    }
    
    else
    {
        return Pas(m - 1, n - 1) + Pas(m, n - 1);
    }
    
}

long Fibonacci(int n)
{
    if (n <= 0)
    {
        throw logic_error("n should be larger than 0");
    }    
    
    else
    {
        n = n;
        int i = n - 1;
        long sum = 0;
        
        while (i >= n - i)
        {
            sum = sum + Pas(n - i, i);
            i = i - 1;
        }
        
        return sum;
    }
}