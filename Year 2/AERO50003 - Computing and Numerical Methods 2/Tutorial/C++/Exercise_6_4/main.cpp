// This program compute bionomial coefficient of n and k

#include <iostream>
using namespace std;

// Using own namespace
namespace fac
{
    unsigned long factorial(int n)
    {
        unsigned long nfac = 1.0;
        
        int i = 1;
        
        while (i <= n)
            {
                nfac *= i;
                i++;
            }
    
    return nfac;        
    }
}


int main()
{
    // Ask user for input
    
    try
    {
    int n, k;
    
    cout << "Please enter n: ";
    cin >> n;
    
    if (n < 0)
    {
        throw logic_error ("n muse be > 0");
    }
    
    cout << "Please enter k: ";
    cin >> k;
    
    if (k < 0)
    {
        throw logic_error ("k muse be > 0");
    }
 
    if (n - k < 0)
    {
        throw logic_error ("k muse be > n");
    }
    
    // Calculate binominal coefficient
    unsigned long BC;
    
    BC = fac::factorial(n) / fac::factorial(k) / fac::factorial(n - k); // Not using * cause initial value is very large
    
    cout << BC << endl;
   
    }
    
    // Output exceptions
    catch (const logic_error& e)
    {
        cout << "An error occured: " << e.what() << endl;
    }     
    
	return 0;
}