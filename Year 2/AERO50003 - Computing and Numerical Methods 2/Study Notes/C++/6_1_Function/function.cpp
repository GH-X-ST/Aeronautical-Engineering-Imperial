/* Function

return_type functin_name (datatype identifier)
{
statements;
return return_value;
}

*/

// Compute the area of a circle
#include <iostream>
using namespace std;

double computeArea (double pRadius) // pRadius is a passing by value
{
    const double vPi = 3.14159;
    double vArea;
    vArea = vPi * pRadius * pRadius;
    return vArea;
}

int main()
{
    double vMyRadius = 4.6, vMyArea;
    vMyArea = computeArea (vMyRadius);
    
    cout << vMyArea << endl;
    
	return 0;
}
