// ifstream // Input from file

// ofstream // Output from file
// fstream  // Both input and output

/* File access modes

ios::in     // File is open for input only

ios::out    // File is open for output only
 
ios::binary // File is formatted as binary (opposed to text)

ios::atet   // File is opened with initial position at the end of the file

ios::app    // Append data to the end of the file if it already exists

ios::trunc  // Delete the file and start afresh if the file already exists

*/

#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int x=5;
    
    ofstream vOut("data.txt", ios::out | ios::trunc); // use OR to combine multiple modes
    
    vOut.precision(5); // set precision of vOut,
    
    vOut << setw(15) << "# x"
         << setw(15) << "x^2"
         << setw(15) << "x^3" << endl;
    
    vOut << setw(15) << x
         << setw(15) << x*x
         << setw(15) << x*x*x << endl;
    
    vOut.close(); // close the file
}

