/* Calling function in nested namespace

namespace1::namespace2::namespace3::namespace4::function()

*/

/* Thrown exception

# include <exception>

using namespace std;

throw error

overflow_error() // Calculation exceed range of datatype
bad_alloc()      // Failure to allocate storage on the heap
logic_error()    // Parameter to a function violate some conditions

*/

#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

// Create a new namespace
namespace mymath
{
    // Create a function to calculate log
    double mylog(double num)
    {
        if (num <= 0)
        {
            throw logic_error("Number must be > 0. ");
        }
        return log(num);
    }
}

int main()
{
    // Using try block catch exceptions
    try
    {
        cout << mymath::mylog(2) << endl; // calling namespace mymath
        cout << mymath::mylog(-2) << endl;
    }
    
    // Using catch block to display the exceptions
    catch (const logic_error& e)
    {
        cout << "An error occured: " << e.what() << endl;
    }
    
    catch (const bad_alloc& e)
    {
        cout << "No allocations here, so should not be called! " << e.what() << endl;
    }
    
	return 0;
}
