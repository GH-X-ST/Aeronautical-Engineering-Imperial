#include <iostream>
using namespace std;

constexpr int Multiply(const int a, const int b) // const parameters in a function declared as constexpr
{
    return a * b;
}

int main(int argc, char **argv)
{    
    const int a = 2, b = 3;
    
    constexpr int result = Multiply(a, b);
    
    cout << result << endl;
	return 0;
}
