#include <iostream>
using namespace std;

int sqr (int pVal);       // function...
double sqr (double pVal); // ...with same name

int main()
{
    cout << sqr(5) << endl;   // first function will be called  // according to the datatype int
    
    cout << sqr(5.5) << endl; // second function will be called // according to the datatype double
    
	return 0;
}

int sqr (int pVal)
{
    cout << "Integal Sqaure" << endl;
    return pVal * pVal;
}

double sqr (double pVal)
{
    cout << "Floating-point Sqaure" << endl;
    return pVal * pVal;
}