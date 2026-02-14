// A pointer is an identifier whose value is a memory address

/* Declaring a pointer

int x = 7;

int *a = &x;    // declare a pointer to an integer

double y = 3.2;

double *b = &y; // declare a pointer to a double 

*/

// Using pointers and deferencing them

#include <iostream>
using namespace std;

int main()
{
    double vMyData     = 3.14159;  // variable delcaration
    
    double *vMyPointer = &vMyData; // store address of vMyData in vMyPointer
    
    cout << vMyPointer << endl;    // print the adress stored in vMyPointer
    
    cout << *vMyPointer << endl;   // print the value at the address in
    
    double *vNullPointer;          // pointer store nothing
    
    cout << *vNullPointer << endl; // might print an arbitary number or cause segmentation fault

    /* Segmentation fault
    
    program attempts to access a memory location  which CPU cannot physically address
    
    */
    
    double *vNPointer = nullptr;      // we can store null value to a pointer
    
    cout << vNPointer << endl;     // nothing will be pointed so output is empty
    
    cout << *vNPointer << endl;    // 0
    
    // Reliably test if a pointer is a nullptr
    if (vMyPointer)
    {
        cout << vMyPointer << endl;
    }
    
    if (vPointer)
    {
        cout << vPointer << endl;
    }
    
	return 0;
}