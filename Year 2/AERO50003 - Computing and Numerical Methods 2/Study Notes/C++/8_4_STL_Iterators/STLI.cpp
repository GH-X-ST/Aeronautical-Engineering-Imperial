// ::iterator // similar to pointer //
// object marks a position in container object and allows such a container to be traversed

// vector<datatype>::iterator identifier

// auto // for C++11 // automatic type deduction

#include <iostream>
#include <vector>
#include <cstdlib> // for random
using namespace std;

int main()
{
    vector<unsigned int> vMyVector(10);
    
    srand(time(0)); // Initialise the rand() make sure each time output is different
    
    // Iterating over a vector by iterator
    vector<unsigned int>::iterator vIt;
    
    for (vIt = vMyVector.begin(); vIt < vMyVector.end(); ++vIt) // same as pointer
    {
        *vIt = rand();
    }
    
    // Iterating over a vector by auto and range based-loop
    for (auto &x : vMyVector) // range-declaration : range-expression
    {
        x = rand();
    }
    
    for (const auto &x : vMyVector)
    {
        cout << x << endl;
    }
    
	return 0;
}