// vector // similar to dynamic allocated array
// however can be expanded or contracted after it has been created

// vector <datatype> identifier;

#include <iostream>
#include <vector> // For STL std::vector
using namespace std;

int main()
{
    unsigned int vSize = 10;
    
    // Creating vectors
    vector<double> vMyVector;           // vector of size 0
    
    vector<float> vVector2(vSize);      // vector of size 10 (do not have to be constant)
    
    vector<char> vString(vSize, 'z');   // specify the initial value
    
    vector<double> vAnother(vMyVector); // copy an existing vector
    
    // Using vectors
    unsigned int n = vMyVector.size(); // find the size of the vector
    cout << n << endl;
    
    vVector2 [3] = 7.0;                // assigned element
    
    vMyVector.push_back(7.0);          // add a single element to the end of array
    
    vMyVector.pop_back();              // remove last element
    
    unsigned int N = 10;
    vMyVector.resize(N);               // explicitly resized vector
    
    vMyVector.clear();                 // empty the vector
    
    // Insert and remove elements
    vector<double> V(5, 0.0);
    
    vector<double>::iterator vIt = V.begin() + 3; // specify the location of insertion
    
    V.insert(vIt, 7.0);                           // insert value
    
    vIt = V.begin() + 1;                          // specify another location
    
    V.erase(vIt);                                 // remove value

	return 0;
}
