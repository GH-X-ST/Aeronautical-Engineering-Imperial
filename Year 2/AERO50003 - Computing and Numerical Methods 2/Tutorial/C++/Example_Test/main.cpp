/* This program is aim to computes the absolute eror of 
 * y = sin(x)^2 + cos(x) ^ 2 when approximating sin(x) and cos(y)
 * by truncated series expansions for the requested value of x
*/

#include <iostream>
#include <cmath>
using namespace std;

// Declare the function

long factorial(int n);

double sinx(double x, int K);

double cosx(double x, int K);

// Main part

int main()
{
    // Initialise parameters
    double vX, vY1, vY2, vError = 0.0; // x, y1, y2. absolute error
    int vK = 5; // number of K for truncated series
    string vIX = " "; // to store input value
    
    // Ask user for input
    cout << "Please input a single value of x: ";
    getline(cin, vIX);
    
    // Convert and check x is in the correct range
    try
    {
        vX = stod(vIX); // convert string to double
        
        if (vX >= M_PI || vX <= -M_PI)
        {
            throw logic_error("input x is out of the range");
        }
    
    }
    
    catch (const logic_error& e)
    {
        cout << "An error occured: " << e.what() << endl;
    }
    
    // Calculate y by different approach
    vY1 = sin(vX) * sin(vX) + cos(vX) * cos(vX);
    
    vY2 = sinx(vX, vK) * sinx(vX, vK) + cosx(vX, vK) * cosx(vX, vK);
    
    // Calculate absolute error
    vError = fabs(vY1 - vY2);
    
    // Output result
    cout.precision(7);
    
    cout << "True values of sin(x): " << sin(vX) << endl;
    cout << "Approximated sin(x): " << sinx(vX, vK) << endl;
    
    cout << "True values of cos(x): " << cos(vX) << endl;
    cout << "Approximated cos(x): " << cosx(vX, vK) << endl;
    
    cout << "Absolute error of y:" << vError << endl;
    
	return 0;
}

// Function to calculate the factorial of positive integer

long factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);             // use recursion
    }
    else if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        throw logic_error("N must be >=c  0. "); // throw exception
    }
}

// Funcion to approximate sin(x)

double sinx(double x, int K)
{
    double pSINX = 0.0;
    
    for (int k = 0; k <= K; k++)
    {
        pSINX += (pow(-1, k) * pow(x, 2 * k + 1)) / factorial(2 * k + 1);
    }
    
    return pSINX;
}

// Funcion to approximate cos(x)
double cosx(double x, int K)
{
    double pCOSX = 0.0;
    
    for (int k = 0; k <= K; k++)
    {
        pCOSX += (pow(-1, k) * pow(x, 2 * k)) / factorial(2 * k);
    }
    
    return pCOSX;
}