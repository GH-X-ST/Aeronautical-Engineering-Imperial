// This program compute an approximation to pi using two different formulae

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Define the initial variable
    double vPiTest = round(M_PI * 10000.0); // accurate to 5 significant figures
    double vN1 = 0.0, vN2 = 1.0;          // the approximations
    int vK1 = 0, vK2 = 1;                 // initial condition
    
    // Approximate use first approach
    while (fabs(vPiTest - 4.0 * vN1 * 10000.0) > 0.5)
    {
        vN1 += pow(-1.0, vK1) / (2.0 * vK1 + 1.0);
        vK1++;
    }
    
    vN1 = 4.0 * vN1;
    
    // Approximate use second approach
    while (fabs(vPiTest - 2.0 * vN2 * 10000.0) > 0.5)
    {
        vN2 *= (4.0 * vK2 * vK2)/(4.0 * vK2 * vK2 - 1.0);
        vK2++;
    }
    
    vN2 = 2.0 * vN2;
    
    // Output the result
    cout.precision(10);
    
    cout << "First approximation use " << vK1 <<
    " loops to get results of pi " << vN1 << endl;
    
    cout << "Second approximation use " << vK2 - 1.0 <<
    " loops to get results of pi " << vN2 << endl;
}
