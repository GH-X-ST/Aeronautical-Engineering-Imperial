// This code is aim to calculate the motion of a parachutist

#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
    // Promote user to enter the mass and drag coefficient
    const double vG = 9.81;
    
    double vM, vC = 0.0;
    
    string vIM,vIC = " ";
    
    cout << "Please enter the mass (in kg): " << endl;
    getline(cin, vIM);
    vM = stod(vIM);
    
    cout << "Please enter the drag coefficient (in kg/s): " << endl;
    getline(cin, vIC);
    vC = stod(vIC);
    
    // Compute parachutist velocity
    double vV3, vV5, vV10 = 0.0;
    
    vV3 = ( vM * vG / vC ) * ( exp( -vC * 3.0 / vM ) - 1.0 );
    
    vV5 = ( vM * vG / vC ) * ( exp( -vC * 5.0 / vM ) - 1.0 );
    
    vV10 = ( vM * vG / vC ) * ( exp( -vC * 10.0 / vM ) - 1.0 );
    
    cout << "Parachutist velocity at 3s is " << vV3 << "(m/s)" << endl;
    
    cout << "Parachutist velocity at 5s is " << vV5 << "(m/s)" << endl;
    
    cout << "Parachutist velocity at 10s is " << vV10 << "(m/s)" << endl;
    
    // Compute terminal velocity
    double vVt = 0.0;
    
    double vTt = numeric_limits<double>::max();
    
    vVt = ( vM * vG / vC ) * ( exp( -vC * vTt / vM ) - 1.0 );
    
    cout << "Parachutist terminal velocity is " << vVt << "(m/s)" << endl;
    
	return 0;
}
