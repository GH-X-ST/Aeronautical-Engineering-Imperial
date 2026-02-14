// Pointer can be assigned in the same way as variables

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    double vK1 = 0.0;
    double vK2 = 1.0;
    double vK3 = 2.0;
    
    double *vPointer = &vK1;
    cout << vPointer << endl;  // print the address stored in vPointer
    cout << *vPointer << endl; // print the value at the address in
    
    vPointer = &vK3;
    cout << vPointer << endl;  // print the address stored in vPointer
    cout << *vPointer << endl; // print the value at the address in
    
    *vPointer += vK2;
    cout << vPointer << endl;  // print the address stored in vPointer
    cout << *vPointer << endl; // print the value at the address in
    cout << vK3 << endl;       // vK3 and *vPointer have the same value
    
    cout << endl;
    
    // Looping over an array using pointers
    int myArray[8] = {1, 1, 2, 3, 5, 8, 11, 19};
    
    int *ptr = &myArray[0];
    
    for (int i = 0; i < 8; i++)
    {
        cout << *ptr++ << endl;
    }
    
	return 0;
}
