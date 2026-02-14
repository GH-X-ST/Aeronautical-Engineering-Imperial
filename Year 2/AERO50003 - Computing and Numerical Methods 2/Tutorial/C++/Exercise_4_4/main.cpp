// Calculate the deflection of a simply supported beam

#include <iostream>
using namespace std;

int main()
{
    // promote user for the parameters
    double vL, vE, vI, vW = 0.0;
    string vIL, vIE, vII, vIW = " ";
    
    cout << "Please input the length of the beam(m): " << endl;
    getline(cin, vIL);
    vL = stod(vIL);
    
    cout << "Please input the Young's modulus of the beam(Pa): " << endl;
    getline(cin, vIE);
    vE = stod(vIE);
  
    cout << "Please input the second moment of area(m^4): " << endl;
    getline(cin, vII);
    vI = stod(vII);

    cout << "Please input the distributed load(N/m): " << endl;
    getline(cin, vIW);
    vW = stod(vIW);
    
    // compute the deflection at the midpoint of the beam
    double vXmid = vL / 2.0;
    double vYmid = ( -vW / ( 24.0 * vE * vI ) ) * 
    ( ( vXmid * vXmid * vXmid * vXmid ) - 2.0 * vL * ( vXmid * vXmid * vXmid )
    + ( vL * vL * vL ) * vXmid );
    
    cout << "Deflection at the midpoint of the beam " << vYmid << "(m)" << endl;
    
	return 0;
}
