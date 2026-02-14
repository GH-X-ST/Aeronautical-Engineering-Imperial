// This code is aim to compute motion of a free falling object

#include <iostream>
using namespace std;

int main()
{
    // Promote user to enter an initial height and time
    double vY0, vT = 0.0;
    string vIY0, vIT = " ";
    
    cout << "Please enter an initial height (m): " << endl;
    getline(cin, vIY0);
    vY0 = stod(vY0);
    
    cout << "Please enter time (s): " << endl;
    getline(cin, vIT);
    vY0 = stod(vT);
    
    // Determine the velocity and position of a body, initially at rest
    const double vG = 9.8; // define the acceleration (m/s^2)
    
    double vV, vY = 0.0;
    
    vV = - vG * vT; // calculate the velocity (m/s)
    
    vY = vY0 - 0.5 * vG * ( vT * vT ); // calculate the position (m)
    
    // Print the velocity and position to the screen
    
    cout << "Velocity at " << vT << "(s) is " << vV << "(m/s)" << endl;
    cout << "Position at " << vT << "(s) is " << vY << "(m)" << endl;
    
	return 0;
}
