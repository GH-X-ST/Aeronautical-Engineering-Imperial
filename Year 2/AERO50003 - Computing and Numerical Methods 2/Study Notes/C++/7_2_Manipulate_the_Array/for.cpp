// Using for-loop to manipulate an array

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const unsigned int vSize = 20;
    
    double vMyArray[vSize];
    
    for (unsigned int i = 0; i < vSize; i++)
    {
        vMyArray[i] = 2.0 * i;
        
        cout << setw(5) << vMyArray[i];
    }
    
    cout << endl;
    
	return 0;
}
