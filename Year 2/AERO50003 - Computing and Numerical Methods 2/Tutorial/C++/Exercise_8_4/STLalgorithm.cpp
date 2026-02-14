#include <iostream>
#include <algorithm> // For STL Algorithms
#include <vector>    // For STL std::vector
#include <cstdlib>   // To generate random number
#include <cmath>
using namespace std;

int main()
{
    unsigned int vSize = 10;
    vector<double> x(vSize);
    vector<double> y(vSize);
    
    // Generate random number
    generate(x.begin(), x.end(), [&]{return (double(rand())/RAND_MAX) * 10;});
    generate(y.begin(), y.end(), [&]{return (double(rand())/RAND_MAX) * 10;});
    
    // Print the coordinates
    for_each(x.begin(), x.end(), [](double i){cout << i << " ";});
    cout << endl;
    for_each(y.begin(), y.end(), [](double i){cout << i << " ";});
    cout << endl;
    
    // Double all the number in x vector
    for_each(x.begin(), x.end(), [](double &i){i *= 2;});
    cout << endl;
    for_each(x.begin(), x.end(), [](double i){cout << i << " ";});
    cout << endl;
    
    // Compute the distanve of each point from the origin
    vector<double> distance(x.size());
    
    transform(x.begin(), x.end(), y.begin(), distance.begin(),
    [](double &i, double &j){return sqrt(i * i + j * j);});
    
    for_each(distance.begin(), distance.end(), [](double i){cout << i << " ";});
    cout << endl;
    
    // Find the nearest and furthest distance
    cout << "Nearest distance is: " << *min_element(distance.begin(), distance.end()) << endl;
    cout << "Furthest distance is: " << *max_element(distance.begin(), distance.end()) << endl;
    
	return 0;
}
