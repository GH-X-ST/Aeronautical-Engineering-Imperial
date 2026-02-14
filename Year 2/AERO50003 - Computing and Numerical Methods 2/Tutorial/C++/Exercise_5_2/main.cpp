// This code is aim to computes the surface area and volume of a sphere

#include <iostream>
using namespace std;

int main()
{
    double vR, vV, vA = 0.0;
    string vI = " ";
    
    // Defining the constant
    const double vPi = 3.1415926;
    
    // Ask user to enter the sphere's radius
    cout << "Please enter the sphere's radius in m: " << endl;
    getline(cin, vI);
    vR = stod(vI);
    
    while (vR <= 0)
    {
        cout << "Please enter the valid sphere's radius!" << endl;
        cout << "Sphere's radius in m is: " << endl;
        getline(cin, vI);
        vR = stod(vI);
    }
    
    // Compute V and A
    vV = 4.0 * vPi * ( vR * vR * vR ) / 3.0;
    vA = 4.0 * vPi * ( vR * vR );
    
    // Output V and A
    cout << "Sphere's volume in m^3 is " << vV << endl;
    cout << "Sphere's area in m^2 is " << vA << endl;
    
	return 0;
}
