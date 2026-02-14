// Worked example

#include <iostream>
using namespace std;

int main()
{
    int n;
    
    for (n = 20; n > 0 ; n--)
    {
        if (n % 4 == 0)
        {
            continue;
        }
        
        cout << (20 - n) << endl;
        
        if (n == 5)
        {
            break;
        }
    }
    
    return 0;
}
