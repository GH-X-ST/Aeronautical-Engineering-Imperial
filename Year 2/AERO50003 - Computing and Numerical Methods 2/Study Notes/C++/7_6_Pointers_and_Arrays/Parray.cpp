// Printing an array using pointers and pointer arthmetic

#include <iostream>
using namespace std;

int main()
{
    const unsigned int size = 5;
    
    double vMyArray[size];
    
    for (unsigned int i = 0; i < size; i++)
    {
        vMyArray[i] = i + 1;
    }
    
    double *vMyPointer = &vMyArray[0];
    
    for (unsigned int i = 0; i < size; i++)
    {
        cout << *vMyPointer << endl;
        
        vMyPointer++;
    }
    
    cout << endl;
    
    cout << *vMyArray << endl;  // vMyArray[0] = *vMyArray
    
	return 0;
}
