/* fixed size arrays will have number of limitations

1. exceed maximum size of the array

2. reserve memory is realtively small

3. cannot resizing

*/

// Heap // area of memory

/* Dynamic memory // memory allocated to a program during its execution


datatype *identifier = new datatype[size]

new    // allocated from heap


delete[] identifier

delete // explicitly released back to the operating system // release memory occupied by new

*/

// Memory leak // program fails to release memory assigned to it

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N; // normally sanitise this

    double *vValue = nullptr; // set vValue to a null pointer    
    int *vArray = nullptr; // set vArray to a null pointer
    
    try
    {
        // For value
        vValue = new double; // request dynamic memory for vValue
        
        *vValue = 42;        // store value at allocated memory
        cout << "Value of vValue is " << *vValue << endl;
        
        delete vValue;       // release memory
        
        // For array
        vArray = new int [5];  // request dynamic memory for vArray
        
        for (int i = 0; i < 5; i++)
        {
            vArray[i] = i;
            
            cout << vArray[i] << " "; // output array
        }
        
        cout << endl;
        
        delete vArray;         // release memory
        
        // For 2D array see 7.11
    }
    
    catch (const bad_alloc& e)
    {
       cout << "Unable to allocate memory!" << endl;

       return 1; 
    }

	return 0;
}
