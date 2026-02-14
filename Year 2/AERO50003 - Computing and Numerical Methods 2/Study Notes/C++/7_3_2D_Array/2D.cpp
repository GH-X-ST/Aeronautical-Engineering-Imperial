// Declaring and using 2D array

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int vMy2DArray[3][2] = { {0, 1}, {2, 3}, {4, 5} };
    
    // Accessing two dimensional array using nested for loops
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "vMy2DArray[" << i << "][" << j << "] = " << vMy2DArray[i][j] << endl;
        }
    }

	return 0;
}
