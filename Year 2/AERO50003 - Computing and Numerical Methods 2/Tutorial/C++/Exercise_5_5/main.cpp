// This program will calculate a discretised sine function and write to the file

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    // Define the parameters
    double x = 0.0, s = 0.0;
    const double pi = M_PI;
    string read;
    
    // Create a file output stream
    ofstream vOut("sine.txt", ios::out | ios::trunc);
    
    // Calculate the ith value of x
    if (vOut.good()) // test if file stream object is valid
    {
        for (int i = 0; i <= 99; i++)
        {
            x = 2 * pi * i / 100;
            s = sin(x);
            
            vOut << setw(10) << setprecision(5) << x;
            vOut << setw(10) << setprecision(5) << s << endl;
        }
        vOut.close();
    }
    else
    {
        cout << "Failed to create a file! " << endl;
    }
    
    return 0
}