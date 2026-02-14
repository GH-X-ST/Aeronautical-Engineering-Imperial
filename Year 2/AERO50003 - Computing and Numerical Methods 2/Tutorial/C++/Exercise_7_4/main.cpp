// Calculate matrix product by recursive algorithm

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// Set global value used for declaration
const int N = 4;

// Declaration
void recursiveMultiply(double A[][N], double B[][N], double C[][N], int n, int Ai, int Aj, int Bi, int Bj, int Ci, int Cj);
void print2DArray(double A[][N]);

int main()
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
    
    recursiveMultiply(A, B, C, N, 0, 0, 0, 0, 0, 0);
    
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
// www.cnblogs.com/SHQHDMR/p/11089228.html
void recursiveMultiply(double A[][N], double B[][N], double C[][N], int n, int Ai, int Aj, int Bi, int Bj, int Ci, int Cj)
{
    if (n == 1)
    {
        C[Ci][Cj] += A[Ai][Aj] * B[Bi][Bj];
        return;
    }
    
    n = n / 2;
    
    // for Ci, Cj
    recursiveMultiply(A, B, C, n, Ai, Aj, Bi, Bj, Ci, Cj);                 
    recursiveMultiply(A, B, C, n, Ai, Aj + n, Bi + n, Bj, Ci, Cj);  

    // for Ci, Cj + n
    recursiveMultiply(A, B, C, n, Ai, Aj, Bi, Bj + n, Ci, Cj + n);                  
    recursiveMultiply(A, B, C, n, Ai, Aj + n, Bi + n, Bj + n, Ci, Cj + n);
    
    // for Ci + n, Cj
    recursiveMultiply(A, B, C, n, Ai + n, Aj, Bi, Bj, Ci + n, Cj);
    recursiveMultiply(A, B, C, n, Ai + n, Aj + n, Bi + n, Bj, Ci + n, Cj);
    
    // for Ci + n, Cj + n
    recursiveMultiply(A, B, C, n, Ai + n, Aj, Bi, Bj + n, Ci + n, Cj + n);
    recursiveMultiply(A, B, C, n, Ai + n, Aj + n, Bi + n, Bj + n, Ci + n, Cj + n);
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
