// This program will sort the array by Insertion Sort algorithm

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// Declaration
void insert(vector<double> &a, vector<double>::iterator x);
void insertionSort(vector<double> &a); 

int main()
{
    int N;
    cout << "How many random value you want to generate? " << endl;
    cin >> N;
    cout << endl;
    
    vector<double> Random(N); 
    
    // *reserve* memory for N+1 elements
    
    Random.reserve (N + 1);
    
    srand(time(0)); // Initialise the rand() make sure each time output is different
    
    // Generate random number into the vector
    generate(Random.begin(), Random.end(), [&]{return (double(rand())/RAND_MAX) * 10.0;});
    
    cout << "Generated value" << endl;
    
    for_each(Random.begin(), Random.end(), [](double i){cout << i << endl;});
    
    cout << endl;
    
    
    // Sort the value
    insertionSort(Random);
    
    cout << "Sorted value" << endl;

    for_each(Random.begin(), Random.end(), [](double i){cout << i << endl;});
    
	return 0;
}


// Function to insert val to suitable position
void insert(vector<double> &a, vector<double>::iterator x)
{
    double val = *x;
    
    vector<double>::iterator y = x + 1;
    
    if (y == a.end())
    {
        return;
    }

    while (y != a.end() && val > *y)
    {
        y++;
    }
    
    a.insert(y, val);
    a.erase(x);
}

// Function to sort value by function above starting from end of the vector
void insertionSort(vector<double> &a)
{
    vector<double>::iterator x;
    
    for (x = a.end(); x != a.begin(); x--)
        {
            insert(a, x - 1);
        }
}
