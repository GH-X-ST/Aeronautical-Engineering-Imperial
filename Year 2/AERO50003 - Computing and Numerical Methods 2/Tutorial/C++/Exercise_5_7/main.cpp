// Calculate parachutist terminal velocity and print value to a file

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    // Define initial parameters
    double t0, t1 = 0.0; // define the initial time
    double v0, v1 = 0.0; // define two velocity parameter
    const double g = -9.8; // define the constant g
    string M, C; // define the mass and drag coefficient...
    double m, c; // convert to the double
    
    // Ask user for input
    cout << "Please write mass of the parachutist(kg): ";
    getline(cin, M);
    m = stod(M);
    
    cout << "Please write drag coefficient(kg/s): ";
    getline(cin, C);
    c = stod(C);

    // Calculate and output results
    ofstream vOut("Parachutist_terminal_velocity.txt", ios::out | ios::trunc);
    if (!vOut.good())
    {
        cout << "Invalid file output! Please check" << endl;
    }
    else
    {
        cout << setw(5) << "t(s)" <<
        setw(10) << setprecision(5) << "v(m/s)" << endl; // set title
        
        vOut << setw(5) << "t(s)" <<
        setw(10) << setprecision(5) << "v(m/s)" << endl; // output title
        
        cout << setw(5) << t0 <<
        setw(10) << setprecision(5) << v0 << endl; // show initial value
        
        vOut << setw(5) << t0 <<
        setw(10) << setprecision(5) << v0 << endl; // output initial value
        
        t1 = t0 + 1.0 ; // get initial t
        v1 = v0 + (g - (c / m) * v0) * (t1 - t0); // get initial v
        
        while (v0 != v1)
        {
            v0 = v1;
            t0 = t1;
            
            t1 = t0 + 1;
            v1 = v0 + (g - (c / m) * v0) * (t1 - t0);
            
            cout << setw(5) << t0 <<
            setw(10) << setprecision(5) << v0 << endl; // show current value
        
        
            vOut << setw(5) << t0 <<
            setw(10) << setprecision(5) << v0 << endl; // outut current value
        }

    cout << endl;
    cout << "Finish output" << endl;
    }
	return 0;
}
