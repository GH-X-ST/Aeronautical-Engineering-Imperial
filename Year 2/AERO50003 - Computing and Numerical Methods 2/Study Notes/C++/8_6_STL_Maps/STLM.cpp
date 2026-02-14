// map // extension to the set // maps unique keys to values

// map<key-type, value-type> identifier

#include <iostream>
#include <map> // For STL std::map
#include <string>

using namespace std;

int main()
{
    // Iteration through map
    map<string, unsigned int> vPeopleAges;
    
    vPeopleAges["Sally"] = 26;
    vPeopleAges["James"] = 30;
    vPeopleAges["Sally"] = 27; // Replaces previous value for Sally
    
    for (const auto &x : vPeopleAges)
    {
        cout << "Name: " << x.first << ", age: " << x.second << endl;
    }

	return 0;
}
