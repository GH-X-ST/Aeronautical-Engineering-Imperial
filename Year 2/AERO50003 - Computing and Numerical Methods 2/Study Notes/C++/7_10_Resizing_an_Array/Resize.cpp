// Resizing an array

#include <iostream>
using namespace std;

int main()
{
    int max = 10;                       // no-const size

    int *vArray = new int [max];        // initially allocated
    
    // Define vArray
    
    int n = 0;
    
    // Read number into the array
    while (cin >> vArray[n])
    {
        n++;
        
        if (n >= max)
        {
            max *= 2;                   // double the previous size
            
            int *vTemp = new int [max]; // create new bigger array
            
            for (int i = 0; i < n; i++)
            {
                vTemp[i] = vArray[i];   // copy values to a new array
            }
            
            delete [] vArray;           // free old array memory
            
            vArray = vTemp;             // now vArray points to temp array
        }
    }
    
    return 0;
}
