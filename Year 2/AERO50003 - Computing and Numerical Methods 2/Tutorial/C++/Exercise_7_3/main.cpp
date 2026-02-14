// Calculate matrix product

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// Set global value used for declaration
const int N = 5;

// Declaration
void multiply(double A[][N], double B[][N], double C[][N]);
void print2DArray(double A[][N]);

int main(int argc, char **argv)
{
    // Create squared matrices
    double A[N][N];
    double B[N][N];
    double C[N][N];
    
    // Allocate values to the matrices
    srand(time(0)); // Initialise the rand() make sure each time output is different
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = int(double (rand()) / RAND_MAX * 10.0);
            B[i][j] = int(double (rand()) / RAND_MAX * 10.0);
            C[i][j] = 0;
        }
    }
    
    multiply(A, B, C);
    
    // Compute matrices
    cout << "Matrix A is: " << endl;
    
    print2DArray(A);
    
    cout << "Matrix B is: " << endl;
    
    print2DArray(B);
    
    cout << endl;
    
    cout << "Matrix C is: " << endl;
    
    print2DArray(C);
    
    cout << endl;
    
	return 0;
}

// Defination
void multiply(double A[][N], double B[][N], double C[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print2DArray(double A[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << setw(5) << A[i][j] << " ";
        }
        cout << endl;
    }    
    
    cout << endl;   
}