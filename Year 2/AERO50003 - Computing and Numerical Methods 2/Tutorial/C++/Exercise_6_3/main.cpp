// Find the deflections of different kind of beam

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Declaration
double simpB(double x, double E, double I, double L, double w);
double cantB(double x, double F, double E, double I, double L);
    
int main()
{
    double F, E, I, L;
    int Mode;
    
    cout << "Please input the length of the beam(m): " << endl;
    cin >> L;
    
    cout << "Please input the Young's modulus of the beam(Pa): " << endl;
    cin >> E;
  
    cout << "Please input the second moment of area(m^4): " << endl;
    cin >> I;
    
    try
    {
    // Ask user what beam they want to calculate
    cout << "What beam is it?" << endl;
    cout << "1. Simply supported beam" << endl;
    cout << "2. Cantilever beam" << endl;
    cout << "3. Exit" << endl;
    cin >> Mode;
    
    if (Mode < 1 || Mode > 3)
    {
        throw logic_error("Invalid input");
    }
    
    // Output result to file at interval 0.1m
    ofstream yOut("deflection.txt", ios::out | ios::trunc);
    
    if (Mode == 1)
    {
        double w;
        
        cout << "Please input the distributed load(N/m): " << endl;
        cin >> w;                          
        
        for (double x = 0; x <= L + 0.01; x += 0.01)
        {
            yOut << setw(5) << x << setw(15) << setprecision(5) << simpB(x, E, I, L, w) << endl;
            cout << setw(5) << x << setw(15) << setprecision(5) << simpB(x, E, I, L, w) << endl;
        }
    }    
    
    else if (Mode == 2)
    {
        double F;
        
        cout << "Please input the load(N/m): " << endl; 
        cin >> F;
        
        for (double x = 0; x <= L + 0.01; x += 0.01)
        {
            yOut << setw(5) << x << setw(15) << setprecision(5) << cantB(x, F, E, I, L) << endl;
            cout << setw(5) << x << setw(15) << setprecision(5) << cantB(x, F, E, I, L) << endl;
        }
    }     
    
    else if (Mode == 3)
    {
    }
    
    yOut.close();
    
    }

    catch (const logic_error& e)
    {
        cout << "An error occured: " << e.what() << endl;
    }

    
    return 0;
}

// Defination
double simpB(double x, double E, double I, double L, double w)
{
    // Compute the deflection of the simply supported beam
    return ( -w / ( 24.0 * E * I ) ) * 
    ( ( x * x * x * x ) - 2.0 * L * ( x * x * x )
    + ( L * L * L ) * x );
}

double cantB(double x, double F, double E, double I, double L)
{
    // Compute the deflection of the simply supported beam
    return ( F / ( 6.0 * E * I ) ) * 
    ( ( x * x * x ) - 3.0 * L * ( x * x ) );    
}
