#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    int b = 5;
    int c = 4;
    
    double r = (double){ a + b * c / a * ( b - c ) + b % c };
    
    cout << "Result is: " << r << endl;
    
	return 0;
}
