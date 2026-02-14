// STL Algorithms // Provide common data manipulation algorithms for use with containers

/* algorithm-name(start(), end(), function)

generate()    // populate sequence of elements in a container

for_each()    // runs user-defined routine on each element from a range of elements

transform()   // manipulate contents of a container

copy()        // elements in one container to be copied into another container

min(a, b)     // minimum of two elements

max(a, b)     // maximum of two elements

min_element() // minimum of set of elements

max_element() // maximum of set of elements

sort()        // compare two elements and infer an ordering of them

binary_search // apply to sorted elements

*/

#include <iostream>
#include <algorithm> // For STL Algorithms
#include <vector>    // For STL std::vector
#include <array>     // For STL std::array
#include <cstdlib>
using namespace std;

// Function for print number
void print_number(int i)
{
    cout << i << endl;
}

// Function for sort
bool compareFunction(int i, int j)
{
    return (i > j);
}

int main()
{
    vector<int> vNumbers(20);
    
    // generate // Generate random number
    generate(vNumbers.begin(), vNumbers.end(), random);
    
    // for_each // Print vector
    for_each(vNumbers.begin(), vNumbers.end(), print_number);
    
    // lambda expression also vaild
    for_each(vNumbers.begin(), vNumbers.end(), [](int i){cout << i << endl;});
    
    // for_each // Finding numbers that are divisible by a specified value
    int divisor = 3;
    vector<int> numbers{1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50};
    
    for_each(numbers.begin(), numbers.end(), [&divisor] (int y)
    {
        if (y % divisor == 0)
        {
            cout << y << endl;
        }
    });
    
    // transform // Modifying containers with the transform algorithm
    vector<int> vInput = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vOutput(vInput.size());
    
    transform(vInput.begin(), vInput.end(), vOutput.begin(), [](int &x){return x * 3;});
    
    vector<int> vMoreInput = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    
    transform(vInput.begin(), vInput.end(), vMoreInput.begin(), vOutput.begin(),
    [](int &x, int&y){return x * y;});
    
    for_each(vOutput.begin(), vOutput.end(), [](int i){cout << i << endl;});
    
    // copy
    array<int, 10> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array<int, 10> y;
    
    copy(x.begin(), x.end(), y.begin());
    
    // copy_if
    vector<int> t;
    
    copy_if(x.begin(), x.end(), back_inserter(t), // same as push_back(t)
    [&](int p){return (p < 5);});
    
    for (auto i : t) {cout << i << endl;}
    
    // min_element
    cout << "Minimum is " << *min_element(vNumbers.begin(), vNumbers.end()) << endl;
    
    // max_element
    cout << "Maximum is " << *max_element(vNumbers.begin(), vNumbers.end()) << endl;
    
    // sort // In ascending order
    sort (vNumbers.begin(), vNumbers.end());
  
    // sort // In descending order
    sort (vNumbers.begin(), vNumbers.end(), compareFunction);
    
    // binary_search // Searching for a number in vector
    int vSearchVal = 1714636915;
    
    sort (vNumbers.begin(), vNumbers.end()); // have to sort in ascending order first
    
    if (binary_search(vNumbers.begin(), vNumbers.end(), vSearchVal))
    {
        cout << "Found it." << endl;
    }
    
	return 0;
}
