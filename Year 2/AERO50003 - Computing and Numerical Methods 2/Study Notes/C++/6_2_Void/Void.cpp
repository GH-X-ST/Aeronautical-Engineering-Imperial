#include <iostream>
using namespace std;

// For function do not have a return statement at the end
void printValue (double pVal)
{
    cout << "Value is: " << pVal << endl;
}

int main()
{
    double a = 42;
    printValue (a); // do not need to define datatype
}
