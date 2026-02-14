// Introduce two way to create a matrix

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Ask user for input
    int N, M;
    
    cout << "Please enter the number of rows N: " ;
    cin >> N;
    cout << "Please enter the number of columns M: " ;
    cin >> M;
    
    // First apporach // as an array of pointers to arrays // less coefficient
    int **vMatrix1 = new int *[N]; // dynamically create array of pointers of size N
    
    for (int i = 0; i < N; i++)    // dynamically allocate memory of size M for each row
    {
        vMatrix1[i] = new int[M];
    }
    
    for (int i = 0; i < N; i++)    // assigned and print value to allocate memory
    {
        for (int j = 0; j < M; j++)
        {
            vMatrix1[i][j] = i * M + j;
            
            cout << setw(3) << vMatrix1[i][j] << " ";
        }
        
        cout << endl;
    }
    
    for (int i = 0; i < N; i++)
    {
        delete[] vMatrix1[i];     // deallocate memory of size M for each 
    }
    
    delete[] vMatrix1;            // deallocate memory of size N
    
    cout << " Now for second method " << endl;
    
    // Second apporach // using single array of numbers // more coefficient
    int *vMatrix2 = new int[M * N]; // dynamically allcate memory of size M*N
    
    for (int i = 0; i < N; i++)     // assigned and print value to allocate memory
    {
        for (int j = 0; j < M; j++)
        {
            vMatrix2[i * M + j] = i * M + j;
            
            cout << setw(3) << vMatrix2[i * M + j] << " ";
        }
        
        cout << endl;
    }    
    
    delete[] vMatrix2;              // deallocate memory
    
	return 0;
}
