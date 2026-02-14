// This program allow user to convert temperatures from Celsius to Fahrenheit

#include <iostream>
#include <string>
using namespace std;

// Declaration
double CtoF(double C);
double FtoC(double F);

// Convert temperature
int main()
{
    // Ask user for input
    double Temp, oTemp;
    string sTemp;
    
    int Sel;
    string sSel;
    
    cout << "Please enter the temperature: ";
    getline(cin, sTemp);
    Temp = stod(sTemp);
    
    // Ask user to choose option
    while (true)
    {
        cout << "Please enter your choice: " << endl;
        cout << "1. Celsius to Fahrenheit" << endl;
        cout << "2. Fahrenheit to Celsius" << endl;
        cout << "3. Exit" << endl;
        getline(cin, sSel);
        Sel = stoi(sSel);
        
        if (Sel == 1)
        {
            oTemp = CtoF(Temp);
            cout << "Temperature becomes " << oTemp << "(F)" << endl;
            break;
        }
        
        else if (Sel == 2)
        {
            oTemp = FtoC(Temp);
            cout << "Temperature becomes " << oTemp << "(C)" << endl;
            break;
        }
        
        else if (Sel == 3)
        {
            break;
        }
        
        else
        {
            cout << "No choice available for this input! " << endl;
        }
    }
    
	return 0;
}

// Defination
double CtoF(double C)
{
    double F;
    return F = 9 / 5 * C + 32;
}

double FtoC(double F)
{
    double C;
    return C = 5 / 9 * F - 32;
}