#include <iostream>
using namespace std;

void tripleValue(double& pVal); // reference operator // & // store the value of pVal after running the function

int main()
{
    double vMyVal = 3.0;
    
    cout << "vMyVal is " << vMyVal << endl;
    
    tripleValue(vMyVal);
    
    cout << "vMyVal becomes " << vMyVal << endl;
    
	return 0;
}

void tripleValue(double& pVal)
{
    pVal *= 3.0; // this function do not have return
}