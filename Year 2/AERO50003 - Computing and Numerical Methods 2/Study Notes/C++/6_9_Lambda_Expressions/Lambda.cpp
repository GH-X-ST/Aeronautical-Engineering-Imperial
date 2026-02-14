// Lambda expression is a function definition that is not bound to an identifier and can capture variables in scope
// [captures] (parameter_list) -> return_type{body}

/* Captures []
[] Capture nothing
[=] Capture all local variables by-value
[&] Capture all local variables by-reference
[x, y, &z] Customize
 */

#include <iostream>
using namespace std;

int main()
{
    int factor = 2;
    
    cout << &factor << endl;
    
    auto Fac = [&] (int x, int y) 
    {
        return factor * (x + y);
    };
    
    cout << Fac(3, 4) << endl;
    
	return 0;
}
