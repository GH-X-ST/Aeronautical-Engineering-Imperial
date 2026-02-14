// This program will sort the array by Insertion Sort algorithm

#include <iostream>
#include <ctime>
#include <cstdlib> // to use random function
using namespace std;

// Declaration
void insert(double a[], int p, double val, int l);
void insertionSort(double a[], int l); 

int main(int argc, char **argv)
{
    // Using code write in 7.1
    const int N = 100; // define the length of array
    double Random[N]; 
    
    srand(time(0)); // Initialise the rand() make sure each time output is different
    
    for (int i = 0; i < N; i++)
    {
        Random[i] = (double (rand()) / RAND_MAX) * 100.0;
    }
    
    try
    {
        insertionSort(Random, N);
        
        for (int i = 0; i < N; i++)
            {
                cout << Random[i] << endl;
            }   
    }
    
    catch (const logic_error& e)
    {
        cout << "An error occured: " << e.what() << endl;
    }
    
    
	return 0;
}


// Function to insert val to position p+1
void insert(double a[], int p, double val, int l)
{
    if (p + 1 > l)
    {
        throw logic_error("position should be inside the array!");
    }
    
    else if (p < 0)
    {
        throw logic_error("position cannot be negative!");
    }
    
    else if (p == 0)
    {
        a[p] = val;
    }
    
    else
    {
        while (val <= a[p - 1])
        {
            a[p] = a[p - 1];
            p--;
        }
        a[p] = val;
    }
}

// Function to sort value by function above
void insertionSort(double a[], int l)
{
    for (int i = 0; i < l; i++)
        {
            insert(a, i, a[i], l);
        }
}