#include <iostream>
#include <map> // for STL std::map
#include <string>
using namespace std;

int main()
{
    // Define map
    map<string, unsigned long> CountryArea;
    
    CountryArea["Russia"] = 17098246;
    CountryArea["Canada"] = 9984670;
    CountryArea["China"] = 9596961;
    CountryArea["United States"] = 9833517;
    CountryArea["Brazil"] = 8515767;
    
    // Iteration through a map
    long vTotalArea;
    
    for (const auto &x : CountryArea)
    {
        cout << x.first << " has area: " << x.second << "(km^2) " << endl;
        vTotalArea += x.second;
    }
    
    cout << "Total Area of country listed above is " << vTotalArea << "(km^2)" << endl;
    
	return 0;
}
