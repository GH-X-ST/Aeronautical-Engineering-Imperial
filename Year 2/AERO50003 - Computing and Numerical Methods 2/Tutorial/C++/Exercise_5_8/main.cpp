// This function is aim to evaluate integral by Simpson's rule

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    // Define basic parameters
    double a = -1.0, b = 1.0;
    string H;
    double h, f, A, B, n;
    
    // Ask user for input
    cout << "Please enter the interval h: ";
    getline(cin, H);
    h = stod(H);
    
    // Verify the input h
    while (h < 0)
    {
        cout << "Input interval h is invalid! " << endl;
        cout << "Please enter a valid interval h: ";
        getline(cin, H);
        h = stod(H);  
    }
    
    // evaluate the integal
    n = (b - a) / h + 1; // define the number of data points
    
    for (int i = 1; i <= n / 2; i++)
    {
        double x = a + (2 * i - 1) * h;
        
        A += pow(x, 2) * exp (pow(x, 2));
    }
    
    for (int i = 1; i <= n / 2 - 1; i++)
    {
        double x = a + 2 * i * h;
        
        B += pow(x, 2) * exp (pow(x, 2));
    }
    
    f = ((b - a) / (3 * n)) * (pow(a, 2) * exp (pow(a, 2)) + 4 * A + 2 * B + pow(b, 2) * exp (pow(b, 2)));
    
    cout << f << endl;
    
    return 0;
}
