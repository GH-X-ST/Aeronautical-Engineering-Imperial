// This program will generate random value and find their min, max, mean values
// solve the problem that code will output same value for same input each time

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

double forMin(int N, double Array[]);
double forMax(int N, double Array[]);
double forMean(int N, double Array[]);

int main()
{
    const int N = 100; // define the length of array
    
    double Random[N]; 
    
    srand(time(0)); // Initialise the rand() make sure each time output is different
    
    for (int i = 0; i < N; i++)
    {
        Random[i] = (double (rand()) / RAND_MAX) * 100.0;
        
        /* if need random number from double 1.5 to 9.5

        (double (rand()) / RAND_MAX) * (9 - 1.5) + 1.5;

        */        
        
        cout << setw(5) << Random[i] << endl;
    }
    
    cout << "Min value is " << forMin(N, Random) << endl;
    cout << "Max value is " << forMax(N, Random) << endl;
    cout << "Mean value is " << forMean(N, Random) << endl;
    
	return 0;
}

// Function to find min of the array
double forMin(int N, double Array[])
{
    double Min = Array[0];
    
    for (int i = 0; i < N - 1; i++)
    {
        if (Min > Array[i + 1])
        {
            Min = Array[i + 1];
        }
            
        else
        {
        }
    }
    
    return Min;
}

// Function to find max of the array
double forMax(int N, double Array[])
{
    double Max = Array[0];
    
    for (int i = 0; i < N - 1; i++)
    {
        if (Max < Array[i + 1])
        {
            Max = Array[i + 1];
        }
            
        else
        {
        }
    }
    
    return Max;
}

// Function to find mean of the array
double forMean(int N, double Array[])
{
    double Mean = 0.0;
    
    for (int i = 0; i < N - 1; i++)
    {
        Mean += Array[i] / N;
    }
    
    return Mean;
}