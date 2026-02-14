#include <iostream>
#include <vector>    // To use STL vector container
#include <algorithm> // To use STL algorithm 
#include <cstdlib>   // To generate random number
#include <string>
using namespace std; 

// Declaratioin
double Random()
{
    return (double (rand()) / RAND_MAX) * 100.0;
} 

int main()
{
    unsigned int vSize = 100;
    
    srand(time(0)); // Initialise the rand() make sure each time output is different
    
    // Create two vectors
    
    vector<double> vV1(vSize);
    
    vector<double> vV2(vSize);
    
    for (unsigned int i = 0; i < vSize; i++)
    {
        vV1[i] = Random();
        vV2[i] = Random();
    }
    
    // Using iterators to generate sum of the first two vectors
    vector<double> vV3(vV1.size(), 0.0);
    
    auto vI1 = vV1.begin();
    auto vI2 = vV2.begin();
    auto vI3 = vV3.begin();
    
    for ( ; vI1 < vV1.end(); ++vI1, ++vI2, ++vI3) // same as pointer
    {
        *vI3 = *vI1 + *vI2;
    }
    
    // Output result
    for (auto i : vV3)
    {
        cout << i << endl;
    }
    
    cout << "Size of vV3 is: " << vV3.size() << endl;
    cout << endl;
    
    // Delete every element of the third vector except first ten
    while (vV3.size() > 10)
    {
        vV3.pop_back();
    }
    
    // Output result again
    for (auto i : vV3)
    {
        cout << i << endl;
    }
    
    cout << "Size of vV3 becomes: " << vV3.size() << endl;
    cout << endl;
    
    // Create a vector containing numbers read from the terminal
    vector<double> vV4; // create a empty vector
    string N;
    double n;
    
    while(true)
    {
        cout << "Please entering a value, entering T to terminate" << endl;
        getline(cin, N);
        
        if (N == "T")
        {
            break;
        }
        
        n = stod(N);
        
        vV4.push_back(n);
    }
    
    // Output result
    for (auto i : vV4)
    {
        cout << i << endl;
    }
    
    cout << "Size of vV4 becomes: " << vV4.size() << endl;
    cout << endl;
    
	return 0;
}
