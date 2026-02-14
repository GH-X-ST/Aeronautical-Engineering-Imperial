// This program is aim to computes n-factorial

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Define parameters
    int n = 0;
    unsigned int i = 1;
    unsigned long nfac = 1;
    string input;
    
    // Ask user for input
    cout << "Please input a positive integer n: ";
    getline(cin, input);
    n = stoi(input);
    
    // Verified input value
    while (true)
    {
        if (n <= 0)
        {
            cout << "Input is not a positive integer, please re-enter the n: ";
            getline(cin, input);
            n = stoi(input);
        }
        else
        {
            break;
        }
    }
    
    // Computes n-factorials
    while (i <= n)
    {
        nfac *= i;
        i++;
    }
    
    cout << "for n = " << n << ", value of n! = " << nfac << endl;
	return 0;
}
