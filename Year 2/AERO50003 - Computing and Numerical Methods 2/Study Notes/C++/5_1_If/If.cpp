#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3 = 0;
    
    cout << "Please enter three integer: " << endl;
    cin >> n1 >> n2 >> n3;
    
    if (n1 >= n2)
    {
        if (n3 >= n2)
        {
            cout << "Minimum number is " << n2 << endl;
        }
        else
        {
            cout << "Minimum number is " << n3 << endl;
        }
    }
    else
    {
        if (n1 <= n3)
        {
            cout << "Minimum number is " << n1 << endl;
        }
        else
        {
            cout << "Minimum number is " << n3 << endl;
        }
    }
    
// We could test statement is true or not by two way
    
// if statement
    
    int a = 6, b = 6;
    
    if (a * b != 42)
    {
        cout << "Product of a and b is not 42!" << endl;
    }
    
// Static assertation
    
    constexpr int c = 6;
    constexpr int d = 6;
    
    static_assert (c * d == 42, "Product of a and b is not 42!"); // produce a complier error
    
}
