#include <iostream>
#include <string>

using namespace std;

// Set default value for function
void print(double pVal, string pLabel = "Value: ", string pUnits = "(cm)") // default value appear last in the parameter list
{
    cout << pLabel << pVal << pUnits << endl;
} 

int main()
{
    double vVal = 5.0;
    
    print(vVal);
    
    print(vVal, "My value: ");
    
    print(vVal / 100, "My value in meter: ", "(m)");
    
	return 0;
}